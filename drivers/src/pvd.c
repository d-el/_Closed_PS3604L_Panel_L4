/*!****************************************************************************
 * @file		pvd.h
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		01.08.2016
 * @copyright	GNU Lesser General Public License v3
 * @brief		Driver power voltage detector
 */

/*!****************************************************************************
* Include
*/
#include "pvd.h"

/*!****************************************************************************
* MEMORY
*/
static suplyFaultCallBack_type suplyFaultCallBack;

/*!****************************************************************************
* @brief	Инициализация PVD с прерыванием
*/
void pvd_init(void){
	uint32_t apb1enr1 = RCC->APB1ENR1;

	RCC->APB1ENR1 	|= RCC_APB1ENR1_PWREN;				//Power interface clock enable
	PWR->CR2		&= ~PWR_CR2_PVDE;					//Power voltage detector disable
	PWR->CR2		&= ~PWR_CR2_PLS;
    PWR->CR2		|= PWR_CR2_PLS_LEV6;				//Power voltage detector level selection VPVD6 around 2.9 V
    PWR->CR2		|= PWR_CR2_PVDE;					//Power voltage detector enable
    RCC->APB1ENR1 	= apb1enr1;							//Restore value

    EXTI->IMR1   	|= EXTI_IMR1_IM16;					//Interrupt request from Line 16 is not masked
    EXTI->EMR1   	|= EXTI_EMR1_EM16;					//Event request from Line 16 is not masked
    EXTI->RTSR1  	|= EXTI_RTSR1_RT16;					//Rising trigger event configuration bit of line 16
    EXTI->PR1    	|= EXTI_PR1_PIF16;     				//Pending

    NVIC_SetPriority(PVD_PVM_IRQn, PVD_IRQ_Priority);
    NVIC_EnableIRQ(PVD_PVM_IRQn);						//PVD through EXTI Line detection Interrupt
}

/*!****************************************************************************
* @brief	Инициализация PVD с прерыванием
*/
void pvd_disable(void){
	uint32_t apb1enr1 = RCC->APB1ENR1;

	RCC->APB1ENR1 	&= ~RCC_APB1ENR1_PWREN;				//Power interface clock enable
	PWR->CR2		&= ~PWR_CR2_PVDE;					//Power voltage detector disable
	RCC->APB1ENR1 	= apb1enr1;							//Restore value

    EXTI->IMR1   	&= ~EXTI_IMR1_IM16;					//Interrupt request from Line 16 is not masked
    EXTI->EMR1   	&= ~EXTI_EMR1_EM16;					//Event request from Line 16 is not masked
    EXTI->RTSR1  	&= ~EXTI_RTSR1_RT16;				//Rising trigger event configuration bit of line 16

    NVIC_DisableIRQ(PVD_PVM_IRQn);
}

/*!****************************************************************************
 *
 */
void pvd_setSuplyFaultCallBack(suplyFaultCallBack_type callBack){
	suplyFaultCallBack = callBack;
}

/*!****************************************************************************
* @brief	Обработчик прерывания PVD
*/
void PVD_PVM_IRQHandler(void){
	suplyFaultCallBack();
}

/*************** LGPL ************** END OF FILE *********** D_EL ************/
