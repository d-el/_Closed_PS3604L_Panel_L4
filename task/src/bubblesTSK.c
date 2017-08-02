﻿/*!****************************************************************************
 * @file		bubbles.c
 * @author		D_EL - Storozhenko Roman
 * @version		V1.0
 * @date		19.08.2014
 * @copyright	GNU Public License
 */

/*!****************************************************************************
 * Include
 */
#include <bubblesTSK.h>

/*!****************************************************************************
 * MEMORY
 */
ball_type	ball[CountOfBalls];
uint16_t	colorsPal[3] = { red, green, blue };
uint16_t	bcolorsCurrent;
uint16_t 	ball_[] = { 0x1E00, 0x3F00, 0x7F80, 0xF3C0, 0xE1C0, 0xE1C0, 0xF3C0, 0x7F80, 0x3F00, 0x1E00, };

/*!****************************************************************************
 * Local prototypes for the functions
 */
void initialize(void);
void physics(void);
void moveball(void);

void bubblesTSK(void *pPrm){
	lcd_fillScreen(black);
	initialize();
	while(1){
		physics();
		moveball();
		vTaskDelay(pdMS_TO_TICKS(60));

	}
}

void nextColor(void){
	static uint8_t n;
	n++;
	if(n > 2)
		n = 0;
	bcolorsCurrent = colorsPal[n];
	bcolorsCurrent = red;
}

void paint_ball(int16_t x, int16_t y, int16_t r, uint16_t color){
	uint32_t h, w, mask;

	//lcd_gotoxy(x - 5, y - 5, x + 5 - 1, y + 5 - 1);
	for(h = 0; h < 10; h++){

		mask = (1 << 15);
		for(w = 0; w < 10; w++){
			if((ball_[h] & mask) != 0){
				//spfd_lcdDat16(color);
			}else{
				//spfd_lcdDat16(black);
			}
			mask >>= 1;
		}
	}
}

void clear_ball(int16_t x, int16_t y, int16_t r, uint16_t color){
	uint32_t h;

	//lcd_gotoxy(x - 5, y - 5, x + 5 - 1, y + 5 - 1);
	for(h = 0; h < 10 * 10; h++){
		//spfd_lcdDat16(black);
	}
}

void initialize(void){ // Initialize the game
	ball[0].color = red;
	ball[0].radius = 5;
	ball[0].speedx = 3 + _rand(2); //Generate Random X direction.
	ball[0].speedy = 2 + _rand(2); //Generate Random Y direction.
	ball[0].old_xcenter = xSize / 2;
	ball[0].old_ycenter = ySize / 2;
	ball[0].new_xcenter = xSize / 2;
	ball[0].new_ycenter = ySize / 2;

	ball[1].color = green;
	ball[1].radius = 5;
	ball[1].speedx = 3 + _rand(2); // Generate Random X direction.
	ball[1].speedy = -2 + _rand(2); // Generate Random Y direction.
	ball[1].old_xcenter = xSize / 2 + 15;
	ball[1].old_ycenter = ySize / 2 + 15;
	ball[1].new_xcenter = xSize / 2 + 15;
	ball[1].new_ycenter = ySize / 2 + 15;

	ball[2].color = blue;
	ball[2].radius = 5;
	ball[2].speedx = -4 + _rand(2); // Generate Random X direction.
	ball[2].speedy = 3 + _rand(2); // Generate Random Y direction.
	ball[2].old_xcenter = xSize / 2 - 15;
	ball[2].old_ycenter = ySize / 2 - 15;
	ball[2].new_xcenter = xSize / 2 - 15;
	ball[2].new_ycenter = ySize / 2 - 15;

	ball[3].color = white;
	ball[3].radius = 5;
	ball[3].speedx = -3 + _rand(2); // Generate Random X direction.
	ball[3].speedy = 2 + _rand(2); // Generate Random Y direction.
	ball[3].old_xcenter = xSize / 2 + 10;
	ball[3].old_ycenter = ySize / 2 + 10;
	ball[3].new_xcenter = xSize / 2 + 10;
	ball[3].new_ycenter = ySize / 2 + 10;

	ball[4].color = sky;
	ball[4].radius = 5;
	ball[4].speedx = 2 + _rand(2); // Generate Random X direction.
	ball[4].speedy = -4 + _rand(2); // Generate Random Y direction.
	ball[4].old_xcenter = xSize / 2 - 10;
	ball[4].old_ycenter = ySize / 2 - 10;
	ball[4].new_xcenter = xSize / 2 - 10;
	ball[4].new_ycenter = ySize / 2 - 10;
}

void moveball(void){
	uint8_t i;
	for(i = 0; i < CountOfBalls; i++){
		paint_ball(ball[i].new_xcenter, ball[i].new_ycenter, ball[i].radius, black);

		ball[i].new_xcenter = ball[i].new_xcenter + ball[i].speedx;
		ball[i].new_ycenter = ball[i].new_ycenter + ball[i].speedy;

		clear_ball(ball[i].old_xcenter, ball[i].old_ycenter, ball[i].radius, black);
		paint_ball(ball[i].new_xcenter, ball[i].new_ycenter, ball[i].radius, ball[i].color);
	}
}

void physics(void){
	uint8_t i, Sumradius;
	signed int yDistance, xDistance, yAbsDistance, xAbsDistance;
	uint8_t j, k;

	for(i = 0; i < CountOfBalls; i++){
		//From Top
		if((ball[i].new_ycenter - ball[i].radius) <= 1){
			ball[i].speedy = -ball[i].speedy; // Reflect From Top
			//nextColor();
			// return;
		}
		//From Bottom
		if((ball[i].new_ycenter + ball[i].radius) >= (ySize - 1)){
			ball[i].speedy = -ball[i].speedy; // Reflect From Bottom
			//nextColor();
			//return;
		}
		//From Left
		if((ball[i].new_xcenter - ball[i].radius) <= 1){
			ball[i].speedx = -ball[i].speedx;
			//nextColor();
			//return;
		}
		//From Right
		if((ball[i].new_xcenter + ball[i].radius + ball[i].speedx) >= (xSize - 1)){
			ball[i].speedx = -ball[i].speedx;
			//nextColor();
			//return;
		}

	}

	for(j = 0; j < CountOfBalls; j++){

		for(k = j + 1; k < CountOfBalls; k++){

			yDistance = ball[j].new_ycenter - ball[k].new_ycenter;
			yAbsDistance = abs(yDistance);

			xDistance = ball[j].new_xcenter - ball[k].new_xcenter;
			xAbsDistance = abs(xDistance);

			Sumradius = ball[j].radius + ball[k].radius;

			if((yAbsDistance <= Sumradius) && (xAbsDistance <= Sumradius)){
				//clash
				//BeepTime(20);
				ball[j].speedx = -ball[j].speedx;
				ball[j].speedy = -ball[j].speedy;

				ball[k].speedx = -ball[k].speedx;
				ball[k].speedy = -ball[k].speedy;
			}
		}
	}
}

/*yDistance = ball[0].new_ycenter - ball[1].new_ycenter;
 yAbsDistance = abs(yDistance);

 xDistance = ball[0].new_xcenter - ball[1].new_xcenter;
 xAbsDistance = abs(xDistance);

 Sumradius = ball[0].radius + ball[1].radius;

 if((yAbsDistance <= Sumradius) && (xAbsDistance <= Sumradius)){
 static uint8_t clash;
 clash++;
 sprintf(str, "%u", clash);
 LCD_PutStr8x12(100, 100, str);

 ball[0].speedx = - ball[0].speedx;
 ball[0].speedy = - ball[0].speedy;
 ball[1].speedx = - ball[1].speedx;
 ball[1].speedy = - ball[1].speedy;
 }*/
/*if( ( abs( ball[0].new_ycenter - ball[1].new_ycenter ) - (ball[0].radius + ball[1].radius ) ) ==
 ( abs( ball[0].new_xcenter - ball[1].new_xcenter ) - (ball[0].radius + ball[1].radius ) ) ){

 static uint8_t clash;
 sprintf(str, "%u", clash);
 LCD_PutStr8x12(0, 0, str);
 clash++;

 ball[0].speedx = - ball[0].speedx +1;
 ball[0].speedy = - ball[0].speedy +1;

 ball[1].speedx = - ball[1].speedx -1;
 ball[1].speedy = - ball[1].speedy -1;
 }*/

/* шарик с R=5
 { 0xE0, 0xF0, 0xF8, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0x00,
 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00 },*/

//vTaskDelay(30);
//столкнулись
/* ball[0].speedx = - ball[0].speedx +1;
 ball[0].speedy = - ball[0].speedy +1;

 ball[1].speedx = - ball[1].speedx -1;
 ball[1].speedy = - ball[1].speedy -1;*/

/* else{
 uint8_t x = 0, y = 0;
 sprintf(str, "%X", 1);
 LCD_PutStr8x12(x, y, str);
 x++;
 y++;

 } */

//
//void play(void)	// Our Budding Game Engine
//{
//    uint16_t i;
//	while(1){
//        moveball();
//        physics();
//        delay_ms(i); // Reduce game speed to human playable level
//
//    }
//}
/******************* (C) COPYRIGHT ***************** END OF FILE ********* D_EL *****/
