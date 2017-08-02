/*!****************************************************************************
 * @file		startupTSK.c
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		02.08.2017
 * @copyright	GNU Lesser General Public License v3
 * @brief		This task create start screen
 */

/*!****************************************************************************
 * Include
 */
#include "startupTSK.h"

/*!****************************************************************************
 * MEMORY
 */
uint32_t startCounter;	///< Device start counter

/*!****************************************************************************
 * @brief
 */
void startupTSK(void *pPrm){
	while(1){
		startCounter++;

		//Start Beep
		BeepTime(ui.beep.welcome.time, ui.beep.welcome.freq);
		LED_ON();
		vTaskDelay(pdMS_TO_TICKS(60));
		LED_OFF();

		//setLcdBrightness(fp.fpSet.lcdLight);
		//iq_mandelbrot();

		lcd_setColor(black, white);
		lcd_PrintImageMonochrome((DISP_W - ImageLogo.w) / 2, 3, black, white, &ImageLogo);  //Logo
		sprintf(str, "COUNT %u", startCounter);
		lcd_putStr(00, 70, &arial, 0, str);
		lcd_putStr(0, 90, &arial, 0, fwinfoVersion);
		lcd_putStr(0, 110, &arial, 0, "2012 - 2017");

		if(fp.fpSet.lcdLight < 10){
			fp.fpSet.lcdLight = 10;
		}
		for(uint16_t i = 0; i < fp.fpSet.lcdLight; i++){
			setLcdBrightness(i);
			vTaskDelay(pdMS_TO_TICKS(3));
		}
		vTaskDelay(pdMS_TO_TICKS(300));
		setLcdBrightness(fp.fpSet.lcdLight);

		//Run key process
		for(uint32_t cnt = 0; (cnt <= KEY_SAMPLES) && (keyProc() == 0); cnt++);

		if(keyState(kOnOff)){
			selWindow(settingWindow);
		}else{
			selWindow(baseWindow);
		}
	}
}

/*************** LGPL ************** END OF FILE *********** D_EL ************/
