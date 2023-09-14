/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : error.c
* Author             : Burak Ozsahin
* Version            : V1.0
* Date               : 06/09/2023
* Description        : error functions
********************************************************************************/



#include <msp430.h>
#include "bsp.h"
#include "main.h"
#include "button.h"



 /*  Function    : input_Error
  *  Inputs      : -
  *  Return      : -
  *  Desc        : Giving an Error message for each signal.
  */



    void input_Error(u16 Error_signal_Flag) {

        switch (Error_signal_Flag) {
            case LS1:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS1 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS2:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS2 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS3:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS3 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS4:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS4 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS5:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS5 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS6:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS6 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case TRIP1:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("TRIP1 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case TRIP2:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("TRIP2 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case HORN:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Input");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("HORN !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            default:
                // Handle unknown error signal (if needed)
                break;
        }
    }



    /*  Function    : output_Error
     *  Inputs      : -
     *  Return      : -
     *  Desc        : Giving an Error message for each signal.
     */



    void output_Error(u16 Error_signal_Flag) {

        switch (Error_signal_Flag) {
            case LS1:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS1 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS2:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS2 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS3:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS3 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS4:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS4 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS5:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS5 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LS6:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LS6 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case TRIP1:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("TRIP1 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case TRIP2:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("TRIP2 !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case HORN:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("Output");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("HORN !");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            default:
                // Handle unknown error signal (if needed)
                break;
        }
    }









    /*  Function    : state_Error
     *  Inputs      : -
     *  Return      : -
     *  Desc        : Giving an Error message for each state.
     */



    void state_Error(u16 testFlag) {

        switch (testFlag) {
            case OFF:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("OFF");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case LOW_IDLE:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("LOW_IDLE");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL1:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("SIGNAL1");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case MUTE_STATE:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("MUTE_STATE");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL2:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("SIGNAL2");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL3:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("SIGNAL3");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL4:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("SIGNAL4");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL5:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("SIGNAL5");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL6:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("SIGNAL6");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case ALL_LOW:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("ALL_LOW");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case ALL_HIGH:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("ALL_HIGH");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case RESET_STATE:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("RESET_STATE");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case OK:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("OK");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case FAIL:

                clearLCD();

                 lcd_Go_To_X_Y(0,0);
                 send_string("State");        // Write a string
                 lcd_Go_To_X_Y(1,0);
                 send_string("Error:");        // Write a string
                 lcd_Go_To_X_Y(2,0);
                 send_string("FAIL");        // Write a string

                 __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

                break;

            default:
                // Handle unknown testFlag value (if needed)
                break;
        }
    }



    /*  Function    : state_Success
     *  Inputs      : -
     *  Return      : -
     *  Desc        : Giving an Success message for each state.
     */


    void state_Success(u16 testFlag) {

        switch (testFlag) {
            case OFF:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("OFF");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.
                break;

            case LOW_IDLE:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("LOW_IDLE");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.
                break;

            case SIGNAL1:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("SIGNAL1");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case MUTE_STATE:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("MUTE_STATE");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL2:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("SIGNAL2");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL3:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("SIGNAL3");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL4:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("SIGNAL4");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL5:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("SIGNAL5");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case SIGNAL6:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("SIGNAL6");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case ALL_LOW:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("ALL_LOW");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case ALL_HIGH:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("ALL_HIGH");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case RESET_STATE:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("RESET_STATE");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case OK:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("OK");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            case FAIL:

                clearLCD();

                lcd_Go_To_X_Y(0,0);
                send_string("State");        // Write a string
                lcd_Go_To_X_Y(1,0);
                send_string("Succeeded:");        // Write a string
                lcd_Go_To_X_Y(2,0);
                send_string("FAIL");        // Write a string

                __delay_cycles(SUCCESS_DELAY_TIME);                               // 1s fakat baya küçültülmesi lazým.

                break;

            default:
                // Handle unknown successFlag value (if needed)
                break;
        }
    }



    /*  Function    : timeout_Error
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an TimeOut message.
    */


    void timeout_Error()
    {
            clearLCD();

            lcd_Go_To_X_Y(0,0);
            send_string("TimeOut");        // Write a string
            lcd_Go_To_X_Y(1,0);
            send_string("Error:");        // Write a string

            __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.
    }



    /*  Function    : testButton_Success
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an Success message for Test button.
    */



    void testButton_Success()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("Test Button");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("Is Pressed !");        // Write a string

        __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.
    }



    /*  Function    : resetButton_Success
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an Success message for Reset button.
    */



    void resetButton_Success()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("Reset Button");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("Is Pressed !");        // Write a string

        __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.
    }



    /*  Function    : muteButton_Success
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an Success message for Mute button.
    */



    void muteButton_Success()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("Mute Button");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("Is Pressed !");        // Write a string

        __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.
    }



    /*  Function    : resetButton_Error
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an TimeOut message for reset button.
    */



    void resetButton_Error()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("Reset button");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("is not pressed !");        // Write a string

        __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.
    }



    /*  Function    : muteButton_Error
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an TimeOut message for mute button.
    */



    void muteButton_Error()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("Mute button");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("is not pressed !");        // Write a string

        __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.

        system_reset();                                   // Bütün sistem sýfýrlandý.
    }



    /*  Function    : start_TestMessage
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an Starting the test message.
    */



    void start_TestMessage()
    {

        lcd_Go_To_X_Y(0,0);
        send_string(" Test is   ");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("starting ...");        // Write a string

        __delay_cycles(1000000);                               // 1s fakat baya küçültülmesi lazým.
    }


    /*  Function    : start_TestError
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an error test message.
    */



    void start_TestError()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("Test");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("can't start ...");        // Write a string
        __delay_cycles(1000000);
    }


    /*  Function    : button1_Error
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an error button1 message.
    */



    void button1_Error()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string(" DKT-66 not ");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string(" connected !!!");        // Write a string
        __delay_cycles(1000000);

        clearLCD();
    }



    /*  Function    : button1_Error
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an error button1 message.
    */



    void button1_Success()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("Safety Switch");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("Is Pressed ...");        // Write a string
        __delay_cycles(1000000);

    }



    /*  Function    : All_Test_Completed
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an error button1 message.
    */



    void All_Test_Completed()
    {
        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("All Tests are");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("Completed !!!");        // Write a string
        __delay_cycles(1000000);
    }


    /*  Function    : Fail
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an error fail message.
    */



    void Fail() {

        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("FAIL !!!");        // Write a string
        __delay_cycles(1000000);


        //system_reset();                                   // Bütün sistem sýfýrlandý.
        LED_FAIL_PORT |= LED_FAIL_PIN;                    // FAIL ledini yak. Test baþarýsýz.
        system_status.testState = OFF;                    // Testler en baþtan yapýlacak.

    }




    /*  Function    : Fatal_Error
    *  Inputs      : -
    *  Return      : -
    *  Desc        : Giving an error fatal message.
    */



    void Fatal_Error() {

        clearLCD();

        lcd_Go_To_X_Y(0,0);
        send_string("FATAL");        // Write a string
        lcd_Go_To_X_Y(1,0);
        send_string("ERROR !!!");        // Write a string
        __delay_cycles(1000000);


    }

