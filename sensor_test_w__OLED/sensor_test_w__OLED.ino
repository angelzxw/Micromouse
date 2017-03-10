#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


// defines pins numbers
const int trigPin_0 = 14;
const int echoPin_0 = 15;
const int trigPin_1 = 16;
const int echoPin_1 = 17;
const int trigPin_2 = 18;
const int echoPin_2 = 19;

// anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST = 23200, MIN_DIST = 150;

// defines variables
long duration_0, duration_1, duration_2;
int distance_0, distance_1, distance_2;

void setup() {
  pinMode(trigPin_0, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_0, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin_1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin_2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_2, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize with the I2C addr 0x3D (for the 128x64)
  display.display();
  delay(2000);
  // Clear the buffer.
  display.clearDisplay();
  display.drawPixel(10, 10, WHITE);

  display.display();
  delay(2000);
  display.clearDisplay();
  
}

void loop() {
  digitalWrite(trigPin_0, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_0, LOW);
  duration_0 = pulseIn(echoPin_0, HIGH);
  distance_0= duration_0*0.034/2;

  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);
  duration_1 = pulseIn(echoPin_1, HIGH);
  distance_1= duration_1*0.034/2;

  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);
  duration_2 = pulseIn(echoPin_2, HIGH);
  distance_2= duration_2*0.034/2;
  
  printReadings();
  delay(60);
}

void printReadings(){
  // Print out results
  Serial.print("Distance_0: ");
  if ( duration_0 > MAX_DIST){
    Serial.println("Out of range");
  }
  else if (duration_0 < MIN_DIST){
    Serial.println("Object to close!!") ;
  }
  else{
    Serial.println(distance_0);
  }
  
  Serial.print("Distance_1: ");
  if ( duration_1 > MAX_DIST){
    Serial.println("Out of range");
  }
  else if (duration_1 < MIN_DIST){
    Serial.println("Object to close!!") ;
  }
  else{
    Serial.println(distance_1);
  }

  Serial.print("Distance_2: ");
  if ( duration_2 > MAX_DIST){
    Serial.println("Out of range");
  }
  else if (duration_2 < MIN_DIST){
    Serial.println("Object to close!!") ;
  }
  else{
    Serial.println(distance_2);
  }
  Serial.println(" ");
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Results"); 
  
  display.print("Dis_0: ");   
  if ( duration_0 > MAX_DIST){
    display.println("Out of range!");
  }
  else if (duration_0 < MIN_DIST){
    display.println("Object to close!");
  }
  else{
    display.println(distance_0);
  }

  display.print("Dis_1: ");   
  if ( duration_1 > MAX_DIST){
    display.println("Out of range!");
  }
  else if (duration_1 < MIN_DIST){
    display.println("Object to close!");
  }
  else{
    display.println(distance_1);
  }
   
  display.print("Dis_2: ");   
  if ( duration_2 > MAX_DIST){
    display.println("Out of range!");
  }
  else if (duration_2 < MIN_DIST){
    display.println("Object to close!");
  }
  else{
    display.println(distance_2);
  }
  
  display.display();

  delay(1000);
  display.clearDisplay();
}


