/*!****************************************************************************
 * @file		24AAxx.c
 * @author		d_el
 * @version		V1.0
 * @date		21.12.2015
 * @copyright	GNU Lesser General Public License v3
 * @brief		Driver for eeprom memory 24AA04, 24AA08
 */

/*!****************************************************************************
 * Include
 */
#include "24AAxx.h"

/*!****************************************************************************
 * Memory
 */
uint8_t eep_tempBff[17];
const uint16_t eepdelay = 5000;

/*!****************************************************************************
 * @brief    	Write data from I2C
 * @param[in]	src - the memory area to write from
 * @param[in]	len - the number of bytes to write
 * @param[in]	slaveAdr - I2C chip address
 * @return		status operation eepOk, eepI2cError
 */
eepStatus_type eep_i2cWrite(void *src, uint16_t len, uint8_t slaveAdr){
	i2c_write(eepI2c, src, len, slaveAdr, i2cNeedStop);
	while(eepI2c->state == i2cTxRun)
		;
	return eepOk;
}

/*!****************************************************************************
 * @brief    	Read data from I2C
 * @param[in]	src - the memory area to copy to
 * @param[in]	len - the number of bytes to read
 * @param[in]	slaveAdr - I2C chip address
 * @return		status operation eepOk, eepI2cError
 */
eepStatus_type eep_i2cRead(void *dst, uint16_t len, uint8_t slaveAdr){
	i2c_read(eepI2c, dst, len, slaveAdr);
	while(eepI2c->state == i2cRxRun)
		;
	return eepOk;
}

/*!****************************************************************************
 * @brief    	Write data to eeprom memory
 * @param[out]	dst - linear address (0 - 1024 for 24AA08)
 * @param[in]	src - source buffer
 * @param[in]	len - number bytes of read
 * @retval		status operation
 */
eepStatus_type eep_write(uint16_t dst, void *src, uint16_t len){
	uint8_t *pData;
	eepAddress_type eepAdr;
	uint8_t adrInBlock;
	uint16_t canWrite;
	eepStatus_type status;
	
	if(len == 0){
		return eepOtherError;
	}
	pData = (uint8_t*) src;
	eepAdr.bit.controlCode = CONTROLCODE;
	eepAdr.bit.rw = eepWrite;
	
	while(len > 0){
		eepAdr.bit.blockSelect = dst / BYTESINPAGE;
		adrInBlock = dst % BYTESINPAGE;
		
		canWrite = (BYTESINPAGE - adrInBlock);
		if(canWrite >= BYTESINBLOCK){
			canWrite = BYTESINBLOCK;
		}
		
		if(len <= canWrite){
			eep_tempBff[0] = adrInBlock;
			memcpy(&eep_tempBff[1], pData, len);
			
			status = eep_i2cWrite(eep_tempBff, len + 1, eepAdr.adr);
			if(status != eepOk){
				return eepI2cError;
			}
			delay_us(eepdelay);
			
			len -= len;
		}else{
			eep_tempBff[0] = adrInBlock;
			memcpy(&eep_tempBff[1], pData, canWrite);
			
			status = eep_i2cWrite(eep_tempBff, canWrite + 1, eepAdr.adr);
			if(status != eepOk){
				return eepI2cError;
			}
			delay_us(eepdelay);
			
			len -= canWrite;
			dst += canWrite;
			pData += canWrite;
		}
	}
	return eepOk;
}

/*!****************************************************************************
 * @brief    	Read data from eeprom memory
 * @param[out]	dst - destination buffer
 * @param[in]	src - linear address (0 - 1024 for 24AA08)
 * @param[in]	len - number bytes of read
 * @retval		status operation
 */
eepStatus_type eep_read(void *dst, uint16_t src, uint16_t len){
	eepAddress_type eepAdr;
	uint8_t adrInBlock;
	eepStatus_type status;
	
	if(len == 0){
		return eepOtherError;
	}
	eepAdr.bit.controlCode = CONTROLCODE;
	eepAdr.bit.blockSelect = src / BYTESINPAGE;
	eepAdr.bit.rw = eepWrite;
	adrInBlock = src % BYTESINPAGE;
	
	status = eep_i2cWrite(&adrInBlock, 1, eepAdr.adr);
	if(status != eepOk){
		return eepI2cError;
	}
	
	eepAdr.bit.rw = eepRead;
	status = eep_i2cRead(dst, len, eepAdr.adr);
	if(status != eepOk){
		return eepI2cError;
	}
	return eepOk;
}

/*************** LGPL ************** END OF FILE *********** D_EL ************/
