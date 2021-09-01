#include <wiringPi.h>
#include "pins.h"

void FireTaser() {
    digitalWrite(TASER, HIGH);
    delay(1000);
    digitalWrite(TASER, LOW);
}
