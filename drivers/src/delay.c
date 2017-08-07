/*!****************************************************************************
 * @file		delay.c
 * @author		d_el
 * @version		V1.0
 * @date		17-01-2015
 * @copyright	GNU Lesser General Public License v3
 * @brief		Driver for system delay
 */

/*!****************************************************************************
 * Include
 */
#include "delay.h"

#if(DELTIM_USE_STATIC_INLINE == 0)

/*!****************************************************************************
 * @brief
 */
void delay_us(uint16_t us){
	DELTIM->PSC = DELTIM_FREQ / 1000000 - 1;                  	//Предделитель на 1us
	DELTIM->ARR = us;
	DELTIM->EGR = TIM_EGR_UG;//Генерируем событие для перегрузки из в рабочие регистры
	__DSB();//Data Synchronization Barrier
	DELTIM->SR = ~TIM_SR_UIF;
	DELTIM->CR1 = TIM_CR1_OPM | TIM_CR1_CEN;//Counter enable
	while((DELTIM->SR & TIM_SR_UIF) == 0);
}

/*!****************************************************************************
 * @brief
 */
void delay_ms(uint16_t ms){
	DELTIM->PSC = DELTIM_FREQ / 1000 - 1;                  		//Предделитель на 1ms
	DELTIM->ARR = ms;
	DELTIM->EGR = TIM_EGR_UG;//Генерируем событие для перегрузки из в рабочие регистры
	__DSB();//Data Synchronization Barrier
	DELTIM->SR = ~TIM_SR_UIF;
	DELTIM->CR1 = TIM_CR1_OPM | TIM_CR1_CEN;//Counter enable
	while((DELTIM->SR & TIM_SR_UIF) == 0);
}

#endif  //#if(DELTIM_USE_STATIC_INLINE == 0)

/*************** LGPL ************** END OF FILE *********** D_EL ************/
