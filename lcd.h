/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : lcd.h
* Author             : Burak Ozsahin
* Version            : V1.0
* Date               : 01/09/2023
* Description        : lcd functions
********************************************************************************/

#ifndef LCD_H_
#define LCD_H_


#include "main.h"


extern u32 i;
extern u32 j;
extern void delay(unsigned int k);
extern void delay_us(unsigned int k);

extern void data_write(void);
extern void data_read(void);
extern void check_busy(void);
extern void send_command(unsigned char cmd);

extern void send_data(unsigned char data);
extern char send_string(char *s);
extern char send_integer(unsigned long int number);
extern void lcd_pin_init(void);
extern void lcd_init(void);
extern void lcd_save();
extern void lcd_go_to_addr(unsigned char addr);
extern void lcd_Go_To_X_Y(char x, char y);
void setLCDLight(char action);

#define D4_MASK BIT0
#define D5_MASK BIT1
#define D6_MASK BIT2
#define D7_MASK BIT3




#endif /* LCD_H_ */
