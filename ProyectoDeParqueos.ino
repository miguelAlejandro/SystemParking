#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "SystemParking"
  https://create.arduino.cc/cloud/things/849f4e42-555e-4965-88a1-0f5a51f11d43 

  Arduino IoT Cloud Properties description

  The following variables are automatically generated and updated when changes are made to the Thing properties

  String p1;
  String p2;
  int parking_1;
  int parking_2;

  Properties which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <Ultrasonic.h>
#include <LiquidCrystal.h>

Ultrasonic ultrasonic_1(4, 5);
Ultrasonic ultrasonic_2(2, 3);


LiquidCrystal lcd(A1, A2, A3, A4, A5, A6);

void getParking(){
   // parqueos 
  parking_1 = ultrasonic_1.read();
  parking_2 = ultrasonic_2.read();
  
  Serial.print("P1CM: ");
  Serial.println(parking_1);

  p1 ="P1CM: " + String(parking_1);
  if(parking_1 < 10){
     digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level);
     p1 += " Not";
  }
  else{
    digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
     p1 += " Yes";
  }

  Serial.print("P2CM: ");
  Serial.print(parking_2);
  Serial.println(p2);
  p2 ="P2CM: " + String(parking_2);
  if(parking_2 < 10){
     digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level);
      p2 += " Not";
  }
  else{
    digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
     p2 += " Yes";
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(p1);
  lcd.setCursor(0, 1);
  lcd.print(p2);
  
}


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);

  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("System Parking");

  lcd.setCursor(0, 1);
  lcd.print("Kisi Rafaela P A");
  
  delay(10000);
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  getParking();
  delay(2000);
}
