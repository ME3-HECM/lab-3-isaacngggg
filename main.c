// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "interrupts.h"
#include "comparator.h"
#include "LEDarray.h"
#include "timers.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  


void main(void) {
	//call your initialisation functions to set up the hardware modules
    LATDbits.LATD7= 0;   //set initial output state
    TRISDbits.TRISD7=0; //set TRIS value for pin (output)
    Interrupts_init();
    DAC_init();
    Comp1_init();
    Timer0_init();
    LEDarray_init();
    
    
    while (1) {
		LEDarray_disp_bin(get16bitTMR0val()>>8);       // display the 8 most significant bits
    }
}   