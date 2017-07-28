/*!****************************************************************************
* @file    beep.h
* @author  d_el
* @version V1.0
* @date    19.12.2014, by d_el
* @brief   --
* @copyright GNU Public License
*/
#ifndef beep_H
#define beep_H

/*!****************************************************************************
* Include
*/
#include "stm32l4xx.h"
#include "gpio.h"
#include "board.h"

/*!****************************************************************************
* User define
*/
#define F_BEEP              4000                                //Частота пищалки (1 - 32767)
#define BEEP_IRQ_Priority   15
#define BEEP_TIM            TIM15
#define TIME_B_TIM          TIM6

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
#define	beepON()            BEEP_TIM->CR1 |= TIM_CR1_CEN        //Включить пищалку
#define	beepOFF()           BEEP_TIM->CR1 &= ~TIM_CR1_CEN       //Выключить пищалку
#define	beepSetFreq(freq)   BEEP_TIM->ARR = SYSTEM_FREQUENCY / (freq) / 2;

/*!****************************************************************************
* Prototypes for the functions
*/
void BeepTime(uint16_t time, uint16_t ferq);
void beep_init(void);
void Dht (void *pvParameters);

#endif //beep_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
