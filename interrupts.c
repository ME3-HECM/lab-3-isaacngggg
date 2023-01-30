#include <xc.h>
#include "interrupts.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
	// turn on global interrupts, peripheral interrupts and the interrupt source 
	// It's a good idea to turn on global interrupts last, once all other interrupt configuration is done.
    INTCONbits.PEIE = 1; // setting up peripheral interrupts
    PIE2bits.C1IE = 1; // setting up the interrupt source p700
    PIR2bits.C1IF = 0; // resetting the flag
    
    PIE0bits.TMR0IE = 1; // setting up the interrupt source p700
    PIR0bits.TMR0IF = 0; // resetting the flag
    
    IPR2bits.C1IP = 1; // setting it to high priority
    INTCONbits.GIE=1; 	//turn on interrupts globally (when this is off, all interrupts are deactivated)

}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{
	//add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...
    //this is the interrupt for the LDR comparator
    if(PIR2bits.C1IF){
        
        LATDbits.LATD7 = !LATDbits.LATD7;
        PIR2bits.C1IF = 0;
        
    }
    
    // this is the interrupt for the timer
    if(PIR0bits.TMR0IF){
        
        LATDbits.LATD7 = !LATDbits.LATD7;
        PIR0bits.TMR0IF = 0;
        
    }
}
