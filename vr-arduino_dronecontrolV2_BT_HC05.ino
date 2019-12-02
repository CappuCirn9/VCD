/**
  ******************************************************************************
  * @file    vr_sample_control_test_V1_demo.ino
  * @author  Nichol
  * @brief   This file provides a demostration on 
              how to control drone by using VoiceRecognitionModule
  ******************************************************************************
  * @note:
        voice control drone
  ******************************************************************************
  * @section  HISTORY
    
    2013/06/13    Initial version.
  */
  
#include <SoftwareSerial.h>
//#include "VoiceRecognitionV3.h"

/**        
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
SoftwareSerial BTSerial(2, 3); // RX | TX for bluetooth

int up = 6;
int down = 7;
int left = 10;
int right = 11;
int front = 8;
int back = 9;

int c = 0;

void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino with HC-05 is ready");
 
    // HC-06 default baud rate is 9600
    BTSerial.begin(9600);  
    Serial.println("BTserial started at 9600");
  
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(front, OUTPUT);
  pinMode(back, OUTPUT);
}

void loop()
{

  digitalWrite(up, HIGH);
  digitalWrite(down, HIGH);
  digitalWrite(left, HIGH);
  digitalWrite(right, HIGH);
  digitalWrite(front, HIGH);
  digitalWrite(back, HIGH);

    if (BTSerial.available())
    {
      Serial.write(BTSerial.read());
      c = BTSerial.read();
      switch(c){
      case 'U' :
        digitalWrite(up, LOW);
        Serial.println("Move Upward");
        delay(500);
        digitalWrite(up, HIGH);
        break;
      case 'D' :
        digitalWrite(down, LOW);
        Serial.println("Move Downward");
        delay(500);
        digitalWrite(down, HIGH);
        break;
      case 'L' :
        digitalWrite(left, LOW);
        Serial.println("Rotate Left");
        delay(500);
        break;
      case 'R' :
        digitalWrite(right, LOW);
        Serial.println("Rotate Right");
        delay(500);
        break;
       case 'F' :
        digitalWrite(front, LOW);
        Serial.println("Move Forward");
        delay(500);
        digitalWrite(front, HIGH);
        break;
      case 'B' :
        digitalWrite(back, LOW);
        Serial.println("Move Backward");
        delay(500);
        digitalWrite(back, HIGH);
        break;
       case 'S' :
        Serial.println("Stop");
        delay(500);
        digitalWrite(left, HIGH);
        digitalWrite(right, HIGH);
        break;

        default:
        Serial.println("Record function undefined");
        delay(500);
        break;
    }
   }
  }
