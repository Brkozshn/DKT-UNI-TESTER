/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : lcd.c
* Author             : Burak Ozsahin
* Version            : V1.0
* Date               : 01/09/2023
* Description        : lcd functions
********************************************************************************/



#include <msp430.h>
#include "lcd.h"
#include "bsp.h"
#include "main.h"
#include "button.h"



u32 i;
u32  j;

char empty_row[16] = {"                "};


void delay(unsigned int k)
{
    for(j=0;j<=k;j++)
    {
        for(i=0; i < 125 ; i++);
    }
}

void delay_us(unsigned int k)
{
    for(j=0;j<=k;j++)
    {
        for(i=0; i < 5 ; i++);
    }
}

void data_write(void)
{
ENABLE_HIGH;
delay_us(3);
ENABLE_LOW;
}
void data_read(void)
{
ENABLE_LOW;
delay_us(3);
ENABLE_HIGH;
}


void check_busy(void)
{
    D7_PIN_DIR &= ~(D7_PIN_BIT); // make D7 as input
while((D7_PIN_IN&D7_PIN_BIT)==1)
{
data_read();
}
D7_PIN_DIR |= D7_PIN_BIT; // make P1.3 as output
}


void send_command(unsigned char cmd)
{
check_busy();
WRITE;
CWR;

if(((cmd>>4)&D4_MASK) == D4_MASK)
    D4_PIN_OUT |= D4_PIN_BIT;
else
    D4_PIN_OUT &= ~D4_PIN_BIT;

if(((cmd>>4)&D5_MASK) == D5_MASK)
    D5_PIN_OUT |= D5_PIN_BIT;
else
    D5_PIN_OUT &= ~D5_PIN_BIT;

if(((cmd>>4)&D6_MASK) == D6_MASK)
    D6_PIN_OUT |= D6_PIN_BIT;
else
    D6_PIN_OUT &= ~D6_PIN_BIT;

if(((cmd>>4)&D7_MASK) == D7_MASK)
    D7_PIN_OUT |= D7_PIN_BIT;
else
    D7_PIN_OUT &= ~D7_PIN_BIT;
data_write(); // give enable trigger


if(((cmd)&D4_MASK) == D4_MASK)
    D4_PIN_OUT |= D4_PIN_BIT;
else
    D4_PIN_OUT &= ~D4_PIN_BIT;

if(((cmd)&D5_MASK) == D5_MASK)
    D5_PIN_OUT |= D5_PIN_BIT;
else
    D5_PIN_OUT &= ~D5_PIN_BIT;

if(((cmd)&D6_MASK) == D6_MASK)
    D6_PIN_OUT |= D6_PIN_BIT;
else
    D6_PIN_OUT &= ~D6_PIN_BIT;

if(((cmd)&D7_MASK) == D7_MASK)
    D7_PIN_OUT |= D7_PIN_BIT;
else
    D7_PIN_OUT &= ~D7_PIN_BIT;

data_write(); // give enable trigger
delay_us(80);

}



void send_data(unsigned char data)
{
check_busy();
WRITE;
DR;

if(((data>>4)&D4_MASK) == D4_MASK)
    D4_PIN_OUT |= D4_PIN_BIT;
else
    D4_PIN_OUT &= ~D4_PIN_BIT;

if(((data>>4)&D5_MASK) == D5_MASK)
    D5_PIN_OUT |= D5_PIN_BIT;
else
    D5_PIN_OUT &= ~D5_PIN_BIT;

if(((data>>4)&D6_MASK) == D6_MASK)
    D6_PIN_OUT |= D6_PIN_BIT;
else
    D6_PIN_OUT &= ~D6_PIN_BIT;

if(((data>>4)&D7_MASK) == D7_MASK)
    D7_PIN_OUT |= D7_PIN_BIT;
else
    D7_PIN_OUT &= ~D7_PIN_BIT;
data_write(); // give enable trigger


if(((data)&D4_MASK) == D4_MASK)
    D4_PIN_OUT |= D4_PIN_BIT;
else
    D4_PIN_OUT &= ~D4_PIN_BIT;

if(((data)&D5_MASK) == D5_MASK)
    D5_PIN_OUT |= D5_PIN_BIT;
else
    D5_PIN_OUT &= ~D5_PIN_BIT;

if(((data)&D6_MASK) == D6_MASK)
    D6_PIN_OUT |= D6_PIN_BIT;
else
    D6_PIN_OUT &= ~D6_PIN_BIT;

if(((data)&D7_MASK) == D7_MASK)
    D7_PIN_OUT |= D7_PIN_BIT;
else
    D7_PIN_OUT &= ~D7_PIN_BIT;


data_write(); // give enable trigger
delay_us(80);
}


char send_string(char *s)
{
    char length = 0;
    delay_us(4);

    while(*s)
    {
        send_data(*s);
        s++;
        length++;
    }
    delay_us(4);
    return length;
}



char send_integer(unsigned long int number)
{
    delay_us(3);

    unsigned char array[25]={0};
    unsigned char digit_number=0;
    unsigned char array_eleman=0;
    unsigned char cnt=0;
   do{
       array[array_eleman++]=number%10;
       number=number/10;
       digit_number++;
   }while(number>0);

  for(cnt=digit_number;cnt>0;cnt--)
  {
      send_data(48+array[cnt-1]);

  }
  return digit_number;
}


void lcd_pin_init(void){

    // F-sense için:
    //REG_EN_PIN_DIR |= REG_EN_PIN_BIT;
    //BOOST_EN_PIN_DIR |= BOOST_EN_PIN_BIT;


    D4_PIN_DIR |= D4_PIN_BIT;
    D5_PIN_DIR |= D5_PIN_BIT;
    D6_PIN_DIR |= D6_PIN_BIT;
    D7_PIN_DIR |= D7_PIN_BIT;

    RS_PIN_DIR      |= RS_PIN_BIT;
    R_W_PIN_DIR     |= R_W_PIN_BIT;
    LCD_EN_PIN_DIR  |= LCD_EN_PIN_BIT;

    D4_PIN_OUT &= ~D4_PIN_BIT;
    D5_PIN_OUT &= ~D5_PIN_BIT;
    D6_PIN_OUT &= ~D6_PIN_BIT;
    D7_PIN_OUT &= ~D7_PIN_BIT;

    // F-sense için:
    //REG_EN_PIN_OUT |= REG_EN_PIN_BIT;
    //BOOST_EN_PIN_OUT |= BOOST_EN_PIN_BIT;

    RS_PIN_OUT      &= ~RS_PIN_BIT;
    R_W_PIN_OUT     &= ~R_W_PIN_BIT;
    LCD_EN_PIN_OUT  &= ~LCD_EN_PIN_BIT;
}


void lcd_init(void)
{

lcd_pin_init();
send_command(0x33);
send_command(0x32);
send_command(0x28); // 4 bit mode
//send_command(0x0E); // display on cursor on
send_command(0x0C); // display on cursor off blink off
send_command(0x01); // clear the screen
send_command(0x06); // increment to right cursor
send_command(0x80); // row 1 column 1
delay_us(80);
}
void lcd_save()
{
send_command(0x33);
send_command(0x32);
send_command(0x28); // 4 bit mode
//send_command(0x0E); // display on cursor on
send_command(0x0C); // display on cursor off blink off
send_command(0x01); // clear the screen
send_command(0x06); // increment to right cursor
send_command(0x80); // row 1 column 1
delay_us(80);
}


void lcd_go_to_addr(unsigned char addr)
{
    unsigned char cmd = 0x80 | addr;
    RS_PIN_OUT      &= ~RS_PIN_BIT;
    R_W_PIN_OUT     &= ~R_W_PIN_BIT;
    send_command(cmd);

}

void lcd_Go_To_X_Y(char x, char y)
{
  char addr;
  switch(x)
  {
     case 0: addr = 0x00; break; //Starting address of 1st line
     case 1: addr = 0x40; break; //Starting address of 2nd line
     case 2: addr = 0x14; break; //Starting address of 3rd line
     case 3: addr = 0x54; break; //Starting address of 4th line
     default: ;
  }

  addr +=y;

  lcd_go_to_addr(addr);
 // RS_PIN_OUT      |= RS_PIN_BIT;
}

void setLCDCursorPosition(u8 x, u8 y)
{
    lcd_Go_To_X_Y(x,y);
  //  system_status.main_menu_lcd_cursor_pos = x;
}

void resetLCDCursorPosition()
{
    setLCDCursorPosition(0,0);
    //  system_status.main_menu_lcd_cursor_pos = x;
}


void clearLCD() {
    // Clear the entire display by sending the clear command
    send_command(0x01);

    // Return the cursor to the home position
    lcd_Go_To_X_Y(0, 0);
}



/*
void clearLCD(){

        lcd_save();
        resetLCDCursorPosition();
        send_string(empty_row);
        __delay_cycles(16000000);

        setLCDCursorPosition(1,0);
        send_string(empty_row);
        __delay_cycles(16000000);

        //delay_us(30);

}
*/


/*
void setLCDLight(char action)
{
    switch(action)
    {
    case ENABLE:
        startTimeout_ms(LCD_BRIGHT_TO, LCD_OFF_TIMER);
        if(system_status.system_battery_active_flag == FALSE){
            startTimeout_ms(LCD_RESULTS_TO, LCD_BACK_TO_RESULTS_TIMER);
            ENABLE_BRIGHTNESS;
        }
        system_status.lcd_flag = TRUE;
        break;

    case DISABLE:
        DISABLE_BRIGHTNESS;
        if(system_status.system_battery_active_flag == TRUE){
            system_status.lcd_flag = FALSE;
        }
        break;
    }
}
*/

