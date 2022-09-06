#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(14, 15, 16, 17, 18, 19); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

#define S0 0
#define S1 1
#define S2 6
#define S3 5
#define sensorOut 7
int Red_frequency = 0;
int Green_frequency = 0;
int Blue_frequency = 0;
int trigPin = 4;
int echoPin = 3;
long duration;
float distance;
#define SENSOR 11 // define pint 7 for sensor
#define ACTION 10 // define pin 6 as for ACTION


void setup() {
   lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 

  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(9,HIGH);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  pinMode(SENSOR, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(ACTION, OUTPUT);// define pin as OUTPUT for ACTION

Serial.begin(9600);
}

void loop() {
   // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);  // Clears the trigPin//
delayMicroseconds(2);
digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
distance= duration*0.034/2;  // Calculating the distance

  
int L =digitalRead(SENSOR);// read the sensor 

     if(L == 0)
{
  delay(2000);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("M/C ON");
  do{
    for(int x=0;x <3200; x++)
    {
      digitalWrite(8,HIGH);
   delayMicroseconds(500);
   digitalWrite(8,LOW);
   delayMicroseconds(500);
   digitalWrite(trigPin, LOW);  // Clears the trigPin//
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;  // Calculating the distance 
    Serial.println(distance);
   if(distance < 5)
   {
     lcd.clear();
     lcd.setCursor(5,0);
     lcd.print("M/C OFF");
     delay(2000);
     lcd.clear();
     lcd.setCursor(3,0);
     lcd.print("Industrial");
     lcd.setCursor(4,1);
     lcd.print("Sorting");
     delay(3000);
     lcd.clear();
     lcd.setCursor(5,0);
     lcd.print("Thanks");
     lcd.setCursor(4,1);
     lcd.print("TEAM(18)");
    break;
   }
    // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  Red_frequency = pulseIn(sensorOut, LOW);
 

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  Green_frequency = pulseIn(sensorOut, LOW);
 

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  Blue_frequency = pulseIn(sensorOut, LOW);

    if((Green_frequency >= 70) && (Green_frequency <= 80 ))
    {
      if((Red_frequency >= 100)&&(Red_frequency <= 107))
      {
        if((Blue_frequency >= 68)&&(Blue_frequency <=78))
        {
          lcd.setCursor(2,1);
          lcd.print("Part'Green'");  
         }
        }
        else if((Red_frequency >= 45)&&(Red_frequency <= 52))
        {
          if((Blue_frequency >= 50)&&(Blue_frequency <=60))
          {
            lcd.setCursor(2,1);
            lcd.print("Part'Red'");
            }
          }
    }
    
    }
   
      

    
    }while(distance > 5);
}
if(distance < 5)
{
    digitalWrite(8,LOW);
       delayMicroseconds(500);
      digitalWrite(8,LOW);
      delayMicroseconds(500);  
  }
 
}
