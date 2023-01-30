#include <xc.h>
#include "timers.h"

/************************************
 * Function to set up timer 0
************************************/
void Timer0_init(void)
{
    T0CON1bits.T0CS=0b010; // Fosc/4
    T0CON1bits.T0ASYNC=0; // see datasheet errata - needed to ensure correct operation when Fosc/4 used as clock source
    
    T0CON1bits.T0CKPS=0b1000; // the equation to arrive at 1:244.1 ratio is
    /*
     * Frequency = 64 Mhz
     * Max bin val = 65536
     * Seconds to max val = max bin val / (clock frequency/4)
     * We need to divide by 4 because of Fosc/4
     * Ratio = 1 / seconds to max
     */
    T0CON0bits.T016BIT=1;	//8bit mode	
	
    // it's a good idea to initialise the timer registers so we know we are at 0
    TMR0H=0b11111111;            //write High reg first, update happens when low reg is written to
    TMR0L=0;
    T0CON0bits.T0EN=1;	//start the timer
}

/************************************
 * Function to return the full 16bit timer value
 * Note TMR0L and TMR0H must be read in the correct order, or TMR0H will not contain the correct value
************************************/
unsigned int get16bitTMR0val(void)
{
	//add your code to get the full 16 bit timer value here
    return (TMR0H <<8)|TMR0L; //combining the high register at(TMROH)(shifting it up) with the low register (TMR0L)
}
