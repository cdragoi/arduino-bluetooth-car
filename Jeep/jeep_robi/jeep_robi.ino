//*** 1- Documentation
//Bluetooth car  controlled by Android app with arduino
//Servo mounted on the roof
//No lights implemented
//This program is used to control a robot car using a app that communicates with Arduino trough a bluetooth module

#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>



//creates two objects to control the terminal 3 and 4 of motor shield

AF_DCMotor motor1(3);
AF_DCMotor motor2(2);
Servo myservo1;  // create servo object to control a servo
Servo myservo2;

SoftwareSerial mySerial(A0, A5); // RX, TX

String serialReceived;
char command;
int pos1 = 0;
int pos2 = 0;

void setup()
{
Serial.begin(9600); //Set the baud rate to your Bluetooth module.
mySerial.begin(38400);
myservo1.attach(10);  // attaches the servo on pin 9 to the servo object
myservo2.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop(){

if (mySerial.available()) {
    //Serial.write(mySerial.read());
command = mySerial.read();


Stop(); //initialize with motors stoped
//Change pin mode only if new command is different from previous.
Serial.println(command);

switch(command){
    case 'F':
    forward();
    break;
  case 'B':
    back();
    break;
  case 'L':
    left();
    break;
  case 'R':
    right();
    break;
    case 'G':
    Forleft();
    break;
  case 'I':
    Forright ();
    break;
  case 'H':
    Backleft();
    break;
  case 'J':
    Backright ();
    break;
  case 'X':
    servo1_up ();
    break;
  case 'x':
    servo1_down ();
    break;   
  case 'q':
    servo2_1 ();
    break;
       
}
}
}

void forward()
{
motor1.setSpeed(255); //Define maximum velocity
motor1.run(FORWARD); //rotate the motor clockwise
}

void back()
{
motor1.setSpeed(255);
motor1.run(BACKWARD); //rotate the motor counterclockwise
}

void left()
{
motor2.setSpeed(200);
motor2.run(BACKWARD); //turn motor2 off
}

void right()
{
motor2.setSpeed(200); //Define maximum velocity
motor2.run(FORWARD); //rotate the motor clockwise
}

void Stop()
{
motor1.setSpeed(0);
motor2.run(RELEASE); //turn motor1 off
motor2.setSpeed(0);
motor2.run(RELEASE); //turn motor2 off
}

void Forright()
{
motor1.setSpeed(255);
motor1.run(FORWARD); //turn motor1 off
motor2.setSpeed(200);
motor2.run(FORWARD); //turn motor2 off
}

void Forleft()
{
motor1.setSpeed(255);
motor1.run(FORWARD); //turn motor1 off
motor2.setSpeed(200);
motor2.run(BACKWARD); //turn motor2 off
}

void Backright()
{
motor1.setSpeed(255);
motor1.run(BACKWARD); //turn motor1 off
motor2.setSpeed(200);
motor2.run(FORWARD); //turn motor2 off
}

void Backleft()
{
motor1.setSpeed(255);
motor1.run(BACKWARD); //turn motor1 off
motor2.setSpeed(200);
motor2.run(BACKWARD); //turn motor2 off
}

void servo1_up()
{
for (pos1 = 0; pos1 <= 80; pos1 += 1) 
{ 
  myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
   delay(15);                       // waits 15ms for the servo to reach the position
}

}
void servo1_down()
{
for (pos1 = 80; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                      // waits 15ms for the servo to reach the position
}
}
void servo2_1()
{
  for (pos1 = 0; pos1 <= 80; pos1 += 1) 
{ 
  myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
   delay(15);                       // waits 15ms for the servo to reach the position
}
  
for (pos2 = 90; pos2 <= 180; pos2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos2 = 180; pos2 >=10; pos2 -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);    
    
  }
  for (pos2 = 10; pos2 <= 90; pos2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);
  }
  for (pos1 = 80; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                      // waits 15ms for the servo to reach the position
}
}

