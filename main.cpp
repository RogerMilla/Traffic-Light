// DEVELOPED BY ROGER MILLA FORTUNATO SANTOS

#include "mbed.h"
#include "TrafficLight.hpp"

InterruptIn button(PA_0);

extern float time_pressed=0;
extern int last_led=0,blink_activated=0,Shut_Down=0,t_press=0,value=0,check_actual=0;

int main()
{
    GreenLed_ON();
    button.rise(&timer_begin);
    button.fall(&timer_end);
}
