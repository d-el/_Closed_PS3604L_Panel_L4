/*!****************************************************************************
 * @file		base.h
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		01.01.2015
 * @copyright	GNU Lesser General Public License v3
 * @brief		Global settings
 */

/**
 * TIM15_CH2 (PB15)              -> PWM Beep
 * TIM6                          -> Time for Beep
 *
 * DMA1_Channel3 [TX] -> Канал вывода видеоинформации
 *
 * DMA1_Channel4 [TX] -> Передача по I2C2
 * DMA1_Channel5 [RX] -> Прием по I2C2
 *
 * DMA1_Channel7 [TX] -> Передача по UART2
 * DMA1_Channel6 [RX] -> Прием по UART2
 *
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
 * Macro functions
 */
#define LED_ON()            gppin_set(GP_LED)
#define LED_OFF()           gppin_reset(GP_LED)
#define LED_TOGGLE()        gppin_togle(GP_LED)

/*!****************************************************************************
 * Prototypes for the functions
 */

#endif //board_H
/*************** LGPL ************** END OF FILE *********** D_EL ************/
