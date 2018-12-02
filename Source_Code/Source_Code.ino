/*  Soil Mosture Sensor With Arduino And LCD
 * 
 *  GitHub URL - https://github.com/narayanvyas/Arduino-Soil-Mosture-Sensor
 * 
 *  Developed By Web Dev Fusion
 *  URL - https://www.webdevfusion.com
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - Soil Mosture Sensor
 *  - An LED
 *  - A 220 Ohm resistor for the LED
 *  - A LCD With I2C Interface
 *  
 *  Libraries
 *  ---------
 *  - None
 *  
 */

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack

int sensorPin = A0;
int sensorValue = 0;
int percentValue = 0;
int LED = 11;
int LEDValue;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  pinMode(LED, HIGH);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);
  
  percentValue = map(sensorValue, 1023, 200, 0, 100);
  LEDValue = map(sensorValue, 1023, 200, 0, 255);
  Serial.print("\nPercent Value: ");
  Serial.print(percentValue);
  Serial.print("%");
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);  
  lcd.print("Percent: ");
  lcd.print(percentValue);
  lcd.print("%");
  analogWrite(LED, LEDValue);
  delay(1000);
  lcd.clear();
}
