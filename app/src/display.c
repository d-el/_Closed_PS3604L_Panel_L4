/*!****************************************************************************
* @file    		display.c
* @author  		d_el - Storozhenko Roman
* @version 		V1.0
* @date    		25.04.2017
* @brief   		--
* @copyright 	GNU Public License
*/

/*!****************************************************************************
* Include
*/
#include "display.h"

/*!****************************************************************************
* MEMORY
*/
char		str[30];
uint16_t	uiBackgroundColor;
uint16_t	uiContentColor;

/*!****************************************************************************
* @brief
*/
void lcd_setColor(uint16_t backgroundColor, uint16_t contentColor){
	uiBackgroundColor = backgroundColor;
	uiContentColor = contentColor;
}

/*!****************************************************************************
* @brief Вывод пикселя
*/
void lcd_setPixel(uint16_t x, uint16_t y, uint16_t color){
	videoBff[(y * DISP_W) + x] = ~__REV16(color);
}

/*!****************************************************************************
* @brief Заливка одним цветом
*/
void lcd_fillScreen(uint16_t color){
	color = ~color;
	uint32_t color32 = ((uint32_t)color << 16) | color;
	uint32_t *data = (uint32_t*)&videoBff[0];
	uint32_t *dataEnd = data + (DISP_W * DISP_H / 2);

	while(data < dataEnd){
		*data++ = color32;
	}
}

/*!****************************************************************************
* @brief
*/
void lcd_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color){
	uint16_t x0 = x;
	uint16_t x2 = x + w;
	uint16_t y2 = y + h;

	while(y < y2){
		while(x < x2){
			lcd_setPixel(x, y, color);
			x++;
		}
		x = x0;
		y++;
	}
}

/*!****************************************************************************
* @brief Вывод символа
*/
void lcd_putChar(uint16_t x, uint16_t y, const tFont *font, char c){
    uint8_t width, height;

    c = c - font->chars[0].n;
    uint8_t c_width = font->chars[c].Image->w;
    uint8_t c_height = font->chars[c].Image->h;

    uint8_t *pdata = (uint8_t*)font->chars[c].Image->data;

    uint8_t  mask;
    uint8_t  bytesPerLine = ((c_width - 1)/8 + 1);
    uint8_t  count;

    for(height = 0; height < c_height; height++){

        for(width = 0; width < bytesPerLine; width++){
            count = c_width - (width * 8);
            if(count > 8){
                count = 8;
            }
            mask = 0x80;
            for(int j = 0; j < count; j++){
                if((*pdata & mask) != 0){
                	lcd_setPixel(x + (width * 8) + j, y + height, uiBackgroundColor);
                }
                else{
                	lcd_setPixel(x + (width * 8) + j, y + height, uiContentColor);
                }
                mask = mask >> 1;
            }
            pdata++;
        }
    }
}

/*!****************************************************************************
* @brief Вывод строки
*/
void lcd_putStr(uint16_t x, uint16_t y, const tFont *font, uint8_t distance, const char *s){
    while(*s != 0){
        lcd_putChar(x, y, font, *s);
        x += font->chars[*s - 0x20].Image->w + distance;
        s++;
    }
}

/*!****************************************************************************
* @brief Знакогенератор (вывод еденичного символа 6x8)
*/
void lcd_putChar6x8(uint8_t x, uint8_t y, uint8_t c){
    uint8_t ch, h, w;

    c = c - 0x20;

    for(h = 0; h < 8; h++){           //Every column of the character
        ch = fonts6x8[c * 8 + h];
        for(w = 0; w < 6; w++){       //Write the pixels
            if((ch & (0x20 >> w)) != 0){
				lcd_setPixel(x + w, y + h, uiContentColor);
			}
			else{
				lcd_setPixel(x + w, y + h, uiBackgroundColor);
			}
        }
    }
}

/*!****************************************************************************
* @brief Вывод строки символов 6x8
*/
void lcd_putString6x8(uint8_t x, uint8_t y, const char *s){
    while (*s){
        lcd_putChar6x8(x, y, *s);
        s++;
        x+= 6;
    }
}

/*!****************************************************************************
* @brief вывод символа 8x12 на дисплей
*/
void lcd_putChar8x12(uint8_t x, uint8_t y, uint8_t c){
    uint8_t     ch, h, w, i, j;

    c = c - 0x20;

    for(h = 0; h < 12; h++){          // every column of the character
        ch = fonts8x12[c * 12 + h];
        for (w = 0; w < 8; w++){      // write the pixels
            if((ch & (0x80 >> w)) != 0){
				lcd_setPixel(x + w, y + h, uiContentColor);
			}
			else{
				lcd_setPixel(x + w, y + h, uiBackgroundColor);
			}
        }
    }
}

/*!****************************************************************************
* @brief вывод текстовой строки 8x12 на дисплей
*/
void lcd_putString8x12(uint8_t x, uint8_t y, const char *s){
    while (*s){
    lcd_putChar8x12(x, y, *s);
    s++;
    x+= 8;
    }
}

/*!****************************************************************************
* @brief Вывод картинки
*/
void lcd_PrintImage16bit(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const void *pIm){
	uint16_t 	*image = (uint16_t*)pIm;
	uint16_t 	*imageEnd;
	uint16_t 	*video = videoBff + x;
	uint16_t 	iw, ih;

	for(ih = 0; ih < h; ih++){
		imageEnd = image + w;
		while(image < imageEnd){
			*video++ = ~ __REV16(*image++);
		}
		video += DISP_W - w;
	}
}

/*!****************************************************************************
* @brief Вывод картинки 8bit R/G/B - 3/3/2
*/
void lcd_PrintImage8bit(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const void *pIm){
	uint8_t 	*image = (uint8_t*)pIm;
	uint8_t 	*imageEnd;
	uint16_t 	*video = videoBff + x;
	uint16_t 	iw, ih;
	uint16_t    color;

	for(ih = 0; ih < h; ih++){
		imageEnd = image + w;
		while(image < imageEnd){
		    color =  (*image & 0xE0) << 8; //RED
		    color |= (*image & 0x1C) << 6; //GREEN
		    color |= (*image & 0x03) << 3; //BLUE
			*video++ = ~ __REV16(color++);
			image++;
		}
		video += DISP_W - w;
	}
}

/*!****************************************************************************
* @brief
*/
void lcd_PrintImageMonochrome(uint8_t x, uint8_t y, uint16_t color, uint16_t backgroundColor, const tImage *image){
    uint8_t width, height;
    uint8_t c_width = image->w;
    uint8_t c_height = image->h;
    uint8_t *pdata = (uint8_t*)image->data;

    uint8_t  mask;
    uint8_t  bytesPerLine = ((c_width - 1)/8 + 1);
    uint8_t  count;

    for(height = 0; height < c_height; height++){

        for(width = 0; width < bytesPerLine; width++){
            count = c_width - (width * 8);
            if(count > 8){
                count = 8;
            }
            mask = 0x80;
            for(int j = 0; j < count; j++){
                if((*pdata & mask) != 0){
                	lcd_setPixel(x + (width * 8) + j, y + height, uiBackgroundColor);
                }
                else{
                	lcd_setPixel(x + (width * 8) + j, y + height, uiContentColor);
                }
                mask = mask >> 1;
            }
            pdata++;
        }
    }
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/