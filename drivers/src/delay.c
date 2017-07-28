/*!****************************************************************************
* @file    delay.c
* @author  Storozhenko Roman - D_EL
* @version V2.2
* @date    17-01-2015
* @copyright GNU Public License
*/

/*!****************************************************************************
* Include
*/
#include "delay.h"

#if(DELTIM_USE_STATIC_INLINE == 0)

/*!****************************************************************************
* @brief    Задержка us
*/
void delay_us(uint16_t us){
    DELTIM->PSC     = DELTIM_FREQ / 1000000 - 1;                  	//Предделитель на 1us
    DELTIM->ARR     = us;
    DELTIM->EGR     = TIM_EGR_UG;                                   //Генерируем событие для перегрузки из в рабочие регистры
    __DSB();														//Data Synchronization Barrier
    DELTIM->SR      = ~TIM_SR_UIF;
    DELTIM->CR1     = TIM_CR1_OPM | TIM_CR1_CEN;                   	//Counter enable
    while((DELTIM->SR & TIM_SR_UIF) == 0);
}

/*!****************************************************************************
* @brief    Задержка ms
*/
void delay_ms(uint16_t ms){
    DELTIM->PSC     = DELTIM_FREQ / 1000 - 1;                  		//Предделитель на 1ms
    DELTIM->ARR     = ms;
    DELTIM->EGR     = TIM_EGR_UG;                                   //Генерируем событие для перегрузки из в рабочие регистры
    __DSB();														//Data Synchronization Barrier
    DELTIM->SR      = ~TIM_SR_UIF;
    DELTIM->CR1     = TIM_CR1_OPM | TIM_CR1_CEN;                   	//Counter enable
    while((DELTIM->SR & TIM_SR_UIF) == 0);
}

#endif  //#if(DELTIM_USE_STATIC_INLINE == 0)

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
