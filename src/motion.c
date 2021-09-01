#include <stdio.h>
#include <wiringPi.h>
#include "pins.h"

unsigned long last_time_bumper_hit = 0;
unsigned long last_time_motion_sensed = 0;
int ml=0,mr=0;

void MotionLeft(void) {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_time_motion_sensed > 200) {
        printf("Motion Left Detected!\n");
    }
    last_time_motion_sensed = interrupt_time;
    ml=1;
}

void MotionRight(void) {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_time_motion_sensed > 200) {
        printf("Motion Right Detected!\n");
    }
    last_time_motion_sensed = interrupt_time;
    mr=1;
}

