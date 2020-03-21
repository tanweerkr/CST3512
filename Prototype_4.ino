/* 
 *  Distance measurement using Arduino
 * CST3512 - Real Time Systems
 * Tanweer Bin Khair - M00585219
 * Rakshit Rohit Sharma - M00651168
 * 
 */

#include <LiquidCrystal_I2C.h> // Library required for LCD Display with I2C Interface.
LiquidCrystal_I2C lcd(0x27,20,4); // The address, columns and rows are specified for this LCD display.

const int pinA = 5; // Pin #5 on Arduino Uno board shall be used as trigger for the HC-SR04 sensor.
const int pinB = 6; // Pin #6 on Arduino Uno board shall be utilized as the echo for the HC-SR04 sensor.

long duration; // Variable type for time defined.
int distance; // Variable type for area defined.
int distanceInch; // Variable type for area defined 2.

void setup() {
lcd.init();
lcd.begin(20,4);
lcd.backlight();
pinMode(pinA, OUTPUT); // pinA will now be utilized for Output data.
pinMode(pinB, INPUT); // pinB will now be utilized for Input data.
Serial.begin(9600); // Initiates serial communication, 9600 baudrates.
}


void loop() {
digitalWrite(pinA, LOW); // The trigger is currently set low.
delayMicroseconds(2); // Delay
digitalWrite(pinA, HIGH); // The trigger is switched to high, thereby the ultrasound is being emitted.
delayMicroseconds(10); // Ultrasound will continue to emit during the delay.
digitalWrite(pinA, LOW); // The trigger is returned to low, the emission has ended.
duration = pulseIn(pinB, HIGH); // The echo is turned high, the time between high and low is taken as the "duration".
distance= duration*0.034/2; // Distance for centimeter is calculated using the data collected by the sensor and the formula.
distanceInch= duration*0.0133/2; // Distance is calculated inch is calculated using the data collected by the sensor and the formula.


lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed.
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distance); // Prints the centimeter distance value from the sensor
lcd.print(" cm"); // Adds the text -> "cm" after displaying the value
delay(10); // Delay before updating with new value every 10 milliseconds.
lcd.setCursor(0,1); // Sets the location at which subsequent tex written to the LCD will be displayed.
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceInch); // Prints the inch distance value from the sensor.
lcd.print(" inch"); // Adds the text -> "inch" after displaying the value
delay(10); // Delay before updating the new value every 10 milliseconds.
}
