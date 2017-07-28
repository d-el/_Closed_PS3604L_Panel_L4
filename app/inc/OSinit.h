/*!****************************************************************************
* @file			OSinit.h
* @author		D_EL - Storozhenko Roman
* @version      V1.0
*/

/*!****************************************************************************
* Include
*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "systemTSK.h"
#include "baseTSK.h"
#include "chargeTSK.h"
#include "settingTSK.h"

/*!****************************************************************************
*-------NAME--------------------size [4byte Word] */
#define SYSTEM_TSK_SZ_STACK     96
#define SCOPE_TSK_SZ_STACK      64
#define BASE_TSK_SZ_STACK       256
#define CHARG_TSK_SZ_STACK      256
#define ADC_TSK_SZ_STACK        64
#define CUBE_TSK_SZ_STACK       256
#define BUBLE_TSK_SZ_STACK      64
#define UART_TSK_SZ_STACK       64
#define SETT_TSK_SZ_STACK       128+32
/*!****************************************************************************
*-------NAME--------------------size [4byte Word] */
#define SYSTEM_TSK_PRIO         4
#define SCOPE_TSK_PRIO          1
#define BASE_TSK_PRIO           1
#define CHARG_TSK_PRIO          1
#define ADC_TSK_PRIO            3
#define CUBE_TSK_PRIO           1
#define BUBLE_TSK_PRIO          1
#define UART_TSK_PRIO           2
#define SETT_TSK_PRIO           1

/*!****************************************************************************
* TaskHandle
*/
extern xTaskHandle         windowTskHandle;

/*!****************************************************************************
* Semaphore
*/
extern xSemaphoreHandle    uart2RxSem;

/*!****************************************************************************
* Prototypes for the functions in OSinit.c
*/
void OSinit(void);

/****************** (C) COPYRIGHT **************** END OF FILE ***************/
