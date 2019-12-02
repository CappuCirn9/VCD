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
#include "VoiceRecognitionV3.h"

/**        
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
SoftwareSerial BTSerial(2, 3); // RX | TX for bluetooth
VR myVR(4,5);    // 2:RX 3:TX, you can choose your favourite pins. changed to 4,5

uint8_t records[7]; // save record
uint8_t buf[64];

#define naik    (0)
#define turun   (1) 
#define kiri    (2)
#define kanan   (3)
#define depan   (4)
#define undur   (5)
#define Stop    (6)

void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino with HC-06 is ready");
 
    // HC-06 default baud rate is 9600
    BTSerial.begin(9600);  
    Serial.println("BTserial started at 9600");

  /** initialize */
  myVR.begin(9600);
  Serial.println("Elechouse Voice Recognition V3 Module Control pinOut");

  
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
  }
  
  if(myVR.load((uint8_t)naik) >= 0){
    Serial.println("Move Upward Command Loaded");
  }
  
  if(myVR.load((uint8_t)turun) >= 0){
    Serial.println("Move Downward Command Loaded");
  }
  
  if(myVR.load((uint8_t)kiri) >= 0){
    Serial.println("Move Left Command Loaded");
  }
  
  if(myVR.load((uint8_t)kanan) >= 0){
    Serial.println("Move Right Command Loaded");
  }
  
  if(myVR.load((uint8_t)depan) >= 0){
    Serial.println("Move Forward Command Loaded");
  }
  
  if(myVR.load((uint8_t)undur) >= 0){
    Serial.println("Move Backward Command Loaded");
  }
  
  if(myVR.load((uint8_t)Stop) >= 0){
    Serial.println("Stop Command Loaded");
  }
}

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case naik:
        /** go up */
        Serial.println("Move Upward");
        BTSerial.write("UUU");
        break;
      case turun:
        /** go down */
        Serial.println("Move Downward");
        BTSerial.write("DDD");
        break;
      case kiri:
        /** go left */
        Serial.println("Move Left");
        BTSerial.write("LLL");
        break;
      case kanan:
        /** go right */
        Serial.println("Move Right");
        BTSerial.write("RRR");
        break;
       case depan:
        /** go forward */
        Serial.println("Move Forward");
        BTSerial.write("FFF");
        break;
      case undur:
        /** go back */
        Serial.println("Move Backward");
        BTSerial.write("BBB");
        break;
       case Stop:
        /** stop */
        Serial.println("Stop");
        BTSerial.write("SSS");
        break;

    }
  }
  }
