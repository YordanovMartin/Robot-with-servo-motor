# Robot-with-stepper-motors
The code is made to be used in the Arduino IDE. It is written for a robot with two stepper motors (JK28HS45-0674)
and two drivers for each of them A4988.
With the idea of a robot made to move around a field and perform various missions.

The robot control code is divided into 3 parts:

• A library that contains all the motion methods, variables, and coefficients used below in the code

• Missions

• The Setup method in which the functions for already completed missions are called


    When calibrating the robot, I realized that the robot should have different values
    to be fed to it when moving forward, backward and when turning left and right in order
    to be as precise and accurate as possible during field missions.


    I also measured the diameter of the tires using the formula p = 2 π r = π d
I calculated that the perimeter of the tires is 17.6cm,
which means that the robot travels this distance when taking 200 steps on the motors.

   
    There are 2 fundamental methods of robot movement that are used in all other methods.
    They are a step forward and a step back. However, when we want the robot to turn in a certain direction,
    one motor must be set to drive forward and the other back, depending on the direction in which we want the robot to move.
    
    
To see the video of the robot you have to download it!
