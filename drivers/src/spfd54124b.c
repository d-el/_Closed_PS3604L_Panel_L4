/*!****************************************************************************
* @file    		spfd54124b.c
* @author  		d_el
* @version 		V1.0
* @date    		19.12.2015, by d_el
* @brief   		--
* @copyright 	GNU Public License
*/

/*!****************************************************************************
* Include
*/
#include "spfd54124b.h"

/*!****************************************************************************
* MEMORY
*/
uint16_t 		videoBff[DISP_W * DISP_H];

/******************************************************************************
* @brief Передача данных
*/
void lcd_spitx(uint32_t data){
	data = ~data;
    SPI1->DR = data;                    //Загружаем данные для передачи
    while (!(SPI1->SR & SPI_SR_TXE));   //Ожидание окончания передачи
}

/*!****************************************************************************
* @brief Передача команды
*/
void lcd_cmd(uint8_t data){
	lcd_spitx(data);
}

/*!****************************************************************************
* @brief Передача данных
*/
void lcd_dat(uint8_t data){
	lcd_spitx((1 << 8) | (data));
}

/******************************************************************************
* @brief Передача данных 16 bit
*/
void lcd_dat16(uint16_t data){
	lcd_spitx((1 << 8) | (data >> 8));
	lcd_spitx((1 << 8) | (data & 0x00FF));
}

/******************************************************************************
*
*/
void Init_SPI2(void){
    gppin_init(GPIOA, 5, alternateFunctionPushPull, pullDisable, 0, 5);	//SPI1_SCK
    gppin_init(GPIOA, 7, alternateFunctionPushPull, pullDisable, 0, 5);	//SPI1_MOSI

    _gppin_set(GPIOA, pinm5);
    _gppin_set(GPIOA, pinm7);
    
    //Максимальная скорость - fPCLK/2
    RCC->APB2ENR    |= RCC_APB2ENR_SPI1EN;                      //Clock enable
    RCC->APB2RSTR	|= RCC_APB2RSTR_SPI1RST;					//Reset module
    RCC->APB2RSTR	&= ~RCC_APB2RSTR_SPI1RST;

    //SPI1->CR1       |= SPI_CR1_BR_1;
    SPI1->CR1       |= SPI_CR1_MSTR;                            //Master configuration
    SPI1->CR1       |= SPI_CR1_SSM;                             //Software slave management enabled
    SPI1->CR1       |= SPI_CR1_SSI;                             //Игнорирование NSS входа
    SPI1->CR2		 = SPI_CR2_DS_3;							//Data size 9bit
    SPI1->CR1       |= SPI_CR1_SPE;                             //SPI enable
}

void Init_SPI2_DMA(void){
	SPI1->CR2		|= SPI_CR2_TXDMAEN;

    /************************************************
    * DMA
    */
	RCC->AHB1ENR     	|= RCC_AHB1ENR_DMA1EN;
    DMA1_CSELR->CSELR 	&= ~DMA_CSELR_C3S_Msk;        			//Channel 5 clear
    DMA1_CSELR->CSELR 	|= 0x1 << DMA_CSELR_C3S_Pos;  			//Channel 3 mapped on SPI1_TX
	DMA1_Channel3->CCR 	= 0;
    DMA1_Channel3->CCR 	&= ~DMA_CCR_EN;              			//Channel disabled
    DMA1_Channel3->CCR 	|= DMA_CCR_PL_0;                        //Channel priority level - Medium
    DMA1_Channel3->CCR 	&= ~DMA_CCR_MSIZE;                      //Memory size - 8 bit
    DMA1_Channel3->CCR 	|= DMA_CCR_PSIZE_0;                     //Peripheral size 16 bit
    DMA1_Channel3->CCR 	|= DMA_CCR_MINC;                        //Memory increment mode enabled
    DMA1_Channel3->CCR 	&= ~DMA_CCR_PINC;                       //Peripheral increment mode disabled
    DMA1_Channel3->CCR 	|= DMA_CCR_CIRC;                        //Circular mode enable
    DMA1_Channel3->CCR 	|= DMA_CCR_DIR;                         //Read from memory
    DMA1_Channel3->CCR 	&= ~DMA_CCR_TCIE;                       //Transfer complete interrupt disable
    DMA1_Channel3->CNDTR = sizeof(videoBff);              		//Number of data
    DMA1_Channel3->CPAR = (uint32_t)&(SPI1->DR);        		//Peripheral address
    DMA1_Channel3->CMAR = (uint32_t)&videoBff[0];               //Memory address
    DMA1_Channel3->CCR    |= DMA_CCR_EN;
}

/*!****************************************************************************
* @brief Инициализация LCD
*/
void lcd_init(void){
    gppin_init(GPIOB, 12, outPushPull, pullDisable, 0, 0);//RST
    Init_SPI2();
    
    HI_lcd_rst;
    for(int i = 0; i < 10000; i++) __NOP();
    LO_lcd_rst;
    for(int i = 0; i < 10000; i++) __NOP();
    HI_lcd_rst;
    for(int i = 0; i < 10000; i++) __NOP();
    
    lcd_cmd(0xBA);
	lcd_dat(0x07);
	lcd_dat(0x15); // Порядок отсылки данных

    lcd_cmd(0x25);
	lcd_dat(0x3F); // Контраст
    lcd_cmd(0x11);	//Выход из режима sleep (sleepout)
    //lcd_cmd(0x14);

    lcd_cmd(0x36);	//Memory Data Access Control
    //lcd_dat(0xA0);	//Альбомная ориентация
    lcd_dat(0x60);	//Альбомная ориентация, повернутая на 180°

    lcd_cmd(0x37);	//VSCROLL ADDR
    lcd_dat(0x00);

    lcd_cmd(0x3a);	//COLMOD pixel format
    lcd_dat(0x05);	//COLMOD pixel format 4=12,5=16,6=18

    lcd_cmd(0x29);	//DISPON
    lcd_cmd(0x20);	//INVOFF
    lcd_cmd(0x13);	//NORON
    
    lcd_gotoxy(0, 0, 159, 127);

    memset(videoBff, 0xFF, sizeof(videoBff));

    Init_SPI2_DMA();
}

/*!****************************************************************************
* @brief Программное выключение LCD
*/
void lcd_disable(void){
	lcd_cmd(0x28);	//DISPOFF
	lcd_cmd(0x11);	//Вход в режим sleep (sleepin)
}

/*!****************************************************************************
* @brief Установка контрастности дисплея
*/
void lcd_contrast(uint8_t data){
    /*lcd_cmd(0x25);          //Write contrast
    if((data > 85)&&(data < 115)){
        lcd_data(data);
    }
    else{
        lcd_data(100);
    }*/
    /*lcd_cmd(0x28);	//DISPOFF
	lcd_cmd(0x11);	//Вход в режим sleep (sleepin)
    
    lcd_cmd(0x25);
	lcd_dat(contrast); // Контраст
    
    lcd_cmd(0x11);	//Выход из режима sleep (sleepout)
    lcd_cmd(0x29);	//DISPON*/
}

/*!****************************************************************************
* @brief Установка окна заливки
*/
void lcd_gotoxy(uint8_t x0, uint8_t y0,  uint8_t x1, uint8_t  y1){
	//Выбираем диапазон столбцов
	lcd_cmd(0x2A);        				//CASETP command –
	lcd_dat(0);           				//Второй байт всегда нулевой, т.к. передача по 2 байта
	lcd_dat(displayOffsetX+x0);         //Левый угол - x
	lcd_dat(0);
	lcd_dat(displayOffsetX+x1);     	//Правый угол – x
	// Диапазон строк
	lcd_cmd(0x2B);        				//PASETP command
	lcd_dat(0);
	lcd_dat(displayOffsetY+y0);         //Левый угол - y
	lcd_dat(0);
	lcd_dat(displayOffsetY+y1);       	//Правый угол - y
	lcd_cmd(0x2C);        				//RAMWR command
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
