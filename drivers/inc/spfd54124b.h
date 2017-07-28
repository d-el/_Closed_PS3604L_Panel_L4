/*!****************************************************************************
* @file   		 spfd54124b.h
* @author  		d_el
* @version 		V1.0
* @date    		19.12.2015, by d_el
* @brief   		--
* @copyright 	GNU Public License
*/
#ifndef spfd54124b_H
#define spfd54124b_H

/*!****************************************************************************
* Include
*/
#include "stm32l4xx.h"
#include "string.h"
#include "gpio.h"
#include "fonts.h"

/*!****************************************************************************
* User define
*/
#define LO_lcd_rst  (GPIOB->BRR = GPIO_BRR_BR12)
#define HI_lcd_rst	(GPIOB->BSRR = GPIO_BSRR_BS12)

#define LO_lcd_cs
#define HI_lcd_cs

#define LO_mosi	    (GPIOA->BRR = GPIO_BRR_BR7)
#define HI_mosi	    (GPIOA->BSRR = GPIO_BRR_BR7)

#define LO_clk	    (GPIOA->BRR = GPIO_BRR_BR5)
#define HI_clk	    (GPIOA->BSRR = GPIO_BRR_BR5)

#define swSpiDelay
    
typedef enum{
	sky     = 0x54fb,
	black   = 0x0000,
	white   = 0xFFFF,
	green   = 0x07E0,
	blue    = 0x001f,
	red     = 0xF800,
	yellow  = 0xFFE0,
	orange  = 0xAB00,
	pink    = 0xF97F,
	brown   = 0x8200,
	gray    = 0x8410,
	lilac   = 0x91D4
}color_type;

//8bit
#define R       red         //RED
#define RG      yellow      //RG - YELLOW
#define G       green       //GREN
#define GB      pink        //GB -САЛАТОВЫЙ
//#define B       0        //BLUE
#define RB      pink        //RB - VIOLET
#define RGB     white       //RGB

#define B

#define dark_green 			0x3DA5
#define half_light_gray 	0xDF7B
#define half_light_yellow 	0xFFF8
#define half_light_red 		0xFF18
#define half_light_green 	0xC7F8
#define half_light_blue 	0x861F

//#define displayOffsetX  2	//для книжной
//#define displayOffsetY  1	//для книжной
#define displayOffsetX  1	//для альбомной
#define displayOffsetY  2	//для альбомной

//#define DISP_W 128	//для книжной
//#define DISP_H 160	//для книжной
#define DISP_W 160	//для альбомной
#define DISP_H 128	//для альбомной

/*!****************************************************************************
* User enum
*/

/*!****************************************************************************
* User typedef
*/

/*!****************************************************************************
* Extern viriables
*/
extern uint16_t 	videoBff[160*128];

/*!****************************************************************************
* Macro functions
*/

/*!****************************************************************************
* Prototypes for the functions
*/
void lcd_spitx(uint32_t data);

void lcd_dat16(uint16_t data);
void lcd_init(void);
void lcd_disable(void);
void lcd_contrast(uint8_t data);
void lcd_gotoxy(uint8_t x0, uint8_t y0,  uint8_t x1, uint8_t  y1);

#endif //spfd54124b_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
