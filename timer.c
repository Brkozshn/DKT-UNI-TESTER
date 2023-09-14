/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : timer.c
* Author             : Burak Ozsahin
* Version            : V1.0
* Date               : 08/09/2023
* Description        : timer functions
********************************************************************************/



#include <msp430.h>
#include "main.h"
#include "bsp.h"
#include "button.h"
#include "lcd.h"



#define TIMER_1SEC_VALUE 200
#define TIMER_05SEC_VALUE TIMER_1SEC_VALUE / 2
#define TIMER_2SEC_VALUE TIMER_1SEC_VALUE * 2



 void  init_Timer()
{
    WDTCTL = WDTPW + WDTHOLD;   // Stop the watchdog timer

    // Initialize system_status counters

    system_status.counter_s = 0;
    system_status.counter_ms = 0;
    system_status.counter_LCD = 0;

    // Configure Timer A0 for 100ms intervals
    TA0CCR0 = 10000;            // Set the timer period
    TA0CCTL0 |= CCIE;           // Enable Timer A0 interrupt
    TA0CTL = TASSEL_2 + MC_1;   // Timer source: SMCLK, Mode: Up to CCR0
}


 void Timer_run() {

     // Initialize your LCD and other peripherals here

     while(1)
     {
         // Print the counter for 1 seconds
         if (system_status.counter_s >= TIMER_1SEC_VALUE) {

             lcd_Go_To_X_Y(0,0);
             send_string("s_Value: ");
             //__delay_cycles(100000);

             lcd_Go_To_X_Y(0,11);
             send_integer(system_status.counter_s);
             //__delay_cycles(1000000);

             system_status.counter_s = 0;
         }

         // Print the counter  for 2 seconds
          if ( system_status.counter_ms >= TIMER_2SEC_VALUE) {

            lcd_Go_To_X_Y(1,1);
            send_string("ms_Value: ");
            //__delay_cycles(100000);

            lcd_Go_To_X_Y(1,11);
            send_integer(system_status.counter_ms);
            //__delay_cycles(1000000);


            system_status.counter_ms = 0;
         }

          __delay_cycles(100000);
          clearLCD();
     }
 }



 // Timer A0 interrupt service routine
 #if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
 #pragma vector = TIMER0_A0_VECTOR
 __interrupt void Timer_A (void)
 #elif defined(__GNUC__)
 void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
 #else
 #error Compiler not supported!
 #endif
 {
    // Increment the counter_s every 1 second
    system_status.counter_s++;
    system_status.counter_ms++;
    system_status.counter_LCD++;
}




