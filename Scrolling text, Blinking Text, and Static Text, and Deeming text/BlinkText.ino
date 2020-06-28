/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 26 June 2020
 by Rathod Jagadish

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:

// include the library code:
#include<LiquidCrystal.h> //Library for LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// LCD pins at which it is attached to the Arduino

void setup() //method used to run the source for the one time onlys
{
  lcd.begin(16, 2);//LCD order i.e. 16 columns & 2 rows
  lcd.print("Hello world!!");//prints on LCD
  delay(1000);//delay of 1 sec
}
void loop() //method to run the source code repeatedly 
{
 lcd.noDisplay();//turn off the display of LCD
 delay(250);//delay to 0.25 seconds
 lcd.display();//turning on the LCD display
 delay(250); //delay of 0.25 seconds again
}
