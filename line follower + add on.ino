#include <Servo.h>
Servo myservo1;
Servo myservo2;
 int pos = 0;
void setup() {
 myservo1.attach(13);
 myservo2.attach(8);
 #define in1 6 //Motor1  L293 Pin in1
 #define in2 7 //Motor1  L293 Pin in1
 #define in3 9 //Motor2  L293Pin in1
 #define in4 10 //Motor2  L293 Pin in1
 #define R_S 4 // Right sensor
 #define L_S 2 // Left sensor
 #define ena 3
 #define enb 5
 #define trigPin 11
 #define echoPin 12
 
  pinMode(R_S, INPUT);
pinMode(L_S, INPUT);
pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT);
 
}
void forward(){ 
  analogWrite(ena, 140);
  analogWrite(enb, 140);
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW); 
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW);
 }
 void turnRight(){
 analogWrite(ena, 140);
  analogWrite(enb, 140);
 digitalWrite(in1, LOW);  //Right Motor forword Pin
 digitalWrite(in2, HIGH); //Right Motor backword Pin 
 digitalWrite(in3, HIGH);  //Left Motor backword Pin
 digitalWrite(in4, LOW); //Left Motor forword Pin
 delayMicroseconds(100000);
 }
 void turnLeft(){
   analogWrite(ena, 140);
  analogWrite(enb, 140);
 digitalWrite(in1, HIGH); //Right Motor forword Pin
 digitalWrite(in2, LOW);  //Right Motor backword Pin
 digitalWrite(in3, LOW); //Left Motor backword Pin
 digitalWrite(in4, HIGH);  //Left Motor forword Pin
 delayMicroseconds(100000);
 }
 void Stop(){
 digitalWrite(in1, LOW); //Right Motor forword Pin 
 digitalWrite(in2, LOW); //Right Motor backword Pin
 digitalWrite(in3, LOW); //Left Motor backword Pin 
 digitalWrite(in4, LOW); //Left Motor forward Pin
}

void loop() {
  if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){forward();} 
  if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();} //
  if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();} 
   if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Stop();} 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration;
  int distance;
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if(distance<5){
    Stop();
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    forward();
    delayMicroseconds(2000000);
    Stop();
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);
    myservo2.write(pos);             // tell servo to go to position in variable 'pos'
    delay(15);
  }
  }
}