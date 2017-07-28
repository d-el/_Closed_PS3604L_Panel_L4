/*!****************************************************************************
*                                                                             *
     _____   _____ ____    __   ___  _  _   _      ______                     *
    |  __ \ / ____|___ \  / /  / _ \| || | | |    |  ____|                    *
    | |__) | (___   __) |/ /_ | | | | || |_| |    | |__                       *
    |  ___/ \___ \ |__ <| '_ \| | | |__   _| |    |  __|                      *
    | |     ____) |___) | (_) | |_| |  | | | |____| |                         *
    |_|    |_____/|____/ \___/ \___/   |_| |______|_|                         *
                                                                              *
*                                                                             *
* @file         main.c                                                        *
* @author       Storozhenko Roman - D_EL                                      *
* @version      V2.0.0                                                        *
* @date         19-12-2014                                                    *
* @brief        Main program body											  *
* @copyright    GNU Public License                                            *
******************************************************************************/

/*!****************************************************************************
* Include
*/
#include "main.h"

/*!****************************************************************************
* MEMORY
*/

/*!****************************************************************************
* @brief    beginning of beginnings
*/
int main(void){
    Init_Hard();
    bs.startCounter++;

    /*****************
    * Start Beep
    */
    BeepTime(ui.beep.welcome.time, ui.beep.welcome.freq);
    LED_ON();
    delay_ms(60);
    LED_OFF();

    //setLcdBrightness(fp.fpSet.lcdLight);
    //iq_mandelbrot();

    lcd_setColor(black, white);
    lcd_PrintImageMonochrome((DISP_W - ImageLogo.w) / 2, 3, black, white, &ImageLogo);  //Logo
    sprintf(str, "COUNT %u", bs.startCounter);
    lcd_putStr(00, 70, &arial, 0, str);
    lcd_putStr(0, 90, &arial, 0, fwinfoVersion);
    lcd_putStr(0, 110, &arial, 0, "2012 - 2017");

    if(fp.fpSet.lcdLight < 10)  fp.fpSet.lcdLight = 10;
    for(uint16_t i = 0; i < fp.fpSet.lcdLight; i++){
        setLcdBrightness(i);
        delay_ms(3);
    }
    delay_ms(300);
    setLcdBrightness(fp.fpSet.lcdLight);

    //Great mutex, semaphore, task, start scheduler
    OSinit();

    while(1){
        LED_ON();
        delay_ms(50);
        LED_OFF();
        delay_ms(50);
    }
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
