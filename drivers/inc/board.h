/*!****************************************************************************
 * @file    board.h
 * @author  d_el
 * @version V1.0
 * @date    15.07.2016, Storozhenko Roman
 * @brief   --
 * @copyright GNU Public License
 *
 * TIM15_CH2 (PB15)              -> PWM Beep
 * TIM6                          -> Time for Beep
 *
 *
 ******************************************************
 * TIM1_CH1 (PA8)                -> PPM
 * TIM1_CH2 (PA9)                -> SYNC
 * TIM1_CH3 (PA10)               -> LED
 * TIM3 						    -> ADC TRIGGER
 * TIM4_CH3 (PB8)			    -> FAN_PWM
 *
 * ADC1_IN1 (PA1)                -> UDC_MEAS
 * ADC1_IN2 (PA2)                -> V_MEAS
 * ADC1_IN3 (PA3)                -> I_MEAS
 *
 * UART1 TX - (PB6)              -> 1Wire
 * UART3 TX - (PB10), RX - (PB11)-> UART CONNECT
 *
 * GPIO (PB15) 				    -> LED
 * GPIO (PB9) 					-> ON_OFF
 * GPIO (PC1)                    -> CC_CV
 * GPIO (PB6)                    -> 1Wire
 */
#ifndef board_H
#define board_H

/*!****************************************************************************
 * Include
 */
#include "gpio.h"

/*!****************************************************************************
 * User define
 */
#define SYSTEM_FREQ         80000000    //[Hz]
#define APB1_FREQ           80000000    //[Hz]
#define APB2_FREQ           80000000    //[Hz]

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
#define LED_ON()            gppin_set(GP_LED)
#define LED_OFF()           gppin_reset(GP_LED)
#define LED_TOGGLE()        gppin_togle(GP_LED)

/*!****************************************************************************
 * Prototypes for the functions
 */

#endif //board_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
