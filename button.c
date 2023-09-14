/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : button.c
* Author             : Burak Ozsahin
* Version            : V1.0
* Date               : 21/08/2023
* Description        : Get buttons state
********************************************************************************/

#include <msp430.h>
#include "main.h"
#include "stdint.h"
#include "bsp.h"
#include "button.h"



#ifdef BUTTON


button_t input_check_point[NUM_OF_INPUT_POINT];

u8 pressed_flag[NUM_OF_INPUT_POINT];

u8 testFlag[NUM_OF_CASE];

u16 Error_signal_Flag[NUM_OF_INPUT_POINT];

u8 inputOutputTransition[NUM_OF_TRANSITION_STATE];

u8 buzzer_flag;
int buzzer_cnt;
u8 led_pins;
u8 relay_pins;



u8 Button_State_Func(button_t *button_ptr)
{
    u8 button_status;


    if((BUTTON_READ_PIN(button_ptr) & button_ptr->BUTTON_MASK)==button_ptr->BUTTON_PRESSED_CONFIG)
        button_ptr->VALUE = PRESSED;
    else if((BUTTON_READ_PIN(button_ptr) & button_ptr->BUTTON_MASK)==button_ptr->BUTTON_RELEASED_CONFIG)
        button_ptr->VALUE = RELEASED;
    else{
        button_status=BUTTON_STATUS_FAIL;
        return button_status;
    }


    // Her buton basýlmasý istendiðinde 100 ms içindeki deðerine bakacak.

    //transitionFunction();

    while (system_status.i_o_timeElapsed < TIME_ELAPSED)
    {
          transitionFunction();
    }


    if((button_ptr->LASTVALUE == UNKNOWN)&&(button_ptr->VALUE == PRESSED))
        {
            button_status = PRESSED;
        }
    else if((button_ptr->LASTVALUE == UNKNOWN)&&(button_ptr->VALUE == RELEASED))
        {
            button_status = RELEASED;
        }
    else if((button_ptr->LASTVALUE == RELEASED)&&(button_ptr->VALUE == PRESSED))
        {
            button_status = AGAIN_PRESSED;
        }
    else if((button_ptr->LASTVALUE == PRESSED)&&(button_ptr->VALUE == RELEASED))
        {
            button_status = AGAIN_RELEASED;
        }
    else if((button_ptr->LASTVALUE == PRESSED)&&(button_ptr->VALUE == PRESSED))
        {
            button_status = STILL_PRESSED;
        }
    else if((button_ptr->LASTVALUE == RELEASED)&&(button_ptr->VALUE == RELEASED))
        {
            button_status = STILL_RELEASED;
        }


    button_ptr->LASTVALUE = button_ptr->VALUE;

    return button_status;
}



u8 is_Button_Pressed_Func(button_t *button_ptr)
{
    u8 button_status;

    if((BUTTON_READ_PIN(button_ptr) & button_ptr->BUTTON_MASK)==button_ptr->BUTTON_PRESSED_CONFIG)
        button_status = PRESSED;
    else if((BUTTON_READ_PIN(button_ptr) & button_ptr->BUTTON_MASK)==button_ptr->BUTTON_RELEASED_CONFIG)
        button_status = RELEASED;
    else{
        button_status=BUTTON_STATUS_FAIL;
        }

    return button_status;
}


u8 check_button(u8 button_name,u8 btn_name_ms){

    u8 button_num=button_name;
    u8 status=Button_State_Func(&input_check_point[button_num]);

    switch(status){

    case PRESSED:
    case AGAIN_PRESSED:
    //start_timeout_ms(btn_name_ms ,BUTTON_MS);
      LOW_POWER_PORT |= LOW_POWER_PIN;
    break;
    default:
    //  start_timeout_ms(btn_name_ms ,BUTTON_MS);
    break;
}

    return status;
}


void security_But1() {


    while (system_status.i_o_timeElapsed < TIME_ELAPSED)
    {
          transitionFunction();
    }


    u8 button1_status = Button_State_Func(&input_check_point[BUTTON1]);


    switch(button1_status)
    {
        case PRESSED:
        case AGAIN_PRESSED:
        case STILL_PRESSED:

        pressed_flag[BUTTON1] = TRUE;
        system_status.i_o_timeElapsed = 0;
        LOW_POWER_PORT   |=  LOW_POWER_PIN;

        button1_Success();

        break;

        case RELEASED:
        case AGAIN_RELEASED:
        case STILL_RELEASED:

       // pressed_flag[BUTTON1] = FALSE;
        system_status.i_o_timeElapsed = 0;

        // LCD ekrana yazdýrma.

        button1_Error();


        // LCD fonks burada olacak "ürün takýlmadý" yazýlacak.

        break;
        default:
        break;
    }

}


#endif /*BUTTON */
