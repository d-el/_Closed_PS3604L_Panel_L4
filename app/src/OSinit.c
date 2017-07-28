/*!****************************************************************************
* @file			OSinit.c
* @author		D_EL - Storozhenko Roman
* @version      V1.0
*/

/*!****************************************************************************
* Include
*/
#include "OSinit.h"

/*!****************************************************************************
* TaskHandle
*/
xTaskHandle         windowTskHandle;

/******************************************************************************
* Semaphore
*/
xSemaphoreHandle    uart2RxSem;

/*!****************************************************************************
* @brief Init operating system
*/
void OSinit(void){
    BaseType_t Result = pdTRUE;

    //Создаём семафор
    vSemaphoreCreateBinary(uart2RxSem);
    xSemaphoreTake(uart2RxSem, portMAX_DELAY);

    //selWindow(settingWindow);

    //Создаём задачи перед запуском ядра
    for(uint32_t cnt = 0; (cnt <= KEY_SAMPLES)&&(keyProc() == 0); cnt++){
    }



	//Result &= xTaskCreate(cube3dTSK,      "cube3dTSK",      CUBE_TSK_SZ_STACK,      NULL, CUBE_TSK_PRIO,    NULL);

    if(keyState(kOnOff)){
    	selWindow(settingWindow);
    }else{
    	selWindow(baseWindow);
    }
    Result &= xTaskCreate(systemTSK,    "systemTSK",    SYSTEM_TSK_SZ_STACK,    NULL, SYSTEM_TSK_PRIO,  NULL);
    Result &= xTaskCreate(uartTSK,      "uartTSK",      UART_TSK_SZ_STACK,      NULL, UART_TSK_PRIO,    NULL);

    if(Result == pdTRUE){
    }
    else{
		while(1){
			LED_ON();
			delay_ms(100);
			LED_OFF();
			delay_ms(900);
		}
    }

    vTaskStartScheduler();
}

/****************** (C) COPYRIGHT **************** END OF FILE ***************/
