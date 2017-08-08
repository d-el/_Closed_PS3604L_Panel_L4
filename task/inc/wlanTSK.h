/*!****************************************************************************
 * @file		wlanTSK.h
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		07.08.2017
 * @copyright	GNU Lesser General Public License v3
 * @brief		WLAN program task
 */
#ifndef wlanTSK_H
#define wlanTSK_H

/*!****************************************************************************
 * Include
 */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "crc.h"
#include "pstypes.h"
#include "OSinit.h"
#include "systemTSK.h"
#include "uart.h"
#include "semihosting.h"

/*!****************************************************************************
 * Define
 */
#define wlanTskUse          		(uart1)
#define WLAN_TSK_QUEUE_COMMAND_LEN	(16)
#define WLAN_TSK_MAX_WAIT_ms    	(100)
#define WLAN_TSK_MAX_ERR 			(10)
#define WLAN_TSK_PERIOD				(1000)	///< [ms]

/*!****************************************************************************
 * Enumeration
 */

/*!****************************************************************************
 * Typedef
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
void wlanTSK(void *pPrm);

#endif //wlanTSK_H
/*************** LGPL ************** END OF FILE *********** D_EL ************/
