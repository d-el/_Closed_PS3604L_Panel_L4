/******************************************************************************
* @file    systemTSK.h
* @author  Storozhenko Roman - D_EL
* @version V1.0
* @date    14-09-2015
* @brief
* @copyright GNU Public License
*/
#ifndef systemTSK_H
#define systemTSK_H

/*!****************************************************************************
* Include
*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "OSinit.h"
#include "board.h"
#include "pstypes.h"
#include "cube3d.h"

/*!****************************************************************************
* User define
*/
#define SYSTEM_TSK_PERIOD   150      //[ms]

#define I_SHORT_CIRCUIT     40000   //[X_XXXX A]
#define MAX_VAL_U           36000   //[X_XXX V]
#define MAX_VAL_I           40000   //[X_XXXX A]
#define U_BIG_STEP          1000    //[X_XXX V]
#define I_BIG_STEP          5000    //[X_XXXX A]

/*!****************************************************************************
* User typedef
*/
typedef enum{
	noneWindow,
	settingWindow,
	baseWindow,
	chargerWindow,
	cube3dWindow
}selWindow_type;

typedef struct{
    uint16_t    lcdLight;	//[X_X %]
}frontPanelSetting_type;

typedef struct{
    transfer_type           tf;     //Общие данные
    frontPanelSetting_type  fpSet;  //Данные настройки передней панели
}frontPanel_type;

/*!****************************************************************************
* User enum
*/

/*!****************************************************************************
* Extern variables
*/
extern frontPanel_type     fp;

/*!****************************************************************************
* Macro functions
*/

/*!****************************************************************************
* Prototypes for the functions
*/
void selWindow(selWindow_type window);
void systemTSK(void *pPrm);

#endif //systemTSK_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
