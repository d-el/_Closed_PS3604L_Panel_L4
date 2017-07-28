/*!****************************************************************************
* @file    drivers.c
* @author  Storozhenko Roman - D_EL
* @version V1.0
* @date    05-07-2013
* @copyright GNU Public License
*/

#ifndef DRIVERS_H
#define DRIVERS_H

/*!****************************************************************************
* Include
*/
#include "IQmathLib.h"
#include "pvd.h"
#include "systemTSK.h"
#include "baseTSK.h"
#include "storage.h"
#include "beep.h"
#include "spfd54124b.h"
#include "uart.h"
#include "i2c.h"
#include "enco.h"
#include "clock.h"
#include "ledpwm.h"
#include "rtc.h"
#include "delay.h"


/*!****************************************************************************
* User define
*/

/*!****************************************************************************
* User typedef
*/

/*!****************************************************************************
* User enum
*/
enum{
    BASE_DAC
};

/*!****************************************************************************
* Extern viriables
*/
//extern syssetting_type      sysset;
extern uint16_t             base[];

/*!****************************************************************************
* Macro functions
*/

/*!****************************************************************************
* Prototypes for the functions
*/
void Init_Hard(void);
void shutdown(void);
void userInitDef(void);
void systemInitDef(void);

#endif //DRIVERS_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
