﻿/*!****************************************************************************
 * @file		drivers.h
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		05-07-2013
 * @copyright	GNU Lesser General Public License v3
 * @brief		MCU peripheral initialization
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
#include "sysTimeMeas.h"

/*!****************************************************************************
 * Define
 */

/*!****************************************************************************
 * Enumeration
 */

/*!****************************************************************************
 * Exported variables
 */

/*!****************************************************************************
 * Macro functions
 */

/*!****************************************************************************
 * Function declaration
 */
void hardInit(void);

#endif //DRIVERS_H
/*************** LGPL ************** END OF FILE *********** D_EL ************/
