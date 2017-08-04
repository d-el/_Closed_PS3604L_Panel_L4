/*!****************************************************************************
 * @file    i2c.c
 * @author  Storozhenko Roman - D_EL
 * @version V1.1
 * @date    1-06-2015
 * @copyright GNU Public License
 */

/*!****************************************************************************
 * Include
 */
#include "i2c.h"

/*!****************************************************************************
 * i2c1 memory
 */
#if (I2C1_USE == 1)
i2c_type i2c1Sct;
i2c_type *i2c1 = &i2c1Sct;
uint8_t i2c1TxBff[I2C1_TxBffSz];
uint8_t i2c1RxBff[I2C1_RxBffSz];
#endif //I2C1_USE

/*!****************************************************************************
 * i2c2 memory
 */
#if (I2C2_USE == 1)
i2c_type i2c2Sct;
i2c_type *i2c2 = &i2c2Sct;
uint8_t i2c2TxBff[I2C2_TxBffSz];
uint8_t i2c2RxBff[I2C2_RxBffSz];
#endif //I2C2_USE

/*!****************************************************************************
 * i2c3 memory
 */
#if (I2C3_USE == 1)
i2c_type i2c3Sct;
i2c_type *i2c3 = &i2c3Sct;
uint8_t i2c3TxBff[I2C3_TxBffSz];
uint8_t i2c3RxBff[I2C3_RxBffSz];
#endif //I2C3_USE

/*!****************************************************************************
 *
 */
void i2c_init(i2c_type *i2cx){
#if (I2C1_USE == 1)
	if(i2cx == i2c1){

	}
#endif //I2C1_USE

#if (I2C2_USE == 1)
	if(i2cx == i2c2){
		/************************************************
		 * Memory setting
		 */
		i2cx->I2C = I2C2;
		i2cx->pDmaTxDmaCh = DMA1_Channel4;
		i2cx->pDmaRxDmaCh = DMA1_Channel5;

		/************************************************
		 * IO
		 * PB13 - I2C2_CSCL
		 * PB14 - I2C2_SDA
		 */
		gppin_init(GPIOB, 10, alternateFunctionOpenDrain, pullUp, 0, I2C2_PINAFSCL);
		gppin_init(GPIOB, 11, alternateFunctionOpenDrain, pullUp, 0, I2C2_PINAFSDA);

		/************************************************
		 * NVIC
		 */
		NVIC_EnableIRQ(I2C2_EV_IRQn);           								//Event interrupt enable
		NVIC_SetPriority(I2C2_EV_IRQn, I2C2_EventInterruptPrior);
		NVIC_EnableIRQ(I2C2_ER_IRQn);           								//Error interrupt enable
		NVIC_SetPriority(I2C2_ER_IRQn, I2C2_ErrorInterruptPrior);

		/************************************************
		 * I2C clock
		 */
		RCC->APB1ENR1 |= RCC_APB1ENR1_I2C2EN;                         		//USART1 clock enable
		RCC->APB1RSTR1 |= RCC_APB1RSTR1_I2C2RST;                        		//USART1 reset
		RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_I2C2RST;

		/************************************************
		 * DMA clock
		 */
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;

		/************************************************
		 * DMA request settings
		 */
		DMA1_CSELR->CSELR &= ~DMA_CSELR_C4S_Msk;        						//Channel 4 clear
		DMA1_CSELR->CSELR |= 0x3 << DMA_CSELR_C4S_Pos;  						//Channel 4 mapped on I2C2_TX
		DMA1_CSELR->CSELR &= ~DMA_CSELR_C5S_Msk;        						//Channel 5 clear
		DMA1_CSELR->CSELR |= 0x3 << DMA_CSELR_C5S_Pos;  						//Channel 5 mapped on I2C3_RX
	}
#endif //I2C2_USE

#if (I2C3_USE == 1)
	if(i2cx == i2c3){

	}
#endif //I2C3_USE

	/************************************************
	 * I2C
	 */
	i2cx->I2C->CR1 |= I2C_CR1_TXDMAEN;								//DMA mode disabled for transmission
	i2cx->I2C->CR1 |= I2C_CR1_RXDMAEN;								//DMA mode enabled for reception

	i2cx->I2C->CR1 |= I2C_CR1_STOPIE;								//Stop detection (STOPF) interrupt enabled

	i2cx->I2C->CR2 |= I2C_CR2_AUTOEND;							//Automatic end mode: a STOP condition is automatically sent when NBYTES data are transferred

	//I2C_TIMINGR 100 kHz for 48 MHz Peripheral clock	(ref DocID027295 Rev 2 1024/1426)
	i2cx->I2C->TIMINGR |= (0xB) << I2C_TIMINGR_PRESC_Pos;
	i2cx->I2C->TIMINGR |= (0x13) << I2C_TIMINGR_SCLL_Pos;
	i2cx->I2C->TIMINGR |= (0xF) << I2C_TIMINGR_SCLH_Pos;
	i2cx->I2C->TIMINGR |= (0x2) << I2C_TIMINGR_SDADEL_Pos;
	i2cx->I2C->TIMINGR |= (0x4) << I2C_TIMINGR_SCLDEL_Pos;

	i2cx->I2C->CR1 |= I2C_CR1_PE;			//Peripheral Enable

	/************************************************
	 * DMA
	 */
	//DMA Channel USART TX
	i2cx->pDmaTxDmaCh->CCR &= ~DMA_CCR_EN;                               		//Channel disabled
	i2cx->pDmaTxDmaCh->CCR |= DMA_CCR_PL_0;                              		//Channel priority level - Medium
	i2cx->pDmaTxDmaCh->CCR &= ~DMA_CCR_MSIZE;                            		//Memory size - 8 bit
	i2cx->pDmaTxDmaCh->CCR &= ~DMA_CCR_PSIZE;                          			//Peripheral size - 8 bit
	i2cx->pDmaTxDmaCh->CCR |= DMA_CCR_MINC;                              		//Memory increment mode enabled
	i2cx->pDmaTxDmaCh->CCR &= ~DMA_CCR_PINC;                             		//Peripheral increment mode disabled
	i2cx->pDmaTxDmaCh->CCR &= ~DMA_CCR_CIRC;                             		//Circular mode disabled
	i2cx->pDmaTxDmaCh->CCR |= DMA_CCR_DIR;                               		//Read from memory
	i2cx->pDmaTxDmaCh->CNDTR = 0;                                        		//Number of data
	i2cx->pDmaTxDmaCh->CPAR = (uint32_t) &i2cx->I2C->TXDR;       				//Peripheral address
	i2cx->pDmaTxDmaCh->CMAR = (uint32_t) NULL;                            		//Memory address

	//DMA Channel USART RX
	i2cx->pDmaRxDmaCh->CCR &= ~DMA_CCR_EN;                               		//Channel disabled
	i2cx->pDmaRxDmaCh->CCR |= DMA_CCR_PL_0;                              		//Channel priority level - Medium
	i2cx->pDmaRxDmaCh->CCR &= ~DMA_CCR_MSIZE;                            		//Memory size - 8 bit
	i2cx->pDmaRxDmaCh->CCR &= ~DMA_CCR_PSIZE;                           		//Peripheral size - 8 bit
	i2cx->pDmaRxDmaCh->CCR |= DMA_CCR_MINC;                              		//Memory increment mode enabled
	i2cx->pDmaRxDmaCh->CCR &= ~DMA_CCR_PINC;                             		//Peripheral increment mode disabled
	i2cx->pDmaRxDmaCh->CCR &= ~DMA_CCR_CIRC;                             		//Circular mode disabled
	i2cx->pDmaRxDmaCh->CCR &= ~DMA_CCR_DIR;                              		//Read from peripheral
	i2cx->pDmaRxDmaCh->CCR |= DMA_CCR_TCIE;                              		//Transfer complete interrupt enable
	i2cx->pDmaRxDmaCh->CNDTR = 0;                                        		//Number of data
	i2cx->pDmaRxDmaCh->CPAR = (uint32_t) &i2cx->I2C->RXDR;       				//Peripheral address
	i2cx->pDmaRxDmaCh->CMAR = (uint32_t) NULL;                      				//Memory address
}

/*!****************************************************************************
 *
 */
void i2c_reInit(i2c_type *i2cx){
	i2c_init(i2cx);
}

/*!****************************************************************************
 *
 */
void i2c_write(i2c_type *i2cx, void *src, uint16_t len, uint8_t slaveAdr, i2c_stopMode_type stopMode){
	i2cx->pDmaTxDmaCh->CCR &= ~DMA_CCR_EN;
	i2cx->pDmaTxDmaCh->CMAR = (uint32_t) src;
	i2cx->pDmaTxDmaCh->CNDTR = len;
	i2cx->slaveAdr = slaveAdr;
	i2cx->stopMode = stopMode;

	if(stopMode == i2cNeedStop){
		i2cx->I2C->CR2 |= I2C_CR2_AUTOEND;					//Automatic end mode: a STOP condition is automatically sent when NBYTES data are transferred
		i2cx->I2C->CR1 &= ~I2C_CR1_TXIE;					//TX interrupt disable
	}else{
		i2cx->I2C->CR2 &= ~I2C_CR2_AUTOEND;
		i2cx->I2C->CR1 |= I2C_CR1_TXIE;					//TX interrupt enable
	}

	i2cx->I2C->CR2 &= ~I2C_CR2_RD_WRN;						//Master requests a write transfer
	i2cx->I2C->CR2 &= ~I2C_CR2_NBYTES;
	i2cx->I2C->CR2 |= (len) << I2C_CR2_NBYTES_Pos;			//Number of bytes
	i2cx->I2C->CR2 &= ~I2C_CR2_SADD;						//Slave address bit (master mode) clear
	i2cx->I2C->CR2 |= (slaveAdr) << I2C_CR2_SADD_Pos;		//Slave address bit (master mode)

	i2cx->pDmaTxDmaCh->CCR |= DMA_CCR_EN;
	i2cx->I2C->CR2 |= I2C_CR2_START;			//Generation start condition
	i2cx->state = i2cTxRun;
}

/*!****************************************************************************
 *
 */
void i2c_read(i2c_type *i2cx, void *dst, uint16_t len, uint8_t slaveAdr){
	i2cx->pDmaRxDmaCh->CCR &= ~DMA_CCR_EN;
	i2cx->pDmaRxDmaCh->CMAR = (uint32_t) dst;
	i2cx->pDmaRxDmaCh->CNDTR = len;
	i2cx->slaveAdr = slaveAdr;

	i2cx->I2C->CR2 |= I2C_CR2_AUTOEND;						//Automatic end mode: a STOP condition is automatically sent when NBYTES data are transferred
	i2cx->I2C->CR1 &= ~I2C_CR1_TXIE;						//TX interrupt disable

	i2cx->I2C->CR2 |= I2C_CR2_RD_WRN;						//Master requests a read transfer

	i2cx->I2C->CR2 &= ~I2C_CR2_NBYTES;
	i2cx->I2C->CR2 |= (len) << I2C_CR2_NBYTES_Pos;			//Number of bytes

	i2cx->I2C->CR2 &= (~(slaveAdr)) << I2C_CR2_SADD_Pos;	//Slave address bit (master mode)
	i2cx->I2C->CR2 |= (slaveAdr) << I2C_CR2_SADD_Pos;		//Slave address bit (master mode)

	i2cx->pDmaRxDmaCh->CCR |= DMA_CCR_EN;
	i2cx->I2C->CR2 |= I2C_CR2_START;			//Generation start condition
	i2cx->state = i2cRxRun;
}

/******************************************************************************
 * I2C ERROR HANDLER
 */
void i2cErrorHendler(i2c_type *i2cx){
	//__IO uint32_t  I2Cx_SR1 = i2cx->I2C->ISR;
}

/******************************************************************************
 * I2C2
 */
#if (I2C2_USE > 0)
void I2C2_EV_IRQHandler(void){
	if((i2c2->I2C->ISR & I2C_ISR_STOPF) != 0){
		if(i2c2->state == i2cTxRun){
			i2c2->state = i2cTxSuccess;
		}
		if(i2c2->state == i2cRxRun){
			i2c2->state = i2cRxSuccess;
		}
#if (I2C2_TC_HOOK > 0)
		i2c2TC_Hook();
#endif //I2C2_TC_HOOK
		i2c2->I2C->ICR = I2C_ICR_STOPCF;
	}else if((i2c2->I2C->ISR & I2C_ISR_TXE) != 0){
		if(i2c2->state == i2cTxRun){
			i2c2->state = i2cTxSuccess;
		}
		if(i2c2->state == i2cRxRun){
			i2c2->state = i2cRxSuccess;
		}
#if (I2C2_TC_HOOK > 0)
		i2c2TC_Hook();
#endif //I2C2_TC_HOOK
		i2c2->I2C->ICR = I2C_ICR_STOPCF;
	}
}
void I2C2_ER_IRQHandler(void){
	i2cErrorHendler(i2c2);
}
void DMA1_Channel5_IRQHandler(void){   //RX
	//DMA1->HIFCR  =  DMA_HIFCR_CTCIF3;       //Clear flag
	i2c2Sct.state = i2cRxSuccess;
}
#endif

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
