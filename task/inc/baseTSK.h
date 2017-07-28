/*!****************************************************************************
* @file			base.h
* @author		D_EL - Storozhenko Roman
* @version      V1.0
* @date
* @brief
* @copyright GNU Public License
*/
#ifndef BASE_H
#define BASE_H

/*!****************************************************************************
* Include
*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "OSinit.h"
#include "ui.h"
#include "pstypes.h"
#include "graphics.h"
#include "rtc.h"
#include "beep.h"
#include "key.h"
#include "enco.h"

/******************************************************************************
* User define
*/
#define NPRESET             3
#define IDLE_TIME           (180000)       		//Время до заставки [ms]
#define BASE_TSK_PERIOD     10                  //[ms]

/******************************************************************************
* User enum
*/

/******************************************************************************
* User typedef
*/
typedef enum{
    VAR_VOLT,
    VAR_CURR,
    VAR_MODE,
}baseVar_type;

typedef enum{
    baseImax,
    baseILimitation,
    baseUnprotected,
}baseMode_type;

typedef struct{
    uint16_t        u;
    uint16_t        i;
    baseMode_type   mode;
}baseSet_type;

typedef struct{
    baseSet_type	set[NPRESET];
    uint32_t    	startCounter;
    uint8_t     	curPreSet;
}base_type;

/******************************************************************************
* Extern variables
*/
extern base_type bs;

/******************************************************************************
* Macro functions
*/

/******************************************************************************
* Prototypes for the functions
*/
void baseTSK(void *pPrm);
void printStatusBar(void);

#endif //BASE_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
