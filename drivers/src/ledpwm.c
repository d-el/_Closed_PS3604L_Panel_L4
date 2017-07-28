/*!****************************************************************************
* @file    ledpwm.c
* @author  d_el
* @version V1.0
* @date    27.12.2015, by d_el
* @brief   pwm for lcd led
* @copyright GNU Public License
*/

/*!****************************************************************************
* Include
*/
#include "ledpwm.h"

/*!****************************************************************************
* MEMORY
*/

/*!****************************************************************************
* @brief Initialize timer
*/
void ledPwm_init(void){
	gppin_init(GPIOB, 0, digitalInput, pullDisable, 0, 0);	//DUMMY

    //TIM16_CH1 - PA6
	gppin_init(GPIOA, 6, alternateFunctionPushPull, pullDisable, 0, 14);
    
    RCC->APB2ENR  	|= RCC_APB2ENR_TIM16EN;                  	//Clock Enable
    RCC->APB2RSTR	|= RCC_APB2RSTR_TIM16RST;					//Reset
    RCC->APB2RSTR	&= ~RCC_APB2RSTR_TIM16RST;

    TIM16->PSC     	= 1 - 1;                                 	//Set prescaler
    TIM16->CCER    	|= TIM_CCER_CC1E;                     		//Chennel enable
    TIM16->CCMR1   	|= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1; 	//PWM mode
    TIM16->ARR     	= 1000;                                     //Auto-reload value
    TIM16->CCR1    	= 0;                                        //Compare value
    TIM16->CR1     	|= TIM_CR1_ARPE;                            //TIMx_ARR register is buffered
    TIM16->BDTR		|= TIM_BDTR_MOE;
    TIM16->CR1     	|= TIM_CR1_CEN;                             //Count enable
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
