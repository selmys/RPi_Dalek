#include <unistd.h>
#include <wiringPi.h>
#include "pins.h"

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
        digitalWrite(STEP, HIGH);
        usleep(SLEEP_TIME);
        digitalWrite(STEP, LOW);
        usleep(SLEEP_TIME);
    }
}

