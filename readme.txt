These files are basic test files for the InterbotiX WidowX Robotic Arm. Do not use these examples with other InterbotiX Arms.


Follow the getting started guide to program the ArbotiX, set the servo IDs, build the arm, and test the WidowX arm
http://learn.trossenrobotics.com/interbotix/robot-arms/widowx-arm


For Pypose to run the main sequence:
  -Load the 'pypose' sketch onto the arm (Sketchbook -> ArbotiX Sketches -> Pypose)
  -Open 'Pypose/widow.ppr' from this repo
  -'Config -> Port' to choose your port
  -Tools -> Sequence 
  -Click 'run'

To edit poses:
  -Tools -> pose editor
  -Select a pose on the right menu
  -Click 'relax' to relax the servos. 
  -Move the arm to the desired position
  -Click 'capture'


For Arduino/ArbotiX stand alone"
  -Open 'Arduino/WidowxArmTestSequence/WidowxArmTestSequence.ino' from this repo
  -Load the sketch onto your arm and it will follow a preprogrammed loop  
  -In 'poses.h' to change the pose values. The first number in the array is always 6 (number of servos). Then the values for each servo are given (base, shoulder, elbow, wrist angle, wrist rotate, gripper)
  -In 'WidowxarmTestSequence.ino each pose is called
      delay(1000);  -> increase/decrease '1000' to increase/decrease the time each pose is held

     bioloid.interpolateSetup(2000); -> increase/decrease '2000'  to increase/decrease the time it takes to go from one pose to the next


The arm has two types of servos - MX servos and AX servos. Each class of servo has a different range of values that will work with it. 

MX-64 and MX-28 (base, shoulder, elbow, wrist angle)
Accepts values from 0 - 4095
0 = 0 degrees
2048 = 180 degrees
4096 = 360 degrees
http://support.robotis.com/en/product/dynamixel/mx_series/mx-64.htm#Actuator_Address_1E


AX-12A (Wrist Rotate and gripper)
Accepts Values from 0 - 1023
See diagram for angles
http://support.robotis.com/en/product/dynamixel/ax_series/dxl_ax_actuator.htm#Actuator_Address_1E

NOTE: The value ranges for each servos listed above are the native limits of the servos. Once in the arm. pyhsical contraints will limit the movement of each servo. The limits are defined as:

Base Servo(1)
#define BASE_MIN    0
#define BASE_MAX    4095

Shoulder Servo(2)
#define SHOULDER_MIN  1024 
#define SHOULDER_MAX  3072

Elbow Servo(3)
#define ELBOW_MIN    1024
#define ELBOW_MAX    3072

Wrist Servo(4)
#define WRIST_MIN    1024
#define WRIST_MAX    3072

Wrist Rotate Servo(5)
#define WROT_MIN     0
#define WROT_MAX     1023

Gripper (6)
#define GRIP_MIN     0
#define GRIP_MAX     512