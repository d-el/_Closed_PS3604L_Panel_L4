/*!****************************************************************************
* @file    		display.h
* @author  		d_el - Storozhenko Roman
* @version 		V1.0
* @date    		25.04.2017
* @brief   		--
* @copyright 	GNU Public License
*/
#ifndef display_H
#define display_H

/*!****************************************************************************
* Include
*/
#include "spfd54124b.h"

/*!****************************************************************************
* Define
*/

/*!****************************************************************************
* Enumeration
*/

/*!****************************************************************************
* Typedef
*/
typedef struct{
    const uint8_t     *data;
    uint8_t     w;
    uint8_t     h;
}tImage;

typedef struct{
    const uint8_t n;
    const tImage  *Image;
}tChar;

typedef struct{
    int length;
    const tChar *chars;
}tFont;

/*!****************************************************************************
* Exported variables
*/
extern char         str[30];
extern const tFont  dSegBold;
extern const tFont  arial;
extern const tFont  ico;
extern const tImage ImageLogo;
extern const uint8_t ImStart[];

/*!****************************************************************************
* Macro functions
*/

/*!****************************************************************************
* Function prototype
*/
void lcd_setColor(uint16_t backgroundColor, uint16_t contentColor);
void lcd_setPixel(uint16_t x, uint16_t y, uint16_t color);
void lcd_fillScreen(uint16_t color);
void lcd_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void lcd_putChar(uint16_t x, uint16_t y, const tFont *font, char c);
void lcd_putStr(uint16_t x, uint16_t y, const tFont *font, uint8_t distance, const char *s);

void lcd_putChar6x8(uint8_t x, uint8_t y, uint8_t c);
void lcd_putString6x8(uint8_t x, uint8_t y, const char *s);
void lcd_putChar8x12(uint8_t x, uint8_t y, uint8_t c);
void lcd_putString8x12(uint8_t x, uint8_t y, const char *s);

void lcd_PrintImage16bit(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const void *pIm);
void lcd_PrintImage8bit(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const void *pIm);
void lcd_PrintImageMonochrome(uint8_t x, uint8_t y, uint16_t color, uint16_t backgroundColor, const tImage *image);

#endif //display_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
