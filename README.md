# Raspberry Pi Driven Dr. Who Dalek Robot
I began thinking about this project in the summer of 2016.
I was inspired by my son and his swarm of children who,
at the time, were all [Dr. Who](https://en.wikipedia.org/wiki/Doctor_Who) fans.

I decided to model my Dalek after this image that I found somewhere on the web.
![Dalek photo](/images/blueandgreydalek.jpg) 

I began by gathering up the parts.
* 1 Raspberry Pi 3 Model B
* 1 RS232 Serial Pi Plus Converter for Raspberry Pi
* 1 HiFiBerry Class-D power amplifier
    * with 2 Bose wired mini speakers
    * connects to the Pi
* 2 Pittman DC servo gear motors (GM9236S019) 
* 1 Servo Control Box
    * connects to the 2 servo motors
    * uses serial interface to the Pi 
* 1 Big Easy (Sparkfun) stepper motor driver board
    * to control the stepper motor for the Dalek's head
* 1 Stepper motor - 42BYGHM809
    * to rotate the head
* 1 Power supply with 12V 5ah Sealed Lead Acid Battery
    * with battery charger
* 4 bumper switch assemblies
* Dozens of extrusions
    * aluminum beams used for the robot's frame
* Dozens of plastic XBeam connectors
* 1 Caster wheel
* 2 3.5 inch diameter wheels
* 1 8 inch stainless steel mixing bowl
    for the head
* Lots of nuts and bolts and wires
* 1 sheet (32x36 inches) stainless steel
    * for the robot's body
* 2 LEDs (red and green) with holders
    * for the robot's eyes
* 1 spark coil
* 1 HC-SR04 ultrasonic sensor
* 2 PIR motion sensors
* 1 RPLIDAR model A1
* 1 Raspberry Pi Camera
* 20 practice golf balls (white)
    * later cut in half
    * later spray painted blue
* 20 foam balls
    * later cut in half
    * later inserted into the golf balls

NOTES: 
1.  I salvaged much of the hardware from a robot kit my college purchased
from a company called [Evolution Robotics](https://en.wikipedia.org/wiki/Evolution_Robotics). 
The robot kit was the [ER1](https://web.archive.org/web/20120910134427/http://www.evolution.com/er1/)
2. I found a hacked up version (by Brian Rudy) of the JR Kerr NMC DLL
sources for use as a shared library on Linux systems. Here you can find the
source code for [libnmc](http://www.praecogito.com/%7Ebrudy/blue_cube/software.html)
3.  I made the body of the robot by cutting the steel sheet into strips
and then using a rivet gun from Home Depot to link them all together.
4.  Fortunately, my colleague and good friend, Andrew (master craftsman) 
helped me with the mechanical work needed to build the Dalek. 

![Andrew Photo](/images/Andrew.jpg)

FUNCTIONALITY:
In the beginning I had great ambitions. I wanted to build an autonomous
robot with the following features:
1.  Able to move freely in all directions
2.  The head should rotate 90 degrees to the left and right
3.  An ultrasonic range sensor could always sense when something is
in front of the robot
4.  Two motion sensors (one on the left side and one on the right)
could detect motion from around the robot
5.  A microphone could detect simple speech and act upon it
6.  Speakers could output music as well as text to speech
7.  A spark coil could emit a spark at the robot's discretion
8.  2 lights in the robot's head (it's eyes) could blink
9.  The LIDAR would allow the robot to be aware of its surroundings
10. Finally I wanted to stream the camera video with status data to the
Internet in real time

![Dalek Video](/videos/dalek.mp4)
