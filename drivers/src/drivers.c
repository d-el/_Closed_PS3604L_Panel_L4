/*!****************************************************************************
* @file    drivers.c
* @author  Storozhenko Roman - D_EL
* @version V1.0
* @date    05-07-2013
* @copyright GNU Public License
*/

/*!****************************************************************************
* Include
*/
#include "drivers.h"

/*!****************************************************************************
* MEMORY
*/

/*!****************************************************************************
* Выключение
*/
void shutdown(void){
	//pvd_disable();
	setLcdBrightness(0);
	LED_OFF();
	nvMem_savePrm(&userConfRegion);
	lcd_disable();
	BeepTime(ui.beep.goodbye.time, ui.beep.goodbye.freq);
	LED_ON();
	delay_ms(10000);
	NVIC_SystemReset();
}

/*!****************************************************************************
*
*/
void Init_Hard(void){
	nvMem_state_type nvMemState;

    clock_init();
    gpio_init();
    delTim_init();
    sysTimeMeasEnable();
    enco_init();
    beep_init();
    ledPwm_init();
    lcd_init();
    rtc_init();
    i2c_init(i2c2);
    uart_init(uart2, BR38400);
	//pvd_init();

    nvMem_init(&userConfRegion);
    nvMem_init(&userReservConfRegion);
    nvMem_init(&systemSettingRegion);

    nvMemState = nvMem_loadPrm(&systemSettingRegion);
    if(nvMemState != nvMem_ok){
        //Инициализация по умолчанию
    	systemInitDef();
    }
    nvMemState = nvMem_loadPrm(&userConfRegion);
    if(nvMemState != nvMem_ok){
        //Попробуем считать резервную копию
        nvMemState = nvMem_loadPrm(&userReservConfRegion);
        if(nvMemState != nvMem_ok){
            //Инициализация по умолчанию
            userInitDef();
        }
    }
    else{
        nvMem_savePrm(&userReservConfRegion);
    }
}

/*!****************************************************************************
* Записывает параметры по умолчанию
*/
void userInitDef(void){
    static const base_type baseDefSetting = {
		.set[0] = {
			.u = 1000,				//[mV]
			.i = 100,				//[mA]
			.mode = mode_limitation,
		},
		.set[1] = {
			.u = 4200,				//[mV]
			.i = 100,				//[mA]
			.mode = mode_limitation,
		},
		.set[2] = {
			.u = 12000,				//[mV]
			.i = 100,				//[mA]
			.mode = mode_limitation,
		},
		.startCounter = 0,
		.curPreSet = 0,
    };

    static const charge_type chargeDefSetting = {
		.u = 	4200, 				//[mV]
		.i =    100,  				//[mA]
		.t =    5,    				//[minute]
		.mode = ch_modeCurrent,
    };

    memcpy(&bs, &baseDefSetting, sizeof(base_type));
    memcpy(&ch, &chargeDefSetting, sizeof(charge_type));

    fp.fpSet.lcdLight = 600;
}

/*!****************************************************************************
* Записывает параметры по умолчанию
*/
void systemInitDef(void){
	static const frontPanelSetting_type systemDefSetting = {
		.lcdLight = 600,			//[X_X %]
	};

	memcpy(&fp, &systemDefSetting, sizeof(frontPanelSetting_type));
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
