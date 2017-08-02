/*!****************************************************************************
 * @file		OSinit.c
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @copyright	GNU Lesser General Public License v3
 * @brief		Create semaphore, mutex, nitialization operational system
 */

/*!****************************************************************************
 * Include
 */
#include "OSinit.h"

/*!****************************************************************************
 * TaskHandle
 */
TaskHandle_t windowTskHandle;

/******************************************************************************
 * Semaphore
 */
SemaphoreHandle_t uart2RxSem;

/*!****************************************************************************
 * @brief Init operating system
 */
void OSinit(void){
	BaseType_t Result = pdTRUE;

	//Create semaphore
	vSemaphoreCreateBinary(uart2RxSem);
	xSemaphoreTake(uart2RxSem, portMAX_DELAY);

	Result &= xTaskCreate(systemTSK, "systemTSK", SYSTEM_TSK_SZ_STACK, NULL, SYSTEM_TSK_PRIO, NULL);
	Result &= xTaskCreate(uartTSK, "uartTSK", UART_TSK_SZ_STACK, NULL, UART_TSK_PRIO, NULL);

	if(Result == pdTRUE){
	}else{
		while(1){
			LED_ON();
			delay_ms(100);
			LED_OFF();
			delay_ms(900);
		}
	}

	selWindow(startupWindow);

	vTaskStartScheduler();
}

/*************** LGPL ************** END OF FILE *********** D_EL ************/
