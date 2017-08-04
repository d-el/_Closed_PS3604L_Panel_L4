/*!****************************************************************************
 * @file    uartTSK.c
 * @author  D_EL
 * @version V1.0.0
 * @date    2015-08-10
 * @brief
 * @copyright GNU Public License
 */

/*!****************************************************************************
 * Include
 */
#include "uartTSK.h"

/*!****************************************************************************
 * MEMORY
 */
QueueHandle_t queueCommand;
uartTsk_type uartTsk = { .state = uartUndef };

/*!****************************************************************************
 * @brief
 */
uint8_t sendCommand(request_type command){
	BaseType_t res;

	res = xQueueSend(queueCommand, (void* )&command, 0);
	if(res == pdPASS){
		return 0;
	}else{
		return 1;
	}

}

/*!****************************************************************************
 * @brief
 */
uint8_t waitForTf(void){
	uint32_t l_normAnswer;
	uint32_t l_noAnswer;
	uint32_t l_errorAnswer;
	uint32_t cnt;

	cnt = 200;
	l_normAnswer = uartTsk.normAnswer;
	l_noAnswer = uartTsk.noAnswer;
	l_errorAnswer = uartTsk.errorAnswer;

	while(cnt != 0){
		if((l_normAnswer + 2) == (uartTsk.normAnswer)){
			return 0;
		}
		if(l_noAnswer != uartTsk.noAnswer){
			cnt--;
		}
		if(l_errorAnswer != uartTsk.errorAnswer){
			cnt--;
		}
	}
	return 1;
}

/*!****************************************************************************
 * @brief
 */
void uartTSK(void *pPrm){
	TickType_t	xLastWakeTime = xTaskGetTickCount();
	BaseType_t 	res;
	uint16_t 	crc;
	uint16_t 	errPrev = 0;
	uint16_t 	noAnswerPrev = 0;

	vTaskDelay(1000);

	// Create a queue
	queueCommand = xQueueCreate(queueCommandLen, sizeof(request_type));
	if(queueCommand == NULL)
		while(1)
			;

	while(1){
		uartTsk.queueLen = uxQueueMessagesWaiting(queueCommand);

		crc = GetCrc(&fp.tf.task, sizeof(task_type));
		memcpy(uart2->pTxBff, &fp.tf.task, sizeof(task_type));
		*(uint16_t*) (uart2->pTxBff + sizeof(task_type)) = crc;
		uart_write(uart2, uart2->pTxBff, sizeof(task_type) + sizeof(uint16_t));

		uart_read(uart2, uart2->pRxBff, sizeof(psState_type) + sizeof(meas_type) + sizeof(uint16_t));
		res = xSemaphoreTake(uart2RxSem, pdMS_TO_TICKS(maxWaitAnswer_ms));
		if(res == pdTRUE){
			//Приняли ответ
			crc = GetCrc(uart2->pRxBff, sizeof(psState_type) + sizeof(meas_type) + sizeof(uint16_t));
			if(crc == 0){
				/*****************************
				 * Очередь комманд
				 */
				res = xQueueReceive(queueCommand, &fp.tf.task.request, 0);
				if(res != pdPASS){
					//Если из очереди не прочитано ни одного элемента
					fp.tf.task.request = setNone;
				}

				memcpy(&fp.tf.state, uart2->pRxBff, sizeof(psState_type) + sizeof(meas_type));
				if(fp.tf.state.bit.lowInputVoltage != 0){
					//shutdown();
				}
				uartTsk.normAnswer++;
				errPrev = uartTsk.errorAnswer;
				noAnswerPrev = uartTsk.noAnswer;
				uartTsk.state = uartConnect;
			}else{
				uartTsk.errorAnswer++;
				if((uartTsk.errorAnswer - errPrev) > maxUartErr){
					uartTsk.state = uartNoConnect;
				}
			}
		}else{
			//Таймаут
			uartTsk.noAnswer++;
			if((uartTsk.noAnswer - noAnswerPrev) > maxUartErr){
				uartTsk.state = uartNoConnect;
			}
		}

		vTaskDelayUntil(&xLastWakeTime, msToSt(UART_TSK_PERIOD));
	}
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
