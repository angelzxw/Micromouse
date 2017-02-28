int BL1 = 3;
int BL2 = 4;
int BR1 = 5;
int BR2 = 6;
int FL1 = 7;
int FL2 = 8;
int FR1 = 9;
int FR2 = 10;
void setup() 
{ 
  pinMode(BL1, OUTPUT);
  pinMode(BL2, OUTPUT);
  pinMode(BR1, OUTPUT);
  pinMode(BR2, OUTPUT);
  pinMode(FL1, OUTPUT);
  pinMode(FL2, OUTPUT);
  pinMode(FR1, OUTPUT);
  pinMode(FR2, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
      analogWrite(BL1, 200);
      analogWrite(BL2, 0);
      analogWrite(BR1, 200);
      analogWrite(BR2, 0);
      analogWrite(FL1, 200);
      analogWrite(FL2, 0);
      analogWrite(FR1, 200);
      analogWrite(FR2, 0);
      delay(1000);
      analogWrite(BL1, 0);
      analogWrite(BL2, 200);
      analogWrite(BR1, 0);
      analogWrite(BR2, 200);
      analogWrite(FL1, 0);
      analogWrite(FL2, 200);
      analogWrite(FR1, 0);
      analogWrite(FR2, 200);
      delay(1000);
} 

