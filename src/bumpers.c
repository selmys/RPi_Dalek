#include <stdio.h>
#include <wiringPi.h>

// setup globals
int blf=0,brf=0,blr=0,brr=0;
unsigned long last_time_bumper_hit = 0;

// Called every time event occurs.
void RightFrontBumperHit(void) {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_time_bumper_hit > 200) {
        printf("Right Front Bumper Hit!\n");
    }
    last_time_bumper_hit = interrupt_time;
    brf=1;
}

void RightRearBumperHit(void) {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_time_bumper_hit > 200) {
        printf("Right Rear Bumper Hit!\n");
    }
    last_time_bumper_hit = interrupt_time;
    brr=1;
}

void LeftRearBumperHit(void) {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_time_bumper_hit > 200) {
        printf("Left Rear Bumper Hit!\n");
    }
    last_time_bumper_hit = interrupt_time;
    blr=1;
}

void LeftFrontBumperHit(void) {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_time_bumper_hit > 200) {
        printf("Left Front Bumper Hit!\n");
    }
    last_time_bumper_hit = interrupt_time;
    blf=1;
}
