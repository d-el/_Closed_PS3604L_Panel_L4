/*!****************************************************************************
 * @file    bkp.c
 * @author  d_el
 * @version V1.0
 * @date    01.08.2016, Storozhenko Roman
 * @brief   --
 * @copyright GNU Public License
 */

/*!****************************************************************************
 * Include
 */
#include "bkp.h"

/*!****************************************************************************
 * MEMORY
 */

/*!****************************************************************************
 * @brief   
 * @param    
 * @retval   
 */
bkpStatus_type bkp_write(uint8_t dst, void *src, uint8_t len){
	/*uint8_t     *pData = (uint8_t*)src;
	 uint16_t    *pDst = (uint16_t*)&BKP->DR1 + dst;
	 
	 union{
	 uint8_t     mas[2];
	 uint16_t    word;
	 }frame;
	 
	 RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;      //включить тактирование PWR и Backup
	 PWR->CR     |= PWR_CR_DBP;                                  //разрешить доступ к Backup области

	 while(len > 1){
	 frame.mas[0] = *pData++;
	 frame.mas[1] = *pData++;
	 *pDst = frame.word;
	 pDst += 2;
	 len -= 2;
	 }
	 
	 if(len != 0){
	 frame.word = *pDst;
	 frame.mas[0] = *pData;
	 *pDst = frame.word;
	 }
	 
	 PWR->CR     &= ~PWR_CR_DBP;                                 //запретить доступ к Backup области*/
	return bkpOk;
}

/*!****************************************************************************
 * @brief   
 * @param    
 * @retval   
 */
bkpStatus_type bkp_read(uint8_t *dst, uint8_t src, uint8_t len){
	/*uint8_t    *pSrc = (uint8_t*)&BKP->DR1 + src;

	 while(len != 0){
	 *dst++ = *pSrc++;
	 len--;
	 if(len == 0){
	 break;
	 }
	 *dst++ = *pSrc++;
	 
	 pSrc += 2;
	 len--;
	 }*/

	return bkpOk;
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
