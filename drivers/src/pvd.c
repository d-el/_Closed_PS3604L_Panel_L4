/*!****************************************************************************
* @file    pvd.c
* @author  d_el
* @version V1.0
* @date    01.08.2016, Storozhenko Roman
* @brief   --
* @copyright GNU Public License
*/

/*!****************************************************************************
* Include
*/
#include "pvd.h"

/*!****************************************************************************
* MEMORY
*/

/*!****************************************************************************
* @brief   Обработчик прерывания PVD
* @param    
* @retval   
*/
void PVD_IRQHandler(void){
    setLcdBrightness(0);
	LED_OFF();
	nvMem_savePrm(&userConfRegion);
	lcd_disable();
	BeepTime(ui.beep.goodbye.time, ui.beep.goodbye.freq);
	LED_ON();
	delay_ms(10000);
	NVIC_SystemReset();
}

/*!****************************************************************************
* Инициализация PVD с прерыванием
*/
void pvd_init(void){
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;                          //Power interface clock enable
    PWR->CR     |= PWR_CR_PLS_2V9;                              //Напряжение срабатывания
    PWR->CR     |= PWR_CR_PVDE;                                 //Power voltage detector enable

    EXTI->IMR   |= EXTI_IMR_MR16;                               //Interrupt request from Line 16 is not masked
    EXTI->EMR   |= EXTI_EMR_MR16;                               //Event request from Line 16 is not masked

    EXTI->RTSR  |= EXTI_RTSR_TR16;                              //Rising trigger event configuration bit of line 16

    NVIC_EnableIRQ (PVD_IRQn);                                  //PVD through EXTI Line detection Interrupt
    NVIC_SetPriority (PVD_IRQn, PVD_IRQ_Priority);              //Установить приоритет
}

/*!****************************************************************************
* Инициализация PVD с прерыванием
*/
void pvd_disable(void){
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;                          //Power interface clock enable
    PWR->CR     |= PWR_CR_PLS_2V9;                              //Напряжение срабатывания
    PWR->CR     |= PWR_CR_PVDE;                                 //Power voltage detector enable

    EXTI->IMR   &= EXTI_IMR_MR16;                               //Interrupt request from Line 16 is not masked
    EXTI->EMR   &= EXTI_EMR_MR16;                               //Event request from Line 16 is not masked

    EXTI->RTSR  |= EXTI_RTSR_TR16;                              //Rising trigger event configuration bit of line 16

    NVIC_DisableIRQ (PVD_IRQn);                                  //PVD through EXTI Line detection Interrupt
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
