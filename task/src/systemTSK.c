/*!****************************************************************************
 * @file		systemTSK.c
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		14.09.2015
 * @copyright	GNU Lesser General Public License v3
 * @brief		System control task
 */

/*!****************************************************************************
 * Include
 */
#include "systemTSK.h"

/*!****************************************************************************
 * Memory
 */
frontPanel_type fp; ///< Data structure front panel

/*!****************************************************************************
 * Local prototypes for the functions
 */
void loadParameters(void);

/*!****************************************************************************
 * @brief
 */
void systemTSK(void *pPrm){
	portTickType 	xLastWakeTime = xTaskGetTickCount();
	selWindow_type 	selWindowPrev = noneWindow;
	BaseType_t 		Result = pdTRUE;

	loadParameters();

	while(1){
		if(selWindowPrev != fp.currentSelWindow){
			if(windowTskHandle != NULL){
				vTaskDelete(windowTskHandle);	//Удаляем текущее окно
			}

			switch(fp.currentSelWindow){
				case startupWindow:
					Result = xTaskCreate(startupTSK, "startupTSK", STARTUP_TSK_SZ_STACK, NULL, STARTUP_TSK_PRIO, &windowTskHandle);
					break;
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
					while(1)
						;	//Fail windowTskHandle
			}

			if(Result != pdTRUE){
				while(1)
					;
			}

			selWindowPrev = fp.currentSelWindow;
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
		if((ledCount == 2) && (uartTsk.state == uartConnect)){
			LED_ON();
		}
		if(ledCount == 3){
			LED_OFF();
		}

		/*************************************/
		vTaskDelayUntil(&xLastWakeTime, msToSt(SYSTEM_TSK_PERIOD));
	}
}

/*!****************************************************************************
 * @brief	Load parameters from memory
 */
void loadParameters(void){
	nvMem_state_type nvMemState;

	prm_loadDefault();

	nvMem_init(&userConfRegion);
	nvMem_init(&userReservConfRegion);
	nvMem_init(&systemSettingRegion);

	nvMemState = nvMem_loadPrm(&systemSettingRegion);
	if(nvMemState != nvMem_ok){
		fp.state.sysSettingLoadDefault = 1;
	}
	nvMemState = nvMem_loadPrm(&userConfRegion);
	if(nvMemState != nvMem_ok){
		//Попробуем считать резервную копию
		nvMemState = nvMem_loadPrm(&userReservConfRegion);
		if(nvMemState != nvMem_ok){
			fp.state.userSettingLoadDefault = 1;
		}
	}else{
		nvMem_savePrm(&userReservConfRegion);
	}
}


/*!****************************************************************************
 * @brief	Select window task & wait selectable
 * 			This function need call from current GUI window
 * @param 	window	window task identifier
 */
void selWindow(selWindow_type window){
	fp.currentSelWindow = window;
	while(windowTskHandle != NULL){
		vTaskDelay(1000);
	}
}

/*************** LGPL ************** END OF FILE *********** D_EL ************/
