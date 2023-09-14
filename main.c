#include <msp430.h> 
#include "button.h"

/**
 * main.c
 */


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    SFRRPCR |= SYSNMIIES | SYSNMI;            // Select NMI function for the RST/NMI pin,

                                             // interrupt on falling edge

                                             // (pull-up R on RST/NMI is already enabled after PUC)

	initSystem();
	task_manager();


	return 0;
}
