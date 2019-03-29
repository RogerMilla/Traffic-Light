// DEVELOPED BY ROGER MILLA FORTUNATO SANTOS
#ifndef TRAFFICLIGHT_HPP
#define TRAFFICLIGHT_HPP
#include "mbed.h"


extern InterruptIn button;

extern float time_pressed;
extern int last_led,blink_activated,Shut_Down,t_press,value,check_actual;

void Leds_OFF();

int Check_Last_Led();
void timing_condt();

void GreenLed_ON();
void YellowLed_ON();
void RedLed_ON();

void timer_begin();
void timer_end();
void blink();
void blink_BLUE();

#endif
