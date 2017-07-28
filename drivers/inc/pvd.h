/*!****************************************************************************
* @file    pvd.h
* @author  d_el
* @version V1.0
* @date    01.08.2016, Storozhenko Roman
* @brief   --
* @copyright GNU Public License
*/
#ifndef pvd_H
#define pvd_H

/*!****************************************************************************
* Include
*/
#include "stm32l4xx.h"
#include "ledpwm.h"
#include "spfd54124b.h"
#include "storage.h"
#include "board.h"
#include "beep.h"
#include "stdlib.h"

/*!****************************************************************************
* User define
*/

/*!****************************************************************************
* User enum
*/

/*!****************************************************************************
* User typedef
*/

/*!****************************************************************************
* Extern viriables
*/

/*!****************************************************************************
* Macro functions
*/

/*!****************************************************************************
* Prototypes for the functions
*/
void pvd_init(void);
void pvd_disable(void);

#endif //pvd_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
