
// Motion Sensor defines
#define MOTION_LEFT 10
#define MOTION_RIGHT 9

void MotionLeft(void) {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_time_motion_sensed > 200) {
        printf("Motion Left Detected!\n");
        SaySomething("Danger! Attack left!");
    }
    last_time_motion_sensed = interrupt_time;
    ml=1;
}

void MotionRight(void) {
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_time_motion_sensed > 200) {
        printf("Motion Right Detected!\n");
        SaySomething("Danger! Attack right!");
    }
    last_time_motion_sensed = interrupt_time;
    mr=1;
}

