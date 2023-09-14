/******************** (C) COPYRIGHT 2023 ORION EE ********************************
* File Name          : bsp.h
* Author             : Burak Ozsahin
* Version            : V1.0.0
* Date               : 21/08/2023
* Description        : board source package
********************************************************************************/
#ifndef BSP_H_
#define BSP_H_

/***************************************************INPUTs -> Check pins******************************/

/* Port Name    :   P4.2
 * Pin Number   :   35
 * Net Name     :   Mute
 */

#define MUTE_PIN    BIT2
#define MUTE_PORT   P4OUT
#define MUTE_IN     P4IN
#define MUTE_DIR    P4DIR
#define MUTE_REN    P4REN

/* Port Name    :   P2.7
 * Pin Number   :   36
 * Net Name     :   Reset
 */

#define RESET_PIN    BIT7
#define RESET_PORT   P2OUT
#define RESET_IN     P2IN
#define RESET_DIR    P2DIR
#define RESET_REN    P2REN

/* Port Name    :   P4.1
 * Pin Number   :   34
 * Net Name     :   Test
 */

#define TEST_PIN    BIT1
#define TEST_PORT   P4OUT
#define TEST_IN     P4IN
#define TEST_DIR    P4DIR
#define TEST_REN    P4REN

/* Port Name    :   P2.1
 * Pin Number   :   47
 * Net Name     :   LS1
 */

#define LS1_PIN    BIT1
#define LS1_PORT   P2OUT
#define LS1_IN     P2IN
#define LS1_DIR    P2DIR
#define LS1_REN    P2REN

/* Port Name    :   P2.0
 * Pin Number   :   46
 * Net Name     :   LS2
 */

#define LS2_PIN    BIT0
#define LS2_PORT   P2OUT
#define LS2_IN     P2IN
#define LS2_DIR    P2DIR
#define LS2_REN    P2REN


/* Port Name    :   P5.2
 * Pin Number   :   45
 * Net Name     :   LS3
 */

#define LS3_PIN    BIT2
#define LS3_PORT   P5OUT
#define LS3_IN     P5IN
#define LS3_DIR    P5DIR
#define LS3_REN    P5REN

/* Port Name    :   P5.1
 * Pin Number   :   44
 * Net Name     :   LS4
 */

#define LS4_PIN    BIT1
#define LS4_PORT   P5OUT
#define LS4_IN     P5IN
#define LS4_DIR    P5DIR
#define LS4_REN    P5REN

/* Port Name    :   P5.0
 * Pin Number   :   43
 * Net Name     :   LS5
 */

#define LS5_PIN    BIT0
#define LS5_PORT   P5OUT
#define LS5_IN     P5IN
#define LS5_DIR    P5DIR
#define LS5_REN    P5REN

/* Port Name    :   P4.7
 * Pin Number   :   42
 * Net Name     :   LS6
 */

#define LS6_PIN    BIT7
#define LS6_PORT   P4OUT
#define LS6_IN     P4IN
#define LS6_DIR    P4DIR
#define LS6_REN    P4REN


/// 3 tane daha eklendi ortak input tanýmlamalarý


/* Port Name    :   P6.2
 * Pin Number   :   41
 * Net Name     :   TRIP1
 */

#define TRIP1_PIN    BIT2
#define TRIP1_PORT   P6OUT
#define TRIP1_IN     P6IN
#define TRIP1_DIR    P6DIR
#define TRIP1_REN    P6REN

/* Port Name    :   P6.1
 * Pin Number   :   40
 * Net Name     :   TRIP2
 */

#define TRIP2_PIN    BIT1
#define TRIP2_PORT   P6OUT
#define TRIP2_IN     P6IN
#define TRIP2_DIR    P6DIR
#define TRIP2_REN    P6REN

/* Port Name    :   P3.6
 * Pin Number   :   39
 * Net Name     :   Horn
 */

#define HORN_PIN    BIT6
#define HORN_PORT   P3OUT
#define HORN_IN     P3IN
#define HORN_DIR    P3DIR
#define HORN_REN    P3REN


/* Port Name    :   P4.0
 * Pin Number   :   22
 * Net Name     :   Start
 */

#define START_PIN    BIT0
#define START_PORT   P4OUT
#define START_IN     P4IN
#define START_DIR    P4DIR
#define START_REN    P4REN


/* Port Name    :   P2.3
 * Pin Number   :   25
 * Net Name     :   BUT1
 */

#define BUTTON1_PIN    BIT3
#define BUTTON1_PORT   P2OUT
#define BUTTON1_IN     P2IN
#define BUTTON1_DIR    P2DIR
#define BUTTON1_REN    P2REN



/******************************************OUTPUTs Manage Pins***************************/

/* Port Name    :   P4.4
 * Pin Number   :   9
 * Net Name     :   Base4
 */

#define BASE4_PIN     BIT4
#define BASE4_PORT    P4OUT
#define BASE4_DIR     P4DIR

/* Port Name    :   P4.3
 * Pin Number   :   8
 * Net Name     :   Base3
 */

#define BASE3_PIN     BIT3
#define BASE3_PORT    P4OUT
#define BASE3_DIR     P4DIR

/* Port Name    :   P1.7
 * Pin Number   :   7
 * Net Name     :   Base2
 */

#define BASE2_PIN     BIT7
#define BASE2_PORT    P1OUT
#define BASE2_DIR     P1DIR

/* Port Name    :   P1.6
 * Pin Number   :   6
 * Net Name     :   Base1
 */

#define BASE1_PIN     BIT6
#define BASE1_PORT    P1OUT
#define BASE1_DIR     P1DIR

/* Port Name    :   P5.3
 * Pin Number   :   10
 * Net Name     :   Base5
 */

#define BASE5_PIN     BIT3
#define BASE5_PORT    P5OUT
#define BASE5_DIR     P5DIR

/* Port Name    :   P5.4
 * Pin Number   :   11
 * Net Name     :   Base6
 */

#define BASE6_PIN     BIT4
#define BASE6_PORT    P5OUT
#define BASE6_DIR     P5DIR



// 3 tane daha buton output ekle test_relay, mute_relay, reset_relay


/* Port Name    :   P4.0
 * Pin Number   :   33
 * Net Name     :   TestOut
 */

#define TEST_OUT_PIN     BIT0
#define TEST_OUT_PORT    P4OUT
#define TEST_OUT_DIR     P4DIR


/* Port Name    :   P3.7
 * Pin Number   :   32
 * Net Name     :   MuteOut
 */

#define MUTE_OUT_PIN     BIT7
#define MUTE_OUT_PORT    P3OUT
#define MUTE_OUT_DIR     P3DIR


/* Port Name    :   P2.4
 * Pin Number   :   28
 * Net Name     :   ResetOut
 */

#define RESET_OUT_PIN     BIT4
#define RESET_OUT_PORT    P2OUT
#define RESET_OUT_DIR     P2DIR

///  2 tane led iþlemlerin tamamlanmasýný görmek için.


/* Port Name    :   P5.8
 * Pin Number   :   11
 * Net Name     :   FAIL LED
 */

#define LED_FAIL_PIN     BIT8
#define LED_FAIL_PORT    P5OUT
#define LED_FAIL_DIR     P5DIR

/* Port Name    :   P5.9
 * Pin Number   :   12
 * Net Name     :   OK LED
 */

#define LED_OK_PIN     BIT9
#define LED_OK_PORT    P5OUT
#define LED_OK_DIR     P5DIR


// TESTER için önemli outputlar eklendi.


/* Port Name    :   P1.4
 * Pin Number   :   4
 * Net Name     :   Base LOW Sup
 */

#define LOW_POWER_PIN     BIT4
#define LOW_POWER_PORT    P1OUT
#define LOW_POWER_DIR     P1DIR



/* Port Name    :   P1.5
 * Pin Number   :   5
 * Net Name     :  Base High Sup
 */

#define HIGH_POWER_PIN     BIT5
#define HIGH_POWER_PORT    P1OUT
#define HIGH_POWER_DIR     P1DIR

/*
#define MCLK_FREQ_MHZ 8                     // MCLK = 8MHz //UART ý 8MHzde çalýþtýramayýnca 1MHz e döndük
#define CPU_CLK 	8000000                 // Hz
*/

/*
#define MCLK_FREQ_MHZ 16                     // MCLK = 16MHz
#define CPU_CLK     16000000                    //Hz
*/

#define MCLK_FREQ_MHZ 1                     // MCLK = 1MHz
#define CPU_CLK     1000000                    //Hz

#define TIMER_CLK CPU_CLK/4                 //  /4 ID_2 TACCRv ayarýndan gelecek
#define TIMER_FREQ 	1000                    //Hz  : kullanýcý ayarý



/********************* LCD için gerekli tanýmlar. *************************/



#ifdef LCD_H_
#define DR              RS_PIN_OUT = RS_PIN_OUT | RS_PIN_BIT    // define RS high
#define CWR             RS_PIN_OUT = RS_PIN_OUT & (~RS_PIN_BIT) // define RS low
#define READ            R_W_PIN_OUT = R_W_PIN_OUT | R_W_PIN_BIT    // define Read signal R/W = 1 for reading
#define WRITE           R_W_PIN_OUT = R_W_PIN_OUT & (~R_W_PIN_BIT) // define Write signal R/W = 0 for writing
#define ENABLE_HIGH     LCD_EN_PIN_OUT = LCD_EN_PIN_OUT | LCD_EN_PIN_BIT    // define Enable high signal
#define ENABLE_LOW      LCD_EN_PIN_OUT = LCD_EN_PIN_OUT & (~LCD_EN_PIN_BIT) // define Enable Low signal

#define ENABLE_BRIGHTNESS   VLED_CONTROL_PIN_OUT |= VLED_CONTROL_PIN_BIT
#define DISABLE_BRIGHTNESS  VLED_CONTROL_PIN_OUT &= ~VLED_CONTROL_PIN_BIT

#define ENABLE_LCD              BOOST_EN_PIN_OUT |= BOOST_EN_PIN_BIT
#define DISABLE_LCD             BOOST_EN_PIN_OUT &= ~BOOST_EN_PIN_BIT

#define ENABLE_RELAY1           RELAY_1_CONTROL_PIN_OUT |= RELAY_1_CONTROL_PIN_BIT
#define DISABLE_RELAY1          RELAY_1_CONTROL_PIN_OUT &= ~RELAY_1_CONTROL_PIN_BIT

#define ENABLE_RELAY2           RELAY_2_CONTROL_PIN_OUT |= RELAY_2_CONTROL_PIN_BIT
#define DISABLE_RELAY2          RELAY_2_CONTROL_PIN_OUT &= ~RELAY_2_CONTROL_PIN_BIT

#define ENABLE_PWR_LED          BAT_LOW_LED_PIN_OUT |= BAT_LOW_LED_PIN_BIT
#define DISABLE_PWR_LED         BAT_LOW_LED_PIN_OUT &= ~BAT_LOW_LED_PIN_BIT

#define DKT_TESTER

//#define LCD_OFI

#ifdef DKT_TESTER

#define D4_PIN_DIR  P5DIR
#define D4_PIN_OUT  P5OUT
#define D4_PIN_BIT  BIT7

#define D5_PIN_DIR  P6DIR
#define D5_PIN_OUT  P6OUT
#define D5_PIN_BIT  BIT0

#define D6_PIN_DIR  P3DIR
#define D6_PIN_OUT  P3OUT
#define D6_PIN_BIT  BIT0

#define D7_PIN_DIR  P3DIR
#define D7_PIN_OUT  P3OUT
#define D7_PIN_IN   P3IN
#define D7_PIN_BIT  BIT3

#define RS_PIN_DIR  P1DIR
#define RS_PIN_OUT  P1OUT
#define RS_PIN_BIT  BIT2

#define R_W_PIN_DIR  P1DIR
#define R_W_PIN_OUT  P1OUT
#define R_W_PIN_BIT  BIT3

#define LCD_EN_PIN_DIR  P2DIR
#define LCD_EN_PIN_OUT  P2OUT
#define LCD_EN_PIN_BIT  BIT2

#endif /*DKT_TESTER*/

/*
#ifdef LCD_OFI

#define D0_PIN_DIR  P3DIR
#define D0_PIN_OUT  P3OUT
#define D0_PIN_BIT  BIT6

#define D1_PIN_DIR  P3DIR
#define D1_PIN_OUT  P3OUT
#define D1_PIN_BIT  BIT2

#define D2_PIN_DIR  P3DIR
#define D2_PIN_OUT  P3OUT
#define D2_PIN_BIT  BIT5

#define D3_PIN_DIR  P2DIR
#define D3_PIN_OUT  P2OUT
#define D3_PIN_IN   P2IN
#define D3_PIN_BIT  BIT7

#define D4_PIN_DIR  P4DIR
#define D4_PIN_OUT  P4OUT
#define D4_PIN_BIT  BIT2

#define D5_PIN_DIR  P4DIR
#define D5_PIN_OUT  P4OUT
#define D5_PIN_BIT  BIT1

#define D6_PIN_DIR  P4DIR
#define D6_PIN_OUT  P4OUT
#define D6_PIN_BIT  BIT0

#define D7_PIN_DIR  P3DIR
#define D7_PIN_OUT  P3OUT
#define D7_PIN_IN   P3IN
#define D7_PIN_BIT  BIT7

#define RS_PIN_DIR  P4DIR
#define RS_PIN_OUT  P4OUT
#define RS_PIN_BIT  BIT7

#define R_W_PIN_DIR  P6DIR
#define R_W_PIN_OUT  P6OUT
#define R_W_PIN_BIT  BIT2

#define LCD_EN_PIN_DIR  P6DIR
#define LCD_EN_PIN_OUT  P6OUT
#define LCD_EN_PIN_BIT  BIT1

*/

// F-sense için:

/* Port Name    :   P6.0
 * Pin Number   :   22
 * Net Name     :   EN-T
 */

// BOOSTER_EN
//#define BOOST_EN_PIN_DIR  P6DIR
//#define BOOST_EN_PIN_OUT  P6OUT
//#define BOOST_EN_PIN_BIT  BIT0


/* Port Name    :   P2.0
 * Pin Number   :   46
 * Net Name     :   EN-R-T  //REGULATOR_EN
 */
//#define REG_EN_PIN_DIR  P2DIR
//#define REG_EN_PIN_OUT  P2OUT
//#define REG_EN_PIN_BIT  BIT0


//#endif /*LCD_OFI*/



#endif /*LCD*/


/* END BSP */


#endif /*_BSP_H_*/
