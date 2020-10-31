/*
 *
 * Initial code from posting found on:
 * https://www.raspberrypi.org/forums/viewtopic.php?t=209270
 *
 * Linux compile:
 * gcc -Wall -o garage garage.c -lwiringPi -lpigpio -lpthread
 *
 * Modifications: Kenneth Lee and Ben Lee
 * Created/Modified: 24-Oct-2020
 *
 * 
 ****************************************************************************** 
 * MIT License
 * 
 * Copyright (c) 2020 Kenneth Lee
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pigpio.h>
#include <string.h>

#define PIN 7 

bool creature;

/*
 *
 * void handleInterrupt(int gpio, int level, uint32_t tick )
 *
 */
void handleInterrupt(int gpio, int level, uint32_t tick ){
  if(level == PI_TIMEOUT){
    if(!creature){
      creature = true;
      puts("Creature detected, make growl sound.");
      char command[50];
      strcpy(command, "mpg321 cougar.mp3");
      system(command);
    }
  }else{
    if(creature){
      creature = false;
    }
  }
}

/*
 *
 * int main(int argc, char **argv)
 *
 */
int main(int argc, char **argv) {
  /*--------Initialize and Setup--------*/
  if(wiringPiSetupGpio() != 0){
    printf("ERROR\n");
    return 1;
  }
  gpioInitialise();
  pinMode(PIN, INPUT);
  gpioSetWatchdog(PIN, 8);
  gpioSetAlertFunc(PIN, &handleInterrupt);
  
  while(1){
  
  }
}

