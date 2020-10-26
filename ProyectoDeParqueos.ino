/*
 * Ultrasonic Simple
 * Prints the distance read by an ultrasonic sensor in
 * centimeters. They are supported to four pins ultrasound
 * sensors (liek HC-SC04) and three pins (like PING)))
 * and Seeed Studio sensors).
 *
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    --------------------
 * | HC-SC04 | Arduino |    | 3 pins | Arduino |
 * ---------------------    --------------------
 * |   Vcc   |   5V    |    |   Vcc  |   5V    |
 * |   Trig  |   12    | OR |   SIG  |   13    |
 * |   Echo  |   13    |    |   Gnd  |   GND   |
 * |   Gnd   |   GND   |    --------------------
 * ---------------------
 * Note: You do not obligatorily need to use the pins defined above
 * 
 * By default, the distance returned by the read()
 * method is in centimeters. To get the distance in inches,
 * pass INC as a parameter.
 * Example: ultrasonic.read(INC)
 *
 * created 3 Apr 2014
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 23 Jan 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 03 Mar 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 11 Jun 2018
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 *
 * This example code is released into the MIT License.
 */

#include <Ultrasonic.h>
#include <LiquidCrystal.h>

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic_1(4, 5);
int parking_1;

Ultrasonic ultrasonic_2(2, 3);
int parking_2;

LiquidCrystal lcd(A1, A2, A3, A4, A5, A6);

void getParking(){
   // parqueos 
  parking_1 = ultrasonic_1.read();
  parking_2 = ultrasonic_2.read();
  
  Serial.print("P1CM: ");
  Serial.println(parking_1);

  String p1 ="P1CM: " + String(parking_1);
  if(parking_1 < 10){
     digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level);
     p1 += " Not";
  }
  else{
    digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
     p1 += " Yes";
  }

  Serial.print("P2CM: ");
  Serial.println(parking_2);
 String p2 ="P2CM: " + String(parking_2);
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
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("System Parking");

  lcd.setCursor(0, 1);
  lcd.print("Kisi Rafaela P A");
  delay(10000);
}

void loop() {
 getParking();
 delay(2000);
}
