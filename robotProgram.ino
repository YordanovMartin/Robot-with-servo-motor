#include <math.h>
 
//Pins for connecting the two motors
#define BAUD (9600)
#define leftStepPin 6
#define leftDirPin 3
#define rightStepPin 5
#define rightDirPin 2
#define stepsPerRevolution 200

//Coefficients obtained by calibrating the movement of the robot
#define perimeterForMovingForward 17.6019 
#define perimeterForMovingBackwards 16.885
#define degreesToStepsLeft 1.11     
#define degreesToStepsRight 1.075

#define defaultDelayBetweenMotorSteps 4
 
//360degrees are equal to 227steps

const int delayBetweenActions = 50;

const int speedMovingForwardAndBackwards = 3;

const int speedForTurning = 9;
 
 //Formula for calculating the centimeters that 1 step makes
const double stepsPerCentimeterForward = stepsPerRevolution / perimeterForMovingForward;
 
const double stepsPerCentimeterBackwards = stepsPerRevolution / perimeterForMovingBackwards;
 
 
// motor library -------------------------------------------------------------------------------------------
 
void motorSetup() 
{
  Serial.println("Motor setup started...");
  Serial.begin(BAUD);
  pinMode(8,OUTPUT); // Enable PIN за всички мотори
  pinMode(leftStepPin,OUTPUT); // Step PIN за Motor 1
  pinMode(leftDirPin,OUTPUT); // Dir  PIN за Motor 1
  pinMode(rightStepPin,OUTPUT); // Step PIN за Motor 2
  pinMode(rightDirPin,OUTPUT); // Dir  PIN за Motor 2 
  digitalWrite(8,LOW); // Set Enable low
  Serial.println("Motor setup ended.");
}
 
void stepForward(int delayBetweenMotorSteps = defaultDelayBetweenMotorSteps) 
{
  
  digitalWrite(leftStepPin,HIGH); // Output high Motor 1
  digitalWrite(rightStepPin,LOW); // Output low Motor 2
  delay(delayBetweenMotorSteps); // Изчаква
 
  digitalWrite(leftStepPin,LOW); // Output low Motor 1
  digitalWrite(rightStepPin,HIGH); // Output high Motor 2
  delay(delayBetweenMotorSteps); // Изчаква
 
}
 
void stepBackwards(int delayBetweenMotorSteps = defaultDelayBetweenMotorSteps) 
{
  digitalWrite(leftStepPin,LOW); // Output low Motor 1
  digitalWrite(rightStepPin,HIGH); // Output high Motor 2
  delay(delayBetweenMotorSteps); // Wait
 
  digitalWrite(leftStepPin,HIGH); // Output high Motor 1
  digitalWrite(rightStepPin,LOW); // Output low Motor 2
  delay(delayBetweenMotorSteps); // Waitква
 
}
 
 
void turnLeft(int degrees, int delayBetweenMotorSteps = defaultDelayBetweenMotorSteps) 
{
 
 
  Serial.println("Turn left started...");
 
  int steps = round(degrees * degreesToStepsLeft);
  Serial.println(steps);
 
  digitalWrite(8,LOW); // Set Enable low
  digitalWrite(leftDirPin,LOW); // Set Dir low Motor 1
  digitalWrite(rightDirPin,LOW); // Set Dir low Motor 2
 
  for(int x = 0; x < steps; x++)
  {
    stepForward(delayBetweenMotorSteps);
  }
  Serial.println("Turn left ended.");
}
 
void turnRight(int degrees, int delayBetweenMotorSteps = defaultDelayBetweenMotorSteps) 
{
  Serial.println("Turn right started...");
 
  int steps = round(degrees * degreesToStepsRight);
  Serial.println(steps);
 
  digitalWrite(8,LOW); // Set Enable low
  digitalWrite(leftDirPin,HIGH); // Set Dir high Motor 1
  digitalWrite(rightDirPin,HIGH); // Set Dir high Motor 2
 
  for(int x = 0; x < steps; x++) 
  {
    stepForward(delayBetweenMotorSteps);
  }
  Serial.println("Turn right ended.");
}
 
 
void moveBackwards(double centimeters, int delayBetweenMotorSteps = defaultDelayBetweenMotorSteps) 
{
  Serial.println("Move backwards started...");
 
  int steps = round(centimeters * stepsPerCentimeterBackwards);
  Serial.println(steps);
 
  digitalWrite(8,LOW); // Set Enable low
  digitalWrite(leftDirPin,HIGH); // Set Dir high Motor 1
  digitalWrite(rightDirPin,LOW); // Set Dir low Motor 2
 
  for(int x = 0; x < steps; x++) 
  {
    stepForward(delayBetweenMotorSteps);
  }
  Serial.println("Move backwards ended.");
}
 
void moveForward(double centimeters, int delayBetweenMotorSteps = defaultDelayBetweenMotorSteps) 
{
  Serial.println("Move forward started...");
 
  int steps = round(centimeters * stepsPerCentimeterForward);
  Serial.println(steps);
 
  digitalWrite(8,LOW); // Set Enable low
  digitalWrite(leftDirPin,LOW); // Set Dir low Motor 1
  digitalWrite(rightDirPin,HIGH); // Set Dir high Motor 2
 
  for(int x = 0; x < steps; x++) 
  {
    stepBackwards(delayBetweenMotorSteps);
  }
  Serial.println("Move forward ended.");
}
 
 
// missions ------------------------------------------------------------------------------------------------
 

void mission1()
{

// 1 jenga
 
moveForward(40, speedMovingForwardAndBackwards);
 delay(delayBetweenActions);
 turnRight(100, speedMovingForwardAndBackwards);
  delay(delayBetweenActions);
 
 
//  2 jenga
 moveForward(22, speedMovingForwardAndBackwards);
 delay(delayBetweenActions);
 turnLeft(20, speedForTurning);
 delay(delayBetweenActions);
 
 
//3 jenga
  moveForward(19, speedMovingForwardAndBackwards);
  delay(delayBetweenActions);
  turnLeft(55, speedForTurning);
  turnRight(55, speedForTurning);
 
//4 jenga
  turnRight(14, speedForTurning);
  delay(delayBetweenActions);
  moveForward(30, speedMovingForwardAndBackwards);
  delay(delayBetweenActions);
 
//5 jenga
  turnRight(125, speedForTurning);
  delay(delayBetweenActions);
  
  moveForward(22, speedMovingForwardAndBackwards);
  delay(delayBetweenActions);
  turnRight(100, speedForTurning);
  delay(delayBetweenActions);
  turnLeft(40, speedForTurning);
  delay(delayBetweenActions);
  moveForward(10, speedMovingForwardAndBackwards);
  delay(delayBetweenActions);
  turnRight(50, speedForTurning);
  delay(delayBetweenActions);
  
  //BASE
 moveForward(55, speedMovingForwardAndBackwards);

}


void mission2()
{



}

// robot program -------------------------------------------------------------------------------------------
 
void setup() 
{
 //The Setup method is called, which signals the motors to start running
  motorSetup();

//After that waits 1 second
  delay(1000);

//And the first mission begins
 mission1();

 
//Mission 2 is still in development
mission2();


}
 
void loop() 
{
 
}
