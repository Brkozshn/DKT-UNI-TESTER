/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : button.h
* Author             : Burak Ozsahin
* Version            : V1.0
* Date               : 21/08/2023
* Description        : button header
********************************************************************************/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "main.h"

#define BUTTON

#ifdef BUTTON
#define I1_INPUT_MS 10
#define BUTTON_MS I1_INPUT_MS

typedef struct button_s
{
    u8 LASTVALUE;
    u8 VALUE;
    u8 BUTTON_PRESSED_CONFIG;
    u8 BUTTON_RELEASED_CONFIG;
    u8 BUTTON_MASK;
    vu8 *BUTTON_PORT_IN;
} button_t;



/*Kullanýlan butonlarýn isimleri buraya yazýlýr, bu sayede otomatik olarak o kadar buton tanýmlanýr*/


// Inputs from DKT-66 TESTER


enum
{

    LS1=0,
    LS2,
    LS3,
    LS4,
    LS5,
    LS6,
    TRIP1,
    TRIP2,
    HORN,                          // Signals to control ends here.
    MUTE,
    RESET,
    TEST,
    START,
    BUTTON1,

    NUM_OF_INPUT_POINT

};



/* Bütün testlerin doðruluðunu kontrol etmek için enum  */

/*
enum
{

    S1=0,
    S2,
    S3,
    S4,
    S5,
    S6,
    OFF_TEST,
    LOW_IDLE_TEST,
    ALL_LOW_TEST,
    ALL_HIGH_TEST,
    RESET_TEST,
    OK,
    DONE,
    INRESETTED,


    NUM_OF_TEST_POINT
};
*/


/*  Switch case içindeki case'ler bu sayede case isimleri daha anlaþýlýr olacak.    */

// TESTER'da test edilecek her case için enum.


enum
{

    OFF=0,
    LOW_IDLE,
    SIGNAL1,
    MUTE_STATE,
    SIGNAL2,
    SIGNAL3,
    SIGNAL4,
    SIGNAL5,
    SIGNAL6,
    ALL_LOW,
    ALL_HIGH,
    RESET_STATE,
    OK,
    FAIL,

    // Önce output sonra input kontrol edilecek. Her case içinde output - input arasý 100 ms olacak.

    // Bütün case'leri ekle

    NUM_OF_CASE

};


// DKT-66 TESTER için outputlar


enum
{

    TEST_OUT=0,
    MUTE_OUT,
    RESET_OUT,
    LOW_POWER,
    HIGH_POWER,
    BASE1,
    BASE2,
    BASE3,
    BASE4,
    BASE5,
    BASE6,

    NUM_OF_OUTPUT_POINT

};


// Button veya input kontrolü için gerekli enum

enum {
    PRESSED,
    RELEASED,
    AGAIN_PRESSED,
    AGAIN_RELEASED,
    STILL_PRESSED,
    STILL_RELEASED,
    UNKNOWN,
    BUTTON_STATUS_FAIL,

    NUM_OF_BUTTON_STATUS
};


enum {

    OUTPUT,
    INPUT,

    NUM_OF_TRANSITION_STATE

};


#define BUTTON_READ_PIN(button_ptr) *(button_ptr->BUTTON_PORT_IN)


/* Kullanýlacak butonlarýn veya inputlarýn gerekli ayarlamalarý burada yapýlýr*/

#define LS1_MASK                 LS1_PIN
#define LS1_PRESSED_CFG          LS1_PIN
#define LS1_RELEASED_CFG         0x00

#define LS2_MASK                 LS2_PIN
#define LS2_PRESSED_CFG          LS2_PIN
#define LS2_RELEASED_CFG         0x00

#define LS3_MASK                 LS3_PIN
#define LS3_PRESSED_CFG          LS3_PIN
#define LS3_RELEASED_CFG         0x00

#define LS4_MASK                 LS4_PIN
#define LS4_PRESSED_CFG          LS4_PIN
#define LS4_RELEASED_CFG         0x00

#define LS5_MASK                 LS5_PIN
#define LS5_PRESSED_CFG          LS5_PIN
#define LS5_RELEASED_CFG         0x00

#define LS6_MASK                 LS6_PIN
#define LS6_PRESSED_CFG          LS6_PIN
#define LS6_RELEASED_CFG         0x00

#define MUTE_MASK                       MUTE_PIN
#define MUTE_PRESSED_CFG                MUTE_PIN
#define MUTE_RELEASED_CFG               0x00

#define RESET_MASK                      RESET_PIN
#define RESET_PRESSED_CFG               RESET_PIN
#define RESET_RELEASED_CFG              0x00

#define TEST_MASK                       TEST_PIN
#define TEST_PRESSED_CFG                TEST_PIN
#define TEST_RELEASED_CFG               0x00


#define TRIP1_MASK                       TRIP1_PIN
#define TRIP1_PRESSED_CFG                TRIP1_PIN
#define TRIP1_RELEASED_CFG               0x00

#define  TRIP2_MASK                      TRIP2_PIN
#define  TRIP2_PRESSED_CFG               0x00
#define  TRIP2_RELEASED_CFG              TRIP2_PIN

#define  HORN_MASK                       HORN_PIN
#define  HORN_PRESSED_CFG                HORN_PIN
#define  HORN_RELEASED_CFG               0x00


#define  START_MASK                       START_PIN
#define  START_PRESSED_CFG                START_PIN
#define  START_RELEASED_CFG               0x00


#define  BUTTON1_MASK                       BUTTON1_PIN
#define  BUTTON1_PRESSED_CFG                BUTTON1_PIN
#define  BUTTON1_RELEASED_CFG               0x00



extern u8 Button_State_Func(button_t *button_ptr);
extern u8 is_Button_Pressed_Func(button_t *button_ptr);
extern u8 check_button(u8 button_name,u8 btn_name_ms);


extern button_t input_check_point[NUM_OF_INPUT_POINT];
extern u8 status_Inputs[NUM_OF_INPUT_POINT];
extern u8 pressed_flag[NUM_OF_INPUT_POINT];                        // for determining buttons are pressed or not
extern u8 testFlag[NUM_OF_CASE];                             // make sure that all tests are corrected.
extern u16 Error_signal_Flag[NUM_OF_INPUT_POINT];                   // for detecting the wrong signal.
extern u8 inputOutputTransition[NUM_OF_TRANSITION_STATE];

extern u8 TRIP1_flag;
extern int TRIP1_cnt;
extern u8 led_pins;
extern u8 relay_pins;

#endif /*BUTTON */



#endif /* BUTTON_H_ */
