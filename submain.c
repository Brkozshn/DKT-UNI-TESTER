/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : submain.c
* Author             : Burak Ozsahin
* Version            : V1.0
* Date               : 21/08/2023
* Description        : submain functions
********************************************************************************/


#include <msp430.h>
#include "bsp.h"
#include "main.h"
#include "button.h"
#include "lcd.h"



 /*  Function    : init_GPIO
  *  Inputs      : -
  *  Return      : -
  *  Desc        : all I/O pins's initialization calRELAY here.
  */

 void init_GPIO()
 {

     /* Watchdog Init */

     WDTCTL = WDTPW + WDTHOLD;       // Stop WDT

     SFRRPCR |= SYSNMIIES | SYSNMI;            // Select NMI function for the RST/NMI pin,
                                              // interrupt on falling edge

     /*All Port Close*/
     P1OUT = 0x00;
     P2OUT = 0x00;
     P3OUT = 0x00;
     P4OUT = 0x00;
     P5OUT = 0x00;


     /* OUTPUTS*/
     BASE1_DIR       |=  BASE1_PIN;
     BASE2_DIR       |=  BASE2_PIN;
     BASE3_DIR       |=  BASE3_PIN;
     BASE4_DIR       |=  BASE4_PIN;
     BASE5_DIR       |=  BASE5_PIN;
     BASE6_DIR       |=  BASE6_PIN;

     HIGH_POWER_DIR  |=  HIGH_POWER_PIN;
     LOW_POWER_DIR   |=  LOW_POWER_PIN;

     RESET_OUT_DIR   |=  RESET_OUT_PIN;
     TEST_OUT_DIR    |=  TEST_OUT_PIN;
     MUTE_OUT_DIR    |=  MUTE_OUT_PIN;


     /*INPUTS*/
     LS1_DIR       &= ~LS1_PIN;
     LS2_DIR       &= ~LS2_PIN;
     LS3_DIR       &= ~LS3_PIN;
     LS4_DIR       &= ~LS4_PIN;
     LS5_DIR       &= ~LS5_PIN;
     LS6_DIR       &= ~LS6_PIN;

     // Tester için:

     TRIP1_DIR     &= ~TRIP1_PIN;
     TRIP2_DIR    &= ~TRIP2_PIN;
     HORN_DIR     &= ~HORN_PIN;

     MUTE_DIR     &= ~MUTE_PIN;
     RESET_DIR    &= ~RESET_PIN;
     TEST_DIR     &= ~TEST_PIN;
     START_DIR     &= ~START_PIN;
     BUTTON1_DIR     &= ~BUTTON1_PIN;


 /*iþlemci içerisinde input dirençlerini pull up olarak set ettik.*/


     //   P1OUT &= ~BIT3;                          // Configure P1.3 as pulRELAY-down
     //   P1REN |=  BIT3;                          // P1.3 pull-up register enable
/*

     LS1_REN    |= LS1_PIN;                            // Enable P2.0 internal resistance
     LS1_PORT   |= LS1_PIN;                            // Set P2.0 as pull-Up resistance

     LS2_REN    |= LS2_PIN;                            // Enable P2.1 internal resistance
     LS2_PORT   |= LS2_PIN;                            // Set P2.1 as pull-Up resistance

     LS3_REN    |= LS3_PIN;                            // Enable P2.2 internal resistance
     LS3_PORT   |= LS3_PIN;                            // Set P2.2 as pull-Up resistance

     LS4_REN    |= LS4_PIN;                            // Enable P2.3 internal resistance
     LS4_PORT   |= LS4_PIN;                            // Set P2.3 as pull-Up resistance

     LS5_REN    |= LS5_PIN;                            // Enable P2.4 internal resistance
     LS5_PORT   |= LS5_PIN;                            // Set P2.4 as pull-Up resistance

     LS6_REN    |= LS6_PIN;                            // Enable P2.5 internal resistance
     LS6_PORT   |= LS6_PIN;                            // Set P2.5 as pull-Up resistance

     MUTE_REN  |= MUTE_PIN;                            // Enable P1.1 internal resistance
     MUTE_PORT |= MUTE_PIN;                            // Set P1.1 as pull-Up resistance

     RESET_REN |= RESET_PIN;                            // Enable P3.1 internal resistance
     RESET_PORT|= RESET_PIN;                            // Set P3.1 as pull-Up resistance

     TEST_REN  |= TEST_PIN;                            // Enable P3.0 internal resistance
     TEST_PORT |= TEST_PIN;                            // Set P3.0 as pull-Up resistance


     // Tester için eklenenler.

     TRIP1_REN  |= TRIP1_PIN;                            // Enable P1.1 internal resistance
     TRIP1_PORT |= TRIP1_PIN;                            // Set P1.1 as pull-Up resistance

     TRIP2_REN |= TRIP2_PIN;                            // Enable P3.1 internal resistance
     TRIP2_PORT|= TRIP2_PIN;                            // Set P3.1 as pull-Up resistance

     HORN_REN  |= HORN_PIN;                            // Enable P3.0 internal resistance
     HORN_PORT |= HORN_PIN;                            // Set P3.0 as pull-Up resistance

     START_REN  |= START_PIN;                            // Enable P3.0 internal resistance
     START_PORT |= START_PIN;                            // Set P3.0 as pull-Up resistance

     BUTTON1_REN  |= BUTTON1_PIN;                            // Enable P3.0 internal resistance
     BUTTON1_PORT |= BUTTON1_PIN;                            // Set P3.0 as pull-Up resistance

*/

     /*END OF INPUTS*/

     PM5CTL0 &= ~LOCKLPM5;                    // Disable the GPIO power-on default high-impedance mode
 }


 ///////// LCD için eklendi 16 MHz ayarlarý için.


 /*  Function    : Software_Trim
  *  Inputs      : -
  *  Return      : -
  *  Desc        : default function.
  */


 void Software_Trim()
 {
     unsigned int oldDcoTap = 0xffff;
     unsigned int newDcoTap = 0xffff;
     unsigned int newDcoDelta = 0xffff;
     unsigned int bestDcoDelta = 0xffff;
     unsigned int csCtl0Copy = 0;
     unsigned int csCtl1Copy = 0;
     unsigned int csCtl0Read = 0;
     unsigned int csCtl1Read = 0;
     unsigned int dcoFreqTrim = 3;
     unsigned char endLoop = 0;

     do
     {
         CSCTL0 = 0x100;                         // DCO Tap = 256
         do
         {
             CSCTL7 &= ~DCOFFG;                  // Clear DCO fault flag
         }while (CSCTL7 & DCOFFG);               // Test DCO fault flag

         __delay_cycles((unsigned int)3000 * MCLK_FREQ_MHZ);// Wait FLL lock status (FLLUNLOCK) to be stable
                                                            // Suggest to wait 24 cycles of divided FLL reference clock
         while((CSCTL7 & (FLLUNLOCK0 | FLLUNLOCK1)) && ((CSCTL7 & DCOFFG) == 0));

         csCtl0Read = CSCTL0;                   // Read CSCTL0
         csCtl1Read = CSCTL1;                   // Read CSCTL1

         oldDcoTap = newDcoTap;                 // Record DCOTAP value of last time
         newDcoTap = csCtl0Read & 0x01ff;       // Get DCOTAP value of this time
         dcoFreqTrim = (csCtl1Read & 0x0070)>>4;// Get DCOFTRIM value

         if(newDcoTap < 256)                    // DCOTAP < 256
         {
             newDcoDelta = 256 - newDcoTap;     // Delta value between DCPTAP and 256
             if((oldDcoTap != 0xffff) && (oldDcoTap >= 256)) // DCOTAP cross 256
                 endLoop = 1;                   // Stop while loop
             else
             {
                 dcoFreqTrim--;
                 CSCTL1 = (csCtl1Read & (~DCOFTRIM)) | (dcoFreqTrim<<4);
             }
         }
         else                                   // DCOTAP >= 256
         {
             newDcoDelta = newDcoTap - 256;     // Delta value between DCPTAP and 256
             if(oldDcoTap < 256)                // DCOTAP cross 256
                 endLoop = 1;                   // Stop while loop
             else
             {
                 dcoFreqTrim++;
                 CSCTL1 = (csCtl1Read & (~DCOFTRIM)) | (dcoFreqTrim<<4);
             }
         }

         if(newDcoDelta < bestDcoDelta)         // Record DCOTAP closest to 256
         {
             csCtl0Copy = csCtl0Read;
             csCtl1Copy = csCtl1Read;
             bestDcoDelta = newDcoDelta;
         }

     }while(endLoop == 0);                      // Poll until endLoop == 1

     CSCTL0 = csCtl0Copy;                       // Reload locked DCOTAP
     CSCTL1 = csCtl1Copy;                       // Reload locked DCOFTRIM
     while(CSCTL7 & (FLLUNLOCK0 | FLLUNLOCK1)); // Poll until FLL is locked
 }



 /*  Function    : hardware_init
  *  Inputs      : -
  *  Return      : -
  *  Desc        : all hardware initialization calRELAY here.
  */


 void hardware_init(void)
 {

     // Default'da 1 Mhz ayarlanýyor birþey yazmamýza gerek yok deðiþtirmek için aþaðýyý aç

     /*

     __bis_SR_register(SCG0);                                       // disable FLL
     CSCTL3 |= SELREF__REFOCLK;                                     // Set REFO as FLL reference source
     CSCTL1 = DCOFTRIMEN_1 | DCOFTRIM0 | DCOFTRIM1 | DCORSEL_5;     // DCOFTRIM=5, DCO Range = 16MHz
     CSCTL2 = FLLD_0 + 487;


     //       CSCTL1 = DCOFTRIMEN_1 | DCOFTRIM0 | DCOFTRIM1 | DCORSEL_3;// DCOFTRIM=3, DCO Range = 8MHz
     //       CSCTL2 = FLLD_0 + 243;                  // DCODIV = 8MHz
     __delay_cycles(3);
     __bic_SR_register(SCG0);                // enable FLL
     Software_Trim();                        // Software Trim to get the best DCOFTRIM value

     */

     init_GPIO();
     init_Timer();
     lcd_init();
     __bis_SR_register(GIE);
 }


 /*  Function    : software_init
  *  Inputs      : -
  *  Return      : -
  *  Desc        : all software initialization calRELAY here.
  */


 void software_init(void)
 {

     system_status.caseCounter = 0;
     system_status.testState = OFF;
     system_status.testStateHolder = OFF;
     system_status.inputOutputTransition = 0;




     input_check_point[LS1].LASTVALUE                  =   UNKNOWN;
     input_check_point[LS1].BUTTON_RELEASED_CONFIG     =   LS1_RELEASED_CFG;
     input_check_point[LS1].BUTTON_PRESSED_CONFIG      =   LS1_PRESSED_CFG;
     input_check_point[LS1].BUTTON_MASK                =   LS1_MASK;
     input_check_point[LS1].BUTTON_PORT_IN             =   &LS1_IN;

     input_check_point[LS2].LASTVALUE                  =   UNKNOWN;
     input_check_point[LS2].BUTTON_RELEASED_CONFIG     =   LS2_RELEASED_CFG;
     input_check_point[LS2].BUTTON_PRESSED_CONFIG      =   LS2_PRESSED_CFG ;
     input_check_point[LS2].BUTTON_MASK                =   LS2_MASK;
     input_check_point[LS2].BUTTON_PORT_IN             =   &LS2_IN;

     input_check_point[LS3].LASTVALUE                  =   UNKNOWN;
     input_check_point[LS3].BUTTON_RELEASED_CONFIG     =   LS3_RELEASED_CFG;
     input_check_point[LS3].BUTTON_PRESSED_CONFIG      =   LS3_PRESSED_CFG ;
     input_check_point[LS3].BUTTON_MASK                =   LS3_MASK;
     input_check_point[LS3].BUTTON_PORT_IN             =   &LS3_IN;

     input_check_point[LS4].LASTVALUE                  =   UNKNOWN;
     input_check_point[LS4].BUTTON_RELEASED_CONFIG     =   LS4_RELEASED_CFG;
     input_check_point[LS4].BUTTON_PRESSED_CONFIG      =   LS4_PRESSED_CFG ;
     input_check_point[LS4].BUTTON_MASK                =   LS4_MASK;
     input_check_point[LS4].BUTTON_PORT_IN             =   &LS4_IN;

     input_check_point[LS5].LASTVALUE                  =   UNKNOWN;
     input_check_point[LS5].BUTTON_RELEASED_CONFIG     =   LS5_RELEASED_CFG;
     input_check_point[LS5].BUTTON_PRESSED_CONFIG      =   LS5_PRESSED_CFG ;
     input_check_point[LS5].BUTTON_MASK                =   LS5_MASK;
     input_check_point[LS5].BUTTON_PORT_IN             =   &LS5_IN;

     input_check_point[LS6].LASTVALUE                  =   UNKNOWN;
     input_check_point[LS6].BUTTON_RELEASED_CONFIG     =   LS6_RELEASED_CFG;
     input_check_point[LS6].BUTTON_PRESSED_CONFIG      =   LS6_PRESSED_CFG ;
     input_check_point[LS6].BUTTON_MASK                =   LS6_MASK;
     input_check_point[LS6].BUTTON_PORT_IN             =   &LS6_IN;

    input_check_point[TRIP1].LASTVALUE                =   UNKNOWN;
    input_check_point[TRIP1].BUTTON_RELEASED_CONFIG   =   TRIP1_RELEASED_CFG;
    input_check_point[TRIP1].BUTTON_PRESSED_CONFIG    =   TRIP1_PRESSED_CFG ;
    input_check_point[TRIP1].BUTTON_MASK              =   TRIP1_MASK;
    input_check_point[TRIP1].BUTTON_PORT_IN           =   &TRIP1_IN;

    input_check_point[TRIP2].LASTVALUE                =   UNKNOWN;
    input_check_point[TRIP2].BUTTON_RELEASED_CONFIG   =   TRIP2_RELEASED_CFG;
    input_check_point[TRIP2].BUTTON_PRESSED_CONFIG    =   TRIP2_PRESSED_CFG ;
    input_check_point[TRIP2].BUTTON_MASK              =   TRIP2_MASK;
    input_check_point[TRIP2].BUTTON_PORT_IN           =   &TRIP2_IN;

    input_check_point[HORN].LASTVALUE                =   UNKNOWN;
    input_check_point[HORN].BUTTON_RELEASED_CONFIG   =   HORN_RELEASED_CFG;
    input_check_point[HORN].BUTTON_PRESSED_CONFIG    =   HORN_PRESSED_CFG ;
    input_check_point[HORN].BUTTON_MASK              =   HORN_MASK;
    input_check_point[HORN].BUTTON_PORT_IN           =   &HORN_IN;

     input_check_point[MUTE].LASTVALUE                =   UNKNOWN;
     input_check_point[MUTE].BUTTON_RELEASED_CONFIG   =   MUTE_RELEASED_CFG;
     input_check_point[MUTE].BUTTON_PRESSED_CONFIG    =   MUTE_PRESSED_CFG ;
     input_check_point[MUTE].BUTTON_MASK              =   MUTE_MASK;
     input_check_point[MUTE].BUTTON_PORT_IN           =   &MUTE_IN;

     input_check_point[RESET].LASTVALUE               =   UNKNOWN;
     input_check_point[RESET].BUTTON_RELEASED_CONFIG  =   RESET_RELEASED_CFG;
     input_check_point[RESET].BUTTON_PRESSED_CONFIG   =   RESET_PRESSED_CFG ;
     input_check_point[RESET].BUTTON_MASK             =   RESET_MASK;
     input_check_point[RESET].BUTTON_PORT_IN          =   &RESET_IN;

     input_check_point[TEST].LASTVALUE                =   UNKNOWN;
     input_check_point[TEST].BUTTON_RELEASED_CONFIG   =   TEST_RELEASED_CFG;
     input_check_point[TEST].BUTTON_PRESSED_CONFIG    =   TEST_PRESSED_CFG ;
     input_check_point[TEST].BUTTON_MASK              =   TEST_MASK;
     input_check_point[TEST].BUTTON_PORT_IN           =   &TEST_IN;

     input_check_point[START].LASTVALUE                =   UNKNOWN;
     input_check_point[START].BUTTON_RELEASED_CONFIG   =  START_RELEASED_CFG;
     input_check_point[START].BUTTON_PRESSED_CONFIG    =  START_PRESSED_CFG ;
     input_check_point[START].BUTTON_MASK              =  START_MASK;
     input_check_point[START].BUTTON_PORT_IN           =  &START_IN;

     // Güvenlik Switch'i button1

     input_check_point[BUTTON1].LASTVALUE                =   UNKNOWN;
     input_check_point[BUTTON1].BUTTON_RELEASED_CONFIG   =  BUTTON1_RELEASED_CFG;
     input_check_point[BUTTON1].BUTTON_PRESSED_CONFIG    =  BUTTON1_PRESSED_CFG ;
     input_check_point[BUTTON1].BUTTON_MASK              =  BUTTON1_MASK;
     input_check_point[BUTTON1].BUTTON_PORT_IN           =  &BUTTON1_IN;


/*
     start_timeout_ms(LS1_TO ,LS1_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(LS2_TO ,LS2_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(LS3_TO ,LS3_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(LS4_TO ,LS4_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(LS5_TO ,LS5_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(LS6_TO ,LS6_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(MUTE_TO ,MUTE_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(RESET_TO ,RESET_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(TEST_TO ,TEST_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor
     start_timeout_ms(TRIPPING_TO ,TRIPPING_INPUT_MS);//sistem baþlangýcýnda bir kere çaðýrýlmasý gerekiyor

*/

     reset_pressed_flags();
     pressed_flag[BUTTON1]=FALSE;

 }

 /*  Function    : initSystem
  *  Inputs      : -
  *  Return      : -
  *  Desc        : Ýnitializes the whole system requirements.
  */

void initSystem()
{
    hardware_init();
    software_init();
}


 /*  Function    : reset_pressed_flags
  *  Inputs      : -
  *  Return      : -
  *  Desc        : All pressed flag  false.
  */



 void reset_pressed_flags()
 {

    pressed_flag[LS1]=FALSE;
    pressed_flag[LS2]=FALSE;
    pressed_flag[LS3]=FALSE;
    pressed_flag[LS4]=FALSE;
    pressed_flag[LS5]=FALSE;
    pressed_flag[LS6]=FALSE;

    pressed_flag[TRIP1]=FALSE;
    pressed_flag[TRIP2]=FALSE;
    pressed_flag[HORN]=FALSE;

    pressed_flag[MUTE]=FALSE;
    pressed_flag[RESET]=FALSE;
    pressed_flag[TEST]=FALSE;
    pressed_flag[HORN]=FALSE;
    pressed_flag[START]=FALSE;
    //pressed_flag[BUTTON1]=FALSE;


    // Test flags (S1,S2,S3 ... )

    testFlag[OFF] = FALSE;
    testFlag[LOW_IDLE] = FALSE;
    testFlag[SIGNAL1] = FALSE;
    testFlag[MUTE_STATE] = FALSE;
    testFlag[SIGNAL2] = FALSE;
    testFlag[SIGNAL3] = FALSE;
    testFlag[SIGNAL4] = FALSE;
    testFlag[SIGNAL5] = FALSE;
    testFlag[SIGNAL6] = FALSE;
    testFlag[ALL_LOW] = FALSE;
    testFlag[ALL_HIGH] = FALSE;
    testFlag[RESET_STATE] = FALSE;
    testFlag[OK] = FALSE;
    testFlag[FAIL] = FALSE;


    // Error signal flags (LS1, LS2, TRIP1, TRIP2) check if any error is occured.

    Error_signal_Flag[LS1] = FALSE;
    Error_signal_Flag[LS2] = FALSE;
    Error_signal_Flag[LS3] = FALSE;
    Error_signal_Flag[LS4] = FALSE;
    Error_signal_Flag[LS5] = FALSE;
    Error_signal_Flag[LS6] = FALSE;
    Error_signal_Flag[TRIP1] = FALSE;
    Error_signal_Flag[TRIP2] = FALSE;
    Error_signal_Flag[HORN] = FALSE;

 }


 /*  Function    : Low_idle_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an output to the Low_idle state.
  */


 void Low_idle_Out() {

     // Low_idle için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;

 }


 /*  Function    : Signal1_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output to the Signal1 state.
  */


 void Signal1_Out() {

     // Signal1 için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;
     BASE1_PORT |= BASE1_PIN;

 }


 /*  Function    : Mute_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output to the Mute state.
  */


 void Mute_Out() {

     // Mute için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;
     MUTE_OUT_PORT |= MUTE_OUT_PIN;

 }


 /*  Function    : Signal2_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        : Giving an Output the Signal2 state.
  */


 void Signal2_Out() {

     // Signal2 için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;
     BASE2_PORT |= BASE2_PIN;

 }


 /*  Function    : Signal3_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output the Signal3 state.
  */

 void Signal3_Out() {

     // S3 için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;
     BASE3_PORT |= BASE3_PIN;

 }



 /*  Function    : Signal4_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output the Signal4 state.
  */


 void Signal4_Out() {

     // Signal4 için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;
     BASE4_PORT |= BASE4_PIN;

 }



 /*  Function    : Signal5_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output to the Signal5 state.
  */


 void Signal5_Out() {

     // Signal5 için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;
     BASE5_PORT |= BASE5_PIN;
 }



 /*  Function    : Signal6_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output to the Signal6 state.
  */


 void Signal6_Out() {

     // Signal6 için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;
     BASE6_PORT |= BASE6_PIN;
 }



 /*  Function    : All_Low_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output the All_Low_Out state.
  */


 void All_Low_Out() {

     // All_Low_Out için çýkýþ vereceðiz.

     HIGH_POWER_PORT &= ~HIGH_POWER_PIN;                 // Hata vermemesi için önlem.

     while (system_status.i_o_timeElapsed < LCD_TIME)
     {
           transitionFunction();
     }

     LOW_POWER_PORT |= LOW_POWER_PIN;
     BASE1_PORT |= BASE1_PIN;
     BASE2_PORT |= BASE2_PIN;
     BASE3_PORT |= BASE3_PIN;
     BASE4_PORT |= BASE4_PIN;
     BASE5_PORT |= BASE5_PIN;
     BASE6_PORT |= BASE6_PIN;

 }



 /*  Function    : All_High_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output reset of the All_High_Out state.
  */


 void All_High_Out() {

     // All_High_Out için çýkýþ vereceðiz.

     LOW_POWER_PORT &= ~LOW_POWER_PIN;                     // Hata vermemesi için önlem.

     while (system_status.i_o_timeElapsed < LCD_TIME)
     {
           transitionFunction();
     }

     HIGH_POWER_PORT |= HIGH_POWER_PIN;
     BASE1_PORT |= BASE1_PIN;
     BASE2_PORT |= BASE2_PIN;
     BASE3_PORT |= BASE3_PIN;
     BASE4_PORT |= BASE4_PIN;
     BASE5_PORT |= BASE5_PIN;
     BASE6_PORT |= BASE6_PIN;
 }



 /*  Function    : Reset_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Giving an Output to the Reset test.
  */


 void Reset_Out()
 {
     // Reset için çýkýþ vereceðiz.

         RESET_OUT_PORT |= RESET_OUT_PIN;
         LOW_POWER_PORT |= LOW_POWER_PIN;

 }



 /*  Function    : test_reset_mute_flags
  *  Inputs      : -
  *  Return      : -
  *  Desc        :   Test, Reset, Mute flags activated..
  */




 void test_reset_mute_flags()
 {
     // Test, Reset, Mute buttons flags are active.

     pressed_flag[MUTE]=TRUE;
     pressed_flag[RESET]=TRUE;
     pressed_flag[TEST]=TRUE;
     pressed_flag[START]=TRUE;

 }



 /*  Function    : Ok_Out
  *  Inputs      : -
  *  Return      : -
  *  Desc        :  Output reset of the Ok test.
  */


 void Ok_Out()
 {

    // Ok için çýkýþ vereceðiz.

     LOW_POWER_PORT |= LOW_POWER_PIN;
     TEST_OUT_PORT |= TEST_OUT_PIN;

 }



 /// Input ve output case'leri ayrý olacak. start_test() fonksiyonunda ayrý case'lerde çaðýrýlacak.
/// S1,S2 ... S6 testlerindeki check_input fonksiyonlarý.



 /*  Function    : output_reset
  *  Inputs      : -
  *  Return      : general_status
  *  Desc        : Starting the S6 test.
  */

u8 output_reset()
 {

    u8  are_outs_resetted = FALSE;

     // All outputs must reset.

     BASE1_PORT &= ~BASE1_PIN;
     BASE2_PORT &= ~BASE2_PIN;
     BASE3_PORT &= ~BASE3_PIN;
     BASE4_PORT &= ~BASE4_PIN;
     BASE5_PORT &= ~BASE5_PIN;
     BASE6_PORT &= ~BASE6_PIN;

     TEST_OUT_PORT &= ~TEST_OUT_PIN;
     MUTE_OUT_PORT &= ~MUTE_OUT_PIN;
     RESET_OUT_PORT &= ~RESET_OUT_PIN;

     //LOW_POWER_PORT &= ~ LOW_POWER_PIN;
     HIGH_POWER_PORT &= ~HIGH_POWER_PIN;

     // Turn off the leds
     LED_OK_PORT &= ~LED_OK_PIN;
     LED_FAIL_PORT &= ~LED_FAIL_PIN;

     are_outs_resetted = TRUE;

     return are_outs_resetted;
 }



 /*  Function    : areInputsReset()
  *  Inputs      : -
  *  Return      : -
  *  Desc        : Resets the Inputs.
  */


 u8 areInputsReset()
 {

   u8  are_inputs_resetted = FALSE;

         /*INPUTS*/

         LS1_PORT       &= ~LS1_PIN;
         LS2_PORT       &= ~LS2_PIN;
         LS3_PORT       &= ~LS3_PIN;
         LS4_PORT       &= ~LS4_PIN;
         LS5_PORT       &= ~LS5_PIN;
         LS6_PORT       &= ~LS6_PIN;

         // Lazým olabilir diye tanýmlandý.

         MUTE_PORT     &= ~MUTE_PIN;
         RESET_PORT    &= ~RESET_PIN;
         TEST_PORT     &= ~TEST_PIN;

         // Tester için:

         TRIP1_PORT     &= ~TRIP1_PIN;
         TRIP2_PORT    &= ~TRIP2_PIN;
         HORN_PORT     &= ~HORN_PIN;
         START_PORT     &= ~START_PIN;

         are_inputs_resetted = TRUE;                // inputlarý resetle

         return are_inputs_resetted;

  }


 /*  Function    : system_reset
  *  Inputs      : -
  *  Return      : -
  *  Desc        : Resets the system.
  */

 void system_reset() {

     u8 input_resetted = FALSE;
     system_status.testState = OFF;

 // Herþey burada resetlenecek.

         reset_pressed_flags();                                                 // Flagleri resetle
         output_reset();                                                        // outputlarý resetle
         input_resetted = areInputsReset();                                    // inputlarý resetle.

         if( input_resetted == TRUE) {

             return;
         }

         else
         {
             system_status.testState = FAIL;             // FAIL State'ine gidecek.
         }
     }


 /*  Function    : checkStartButton()
  *  Inputs      : -
  *  Return      : -
  *  Desc        : Checks the buttons are pressed respectively (test --> reset --> mute).
  */

void checkStartButton(){

    //Testin baþlamasý için sýrasýyla test, reset, mute butonlarýna basýlmalý.


    u8 test_status = RELEASED;
    u8 reset_status = RELEASED;
    u8 mute_status = RELEASED;


    while (system_status.caseCounter++ < TIMEOUT_PERIOD) {


        // if all buttons were pressed, start the test
        if ((mute_status == PRESSED || mute_status == AGAIN_PRESSED) &&
            (reset_status == PRESSED || reset_status == AGAIN_PRESSED) &&
            (test_status == PRESSED || test_status == AGAIN_PRESSED))
        {                                                                    // 3 sinyali de kontrol et
            pressed_flag[START] = TRUE;
            system_status.caseCounter = 0;

            start_TestMessage();

            //start_test();
            break;
        }


        test_status = Button_State_Func(&input_check_point[TEST]);
        if (test_status == PRESSED || test_status == AGAIN_PRESSED) {


            switch(test_status){

            case PRESSED:
            case AGAIN_PRESSED:
                //system_reset();
                pressed_flag[TEST] = TRUE;
                system_status.caseCounter = 0;
                testButton_Success();


                // Wait for Reset button press
                           while (system_status.caseCounter++ < TIMEOUT_PERIOD) {
                               reset_status = Button_State_Func(&input_check_point[RESET]);
                               if (reset_status == PRESSED || reset_status == AGAIN_PRESSED) {
                                   pressed_flag[RESET] = TRUE;
                                   system_status.caseCounter = 0; // Reset the counter
                                   resetButton_Success();
                                   break;
                               }
                           }

                           if(system_status.caseCounter >= TIMEOUT_PERIOD){            // 10 s içinde basýlmazsa baþa döner.

                               system_status.caseCounter = 0;
                               __no_operation();

                               // LCD ekrana yazdýrma.

                               resetButton_Error();                              // reset button error message.
                               system_reset();                                   // Bütün sistem sýfýrlandý.
                               return;
                           }


                system_status.caseCounter = 0;

                // Wait for Mute button press
                           while (system_status.caseCounter++ < TIMEOUT_PERIOD) {
                               mute_status = Button_State_Func(&input_check_point[MUTE]);
                               if (mute_status == PRESSED || mute_status == AGAIN_PRESSED) {
                                   pressed_flag[MUTE] = TRUE;
                                   system_status.caseCounter = 0; // Reset the counter
                                   muteButton_Success();
                                   break;
                               }
                           }

                           if(system_status.caseCounter >= TIMEOUT_PERIOD){               // 10 s içinde basýlmazsa baþa döner.

                               system_status.caseCounter = 0;
                               __no_operation();

                               // LCD ekrana yazdýrma.
                               muteButton_Error();
                               system_reset();                                   // Bütün sistem sýfýrlandý.
                               return;
                           }

                           // if all buttons were pressed, start the test
                           if ((mute_status == PRESSED || mute_status == AGAIN_PRESSED) &&
                               (reset_status == PRESSED || reset_status == AGAIN_PRESSED) &&
                               (test_status == PRESSED || test_status == AGAIN_PRESSED))
                           {                                                                    // 3 sinyali de kontrol et
                               pressed_flag[START] = TRUE;
                               system_status.caseCounter = 0;

                               start_TestMessage();

                               //start_test();
                               break;
                           }

                    default:
                break;
            }
        }
    }
}



/*  Function    : transitionFunction
 *  Inputs      : .
 *  Return      : -
 *  Desc        : Provides a transition.
 */


void transitionFunction()
{

    if(system_status.i_o_timeElapsed++ <= TIME_ELAPSED) {

       // system_status.waitCounter = 0;
        __no_operation();
    }
}


/*  Function    : start_test
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Starting the tests and check if it is completed or not.
 */


void start_test(){

    u8 are_outs_checked = FALSE;

    system_status.caseCounter = 0;
    system_status.i_o_timeElapsed = 0;
    system_status.inputOutputTransition = OUTPUT;


    if(pressed_flag[BUTTON1] == FALSE)
    {
        // LCD function yazýlacak. Ürün çýkarýldý yazýlacak.

        button1_Error();
        __no_operation();

        return;
    }

    if(pressed_flag[START] == FALSE)
    {
        start_TestError();
        return;
    }

    while (system_status.i_o_timeElapsed < TIME_ELAPSED)
    {
          transitionFunction();
    }


 // Önce output sonra input kontrol edilecek. CASE'lerin yerleri deðiþecek.


        switch(system_status.testState){

        case OFF:

            system_status.i_o_timeElapsed = 0;

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.

                check_Input_Off();

                if(testFlag[OFF] == TRUE)
                {
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testState = LOW_IDLE;

                 state_Success(OFF);

                 break;

                }

              else if (testFlag[OFF] == FALSE)
              {
                system_status.testState = FAIL;                     // FAIL State'ine gidecek.
                state_Error(OFF);                         // Printing out an Error message.

                return;
              }

                break;

            case OUTPUT:
                LOW_POWER_PORT &= ~ LOW_POWER_PIN;
                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.

                // burada output verme yok çünkü OFF state'inde

              if(are_outs_checked == TRUE)
              {
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.

                 output_Error(OFF);

                 return;
              }

                break;
            default:
                break;
            }
            __no_operation();
            if(system_status.testState != OFF)
            {
                __no_operation();
                break;
            }
            __no_operation();
            }

            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            // Bu kýsýmdaki delaylerim 1s kalmasýnda sakýnca olmayabilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.

                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case LOW_IDLE:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


                while (system_status.i_o_timeElapsed < TIME_ELAPSED)
                {
                      transitionFunction();
                }

                switch(system_status.inputOutputTransition){

                case INPUT:

                    // Input reset eklenebilir.

                    check_Input_Lowidle();

                    if(testFlag[LOW_IDLE] == TRUE)
                    {
                         system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                         system_status.i_o_timeElapsed = 0;               // Reset the counter
                         system_status.testState = SIGNAL1;

                         state_Success(LOW_IDLE);
                         break;
                    }

                          else if (testFlag[LOW_IDLE] == FALSE)
                          {
                              system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                              state_Error(LOW_IDLE);                         // Printing out an Error message.

                              return;
                          }

                    break;

                case OUTPUT:

                  are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.

                  if(are_outs_checked == TRUE)
                  {
                      // burada output verildi. LOW_POWER'a   çünkü LOW_IDLE state'inde

                     Low_idle_Out();
                     system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                     system_status.i_o_timeElapsed = 0;                       // Reset the counter
                     system_status.inputOutputTransition = INPUT;
                     break;

                  }

                  else if (are_outs_checked == FALSE)

                  {
                      output_Error(LOW_IDLE);
                     system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                     return;
                  }

                    break;
                default:
                    break;

                }

                if(system_status.testState != LOW_IDLE)
                {
                    __no_operation();
                    break;
                }
                __no_operation();

         }

                // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

                // Bu kýsýmdaki delaylerim 1s kalmasýnda sakýnca olmayabilir.

                if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde bitmezse baþa döner.

                    system_status.caseCounter = 0;
                    __no_operation();

                    //system_reset();                                   // Bütün sistem sýfýrlandý.
                    system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                    timeout_Error();
                }

            break;


        case SIGNAL1:

            // Her case'in 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.

                check_Input_Signal1();

                if(testFlag[SIGNAL1] == TRUE)
                {
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testState = MUTE_STATE;

                 state_Success(SIGNAL1);

                 break;

                }

              else if (testFlag[SIGNAL1] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(SIGNAL1);                         // Printing out an Error message.

                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.


              if(are_outs_checked == TRUE)
              {
                  // output verilecek. (istenilen sinyallere)

                 Signal1_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 output_Error(SIGNAL1);

                 return;
              }

                break;
            default:
                break;
            }

            if(system_status.testState != SIGNAL1)
            {
                __no_operation();
                break;
            }
            __no_operation();
            }

            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case MUTE_STATE:


            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.


            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.


                check_Input_Mute();

                if(testFlag[MUTE_STATE] == TRUE)
                {

                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testStateHolder = MUTE_STATE;        // Code will be entered in this case in reset case.
                 system_status.testState = RESET_STATE;

                 state_Success(MUTE_STATE);
                 break;

                }

              else if (testFlag[MUTE_STATE] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(MUTE_STATE);                         // Printing out an Error message.
                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.


              if(are_outs_checked == TRUE)
              {
                  // output verilecek. (istenilen sinyallere)

                 Mute_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                  output_Error(MUTE_STATE);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.

                 return;
              }

                break;

            default:
                break;
            }

            if(system_status.testState != MUTE_STATE)
            {
                __no_operation();
                break;
            }
            __no_operation();

            }


            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case SIGNAL2:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            transitionFunction();

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.


                check_Input_Signal2();

                if(testFlag[SIGNAL2] == TRUE)
                {

                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testStateHolder = SIGNAL2;        // Code will be entered in this case in reset case.
                 system_status.testState = RESET_STATE;

                 state_Success(SIGNAL2);

                 break;

                }

              else if (testFlag[SIGNAL2] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(SIGNAL2);                         // Printing out an Error message.
                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.


              if(are_outs_checked == TRUE)
              {
                  // output verilecek. (istenilen sinyallere)

                 Signal2_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                  output_Error(SIGNAL2);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 return;
              }

                break;
            default:
                break;
            }

            if(system_status.testState != SIGNAL2)
            {
                __no_operation();
                break;
            }
            __no_operation();

            }

            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case SIGNAL3:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.

                check_Input_Signal3();

                if(testFlag[SIGNAL3] == TRUE)
                {

                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testStateHolder = SIGNAL3;        // Code will be entered in this case in reset case.
                 system_status.testState = RESET_STATE;

                 state_Success(SIGNAL3);

                 break;

                }

              else if (testFlag[SIGNAL3] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(SIGNAL3);                         // Printing out an Error message.
                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.


              if(are_outs_checked == TRUE)
              {
                  // output verilecek. (istenilen sinyallere)

                 Signal3_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                 output_Error(SIGNAL3);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 return;
              }

                break;
            default:
                break;
            }

            if(system_status.testState != SIGNAL3)
            {
                __no_operation();
                break;
            }
            __no_operation();

            }


            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();

            }

            break;



        case SIGNAL4:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.


                check_Input_Signal4();

                testFlag[SIGNAL4] = TRUE;

                if(testFlag[SIGNAL4] == TRUE)
                {

                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testStateHolder = SIGNAL4;        // Code will be entered in this case in reset case.
                 system_status.testState = RESET_STATE;

                 state_Success(SIGNAL4);

                 break;

                }

              else if (testFlag[SIGNAL4] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(SIGNAL4);                         // Printing out an Error message.
                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.

                // burada output verme yok çünkü OFF state'inde

              if(are_outs_checked == TRUE)
              {
                  // output verilecek. (istenilen sinyallere)

                 Signal4_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                 output_Error(SIGNAL4);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 return;
              }

                break;
            default:
                break;
            }

            if(system_status.testState != SIGNAL4)
            {
                __no_operation();
                break;
            }
            __no_operation();

            }


            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case SIGNAL5:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.


                check_Input_Signal5();

                if(testFlag[SIGNAL5] == TRUE)
                {

                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testStateHolder = SIGNAL5;        // Code will be entered in this case in reset case.
                 system_status.testState = RESET_STATE;

                 state_Success(SIGNAL5);

                 break;

                }

              else if (testFlag[SIGNAL5] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(SIGNAL5);                         // Printing out an Error message.
                return;

              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.

                // burada output verme yok çünkü OFF state'inde

              if(are_outs_checked == TRUE)
              {
                  // output verilecek. (istenilen sinyallere)

                 Signal5_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                  output_Error(SIGNAL5);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 return;
              }

                break;
            default:
                break;
            }

            if(system_status.testState != SIGNAL5)
            {
                __no_operation();
                break;
            }
            __no_operation();

        }

            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case SIGNAL6:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.


                check_Input_Signal6();

                if(testFlag[SIGNAL6] == TRUE)
                {

                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testStateHolder = SIGNAL6;        // Code will be entered in this case in reset case.
                 system_status.testState = RESET_STATE;

                 state_Success(SIGNAL6);

                 break;

                }

              else if (testFlag[SIGNAL6] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(SIGNAL6);                         // Printing out an Error message.
                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.


              if(are_outs_checked == TRUE)
              {

                  // output verilecek. (istenilen sinyallere)

                 Signal6_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                  output_Error(SIGNAL6);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 return;
              }

                break;
            default:
                break;
            }

            if(system_status.testState != SIGNAL6)
            {
                __no_operation();
                break;
            }
            __no_operation();

            }


            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case ALL_LOW:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.


                check_Input_All_Low_High();                           // All_Low ile All_High input check ayný sinyalleri kontrol ediyor.


                if(testFlag[ALL_LOW] == TRUE)
                {
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testStateHolder = ALL_LOW;        // Code will be entered in this case in reset case.
                 system_status.testState = RESET_STATE;

                 state_Success(ALL_LOW);

                 break;
                }

              else if (testFlag[ALL_LOW] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(ALL_LOW);                         // Printing out an Error message.
                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.


              if(are_outs_checked == TRUE)
              {
                  // output verilecek. (istenilen sinyallere)

                 All_Low_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                  output_Error(ALL_LOW);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 return;
              }

                break;
            default:
                break;
            }

            if(system_status.testState != ALL_LOW)
            {
                __no_operation();
                break;
            }
            __no_operation();

         }

            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case ALL_HIGH:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

                // Input reset eklenebilir.

                check_Input_All_Low_High();                           // All_Low ile All_High input check ayný sinyalleri kontrol ediyor.

                testFlag[ALL_HIGH] = TRUE;

                if(testFlag[ALL_HIGH] == TRUE)
                {
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;               // Reset the counter
                 system_status.testStateHolder = ALL_HIGH;        // Code will be entered in this case in reset case.
                 system_status.testState = RESET_STATE;

                 state_Success(ALL_HIGH);

                 break;

                }

              else if (testFlag[ALL_HIGH] == FALSE)
              {

                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(ALL_HIGH);                         // Printing out an Error message.
                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.

              if(are_outs_checked == TRUE)
              {
                  // output verilecek. (istenilen sinyallere)

                 All_High_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                  output_Error(ALL_HIGH);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 return;
              }

                break;
            default:
                break;
            }


            if(system_status.testState != ALL_HIGH)
            {
                __no_operation();
                break;
            }
            __no_operation();

         }

            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME){            // 10 s içinde basýlmazsa baþa döner.

                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                   // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;


        case RESET_STATE:

            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

            // Waiting for applying the test.

            while (system_status.caseCounter++ < CASE_TIME) {


            while (system_status.i_o_timeElapsed < TIME_ELAPSED)
            {
                  transitionFunction();
            }

            switch(system_status.inputOutputTransition){

            case INPUT:

            // Input reset eklenebilir.

            check_Input_Reset();

            if(testFlag[RESET_STATE] == TRUE)
            {
                // Önceki state'i aklýnda tut ona göre reset_state'inden sonra önceki state'in bir sonrakine git.

                system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                system_status.i_o_timeElapsed = 0;                            // Reset the counter


                switch(system_status.testStateHolder)
                {

                    case MUTE_STATE:

                        if(testFlag[MUTE_STATE] == TRUE)
                        {
                         system_reset();
                         test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                         system_status.testState = SIGNAL2;
                         break;
                        }

                        else if (testFlag[MUTE_STATE] == FALSE)
                        {
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          return;
                        }

                        break;

                    case SIGNAL2:

                        if(testFlag[SIGNAL2] == TRUE)
                        {
                         system_reset();
                         test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                         system_status.testState = SIGNAL3;
                         break;
                        }

                        else if (testFlag[SIGNAL2] == FALSE)
                        {
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          return;
                        }

                        break;

                    case SIGNAL3:

                        if(testFlag[SIGNAL3] == TRUE)
                        {
                         system_reset();
                         test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                         system_status.testState = SIGNAL4;              // TEST yapmak için sinyal5 e atlattýk.
                         break;
                        }

                        else if (testFlag[SIGNAL3] == FALSE)
                        {
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          return;
                        }


                        break;

                    case SIGNAL4:

                        if(testFlag[SIGNAL4] == TRUE)
                        {
                         system_reset();
                         test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                         system_status.testState = SIGNAL5;
                         break;
                        }

                        else if (testFlag[SIGNAL4] == FALSE)
                        {
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          return;
                        }

                        break;

                    case SIGNAL5:

                        if(testFlag[SIGNAL5] == TRUE)
                        {
                         system_reset();
                         test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                         system_status.testState = SIGNAL6;
                         break;
                        }

                        else if (testFlag[SIGNAL5] == FALSE)
                        {
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          return;
                        }

                        break;

                    case SIGNAL6:

                        if(testFlag[SIGNAL6] == TRUE)
                        {
                         system_reset();
                         test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                         system_status.testState = ALL_LOW;
                         break;
                        }

                        else if (testFlag[SIGNAL6] == FALSE)
                        {
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          return;
                        }

                        break;

                    case ALL_LOW:

                        if(testFlag[ALL_LOW] == TRUE)
                        {
                         system_reset();
                         test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                         system_status.testState = ALL_HIGH;
                         break;
                        }

                        else if (testFlag[ALL_LOW] == FALSE)
                        {
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          return;
                        }

                        break;

                    case ALL_HIGH:

                        if(testFlag[ALL_HIGH] == TRUE)
                        {
                         system_reset();
                         test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                         system_status.testState = OK;
                         break;
                        }

                        else if (testFlag[ALL_HIGH] == FALSE)
                        {
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          return;
                        }

                        break;
                    default:
                    break;
                    }

                 break;

                }

              else if (testFlag[RESET_STATE] == FALSE)
              {
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                state_Error(RESET_STATE);                         // Printing out an Error message.
                return;
              }

                break;

            case OUTPUT:

                are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.

              if(are_outs_checked == TRUE)
              {
                  // output verildi. (istenilen sinyallere)

                 Reset_Out();
                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                 system_status.i_o_timeElapsed = 0;                            // Reset the counter
                 system_status.inputOutputTransition = INPUT;
                 break;
              }

              else if (are_outs_checked == FALSE)
              {
                  output_Error(RESET_STATE);
                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                 return;
              }

                break;
            default:
                break;
            }

            if(system_status.testState != RESET_STATE)
            {
                __no_operation();
                break;
            }
            __no_operation();

            }

            // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

            if(system_status.caseCounter >= CASE_TIME)
            {                                                        // 10 s içinde basýlmazsa baþa döner.
                system_status.caseCounter = 0;
                __no_operation();
                //system_reset();                                    // Bütün sistem sýfýrlandý.
                system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                timeout_Error();
            }

            break;

        case OK:

            // Ok case'i içinde ayný þeyler yapýlacak.


            // Her case'in içine 100 ms içinde gerçekleþmesini saðla eðer olmazsa fail versin.

                  i = 0;

                    // Waiting for applying the test.

                    // Code has to enter this logic 3 times. (OK -> Low_idle)

              for (i = 0; i < 3; i++) {

                 system_status.caseCounter = 0;

                    while (system_status.caseCounter++ < CASE_TIME) {


                    while (system_status.i_o_timeElapsed < TIME_ELAPSED)
                    {
                          transitionFunction();
                    }

                    switch(system_status.testStateHolder)
                    {
                        case OK:

                            switch(system_status.inputOutputTransition){

                            case INPUT:

                                // Inputlarý sýfýrlama eklenebilir.

                                check_Input_Ok();

                     // Önceki state'i aklýnda tut ona göre reset_state'inden sonra önceki state'in bir sonrakine git.


                                if(testFlag[OK] == TRUE)
                                {
                                    system_reset();                                  // Bütün sistem sýfýrlandý.
                                    LED_OK_PORT |= LED_OK_PIN;                      // OK ledini yak. Test tamamlandý.
                                    system_status.testState = OFF ;                 // Testler en baþtan yapýlacak
                                    system_status.testStateHolder = LOW_IDLE;      // Low_idle state'inden tekrar buraya gelecek.
                                    testFlag[OK] = TRUE;
                                    system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                                    system_status.i_o_timeElapsed = 0;               // Reset the counter

                                    state_Success(OK);
                                    break;
                                }

                                else if (testFlag[OK] == FALSE)
                                {
                                    system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                                    state_Error(OK);                         // Printing out an Error message.
                                    return;
                                }

                              case OUTPUT:

                                  are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.


                                if(are_outs_checked == TRUE)
                                {
                                    // output verildi. (istenilen sinyallere)

                                   Ok_Out();
                                   system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                                   system_status.i_o_timeElapsed = 0;                            // Reset the counter
                                   system_status.inputOutputTransition = INPUT;
                                   break;
                                }

                                else if (are_outs_checked == FALSE)
                                {
                                    output_Error(OK);
                                   system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                                   return;
                                }

                                  break;
                              default:
                                  break;
                              }

                             test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.

                            break;

                        case LOW_IDLE:

                            switch(system_status.inputOutputTransition){

                            case INPUT:

                                // Input reset eklenebilir.

                                check_Input_Lowidle();

                                if(testFlag[LOW_IDLE] == TRUE)
                                {
                                     system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                                     system_status.i_o_timeElapsed = 0;                             // Reset the counter
                                     system_status.testState = OFF ;                                // Testler en baþtan yapýlacak
                                     system_status.testStateHolder = OK;             // Low_idle state'inden tekrar buraya gelecek.

                                     state_Success(LOW_IDLE);

                                     break;
                                }
                                      else if (testFlag[LOW_IDLE] == FALSE)
                                      {
                                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                                          state_Error(LOW_IDLE);                         // Printing out an Error message.
                                          return;
                                      }

                                break;

                            case OUTPUT:

                              are_outs_checked = output_reset();                   // output resetlendi mi ? fonksiyonu.

                              if(are_outs_checked == TRUE)
                              {
                                  // burada output verildi. LOW_POWER'a   çünkü LOW_IDLE state'inde

                                 Low_idle_Out();
                                 system_status.caseCounter += system_status.i_o_timeElapsed;    // Adding the elapsed time
                                 system_status.i_o_timeElapsed = 0;                       // Reset the counter
                                 system_status.inputOutputTransition = INPUT;
                                 break;
                              }

                              else if (are_outs_checked == FALSE)
                              {
                                  output_Error(LOW_IDLE);
                                 system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                                 return;
                              }

                                break;
                            default:
                                break;

                            }

                             system_reset();
                             test_reset_mute_flags();                                     // test -> reset -> mute buttons must be pressed for control.
                             pressed_flag[BUTTON1]=FALSE;
                            break;
                    }

                    if(system_status.testState != OK)
                    {
                        __no_operation();
                        break;
                    }
                    __no_operation();

                 }
              }
                    system_reset();
                    pressed_flag[BUTTON1]=FALSE;
                    system_status.testState = OFF;
                    All_Test_Completed();
                    LOW_POWER_PORT &= ~ LOW_POWER_PIN;

                      // Bu aþaðýdaki kýsmý kaldýrmamýz gerekebilir.

                      if(system_status.caseCounter >= CASE_TIME*2)
                      {                                                        // 10 s içinde basýlmazsa baþa döner.
                          system_status.caseCounter = 0;
                          system_status.testState = FAIL;                      // FAIL State'ine gidecek.
                          timeout_Error();
                      }

                      break;
        case FAIL:
            system_reset();
            pressed_flag[BUTTON1]=FALSE;
            Fail();
            break;
        default:
            break;
        }

        if( system_status.testState >= NUM_OF_CASE)
        {
            system_status.testState = 0;                      // Eðer fazla bir deðere ulaþýrsa
        }
    }



 /*  Function    : task_manager
  *  Inputs      : -
  *  Return      : -
  *  Desc        : All tasks run in here.
  */


 void task_manager()
 {

     while(1) {

         // Buraya security_But1() çaðýrýlacak. Eðer button1 e basýlýrsa test -> mute -> reset aktif olacak.

        // security_But1();
         __no_operation();

         //pressed_flag[BUTTON1] = TRUE;


         if(pressed_flag[BUTTON1] == FALSE)
         {
             // LCD function yazýlacak. Ürün çýkarýldý yazýlacak.
             security_But1();
             //button1_Error();
         }

         else
         {
             if(pressed_flag[TEST] == FALSE &&  pressed_flag[RESET] == FALSE && pressed_flag[MUTE] == FALSE)
             {
                 checkStartButton();
                 __no_operation();
             }
             __no_operation();
            //pressed_flag[START] = TRUE;      // debug için test debugtan sonra silinecek.
             start_test();
             __no_operation();
         }
     }
 }
