
#include <stdio.h>
#include <time.h>
#include <wiringPi.h>

#include <nmc/sio_util.h>
#include <nmc/nmccom.h>
#include <nmc/picio.h>
#include <nmc/picservo.h>

#include "pins.h"

// This routine calls the function NmcInit() to initialize all of the
// controllers found on the specified serial port.  Controller addresses
// are dynamically set, with the end controller starting at address = 1;
// All module group addresses are set to 0xFF.  Addresses may be changed
// later if required, but most applications may leave the addresses as
// set by NmcInit(). The global variable mod[] is an array of type NMCMOD
// which contains basic information about each module found on the network.
// The data type NMCMOD is defined in nmccom.h.
void Init ()
{
    int i, nummod;
    char device[13] = "/dev/ttyS0";
    nummod = NmcInit (device, 19200); //Returns # of modules found

    printf ("Enumerating devices\n");
    if (nummod == 0) {
        printf("No Servo Controllers found.\n");
        NmcShutdown ();
    }
    else {
          for (i = 0; i < nummod; i++){
                if (NmcGetModType ((byte) (i + 1)) == SERVOMODTYPE){
                      printf ("Module %d: PIC-SERVO Controller\n", i + 1);
                }
                if (NmcGetModType ((byte) (i + 1)) == IOMODTYPE){
                      printf ("Module %d: PIC-IO Controller\n", i + 1);
                }
          }
          if (NmcGetModType (1) != SERVOMODTYPE){
                printf ("Module 1 not a PIC-SERVO\n");
                NmcShutdown ();
          }
    }
}

// Set the servo parameters for motor controllers (wheels) 1 and 2
void SetGain ()
{
    ServoSetGain (LEFT, //wheel = 1
              100,  //Kp = 100
              1000, //Kd = 1000
              0,    //Ki = 0
              0,    //IL = 0
              255,  //OL = 255
              0,    //CL = 0
              4000, //EL = 4000
              1,    //SR = 1
              0     //DC = 0
        );

    ServoSetGain (RIGHT, //wheel = 2
              100,  //Kp = 100
              1000, //Kd = 1000
              0,    //Ki = 0
              0,    //IL = 0
              255,  //OL = 255
              0,    //CL = 0
              4000, //EL = 4000
              1,    //SR = 1
              0     //DC = 0
        );
}

// This routine enables the amplifier and starts the motor
// servoing at its current position.
void ServoOn (int wheel)
{
    ServoStopMotor (wheel, AMP_ENABLE | MOTOR_OFF); //enable amp
    ServoStopMotor (wheel, AMP_ENABLE | STOP_ABRUPT);//stop at current pos.
    ServoResetPos (wheel);              //reset the posiiton counter to 0
}

// This routine loads a trapezoidal profile trajectory
// (position, velocity and acceleration) and starts the
// motion immediately.
void StartWheel(int wheel, int direction, int speed)
{
    printf("Starting wheel %d, direction %x, speed %d at %d\n",
        wheel,direction,speed,(int)time(NULL));

    switch (wheel) {
        case LEFT:
            if(direction == FORWARD) direction = REVERSE;
            else direction = FORWARD;
    }

    ServoLoadTraj (wheel, LOAD_VEL | LOAD_ACC | VEL_MODE | ENABLE_SERVO | direction | START_NOW,
               0,       //pos
               speed,   //vel
               2000,    //acc = 100 initially
               0        //pwm
        );
}

void StopWheel(int wheel)
{
    ServoStopMotor(wheel, AMP_ENABLE | STOP_SMOOTH);
}

void AllStop()
{
    ServoStopMotor(LEFT, AMP_ENABLE | STOP_SMOOTH);
    ServoStopMotor(RIGHT, AMP_ENABLE | STOP_SMOOTH);
}

void AheadFull()
{
    StartWheel(RIGHT,FORWARD,SPEED);
    StartWheel(LEFT,FORWARD,SPEED);
}

void ReverseFull()
{
    StartWheel(RIGHT,REVERSE,SPEED);
    StartWheel(LEFT,REVERSE,SPEED);
}

void ReadPos (int addr)
{
    long position;

    //Cause PIC-SERVO controller to send back position data with each command
    //Position data will also be sent back with this command
    NmcDefineStatus (addr, SEND_POS);

    //Retrieve the position data from the local data structure
    position = ServoGetPos (addr);
    printf ("Current Position: %ld\n", position);
}

void TurnRight(unsigned int t)
{
    AllStop();
    StartWheel(LEFT,FORWARD,SPEED);
    delay(t); //milliseconds
    StopWheel(LEFT);
}

void TurnLeft(unsigned int t)
{
    AllStop();
    StartWheel(RIGHT,FORWARD,SPEED);
    delay(t); //milliseconds
    StopWheel(RIGHT);
}


