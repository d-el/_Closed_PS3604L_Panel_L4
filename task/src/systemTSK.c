/*!****************************************************************************
* @file    systemTSK.c
* @author  Storozhenko Roman - D_EL
* @version V1.0
* @date    14-09-2015
* @brief
* @copyright GNU Public License
*/

#include "systemTSK.h"

/*!****************************************************************************
* Memory
*/
frontPanel_type     fp; //Данные передней панели
selWindow_type		currentSelWindow;

/*!****************************************************************************
* @brief
*/
void selWindow(selWindow_type window){
	currentSelWindow = window;
	while(windowTskHandle != NULL){
		vTaskDelay(1000);
	}
}

/*!****************************************************************************
* @brief
*/
void systemTSK(void *pPrm){
    portTickType        xLastWakeTime = xTaskGetTickCount();                          //Инициализируем xLastWakeTime текущим временем
    selWindow_type      selWindowPrev = noneWindow;
    BaseType_t 			Result = pdTRUE;
    
    while(1){
    	if(selWindowPrev != currentSelWindow){
    		if(windowTskHandle != NULL){
    			vTaskDelete(windowTskHandle);	//Удаляем текущее окно
    		}

    		switch(currentSelWindow){
    			case settingWindow:
    				Result = xTaskCreate(settingTSK, "settingTSK", SETT_TSK_SZ_STACK, NULL, SETT_TSK_PRIO, &windowTskHandle);
    				break;
    			case baseWindow:
    				Result = xTaskCreate(baseTSK, "baseTSK", BASE_TSK_SZ_STACK, NULL, BASE_TSK_PRIO, &windowTskHandle);
    				break;
    			case chargerWindow:
    				Result = xTaskCreate(chargeTSK, "chargeTSK", CHARG_TSK_SZ_STACK, NULL, CHARG_TSK_PRIO, &windowTskHandle);
    				break;
    			case cube3dWindow:
					Result = xTaskCreate(cube3dTSK, "cube3dTSK", CUBE_TSK_SZ_STACK, NULL, CUBE_TSK_PRIO, &windowTskHandle);
					break;
				default:
    				while(1);	//Fail windowTskHandle
    		}

    		if(Result != pdTRUE){
    			while(1);
    		}

    		selWindowPrev = currentSelWindow;
    	}
        
		/**************************************
		* Вызов периодических функций
		*/
		static uint8_t ledCount = 0;
		if(ledCount++ == 10){
			LED_ON();
			ledCount = 0;
		}
		if(ledCount == 1){
			LED_OFF();
		}
		if((ledCount == 2)&&(uartTsk.state == uartConnect)){
			LED_ON();
		}
		if(ledCount == 3){
			LED_OFF();
		}

        /*************************************/
        vTaskDelayUntil(&xLastWakeTime, msToSt(SYSTEM_TSK_PERIOD));
    }
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
