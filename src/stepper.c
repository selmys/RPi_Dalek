#include <unistd.h>
#include <wiringPi.h>
#include "pins.h"

// Controlling the head of the Dalek

// Stepper motor defines
#define ENABLE      23
#define MS1         24
#define MS2         25
#define MS3          8
#define RST          7
#define SLEEP        1
#define STEP        12
#define DIRECTION   16

#define SLEEP_TIME  4000

//  MS1 MS2 MS3 STEP
//   L   L   L  FULL
//   H   L   L  HALF
//   L   H   L  QUARTER
//   H   H   L  EIGHT
//   H   H   H  SIXTEENTH

void MoveHead(int direction) {
    switch (direction) {
        case 0:  // CLOCKWISE  
                digitalWrite(DIRECTION, LOW);
                break;
        case 1:  // COUNTERCLOCKWISE
                digitalWrite(DIRECTION, HIGH);
                break;
    }
    sleep(1);
    for(int i=0;i<100;i++) {
//        printf("Step %d\n",i);
        digitalWrite(STEP, HIGH);
        usleep(SLEEP_TIME);
        digitalWrite(STEP, LOW);
        usleep(SLEEP_TIME);
    }
}

