# Traffic-Light

On this project we had the objective to simulate a Traffic Light rotine, and with a single button, according to it press state
 (that will be listed below), we may take certain action.
 
 Light Looping time:
 - GREEN ON (20 seconds)
 - YELLOW ON (4 seconds)
 - RED ON (10 seconds)
 
Button criteria

  With the system ON:

       - Single press with GREEN is ON - change it to YELLOW

       - Long Press between 3 and 10 seconds - YELLOW LED blinking.

       - Long Press more than 10 seconds - Turn OFF system
  
  With the system OFF:

       - Long Press more than 10 seconds - Turn ON the previous light before system goes OFF.
  
  Blue Led 

       - Everytime the button is short pressed it will blink once.
       - For long press, it will blink once for each second, making easier to know how many seconds you have pressed it. 
       
This project was developed using C language and implemented on STM32F4 Discovery Kit. 

For any further question, please contact me.
