//*** 1- Documentation

//This program is used to control a robot car using a app that communicates with Arduino trough a bluetooth module

#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(11,12); // RX, TX
String serialReceived;
char command;

int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
void setup()
{
Serial.begin(38400); //Set the baud rate to your Bluetooth module.
mySerial.begin(9600);

pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
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
}
}
}
void forward()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
}

void back()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB, 200);
  } 

void left(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 250);
  }  

void right(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 250);
  }  
void Stop()
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);  
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}

void Forright()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
analogWrite(enA, 200);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enB, 250);
}

void Forleft()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
analogWrite(enA, 200);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enB, 250);
}

void Backright()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
analogWrite(enA, 200);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enB, 250);
}

void Backleft()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
analogWrite(enA, 200);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enB, 250);
}

