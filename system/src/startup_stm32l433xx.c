/*!****************************************************************************
 * @file		startup_stm32l433xx.c
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		02.05.2017
 * @copyright	GNU Lesser General Public License v3
 * @brief		Interrupt vector table, init .bss, init .data
 */

/*!****************************************************************************
* Include
*/
#include "stdint.h"

extern void __libc_init_array(void);	///Initialization routines
extern void __libc_fini_array(void);	///Cleanup routines
extern void SystemInit(void);			///System initialization function
extern int main(void);					///Entry point for the application

extern uint32_t _estack;				///Highest address of the user mode stack
extern uint32_t _sdata;  				///RAM data start
extern uint32_t _edata;  				///RAM data end
extern uint32_t _sidata; 				///ROM data start
extern uint32_t _sbss;   				///RAM bss start
extern uint32_t _ebss;  				///RAM bss end

typedef void(*intVector_type)(void);	///Interrupt service routine type

/*!****************************************************************************
 * @brief  Initialization .bss section
 */
void __initializeBss(uint32_t *bssStart, uint32_t *bssEnd){
	uint32_t* pData = bssStart;

	///Verify align by 4
	if(((uint32_t) bssStart % 4) || ((uint32_t) bssEnd % 4)){
		while(1)
			;
	}

	while(pData < bssEnd){
		*pData++ = 0;
	}
}

/*!****************************************************************************
 * @brief  Initialization .data section
 */
void __initializeData(uint32_t *dataStart, uint32_t *dataEnd, uint32_t *src){
	uint32_t *pData = dataStart;

	///Verify align by 4
	if(((uint32_t) dataStart % 4) || ((uint32_t) dataEnd % 4)||((uint32_t) src % 4)){
		while(1)
			;
	}

	while(pData < dataEnd){
		*pData++ = *src++;
	}
}

/*!****************************************************************************
 * @brief	Program entry point
 */
void Reset_Handler(void){
	__initializeData(&_sdata, &_edata, &_sidata);
	__initializeBss(&_sbss, &_ebss);
	__libc_init_array();
	SystemInit();
	main();
	__libc_fini_array();
	while(1);
}

///Cortex-M4 Processor Exceptions Numbers
__attribute__((weak)) void NMI_Handler				(void){while(1);}	/*!< 2 Cortex-M4 Non Maskable Interrupt								*/
__attribute__((weak)) void HardFault_Handler		(void){while(1);}	/*!< 3 Cortex-M4 Hard Fault Interrupt								*/
__attribute__((weak)) void MemManage_Handler		(void){while(1);}	/*!< 4 Cortex-M4 Memory Management Interrupt						*/
__attribute__((weak)) void BusFault_Handler			(void){while(1);}	/*!< 5 Cortex-M4 Bus Fault Interrupt								*/
__attribute__((weak)) void UsageFault_Handler		(void){while(1);}	/*!< 6 Cortex-M4 Usage Fault Interrupt								*/
__attribute__((weak)) void SVC_Handler				(void){while(1);}	/*!< 11 Cortex-M4 SV Call Interrupt									*/
__attribute__((weak)) void DebugMon_Handler			(void){while(1);}	/*!< 12 Cortex-M4 Debug Monitor Interrupt							*/
__attribute__((weak)) void PendSV_Handler			(void){while(1);}	/*!< 14 Cortex-M4 Pend SV Interrupt									*/
__attribute__((weak)) void SysTick_Handler			(void){while(1);}	/*!< 15 Cortex-M4 System Tick Interrupt								*/
///STM32 specific Interrupt
__attribute__((weak)) void WWDG_IRQHandler			(void){while(1);}	/*!< Window WatchDog Interrupt										*/
__attribute__((weak)) void PVD_PVM_IRQHandler		(void){while(1);}	/*!< PVD/PVM1/PVM2/PVM3/PVM4 through EXTI Line detection Interrupts	*/
__attribute__((weak)) void TAMP_STAMP_IRQHandler	(void){while(1);}	/*!< Tamper and TimeStamp interrupts through the EXTI line			*/
__attribute__((weak)) void RTC_WKUP_IRQHandler		(void){while(1);}	/*!< RTC Wakeup interrupt through the EXTI line						*/
__attribute__((weak)) void FLASH_IRQHandler			(void){while(1);}	/*!< FLASH global Interrupt											*/
__attribute__((weak)) void RCC_IRQHandler			(void){while(1);}	/*!< RCC global Interrupt											*/
__attribute__((weak)) void EXTI0_IRQHandler			(void){while(1);}	/*!< EXTI Line0 Interrupt											*/
__attribute__((weak)) void EXTI1_IRQHandler			(void){while(1);}	/*!< EXTI Line1 Interrupt											*/
__attribute__((weak)) void EXTI2_IRQHandler			(void){while(1);}	/*!< EXTI Line2 Interrupt											*/
__attribute__((weak)) void EXTI3_IRQHandler			(void){while(1);}	/*!< EXTI Line3 Interrupt											*/
__attribute__((weak)) void EXTI4_IRQHandler			(void){while(1);}	/*!< EXTI Line4 Interrupt											*/
__attribute__((weak)) void DMA1_Channel1_IRQHandler	(void){while(1);}	/*!< DMA1 Channel 1 global Interrupt								*/
__attribute__((weak)) void DMA1_Channel2_IRQHandler	(void){while(1);}	/*!< DMA1 Channel 2 global Interrupt								*/
__attribute__((weak)) void DMA1_Channel3_IRQHandler	(void){while(1);}	/*!< DMA1 Channel 3 global Interrupt								*/
__attribute__((weak)) void DMA1_Channel4_IRQHandler	(void){while(1);}	/*!< DMA1 Channel 4 global Interrupt								*/
__attribute__((weak)) void DMA1_Channel5_IRQHandler	(void){while(1);}	/*!< DMA1 Channel 5 global Interrupt								*/
__attribute__((weak)) void DMA1_Channel6_IRQHandler	(void){while(1);}	/*!< DMA1 Channel 6 global Interrupt								*/
__attribute__((weak)) void DMA1_Channel7_IRQHandler	(void){while(1);}	/*!< DMA1 Channel 7 global Interrupt								*/
__attribute__((weak)) void ADC1_IRQHandler			(void){while(1);}	/*!< ADC1 global Interrupt											*/
__attribute__((weak)) void CAN1_TX_IRQHandler		(void){while(1);}	/*!< CAN1 TX Interrupt												*/
__attribute__((weak)) void CAN1_RX0_IRQHandler		(void){while(1);}	/*!< CAN1 RX0 Interrupt												*/
__attribute__((weak)) void CAN1_RX1_IRQHandler		(void){while(1);}	/*!< CAN1 RX1 Interrupt												*/
__attribute__((weak)) void CAN1_SCE_IRQHandler		(void){while(1);}	/*!< CAN1 SCE Interrupt												*/
__attribute__((weak)) void EXTI9_5_IRQHandler		(void){while(1);}	/*!< External Line[9:5] Interrupts									*/
__attribute__((weak)) void TIM1_BRK_TIM15_IRQHandler(void){while(1);}	/*!< TIM1 Break interrupt and TIM15 global interrupt				*/
__attribute__((weak)) void TIM1_UP_TIM16_IRQHandler	(void){while(1);}	/*!< TIM1 Update Interrupt and TIM16 global interrupt				*/
__attribute__((weak)) void TIM1_TRG_COM_IRQHandler	(void){while(1);}	/*!< TIM1 Trigger and Commutation Interrupt							*/
__attribute__((weak)) void TIM1_CC_IRQHandler		(void){while(1);}	/*!< TIM1 Capture Compare Interrupt									*/
__attribute__((weak)) void TIM2_IRQHandler			(void){while(1);}	/*!< TIM2 global Interrupt											*/
__attribute__((weak)) void I2C1_EV_IRQHandler		(void){while(1);}	/*!< I2C1 Event Interrupt											*/
__attribute__((weak)) void I2C1_ER_IRQHandler		(void){while(1);}	/*!< I2C1 Error Interrupt											*/
__attribute__((weak)) void I2C2_EV_IRQHandler		(void){while(1);}	/*!< I2C2 Event Interrupt											*/
__attribute__((weak)) void I2C2_ER_IRQHandler		(void){while(1);}	/*!< I2C2 Error Interrupt											*/
__attribute__((weak)) void SPI1_IRQHandler			(void){while(1);}	/*!< SPI1 global Interrupt											*/
__attribute__((weak)) void SPI2_IRQHandler			(void){while(1);}	/*!< SPI2 global Interrupt											*/
__attribute__((weak)) void USART1_IRQHandler		(void){while(1);}	/*!< USART1 global Interrupt										*/
__attribute__((weak)) void USART2_IRQHandler		(void){while(1);}	/*!< USART2 global Interrupt										*/
__attribute__((weak)) void USART3_IRQHandler		(void){while(1);}	/*!< USART3 global Interrupt										*/
__attribute__((weak)) void EXTI15_10_IRQHandler		(void){while(1);}	/*!< External Line[15:10] Interrupts								*/
__attribute__((weak)) void RTC_Alarm_IRQHandler		(void){while(1);}	/*!< RTC Alarm (A and B) through EXTI Line Interrupt				*/
__attribute__((weak)) void SDMMC1_IRQHandler		(void){while(1);}	/*!< SDMMC1 global Interrupt										*/
__attribute__((weak)) void SPI3_IRQHandler			(void){while(1);}	/*!< SPI3 global Interrupt											*/
__attribute__((weak)) void TIM6_DAC_IRQHandler		(void){while(1);}	/*!< TIM6 global and DAC1&2 underrun error	interrupts				*/
__attribute__((weak)) void TIM7_IRQHandler			(void){while(1);}	/*!< TIM7 global interrupt											*/
__attribute__((weak)) void DMA2_Channel1_IRQHandler	(void){while(1);}	/*!< DMA2 Channel 1 global Interrupt								*/
__attribute__((weak)) void DMA2_Channel2_IRQHandler	(void){while(1);}	/*!< DMA2 Channel 2 global Interrupt								*/
__attribute__((weak)) void DMA2_Channel3_IRQHandler	(void){while(1);}	/*!< DMA2 Channel 3 global Interrupt								*/
__attribute__((weak)) void DMA2_Channel4_IRQHandler	(void){while(1);}	/*!< DMA2 Channel 4 global Interrupt								*/
__attribute__((weak)) void DMA2_Channel5_IRQHandler	(void){while(1);}	/*!< DMA2 Channel 5 global Interrupt								*/
__attribute__((weak)) void COMP_IRQHandler			(void){while(1);}	/*!< COMP1 and COMP2 Interrupts										*/
__attribute__((weak)) void LPTIM1_IRQHandler		(void){while(1);}	/*!< LP TIM1 interrupt												*/
__attribute__((weak)) void LPTIM2_IRQHandler		(void){while(1);}	/*!< LP TIM2 interrupt												*/
__attribute__((weak)) void USB_IRQHandler			(void){while(1);}	/*!< USB event Interrupt											*/
__attribute__((weak)) void DMA2_Channel6_IRQHandler	(void){while(1);}	/*!< DMA2 Channel 6 global interrupt								*/
__attribute__((weak)) void DMA2_Channel7_IRQHandler	(void){while(1);}	/*!< DMA2 Channel 7 global interrupt								*/
__attribute__((weak)) void LPUART1_IRQHandler		(void){while(1);}	/*!< LP UART1 interrupt												*/
__attribute__((weak)) void QUADSPI_IRQHandler		(void){while(1);}	/*!< Quad SPI global interrupt										*/
__attribute__((weak)) void I2C3_EV_IRQHandler		(void){while(1);}	/*!< I2C3 event interrupt											*/
__attribute__((weak)) void I2C3_ER_IRQHandler		(void){while(1);}	/*!< I2C3 error interrupt											*/
__attribute__((weak)) void SAI1_IRQHandler			(void){while(1);}	/*!< Serial Audio Interface 1 global interrupt						*/
__attribute__((weak)) void SWPMI1_IRQHandler		(void){while(1);}	/*!< Serial Wire Interface 1 global interrupt						*/
__attribute__((weak)) void TSC_IRQHandler			(void){while(1);}	/*!< Touch Sense Controller global interrupt						*/
__attribute__((weak)) void LCD_IRQHandler			(void){while(1);}	/*!< LCD global interrupt											*/
__attribute__((weak)) void RNG_IRQHandler			(void){while(1);}	/*!< RNG global interrupt											*/
__attribute__((weak)) void FPU_IRQHandler			(void){while(1);}	/*!< FPU global interrupt											*/
__attribute__((weak)) void CRS_IRQHandler			(void){while(1);}	/*!< CRS global interrupt											*/

/*!****************************************************************************
* Interrupt vector table
*/
intVector_type intVector[] __attribute__ ((section (".isr_vector"))) = {
	///Stack
	(intVector_type)&_estack,
	///Cortex-M4 Processor Exceptions
	Reset_Handler,
	NMI_Handler,
	HardFault_Handler,
	MemManage_Handler,
	BusFault_Handler,
	UsageFault_Handler,
	0,
	0,
	0,
	0,
	SVC_Handler,
	DebugMon_Handler,
	0,
	PendSV_Handler,
	SysTick_Handler,
	///STM32 specific Interrupt
	WWDG_IRQHandler,
	PVD_PVM_IRQHandler,
	TAMP_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	ADC1_IRQHandler,
	CAN1_TX_IRQHandler,
	CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM15_IRQHandler,
	TIM1_UP_TIM16_IRQHandler,
	TIM1_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	0,
	0,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTC_Alarm_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	SDMMC1_IRQHandler,
	0,
	SPI3_IRQHandler,
	0,
	0,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Channel1_IRQHandler,
	DMA2_Channel2_IRQHandler,
	DMA2_Channel3_IRQHandler,
	DMA2_Channel4_IRQHandler,
	DMA2_Channel5_IRQHandler,
	0,
	0,
	0,
	COMP_IRQHandler,
	LPTIM1_IRQHandler,
	LPTIM2_IRQHandler,
	USB_IRQHandler,
	DMA2_Channel6_IRQHandler,
	DMA2_Channel7_IRQHandler,
	LPUART1_IRQHandler,
	QUADSPI_IRQHandler,
	I2C3_EV_IRQHandler,
	I2C3_ER_IRQHandler,
	SAI1_IRQHandler,
	0,
	SWPMI1_IRQHandler,
	TSC_IRQHandler,
	LCD_IRQHandler,
	0,
	RNG_IRQHandler,
	FPU_IRQHandler,
	CRS_IRQHandler,
};

/*************** LGPL ************** END OF FILE *********** D_EL ************/
