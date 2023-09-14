/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : case.c
* Author             : Burak Ozsahin
* Version            : V1.0
* Date               : 25/08/2023
* Description        : case functions
********************************************************************************/

#include <msp430.h>
#include "bsp.h"
#include "main.h"
#include "button.h"



 /*  Function    : check_State_Off
  *  Inputs      : -
  *  Return      : -
  *  Desc        : Checking  inputs of the off state.
  */



void check_Input_Off()
{
    // Check status of all signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);


    // Check if all signals are inactive
    if ((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
        (LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
        (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
        (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
        (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
        (LS6_status == RELEASED || LS6_status == AGAIN_RELEASED || LS6_status == STILL_RELEASED) &&
        (TRIP1_status == RELEASED || TRIP1_status == AGAIN_RELEASED || TRIP1_status == STILL_RELEASED) &&
        (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED) &&
        (HORN_status == RELEASED || HORN_status == AGAIN_RELEASED || HORN_status == STILL_RELEASED))
    {
        // Set flags for successful test
        testFlag[OFF] = TRUE;
    }

    else
    {
        // Set error flags for any active signals
        testFlag[OFF] = FALSE;

        if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
        {
            Error_signal_Flag[LS1] = TRUE;
            system_status.input_error = LS1;
        }
        if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
        {
            Error_signal_Flag[LS2] = TRUE;
            system_status.input_error  = LS2;
        }
        if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
        {
            Error_signal_Flag[LS3] = TRUE;
            system_status.input_error  = LS3;
        }
        if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
        {
            Error_signal_Flag[LS4] = TRUE;
            system_status.input_error  = LS4;
        }
        if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
        {
            Error_signal_Flag[LS5] = TRUE;
            system_status.input_error  = LS5;
        }
        if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
        {
            Error_signal_Flag[LS6] = TRUE;
            system_status.input_error  = LS6;
        }
        if (TRIP1_status != RELEASED && TRIP1_status != AGAIN_RELEASED && TRIP1_status != STILL_RELEASED)
        {
            Error_signal_Flag[TRIP1] = TRUE;
            system_status.input_error  = TRIP1;
        }
        if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
        {
            Error_signal_Flag[TRIP2] = TRUE;
            system_status.input_error  = TRIP2;
        }
        if (HORN_status != RELEASED && HORN_status != AGAIN_RELEASED && HORN_status != STILL_RELEASED)
        {
            Error_signal_Flag[HORN] = TRUE;
            system_status.input_error = HORN;
        }

        input_Error(system_status.input_error);
        system_status.testState = FAIL;
    }
}



/*  Function    : check_Input_Lowidle
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Lowidle state.
 */

void check_Input_Lowidle()
{
    // Check status of active signals
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check status of inactive signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);



    // Check active signals
    if (TRIP2_status == RELEASED || TRIP2_status == AGAIN_RELEASED || TRIP2_status == STILL_RELEASED)
    {
        // Check inactive signals
        if (!((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
              (LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
              (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
              (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
              (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
              (LS6_status == RELEASED || LS6_status == AGAIN_RELEASED || LS6_status == STILL_RELEASED) &&
              (TRIP1_status == RELEASED || TRIP1_status == AGAIN_RELEASED || TRIP1_status == STILL_RELEASED) &&
              (HORN_status == RELEASED || HORN_status == AGAIN_RELEASED || HORN_status == STILL_RELEASED)))
        {
            // Set error flags for inactive signals
            testFlag[LOW_IDLE] = FALSE;
            system_status.testState = FAIL;

            // Check each inactive signal and set error_occurred if any is active
            if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS1] = TRUE;
                system_status.input_error = LS1;
            }
            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }
            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }
            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }
            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }
            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS6;
            }
            if (TRIP1_status != RELEASED && TRIP1_status != AGAIN_RELEASED && TRIP1_status != STILL_RELEASED)
            {
                Error_signal_Flag[TRIP1] = TRUE;
                system_status.input_error = TRIP1;
            }
            if (HORN_status != RELEASED && HORN_status != AGAIN_RELEASED && HORN_status != STILL_RELEASED)
            {
                Error_signal_Flag[HORN] = TRUE;
                system_status.input_error = HORN;
            }

            input_Error(system_status.input_error);
            system_status.testState = FAIL;
        }

        else
        {
            // Set flags for successful test
            testFlag[LOW_IDLE] = TRUE;
            Error_signal_Flag[TRIP2] = FALSE;
        }
    }

    else
    {
        // Set error flags for active signals
        testFlag[LOW_IDLE] = FALSE;

        if (TRIP2_status != RELEASED && TRIP2_status != AGAIN_RELEASED && TRIP2_status != STILL_RELEASED)
        {
            Error_signal_Flag[TRIP2] = TRUE;
            system_status.input_error = TRIP2;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);
    }
}



/*  Function    : check_Input_Mute
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Mute state.
 */

void check_Input_Mute()
{
    // Check status of active signals
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);

    // Check status of inactive signals
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);


    // Check active signals
    if ((TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
        (LS1_status == PRESSED || LS1_status == AGAIN_PRESSED || LS1_status == STILL_PRESSED))
    {
        // Check inactive signals
        if (!((LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
              (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
              (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
              (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
              (LS6_status == RELEASED || LS6_status == AGAIN_RELEASED || LS6_status == STILL_RELEASED) &&
              (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED) &&
              (HORN_status == RELEASED || HORN_status == AGAIN_RELEASED || HORN_status == STILL_RELEASED)))
        {
            // Set error flags for inactive signals
            testFlag[MUTE_STATE] = FALSE;
            system_status.testState = FAIL;

            // Check each inactive signal and set error_occurred if any is active
            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {   Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }
            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }
            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }
            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }
            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS5;
            }
            if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
            {
                Error_signal_Flag[TRIP2] = TRUE;
                system_status.input_error = TRIP2;
            }
            if (HORN_status != RELEASED && HORN_status != AGAIN_RELEASED && HORN_status != STILL_RELEASED)
            {
                Error_signal_Flag[HORN] = TRUE;
                system_status.input_error = HORN;
            }

            input_Error(system_status.input_error);
            system_status.testState = FAIL;

        }

        else
        {
            // Set flags for successful test
            testFlag[MUTE_STATE] = TRUE;
            Error_signal_Flag[TRIP1] = FALSE;
            Error_signal_Flag[LS1] = FALSE;
        }
    }

    else
    {
        // Set error flags for active signals
        testFlag[MUTE_STATE] = FALSE;


        if (TRIP1_status == RELEASED && TRIP1_status == AGAIN_RELEASED && TRIP1_status == STILL_RELEASED)
        {
            Error_signal_Flag[TRIP1] = TRUE;
            system_status.input_error = HORN;
        }

        if (LS1_status == RELEASED && LS1_status == AGAIN_RELEASED && LS1_status == STILL_RELEASED)
        {
            Error_signal_Flag[LS1] = TRUE;
            system_status.input_error = HORN;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);

    }
}



/*  Function    : check_Input_Signal1
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Signal1 state.
 */


void check_Input_Signal1()
{
    // Check status of active signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check status of inactive signals
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check active signals
    if ((LS1_status == PRESSED || LS1_status == AGAIN_PRESSED || LS1_status == STILL_PRESSED) &&
        (TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
        (HORN_status == PRESSED || HORN_status == AGAIN_PRESSED || HORN_status == STILL_PRESSED))
    {
        // Check inactive signals
        if (!((LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
              (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
              (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
              (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
              (LS6_status == RELEASED || LS6_status == AGAIN_RELEASED || LS6_status == STILL_RELEASED) &&
              (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED)))
        {
            // Set error flags for inactive signals
            testFlag[SIGNAL1] = FALSE;
            system_status.testState = FAIL;

            // Check each inactive signal and set error_occurred if any is active
            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }
            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }
            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }
            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }
            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS6;
            }
            if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
            {
                Error_signal_Flag[TRIP2] = TRUE;
                system_status.input_error = TRIP2;
            }

            input_Error(system_status.input_error);
            system_status.testState = FAIL;

        }

        else
        {
            // Set flags for successful test
            testFlag[SIGNAL1] = TRUE;
            Error_signal_Flag[LS1] = FALSE;
            Error_signal_Flag[TRIP1] = FALSE;
            Error_signal_Flag[HORN] = FALSE;
        }
    }

    else
    {
        // Set error flags for active signals
        testFlag[SIGNAL1] = FALSE;

        if (TRIP1_status == RELEASED && TRIP1_status == AGAIN_RELEASED && TRIP1_status == STILL_RELEASED)
        {
            Error_signal_Flag[TRIP1] = TRUE;
            system_status.input_error = TRIP1;
        }

        if (LS1_status == RELEASED && LS1_status == AGAIN_RELEASED && LS1_status == STILL_RELEASED)
        {
            Error_signal_Flag[LS1] = TRUE;
            system_status.input_error = LS1;
        }

        if (HORN_status == RELEASED && HORN_status == AGAIN_RELEASED && HORN_status == STILL_RELEASED)
        {
            Error_signal_Flag[HORN] = TRUE;
            system_status.input_error = HORN;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);
    }
}




/*  Function    : check_Input_Signal2
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Signal2 state.
 */



void check_Input_Signal2()
{
    // Check status of active signals
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check status of inactive signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check active signals
    if ((LS2_status == PRESSED || LS2_status == AGAIN_PRESSED || LS2_status == STILL_PRESSED) &&
        (TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
        (HORN_status == PRESSED || HORN_status == AGAIN_PRESSED || HORN_status == STILL_PRESSED))
    {
        // Check inactive signals
        if (!((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
              (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
              (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
              (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
              (LS6_status == RELEASED || LS6_status == AGAIN_RELEASED || LS6_status == STILL_RELEASED) &&
              (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED)))
        {
            // Set error flags for inactive signals
            testFlag[SIGNAL2] = FALSE;
            system_status.testState = FAIL;

            // Check each inactive signal and set error_occurred if any is active
            if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS1] = TRUE;
                system_status.input_error = LS1;
            }
            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }
            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }
            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }
            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS6;
            }
            if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
            {
                Error_signal_Flag[TRIP2] = TRUE;
                system_status.input_error = TRIP2;
            }

            input_Error(system_status.input_error);
            system_status.testState = FAIL;

        }

        else
        {
            // Set flags for successful test
            testFlag[SIGNAL2] = TRUE;
            Error_signal_Flag[LS2] = FALSE;
            Error_signal_Flag[TRIP1] = FALSE;
            Error_signal_Flag[HORN] = FALSE;
        }
    }

    else
    {
        // Set error flags for active signals
        testFlag[SIGNAL2] = FALSE;

        if (TRIP1_status == RELEASED && TRIP1_status == AGAIN_RELEASED && TRIP1_status == STILL_RELEASED)
        {
            Error_signal_Flag[TRIP1] = TRUE;
            system_status.input_error = TRIP1;
        }

        if (LS2_status == RELEASED && LS2_status == AGAIN_RELEASED && LS2_status == STILL_RELEASED)
        {
            Error_signal_Flag[LS2] = TRUE;
            system_status.input_error = LS2;
        }

        if (HORN_status == RELEASED && HORN_status == AGAIN_RELEASED && HORN_status == STILL_RELEASED)
        {
            Error_signal_Flag[HORN] = TRUE;
            system_status.input_error = HORN;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);

    }

}


/*  Function    : check_Input_Signal3
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Signal3 state.
 */

void check_Input_Signal3()
{
    // Check status of active signals
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check status of inactive signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check active signals
    if ((LS3_status == PRESSED || LS3_status == AGAIN_PRESSED || LS3_status == STILL_PRESSED) &&
        (TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
        (HORN_status == PRESSED || HORN_status == AGAIN_PRESSED || HORN_status == STILL_PRESSED))
    {
        // Check inactive signals
        if (!((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
              (LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
              (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
              (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
              (LS6_status == RELEASED || LS6_status == AGAIN_RELEASED || LS6_status == STILL_RELEASED) &&
              (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED)))
        {
            // Set error flags for inactive signals
            testFlag[SIGNAL3] = FALSE;
            system_status.testState = FAIL;

            // Check each inactive signal and set error_occurred if any is active
            if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS1] = TRUE;
                system_status.input_error = LS1;
            }
            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }
            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }
            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }
            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS6;
            }
            if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
            {
                Error_signal_Flag[TRIP2] = TRUE;
                system_status.input_error = TRIP2;
            }

            input_Error(system_status.input_error);
        }

        else
        {
            // Set flags for successful test
            testFlag[SIGNAL3] = TRUE;
            Error_signal_Flag[LS3] = FALSE;
            Error_signal_Flag[TRIP1] = FALSE;
            Error_signal_Flag[HORN] = FALSE;
        }
    }

    else
    {
        // Set error flags for active signals
        testFlag[SIGNAL3] = FALSE;

        if (TRIP1_status == RELEASED && TRIP1_status == AGAIN_RELEASED && TRIP1_status == STILL_RELEASED)
        {
            Error_signal_Flag[TRIP1] = TRUE;
            system_status.input_error = TRIP1;
        }

        if (LS3_status == RELEASED && LS3_status == AGAIN_RELEASED && LS3_status == STILL_RELEASED)
        {
            Error_signal_Flag[LS3] = TRUE;
            system_status.input_error = LS3;
        }

        if (HORN_status == RELEASED && HORN_status == AGAIN_RELEASED && HORN_status == STILL_RELEASED)
        {
            Error_signal_Flag[HORN] = TRUE;
            system_status.input_error = HORN;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);
    }
}



/*  Function    : check_Input_Signal4
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Signal4 state.
 */



void check_Input_Signal4()
{
    // Check status of active signals
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check status of inactive signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check active signals
    if ((LS4_status == PRESSED || LS4_status == AGAIN_PRESSED || LS4_status == STILL_PRESSED) &&
        (TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
        (HORN_status == PRESSED || HORN_status == AGAIN_PRESSED || HORN_status == STILL_PRESSED))
    {
        // Check inactive signals
        if (!((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
              (LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
              (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
              (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
              (LS6_status == RELEASED || LS6_status == AGAIN_RELEASED || LS6_status == STILL_RELEASED) &&
              (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED)))
        {
            // Set error flags for inactive signals
            testFlag[SIGNAL4] = FALSE;
            //system_status.testState = FAIL;

            // Check each inactive signal and set error_occurred if any is active
            if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS1] = TRUE;
                system_status.input_error = LS1;
            }
            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }
            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }
            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }
            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS6;
            }
            if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
            {
                Error_signal_Flag[TRIP2] = TRUE;
                system_status.input_error = TRIP2;
            }

            input_Error(system_status.input_error);
        }

        else
        {
            // Set flags for successful test
            testFlag[SIGNAL4] = TRUE;
            Error_signal_Flag[LS4] = FALSE;
            Error_signal_Flag[TRIP1] = FALSE;
            Error_signal_Flag[HORN] = FALSE;
        }
    }

    else
    {
        // Set error flags for active signals
        testFlag[SIGNAL4] = FALSE;

        if (TRIP1_status == RELEASED && TRIP1_status == AGAIN_RELEASED && TRIP1_status == STILL_RELEASED)
        {
            Error_signal_Flag[TRIP1] = TRUE;
            system_status.input_error = TRIP1;
        }

        if (LS4_status == RELEASED && LS4_status == AGAIN_RELEASED && LS4_status == STILL_RELEASED)
        {
            Error_signal_Flag[LS4] = TRUE;
            system_status.input_error = LS4;
        }

        if (HORN_status == RELEASED && HORN_status == AGAIN_RELEASED && HORN_status == STILL_RELEASED)
        {
            Error_signal_Flag[HORN] = TRUE;
            system_status.input_error = HORN;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);

    }
}



/*  Function    : check_Input_Signal5
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Signal5 state.
 */


void check_Input_Signal5()
{

    // Check status of active signals
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check status of inactive signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check active signals
    if ((LS5_status == PRESSED || LS5_status == AGAIN_PRESSED || LS5_status == STILL_PRESSED) &&
        (TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
        (HORN_status == PRESSED || HORN_status == AGAIN_PRESSED || HORN_status == STILL_PRESSED))
    {
        // Check inactive signals
        if (!((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
              (LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
              (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
              (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
              (LS6_status == RELEASED || LS6_status == AGAIN_RELEASED || LS6_status == STILL_RELEASED) &&
              (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED)))
        {
            // Set error flags for inactive signals
            testFlag[SIGNAL5] = FALSE;
            system_status.testState = FAIL;

            // Check each inactive signal and set error_occurred if any is active

            if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS1] = TRUE;
                system_status.input_error = LS1;
            }

            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }

            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }

            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }

            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS6;
            }

            if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
            {
                Error_signal_Flag[TRIP2] = TRUE;
                system_status.input_error = TRIP2;
            }

            system_status.testState = FAIL;
            input_Error(system_status.input_error);
        }

        else
        {
            // Set flags for successful test
            testFlag[SIGNAL5] = TRUE;
            Error_signal_Flag[LS5] = FALSE;
            Error_signal_Flag[TRIP1] = FALSE;
            Error_signal_Flag[HORN] = FALSE;
        }
    }

    else
    {
        // Set error flags for active signals
        testFlag[SIGNAL5] = FALSE;

        if (TRIP1_status == RELEASED && TRIP1_status == AGAIN_RELEASED && TRIP1_status == STILL_RELEASED)
        {
            Error_signal_Flag[TRIP1] = TRUE;
            system_status.input_error = TRIP1;
        }

        if (LS5_status == RELEASED && LS5_status == AGAIN_RELEASED && LS5_status == STILL_RELEASED)
        {
            Error_signal_Flag[LS5] = TRUE;
            system_status.input_error = LS5;
        }

        if (HORN_status == RELEASED && HORN_status == AGAIN_RELEASED && HORN_status == STILL_RELEASED)
        {
            Error_signal_Flag[HORN] = TRUE;
            system_status.input_error = HORN;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);
    }
}




/*  Function    : check_Input_Signal6
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Signal6 state.
 */

void check_Input_Signal6()
{

    // Check status of active signals
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check status of inactive signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check active signals
    if ((LS6_status == PRESSED || LS6_status == AGAIN_PRESSED || LS6_status == STILL_PRESSED) &&
        (TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
        (HORN_status == PRESSED || HORN_status == AGAIN_PRESSED || HORN_status == STILL_PRESSED))
    {
        // Check inactive signals
        if (!((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
              (LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
              (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
              (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
              (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
              (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED)))
        {
            // Set error flags for inactive signals
            testFlag[SIGNAL6] = FALSE;
            system_status.testState = FAIL;

            // Check each inactive signal and set error_occurred if any is active

            if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS1] = TRUE;
                system_status.input_error = LS1;
            }

            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }

            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }

            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }

            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }

            if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
            {
                Error_signal_Flag[TRIP2] = TRUE;
                system_status.input_error = TRIP2;
            }

            system_status.testState = FAIL;
            input_Error(system_status.input_error);
        }

        else
        {
            // Set flags for successful test
            testFlag[SIGNAL6] = TRUE;
            Error_signal_Flag[LS6] = FALSE;
            Error_signal_Flag[TRIP1] = FALSE;
            Error_signal_Flag[HORN] = FALSE;
        }
    }

    else
    {
        // Set error flags for active signals
        testFlag[SIGNAL6] = FALSE;

        if (TRIP1_status == RELEASED && TRIP1_status == AGAIN_RELEASED && TRIP1_status == STILL_RELEASED)
        {
            Error_signal_Flag[TRIP1] = TRUE;
            system_status.input_error = TRIP1;
        }

        if (LS6_status == RELEASED && LS6_status == AGAIN_RELEASED && LS6_status == STILL_RELEASED)
        {
            Error_signal_Flag[LS6] = TRUE;
            system_status.input_error = LS6;
        }

        if (HORN_status == RELEASED && HORN_status == AGAIN_RELEASED && HORN_status == STILL_RELEASED)
        {
            Error_signal_Flag[HORN] = TRUE;
            system_status.input_error = HORN;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);
    }
}



/*  Function    : check_Input_All_Low_High
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the All_Low and All_High state.
 */


void check_Input_All_Low_High()
{
    // Check status of active signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check inactive signal
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check if TRIP2 is inactive and all other signals are active
    if (TRIP2_status == PRESSED || TRIP2_status == AGAIN_PRESSED || TRIP2_status == STILL_PRESSED)
    {
        // Check if in ALL_LOW state
        if (system_status.testState == ALL_LOW)
        {
            // Check active signals
            if ((LS1_status == PRESSED || LS1_status == AGAIN_PRESSED || LS1_status == STILL_PRESSED) &&
                (LS2_status == PRESSED || LS2_status == AGAIN_PRESSED || LS2_status == STILL_PRESSED) &&
                (LS3_status == PRESSED || LS3_status == AGAIN_PRESSED || LS3_status == STILL_PRESSED) &&
                (LS4_status == PRESSED || LS4_status == AGAIN_PRESSED || LS4_status == STILL_PRESSED) &&
                (LS5_status == PRESSED || LS5_status == AGAIN_PRESSED || LS5_status == STILL_PRESSED) &&
                (LS6_status == PRESSED || LS6_status == AGAIN_PRESSED || LS6_status == STILL_PRESSED) &&
                (TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
                (HORN_status == PRESSED || HORN_status == AGAIN_PRESSED || HORN_status == STILL_PRESSED))
            {
                // Set flag for successful ALL_LOW state
                testFlag[ALL_LOW] = TRUE;
            }

            else
            {
                // Set error flags for any inactive signals
                if (LS1_status != PRESSED && LS1_status != AGAIN_PRESSED && LS1_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS1] = TRUE;
                    system_status.input_error = LS1;
                }

                if (LS2_status != PRESSED && LS2_status != AGAIN_PRESSED && LS2_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS2] = TRUE;
                    system_status.input_error = LS2;
                }

                if (LS3_status != PRESSED && LS3_status != AGAIN_PRESSED && LS3_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS3] = TRUE;
                    system_status.input_error = LS3;
                }

                if (LS4_status != PRESSED && LS4_status != AGAIN_PRESSED && LS4_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS4] = TRUE;
                    system_status.input_error = LS4;
                }

                if (LS5_status != PRESSED && LS5_status != AGAIN_PRESSED && LS5_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS5] = TRUE;
                    system_status.input_error = LS5;
                }

                if (LS6_status != PRESSED && LS6_status != AGAIN_PRESSED && LS6_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS6] = TRUE;
                    system_status.input_error = LS6;
                }

                if (TRIP1_status != PRESSED && TRIP1_status != AGAIN_PRESSED && TRIP1_status != STILL_PRESSED)
                {
                    Error_signal_Flag[TRIP1] = TRUE;
                    system_status.input_error = TRIP1;
                }

                if (HORN_status != PRESSED && HORN_status != AGAIN_PRESSED && HORN_status != STILL_PRESSED)
                {
                    Error_signal_Flag[HORN] = TRUE;
                    system_status.input_error = HORN;
                }

                testFlag[ALL_LOW] = FALSE;
                system_status.testState = FAIL;
                input_Error(system_status.input_error);
            }
        }

        else if (system_status.testState == ALL_HIGH)
        {
            // Check active signals

            if ((LS1_status == PRESSED || LS1_status == AGAIN_PRESSED || LS1_status == STILL_PRESSED) &&
                (LS2_status == PRESSED || LS2_status == AGAIN_PRESSED || LS2_status == STILL_PRESSED) &&
                (LS3_status == PRESSED || LS3_status == AGAIN_PRESSED || LS3_status == STILL_PRESSED) &&
                (LS4_status == PRESSED || LS4_status == AGAIN_PRESSED || LS4_status == STILL_PRESSED) &&
                (LS5_status == PRESSED || LS5_status == AGAIN_PRESSED || LS5_status == STILL_PRESSED) &&
                (LS6_status == PRESSED || LS6_status == AGAIN_PRESSED || LS6_status == STILL_PRESSED) &&
                (TRIP1_status == PRESSED || TRIP1_status == AGAIN_PRESSED || TRIP1_status == STILL_PRESSED) &&
                (HORN_status == PRESSED || HORN_status == AGAIN_PRESSED || HORN_status == STILL_PRESSED))
            {
                // Set flag for successful ALL_HIGH state
                testFlag[ALL_HIGH] = TRUE;
            }

            else
            {
                // Set error flags for any active signals
                if (LS1_status != PRESSED && LS1_status != AGAIN_PRESSED && LS1_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS1] = TRUE;
                    system_status.input_error = LS1;
                }
                if (LS2_status != PRESSED && LS2_status != AGAIN_PRESSED && LS2_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS2] = TRUE;
                    system_status.input_error = LS2;
                }
                if (LS3_status != PRESSED && LS3_status != AGAIN_PRESSED && LS3_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS3] = TRUE;
                    system_status.input_error = LS3;
                }
                if (LS4_status != PRESSED && LS4_status != AGAIN_PRESSED && LS4_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS4] = TRUE;
                    system_status.input_error = LS4;
                }
                if (LS5_status != PRESSED && LS5_status != AGAIN_PRESSED && LS5_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS5] = TRUE;
                    system_status.input_error = LS5;
                }
                if (LS6_status != PRESSED && LS6_status != AGAIN_PRESSED && LS6_status != STILL_PRESSED)
                {
                    Error_signal_Flag[LS6] = TRUE;
                    system_status.input_error = LS6;
                }
                if (TRIP1_status != PRESSED && TRIP1_status != AGAIN_PRESSED && TRIP1_status != STILL_PRESSED)
                {
                    Error_signal_Flag[TRIP1] = TRUE;
                    system_status.input_error = TRIP1;
                }
                if (HORN_status != PRESSED && HORN_status != AGAIN_PRESSED && HORN_status != STILL_PRESSED)
                {
                    Error_signal_Flag[HORN] = TRUE;
                    system_status.input_error = HORN;
                }

                testFlag[ALL_HIGH] = FALSE;
                system_status.testState = FAIL;
                input_Error(system_status.input_error);
            }
        }

        else
        {
            // Test state is neither ALL_LOW nor ALL_HIGH
            testFlag[ALL_LOW] = FALSE;
            testFlag[ALL_HIGH] = FALSE;
            Fatal_Error();
        }
    }

    else
    {
        // Set error flags for TRIP2 being active


        if (TRIP2_status != PRESSED && TRIP2_status != AGAIN_PRESSED && TRIP2_status != STILL_PRESSED)
        {
            Error_signal_Flag[TRIP2] = TRUE;
            system_status.input_error = TRIP2;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error );


        if (system_status.testState == ALL_LOW)
        {
            testFlag[ALL_LOW] = FALSE;
            state_Error(ALL_LOW);
        }

        else if (system_status.testState == ALL_HIGH)
        {
            testFlag[ALL_HIGH] = FALSE;
            state_Error(ALL_HIGH);
        }

        else
        {
            Fatal_Error();
        }
    }
}



/*  Function    : check_Input_Reset
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the Reset state.
 */



void check_Input_Reset()
{
    // Check status of active signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check inactive signal
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check if TRIP2 is active and all other signals are inactive
    if (TRIP2_status == RELEASED || TRIP2_status == AGAIN_RELEASED || TRIP2_status == STILL_RELEASED)
    {
        // Check inactive signals
        if ((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
            (LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
            (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
            (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
            (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
            (TRIP1_status == RELEASED || TRIP1_status == AGAIN_RELEASED || TRIP1_status == STILL_RELEASED) &&
            (HORN_status == RELEASED || HORN_status == AGAIN_RELEASED || HORN_status == STILL_RELEASED))
        {
            // Set flag for successful reset state
            testFlag[RESET_STATE] = TRUE;
            pressed_flag[TRIP2] = TRUE;
        }

        else
        {
            // Set error flags for any active signals
            if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS1] = TRUE;
                system_status.input_error = LS1;
            }
            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }
            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }
            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }
            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }
            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS6;
            }
            if (TRIP1_status != RELEASED && TRIP1_status != AGAIN_RELEASED && TRIP1_status != STILL_RELEASED)
            {
                Error_signal_Flag[TRIP1] = TRUE;
                system_status.input_error = TRIP1;
            }
            if (HORN_status != RELEASED && HORN_status != AGAIN_RELEASED && HORN_status != STILL_RELEASED)
            {
                Error_signal_Flag[HORN] = TRUE;
                system_status.input_error = HORN;
            }

            testFlag[RESET_STATE] = FALSE;
            input_Error(system_status.input_error);
            system_status.testState = FAIL;
        }
    }

    else
    {
        // Set error flags for TRIP2 being inactive

        testFlag[RESET_STATE] = FALSE;

        if (TRIP2_status != RELEASED && TRIP2_status != AGAIN_RELEASED && TRIP2_status != STILL_RELEASED)
        {
            Error_signal_Flag[TRIP2] = TRUE;
            system_status.input_error = TRIP2;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);
    }
}



/*  Function    : check_Input_Ok
 *  Inputs      : -
 *  Return      : -
 *  Desc        : Checking  inputs of the OK state.
 */

void check_Input_Ok()
{
    // Check status of active signals
    u8 LS1_status = Button_State_Func(&input_check_point[LS1]);
    u8 LS2_status = Button_State_Func(&input_check_point[LS2]);
    u8 LS3_status = Button_State_Func(&input_check_point[LS3]);
    u8 LS4_status = Button_State_Func(&input_check_point[LS4]);
    u8 LS5_status = Button_State_Func(&input_check_point[LS5]);
    u8 LS6_status = Button_State_Func(&input_check_point[LS6]);
    u8 TRIP1_status = Button_State_Func(&input_check_point[TRIP1]);
    u8 HORN_status = Button_State_Func(&input_check_point[HORN]);

    // Check inactive signal
    u8 TRIP2_status = Button_State_Func(&input_check_point[TRIP2]);

    // Check if TRIP2 is active and all other signals are inactive
    if (TRIP2_status == RELEASED || TRIP2_status == AGAIN_RELEASED || TRIP2_status == STILL_RELEASED)
    {
        // Check inactive signals
        if ((LS1_status == RELEASED || LS1_status == AGAIN_RELEASED || LS1_status == STILL_RELEASED) &&
            (LS2_status == RELEASED || LS2_status == AGAIN_RELEASED || LS2_status == STILL_RELEASED) &&
            (LS3_status == RELEASED || LS3_status == AGAIN_RELEASED || LS3_status == STILL_RELEASED) &&
            (LS4_status == RELEASED || LS4_status == AGAIN_RELEASED || LS4_status == STILL_RELEASED) &&
            (LS5_status == RELEASED || LS5_status == AGAIN_RELEASED || LS5_status == STILL_RELEASED) &&
            (TRIP1_status == RELEASED || TRIP1_status == AGAIN_RELEASED || TRIP1_status == STILL_RELEASED) &&
            (HORN_status == RELEASED || HORN_status == AGAIN_RELEASED || HORN_status == STILL_RELEASED))
        {
            // Set flag for successful OK state
            testFlag[OK] = TRUE;
            pressed_flag[TRIP2] = TRUE;
        }

        else
        {
            // Set error flags for any active signals
            if (LS1_status != RELEASED && LS1_status != AGAIN_RELEASED && LS1_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS1] = TRUE;
                system_status.input_error = LS1;
            }
            if (LS2_status != RELEASED && LS2_status != AGAIN_RELEASED && LS2_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS2] = TRUE;
                system_status.input_error = LS2;
            }
            if (LS3_status != RELEASED && LS3_status != AGAIN_RELEASED && LS3_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS3] = TRUE;
                system_status.input_error = LS3;
            }
            if (LS4_status != RELEASED && LS4_status != AGAIN_RELEASED && LS4_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS4] = TRUE;
                system_status.input_error = LS4;
            }
            if (LS5_status != RELEASED && LS5_status != AGAIN_RELEASED && LS5_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS5] = TRUE;
                system_status.input_error = LS5;
            }
            if (LS6_status != RELEASED && LS6_status != AGAIN_RELEASED && LS6_status != STILL_RELEASED)
            {
                Error_signal_Flag[LS6] = TRUE;
                system_status.input_error = LS6;
            }
            if (TRIP1_status != RELEASED && TRIP1_status != AGAIN_RELEASED && TRIP1_status != STILL_RELEASED)
            {
                Error_signal_Flag[TRIP1] = TRUE;
                system_status.input_error = TRIP1;
            }
            if (HORN_status != RELEASED && HORN_status != AGAIN_RELEASED && HORN_status != STILL_RELEASED)
            {
                Error_signal_Flag[HORN] = TRUE;
                system_status.input_error = HORN;
            }
            testFlag[OK] = FALSE;
            input_Error(system_status.input_error);
            system_status.testState = FAIL;
        }
    }

    else
    {
        // Set error flags for TRIP2 being inactive

        testFlag[OK] = FALSE;

        if (TRIP2_status != RELEASED && TRIP2_status != AGAIN_RELEASED && TRIP2_status != STILL_RELEASED)
        {
            Error_signal_Flag[TRIP2] = TRUE;
            system_status.input_error = TRIP2;
        }

        system_status.testState = FAIL;
        input_Error(system_status.input_error);
    }
}
