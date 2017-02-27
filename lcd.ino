/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
//#include <SoftwareSerial.h>
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
const int trigPin_2 = 11;
const int echoPin_2 = 12;

long duration, duration_2;
int distanceCm, distanceInch, distanceCm_2, distanceInch_2;

//SoftwareSerial mySerial(3,2);

void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
//mySerial.begin(9600);
delay(500);
lcd.clear();
lcd.print("hello, worldy!");
//mySerial.write(254);
//mySerial.write(128);
//mySerial.write("D1: ");
//mySerial.write("D2: ");

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPin_2, OUTPUT);
pinMode(echoPin_2, INPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;

digitalWrite(trigPin_2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_2, LOW);
duration_2 = pulseIn(echoPin_2, HIGH);
distanceCm_2= duration_2*0.034/2;
distanceInch_2 = duration_2*0.0133/2;

//sprintf(tempstring,"%4d",distanceCm); // create strings from the numbers
//sprintf(rpmstring,"%4d",disitanceCm_2);
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
//lcd.print(distanceCm); // Prints string "1st Distance" on the LCD
//lcd.print(distanceCm_2); // Prints the distance value from the sensor
//lcd.print("hello, world!");
delay(10);
lcd.setCursor(0,1);
//lcd.print("hello, world2!");
//lcd.print(distanceInch);

//lcd.print(distanceInch_2);

delay(1000);

//Serial.print("Distance1: ");
//Serial.println(distanceCm);
//Serial.print("  Distance2: ");
//Serial.println(distanceCm_2);
}                        

