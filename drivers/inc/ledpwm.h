﻿/*!****************************************************************************
 * @file    ledpwm.h
 * @author  d_el
 * @version V1.0
 * @date    27.12.2015, by d_el
 * @brief   pwm for lcd led
 * @copyright GNU Public License
 */
#ifndef ledpwm_H
#define ledpwm_H

/*!****************************************************************************
 * Include
 */
#include "stm32l4xx.h"
#include "gpio.h"

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
#define setLcdBrightness(x)    (TIM16->CCR1 = (x)) //[XXX_X %]

/*!****************************************************************************
 * Prototypes for the functions
 */
void ledPwm_init(void);

#endif //ledpwm_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
