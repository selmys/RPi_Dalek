//Note: All GPIOs are in INPUT mode at boot up.
//      GPIO 0-8 have pull-ups to 3V3 enabled, 
//      GPIO 9-27 have pull-downs to 0V enabled.

// Servo motor defines
#define LEFT 2
#define RIGHT 1
#define SPEED 2000000
#define FORWARD 0x00    //REVERSE already defined as 0x40 in nmccom.h

// Bumper defines
#define RIGHT_FRONT_BUMPER_GPIO  0
#define LEFT_FRONT_BUMPER_GPIO   5
#define RIGHT_REAR_BUMPER_GPIO   6
#define LEFT_REAR_BUMPER_GPIO   13

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

// Sonar defines
#define SONAR_ECHO  4
#define SONAR_TRIG 11

// Motion Sensor defines
#define MOTION_LEFT 10
#define MOTION_RIGHT 9

// LED defines
#define RED_LEFT    27
#define GREEN_RIGHT 22

// Taser defines
#define TASER 17

