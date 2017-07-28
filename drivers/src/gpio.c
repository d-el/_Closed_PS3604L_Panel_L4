/*!****************************************************************************
* @file     gpio.c
* @author   Storozhenko Roman - D_EL, 14.08.2016 - 4eef
* @version  V1.0
* @date     20.07.2016
* @date     02.08.2016  fix set nAF
* @brief    gpio driver for stm32F0
*/

/*!****************************************************************************
* Include
*/
#include "gpio.h"

/*!****************************************************************************
* MEMORY
*/
const pinMode_type    pinsMode[] = {
/*1 */  makepin(GPIOB,  3,  digitalInput, 	pullUp,    		0,	0), //bMode
/*2 */  makepin(GPIOA,  4,  digitalInput, 	pullUp,    		0,	0), //bOnOff
/*3 */  makepin(GPIOA,  15, digitalInput, 	pullUp,    		0,	0), //bView
/*4 */  makepin(GPIOB,  1,  digitalInput, 	pullUp,    		0,	0), //bNext
/*5 */  makepin(GPIOA,  12, digitalInput, 	pullUp,    		0,	0), //bZero
/*6 */  makepin(GPIOA,  11, digitalInput, 	pullUp,    		0,	0), //bUp
/*7 */  makepin(GPIOA,  10, digitalInput, 	pullUp,    		0,	0), //bDown
/*8 */  makepin(GPIOB,  9,  outPushPull,  	pullDisable,	0,	0), //LED
//*9 */  makepin(GPIOB,  14, digitalInput, 	pullDisable,	0,	0), //dummy
//*10*/  makepin(GPIOB,  15, digitalInput, 	pullDisable,	0,	0), //dummy
};
uint32_t pinNum = sizeof(pinsMode) / sizeof(pinMode_type);

/*!****************************************************************************
* InitAllGpio
*/
void gpio_init(void){
    pinMode_type *pgpios;
    pinMode_type *pgpiosEnd;

    pgpios = (pinMode_type*)pinsMode;
    pgpiosEnd = pgpios + pinNum;

    while(pgpios < pgpiosEnd){
        gppin_init(pgpios->p, pgpios->npin, pgpios->mode, pgpios->pull, pgpios->iniState, pgpios->nAF);
        pgpios++;
    }
}

/*!****************************************************************************
*
*/
void gppin_init(GPIO_TypeDef *port, uint8_t npin, gpioMode_type mode, gpioPull_type pull, uint8_t iniState, uint8_t nAF){
    //Clock enable
         if(port == GPIOA)   RCC->AHB2ENR    |= RCC_AHB2ENR_GPIOAEN;
    else if(port == GPIOB)   RCC->AHB2ENR    |= RCC_AHB2ENR_GPIOBEN;
    else if(port == GPIOC)   RCC->AHB2ENR    |= RCC_AHB2ENR_GPIOCEN;
    else if(port == GPIOD)   RCC->AHB2ENR    |= RCC_AHB2ENR_GPIODEN;
    else if(port == GPIOE)   RCC->AHB2ENR    |= RCC_AHB2ENR_GPIOEEN;
    //else if(port == GPIOF)   RCC->AHB2ENR    |= RCC_AHB2ENR_GPIOFEN;
    //else if(port == GPIOG)   RCC->AHB2ENR    |= RCC_AHB2ENR_GPIOGEN;
    else if(port == GPIOH)   RCC->AHB2ENR    |= RCC_AHB2ENR_GPIOHEN;
    //else if(port == GPIOO)   RCC->AHB2ENR    |= RCC_AHB1ENR_GPIOOEN;

    if(iniState != 0){
        port->BSRR = (1<<npin);
    }
    else{
        port->BRR = (1<<npin);
    }

    /*
    * Clear bit field
    */
    port->MODER         &= ~(0x03 << (2 * npin));
    port->OTYPER        &= ~(1<<npin);
    port->PUPDR         &= ~(GPIO_RESERVED << (2*npin));
    port->AFR[npin / 8] &= ~(GPIO_AFRL_AFSEL0_Msk << (4*(npin % 8)));

    //Set pull
    if(pull == pullUp){
        port->PUPDR |= GPIO_PULL_UP << (2*npin);
    }else if(pull == pullDown){
        port->PUPDR |= GPIO_PULL_DOWN << (2*npin);
    }

    //Set mode
    switch(mode){
        case analogMode:
            port->MODER |= GPIO_ANALOG_MODE << (2*npin);
            break;

        case digitalInput:
            port->MODER         &= ~(0x03 << (2 * npin));
            break;

        case outPushPull:
            port->MODER |= GPIO_GP_OUT << (2*npin);
            port->OTYPER |= GPIO_PUSH_PULL << npin;
            break;

        case outOpenDrain:
            port->MODER     |= GPIO_GP_OUT << (2*npin);
            port->OTYPER    |= GPIO_OPEN_DRAIN << npin;
            break;

       case alternateFunctionPushPull:
            port->MODER     |= GPIO_AF_MODE << (2*npin);
            port->OTYPER    |= GPIO_PUSH_PULL << npin;
            port->OSPEEDR   |= 3 << (2*npin);   //High speed
            break;

        case alternateFunctionOpenDrain:
            port->MODER     |= GPIO_AF_MODE << (2*npin);
            port->OTYPER    |= GPIO_OPEN_DRAIN << npin;
            break;
    }

    //Set number alternate function
    port->AFR[npin / 8] |= nAF << (4*(npin % 8));
}

/*************** (C) COPYRIGHT ************** END OF FILE ********* D_EL *****/
