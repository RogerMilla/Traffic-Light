// DEVELOPED BY ROGER MILLA FORTUNATO SANTOS

#include "TrafficLight.hpp"



DigitalOut myGREENled(PD_12);
DigitalOut myYELLOWled(PD_13);
DigitalOut myREDled(PD_14);
DigitalOut myBLUEled(PD_15);
Timeout timeout;
Ticker ticker,ticker_Blue;
Timer timer;

//**************************************************************************
//---------------------------- CHECK LAST LED ON ---------------------------

int Check_Last_Led()
{


    if (myGREENled.read()==1) {
        value = 1;
    } else if (myYELLOWled.read()==1) {
        value = 2;
    } else if (myREDled.read()==1) {
        value = 3;
    }

    return value;
}


//**************************************************************************
//---------------------------- LEDS TIMING CONDITION  ----------------------

void timing_condt()
{


    if ((3<=time_pressed)&&(time_pressed<10) && Shut_Down==0) {

        if (blink_activated==0) {
            t_press=5;
        } else {
            t_press=last_led;
            ticker.detach();
            blink_activated=0;
        }


    } else if (time_pressed>=10) {

        if (Shut_Down==0) {
            t_press=10;
            ticker.detach();
        } else if (blink_activated==0) {
            blink_activated=0;
            t_press=check_actual;
            Shut_Down=0;
        } else {
            blink_activated=0;
            t_press=5;
            Shut_Down=0;

        }

    } else if(last_led==1 && time_pressed<3 && blink_activated==0) {
        t_press=2;
    } else {
        t_press=check_actual;
    }



    switch(t_press) {
        case 1:
            GreenLed_ON();
            break;
        case 2:
            YellowLed_ON();
            break;
        case 3:
            RedLed_ON();
            break;
        case 5:
            Leds_OFF();
            blink_activated=1;
            ticker.attach(&blink,0.5);
            break;
        case 10:
            Shut_Down=1;
            Leds_OFF();
            break;

    }
}



//**************************************************************************
//---------------------------- TURN LEDS OFF -------------------------------

void Leds_OFF()
{
    myGREENled=0;
    myYELLOWled=0;
    myREDled=0;

}

//**************************************************************************
//---------------------------- BLINK YELLOW LED ----------------------------

void blink()
{
    myYELLOWled=!myYELLOWled;
    blink_activated=1;
}

//---------------------------- BLINK BLUE LED -------------------------------
void blink_BLUE()
{
    myBLUEled=!myBLUEled;   // Each Blink correspond to 1 sec.
}

//**************************************************************************
//---------------------------- PRESS BUTTON ------------------------------

void timer_begin()             //rise, press button
{


    timer.start();
    check_actual= Check_Last_Led();
    if (blink_activated==0) {
        last_led= Check_Last_Led();
    }
    ticker_Blue.attach(&blink_BLUE,0.5);

}

void timer_end()             //fall, release button
{
    timer.stop();
    time_pressed=timer.read();
    timer.reset();
    myBLUEled=0;
    ticker_Blue.detach();
    timing_condt();
}
//**************************************************************************
//---------------------------- TURN LEDS ON ----------------------------------

void GreenLed_ON()
{
    if (blink_activated==0 && Shut_Down==0) {
        Leds_OFF();
        myGREENled=1;
        timeout.attach(&YellowLed_ON,20);
    }
}

void YellowLed_ON()
{

    if ((blink_activated==0 || check_actual==1) && Shut_Down==0) {  // Lock condition for YELLOW_LED
        Leds_OFF();
        myYELLOWled=1;
        timeout.attach(&RedLed_ON,4);

    }

}

void RedLed_ON()
{
    if (blink_activated==0 && Shut_Down==0) {  //Lock condition for RED_LED
        Leds_OFF();
        myREDled=1;
        timeout.attach(&GreenLed_ON,10);
    }
}
