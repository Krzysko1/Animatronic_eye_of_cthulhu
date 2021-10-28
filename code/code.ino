/*
 * Simple.cpp
 * 
 *
 *  Shows smooth linear movement from one servo position to another.
 *  Do not use interrupts, therefore it can run on any platform where the Arduino Servo library is available.
 *
 *  Copyright (C) 2019-2021  Armin Joachimsmeyer
 *  armin.joachimsmeyer@gmail.com
 *
 *  This file is part of ServoEasing https://github.com/ArminJo/ServoEasing.
 *
 *  ServoEasing is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/gpl.html>.
 */
// This code is a modified example from open source ServoEasing liblary 
// It creates "random values" then writes them to servos giving them random positions and speed values. 
#include <Arduino.h>

#include "ServoEasing.hpp"

#include "PinDefinitionsAndMore.h" //in this file you can change pins 


ServoEasing Servo1;
ServoEasing Servo2;
ServoEasing Servo3;
ServoEasing Servo4;
#define START_DEGREE_VALUE  90 // The degree value written to the servo at time of attach.
#define START_DEGREE_VALUE  90
int randNumber1;
int randNumber2;
int randSpeed1;
int randSpeed2;
int randSpeed3;
int randNumber3;

void toggleLED_BUILTIN_Every10thCall();

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)  || defined(ARDUINO_attiny3217)
    delay(4000); // To be able to connect Serial monitor after reset or power up and before first print out. Do not wait for an attached Serial Monitor!
#endif
    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_SERVO_EASING));

    /********************************************************
     * Attach servo to pin and set servos to start position.
     * This is the position where the movement starts.
     *******************************************************/
    
  
    if (Servo1.attach(SERVO1_PIN, START_DEGREE_VALUE) == INVALID_SERVO) {
        Serial.println(F("Error attaching servo"));
    }
    if (Servo2.attach(SERVO2_PIN, START_DEGREE_VALUE) == INVALID_SERVO) {
        Serial.println(F("Error attaching servo"));
    }
      if (Servo3.attach(SERVO3_PIN, START_DEGREE_VALUE) == INVALID_SERVO) {
        Serial.println(F("Error attaching servo"));
    }
      if (Servo4.attach(SERVO4_PIN, START_DEGREE_VALUE) == INVALID_SERVO) {
        Serial.println(F("Error attaching servo"));
    }
    
    delay(500); // Wait for servo to reach start position.

    Servo1.setSpeed(40);  //set servo speed
    Servo2.setSpeed(40);
    Servo3.setSpeed(40);
    Servo4.setSpeed(40);
    
   Servo1.setEasingType(EASE_CIRCULAR_IN_OUT);
   Servo2.setEasingType(EASE_CIRCULAR_IN_OUT);
   Servo3.setEasingType(EASE_CIRCULAR_IN_OUT);
   Servo4.setEasingType(EASE_CIRCULAR_IN_OUT);
   Serial.println(F("End of setup, start of loop."));
}

void loop() {


    randNumber1 = random(0, 180);
    randNumber2 = random(100, 140); // you need to restrain the range of motion of servo2 
    randSpeed1 = random(35, 100);
    randSpeed2 = random(20, 40);
    randSpeed3 = random(70, 130); 
    
    randNumber3 = constrain (randNumber1, 40, 120); // you need to restrain the range of motion of servo 3 and 4 to not hit the eye

  //sequence of moves
    Servo3.easeTo(randNumber3,randSpeed3); 
    Servo4.easeTo(randNumber3,randSpeed3); 
    Servo1.easeTo(randNumber1,randSpeed1); 
    Servo2.easeTo(randNumber2,randSpeed2); 
    Servo3.easeTo(randNumber3,randSpeed3); 
    Servo4.easeTo(randNumber3,randSpeed3);
    Servo1.easeTo(randNumber1,randSpeed3);
    Servo3.easeTo(randNumber3,randSpeed3); 
    Servo4.easeTo(randNumber3,randSpeed3); 
    Servo1.easeTo(randNumber1,randSpeed3);
    Servo2.easeTo(randNumber2,randSpeed2); 
    Servo3.easeTo(randNumber3,randSpeed3); 
    Servo4.easeTo(randNumber3,randSpeed3);  
    Servo1.easeTo(randNumber1,randSpeed1);
    Servo2.easeTo(randNumber2,randSpeed2); 
   
   
}
