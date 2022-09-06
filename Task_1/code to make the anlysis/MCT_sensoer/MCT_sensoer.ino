///////////////////////////////ultrasonic_SENSOR/////////////////////////////////////
int trigPin = 9;
int echoPin = 10;
long duration;
float distance;

//////////////////////////////////////COLOR_SENSOR////////////////////////////////////
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int frequencyRed = 0;
int frequencyGreen = 0;
int frequencyBlue = 0;
int COLOR =0;

void setup (){
  
///////////////////////////////// Ultrasonic setup ////////////////////////////////
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
//////////////////////////////////COLOR_SENSOR_SETUP//////////////////////////////
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
 
  digitalWrite(S0,HIGH);  // Setting frequency-scaling to 20%
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}

void loop ()
{
///////////////////////////////////////////////ULTRASONIC_SENSOR_LOOP////////////////////////
digitalWrite(trigPin, LOW);  // Clears the trigPin//
delayMicroseconds(2);

digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds

distance= duration*0.034/2;  // Calculating the distance


//////////////////////////////////////////COLOR_SENSOR_LOOP///////////////////////////////////
/*red*/
  digitalWrite(S2,LOW); // Setting red filtered photodiodes to be read
  digitalWrite(S3,LOW);
  frequencyRed = pulseIn(sensorOut, LOW);  // Reading the output frequency
 
  /*green*/
  digitalWrite(S2,HIGH); // Setting Green filtered photodiodes to be read
  digitalWrite(S3,HIGH); 
  frequencyGreen = pulseIn(sensorOut, LOW); // Reading the output frequency

 /*blue*/
  digitalWrite(S2,LOW);  // Setting Blue filtered photodiodes to be read
  digitalWrite(S3,HIGH);
  frequencyBlue = pulseIn(sensorOut, LOW); // Reading the output frequency
  
 /*system_setup*/
  if( frequencyRed < frequencyGreen && frequencyRed < frequencyBlue )
  {
  COLOR = frequencyRed;//printing RED color frequency
  }
  else if (frequencyGreen < frequencyRed && frequencyGreen < frequencyBlue )
  {
  COLOR = frequencyGreen ;//printing RED color frequency
  }
  else if (frequencyBlue < frequencyGreen && frequencyBlue < frequencyRed )
  {
  COLOR = frequencyBlue ;//printing RED color frequency
  }
if (distance <= 10 )
{ 
 Serial.print(distance); // Prints the distance on the Serial Monitor
  /*Serial.print("CM");*/
 Serial.print(",");
 Serial.println(COLOR);
  delay(10);
}
}
