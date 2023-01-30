#ifndef _LEDarray_H
#define _LEDarray_H

#include <xc.h>

#define _XTAL_FREQ 64000000

//function prototypes
void LEDarray_init(void);
void LDRbutton_init(void);
void RF2button_init(void);
void LEDarray_disp_bin(unsigned int number);
void LEDarray_disp_dec(int number);
void LEDarray_disp_linear(int number,int max);
void LEDarray_disp_bin_n(int number, int max);
void LEDarray_disp_PPM(int cur_max, int max, int cal_max);


#endif
