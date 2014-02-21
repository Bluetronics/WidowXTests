#include <ax12.h>
#include <BioloidController.h>
#include "poses.h"

BioloidController bioloid = BioloidController(1000000);



void setup(){
   pinMode(0,OUTPUT);  
   
   //initialize variables 


}

void loop(){
  
  
    delay(100);                    // recommended pause
    bioloid.loadPose(Sleep);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    
    
    delay(1000); //INCREASE THIS TO INCREASE THE TIME THAT THE POSE IS HELD FOR
    
    
    bioloid.interpolateSetup(2000); //INCREASE THIS TO INCREASE THE TIME IT TAKES TO TRANSITION FROM ONE POSE TO THE NEXT
                              // setup for interpolation from current->next over 1 second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }


  
    delay(100);                    // recommended pause
    bioloid.loadPose(Home);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    delay(1000);
    bioloid.interpolateSetup(1000); // setup for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }


  
    delay(100);                    // recommended pause
    bioloid.loadPose(Up);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    delay(1000);
    bioloid.interpolateSetup(500); // setup for interpolation from current->next over 1/4 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }


  
    delay(100);                    // recommended pause
    bioloid.loadPose(DownGripper);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    delay(1000);
    bioloid.interpolateSetup(1000); // setup for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }


  
    delay(100);                    // recommended pause
    bioloid.loadPose(RightAngle);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    delay(2000);
    bioloid.interpolateSetup(1000); // setup for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }

    delay(100);                    // recommended pause
    bioloid.loadPose(Turn);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    delay(1000);
    bioloid.interpolateSetup(10000); // setup for interpolation from current->next over 5 seconds
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }


  
}


    
    
