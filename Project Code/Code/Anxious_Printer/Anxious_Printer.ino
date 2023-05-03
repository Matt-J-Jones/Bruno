#include <HCSR04.h>
#include <Servo.h>

byte triggerPin = 12;
byte echoPin = 11;
Servo myservo;
int pos = 0;
int inc_time;
int ledPin = 8;

void setup () {
  Serial.begin(9600);
  HCSR04.begin(triggerPin, echoPin);
  
  //assign servo to pin, and set to defualt position
  myservo.attach(9);
  myservo.write(90);
  
  pinMode(ledPin, OUTPUT);
}

void loop () {
  double* distances = HCSR04.measureDistanceCm();
  
  //map distances from -1cm to 50cm over inputs of 1 to 15.
  int dist_serv = map(distances[0], -1.00,50,1,15);

  digitalWrite(ledPin, LOW);
  
  Serial.println(dist_serv);
  inc_time = dist_serv;

  //if the value for inc_time is closer than 15, but further away from 1, 
  //it begins moving the servo motor. each sweep is delayed by the value of inc_time.
  
  if (dist_serv < 16 && dist_serv > 1){
    serv_neg(inc_time);
    delay(inc_time);
    serv_pos(inc_time);
    delay(inc_time);
  } else {
    
    //if the value of inc_time is over 15, it defaults to it's standby position
    
    myservo.write(90);
  }
  
}

void serv_pos(int tim_delay){
  int x = 80;
  while (x < 101){
    digitalWrite(ledPin, HIGH);
    myservo.write(x);
    delay(tim_delay);
    x++;
  }
}

void serv_neg(int tim_delay){
  int x = 100;
  while (x > 79){
    myservo.write(x);
    delay(tim_delay);
    digitalWrite(ledPin, LOW);
    x--;
  }
}
