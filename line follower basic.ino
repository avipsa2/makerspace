
void setup() {
 
 #define in1 6 //Motor1  L293 Pin in1
 #define in2 7 //Motor1  L293 Pin in1
 #define in3 9 //Motor2  L293Pin in1
 #define in4 10 //Motor2  L293 Pin in1
 #define R_S 4 // Right sensor
 #define L_S 2 // Left sensor
 #define ena 3
 #define enb 5
 
  pinMode(R_S, INPUT);
pinMode(L_S, INPUT);
pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 
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
   
}