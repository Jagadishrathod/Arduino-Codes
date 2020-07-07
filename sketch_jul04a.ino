
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

 Library originally added 18 Apr 2008
 by Rathod Jagadish
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
int LCD_LIGHT_PIN = A4;
int Button = 8;
int counter=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
	lcd.begin(16, 2);
	Serial.begin(9600);
	lcd.print("Welcome to LCD display");
	pinMode(Button,INPUT);
	pinMode(LCD_LIGHT_PIN,OUTPUT);
	digitalWrite(Button,LOW);
	analogWrite(LCD_LIGHT_PIN,LOW);
}

void loop() {
	if(digitalRead(button) == HIGH){
		counter++;
		if(counter>4){
			counter=0;
		}	
	}
	else{
		if(counter==1){
			lcd.clear();
			lcd.setCursor(0, 1);
			lcd.print("Static Text");
			analogWrite(LCD_LIGHT_PIN, HIGH);
			delay(1000);
			analogWrite(LCD_LIGHT_PIN, LOW); 
		}
		if(counter==2){
			lcd.setCursor(0, 1);
			lcd.print("Deeming Text");
			analogWrite(LCD_LIGHT_PIN, HIGH);
			delay(1000);
			lcd.clear();
			delay(1000);
			analogWrite(LCD_LIGHT_PIN, LOW);
		}
		if(counter==3){
			lcd.clear();
			lcd.setCursor(0,1);
			lcd.print("Scrolling Text");
			delay(1000);
			analogWrite(LCD_LIGHT_PIN, HIGH);
			for(int PositionCount=0; PositionCount<6; PositionCount++){
				lcd.scrollDisplayRight(); 
				delay(450);
			}
			for(int PositionCount=0; PositionCount<6; PositionCount++){
				lcd.scrollDisplayLeft();
				delay(450);
			}
			analogWrite(LCD_LIGHT_PIN, LOW);
		}
		if(counter==4){
			lcd.clear();
			lcd.setCursor(0, 1);
			lcd.print("Blink Text");
			analogWrite(LCD_LIGHT_PIN, HIGH);
			lcd.display();
			delay(1000);
			lcd.noDisplay();
			analogWrite(LCD_LIGHT_PIN, LOW);
		}
	}
}
