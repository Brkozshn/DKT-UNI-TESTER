/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : main.h
* Author             : Burak Ozsahin
* Version            : V1.0.0
* Date               : 21/08/2023
* Description        : main header
********************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_


#define CLEAR_INTERRUPTS    _BIC_SR(GIE)
#define RESTORE_INTERRUPTS  _BIS_SR(GIE)


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed short int s16;
typedef signed long int s32;

typedef volatile unsigned char vu8;
typedef volatile unsigned short int vu16;
typedef volatile unsigned long int vu32;

typedef volatile unsigned int vui16;

typedef volatile signed char vs8;
typedef volatile signed short int vs16;
typedef volatile signed long int vs32;


#define ENABLE  1
#define DISABLE 0

#define TRUE    1
#define FALSE   0


// Define the timeout period in milliseconds (10 seconds) adjustment is made
#define TIMEOUT_PERIOD 70000                   // 10 seconds
#define TIME_ELAPSED 3500                       // 100 milliseconds
#define CASE_TIME 14000                        // 2 seconds.
#define LCD_TIME 7000                          // 1 second.
#define SUCCESS_DELAY_TIME 1000            // success delay time


typedef struct system_status_s
{
    u32 timer_lcd;                       // LCD fonksiyonlarý için gereken süre.
    u8 Threshold_Control;
    u32 caseCounter;                      // Her case'in tamamlanmasý için gereken süre
    u32 i_o_timeElapsed;                  // Her case'in tamamlanmasý için gereken süre
    u8 testState;                         // Hangi case'de olduðumuzu belirleyen deðiþken
    u8 testStateHolder;                    // Her state içinde arttýrdýktan sonra testState deðerini bunun içine at.
    u8 inputOutputTransition;             // Input ve output arasýndaki geçiþ deðiþkeni (100 ms)
    u32 counter_ms;                         // ms cinsinden counter sayacý
    u32 counter_s;                          // s cinsinden counter sayacý
    u32 counter_LCD;                        // Lcd için counter sayacý
    u16 input_error;                        // Inputlar için error
}system_status_t;


system_status_t system_status;



extern void hardware_init(void);
extern void software_init(void);
extern void initSystem();
extern void task_manager(void);
extern void buzzer_control();
extern void input_process(void);
extern void All_Relay_Close();
extern void Test_All_Relay();
extern void input_control();
extern void input_control_one_by_one(u8 input_name,u8 input_to);

extern void start_test();
extern void transitionFunction();
extern u8 output_reset();
extern void system_reset();
extern void checkStartButton();
extern void security_But1();

// DKT-TESTER için eklenen func.

extern void check_Input_Off();
extern void check_Input_Lowidle();
extern void check_Input_Mute();
extern void check_Input_Signal1();
extern void check_Input_Signal2();
extern void check_Input_Signal3();
extern void check_Input_Signal4();
extern void check_Input_Signal5();
extern void check_Input_Signal6();
extern void check_Input_All_Low_High();
extern void check_Input_Reset();
extern void check_Input_Ok();

// Functions For LCD

extern void lcd_pin_init();
extern char send_integer(unsigned long int number);
extern void lcd_init();
extern void lcd_save();
extern char send_string(char *s);
extern void send_data(unsigned char data);
extern void delay(unsigned int k);
extern void lcd_Go_To_X_Y(char x, char y);
extern void LCD_SendCmd(unsigned char cmd);
extern void LCD_SendData(unsigned char data);
extern void LCD_Clear();
extern void LCD_WriteString(const char *str);
extern void clearLCD();
extern  void Software_Trim();

// Added from F-sense


// Functions for giving an error message.

extern void input_Error(u16 Error_signal_Flag);
extern  void output_Error(u16 Error_signal_Flag);
extern void state_Error(u16 testFlag);
extern void timeout_Error();
extern void resetButton_Error();
extern void muteButton_Error();
extern void start_TestMessage();
extern void start_TestError();
extern void state_Success(u16 testFlag);
extern void button1_Error();
extern void button1_Success();
extern void testButton_Success();
extern void resetButton_Success();
extern void muteButton_Success();

extern void All_Test_Completed();
extern void Fail();
extern void Fatal_Error();


// Created for easy access.



// Timer Functions

extern void init_Timer();
extern  void Timer_run();




// Yeni yazýlan fonksiyonlarý buraya ekle.

extern void reset_LEDs();
extern void LEDs_ON();
extern void reset_RELAYs();
extern void reset_pressed_flags();
extern void horn_pin_status(u8 status);
extern void buzzer_select_pin_status(u8 status);
extern void buzzer_alarm(u16 alarm_ms, u8 repeat_cnt);
extern void Trip_pin_status(u8 status);
extern void LED_pin_status(u8 led_port,u8 led_pin, u8 status);
extern void LED_Blink(vui16 *led_port,u8 led_pin);

#endif /* MAIN_H_ */
