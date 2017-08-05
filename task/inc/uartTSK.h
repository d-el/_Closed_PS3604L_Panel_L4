﻿/**
 *******************************************************************************
 * @file    uartTSK.h
 * @author  D_EL
 * @version V1.0.0
 * @date    2015-08-10
 * @brief
 * @copyright GNU Public License
 */
#ifndef uartTSK_H
#define uartTSK_H

/*!****************************************************************************
 * Include
 */
#include "string.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "crc.h"
#include "pstypes.h"
#include "OSinit.h"
#include "systemTSK.h"
#include "uart.h"

/*!****************************************************************************
 * Define
 */
#define uartTskUse          (uart2)
#define PieceBufRx          (32)
#define queueCommandLen     (16)
#define maxWaitAnswer_ms    (100)
#define maxUartErr 			(10)
#define UART_TSK_PERIOD		(15)	///< [ms]

/*!****************************************************************************
 * Enumeration
 */

/******************************************************************************
 * Typedef
 */
typedef enum {
	uartConnect, uartNoConnect, uartUndef,
} uartTskState_type;

typedef struct {
	volatile uint32_t normAnswer;
	volatile uint32_t noAnswer;
	volatile uint32_t errorAnswer;
	volatile uint32_t queueLen;
	volatile uartTskState_type state;
} uartTsk_type;


/*!****************************************************************************
 * Exported variables
 */
extern uartTsk_type uartTsk;

/*!****************************************************************************
 * Macro functions
 */

/******************************************************************************
 * Prototypes for the functions
 */
void uartTSK(void *pPrm);
uint8_t waitForTf(void);
uint8_t sendCommand(request_type command);

#endif //uartTSK_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
