#include <Servo.h>
Servo myservo1;
int sensor1=3;
int sensor2=2;
int pos1=0;



void  intfun()
{
  detachInterrupt(digitalPinToInterrupt(sensor2));
  
 myservo1.write(0);
   pos1=0;
   

}

void setup() {
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  
  Serial.begin(9600);
  myservo1.attach(5);
  myservo1.write(0);

 
}

void loop() {
  bool instdis=digitalRead(sensor1);
   
 
 if(instdis ==LOW)
 {
    
   if (pos1!=90)
   {
      for (int pos = 0; pos <= 90; pos += 1){
      myservo1.write(pos);
      delay(20);
      pos1=pos;
      
      
     
     //serial.println(pos);
  
    }
    attachInterrupt(digitalPinToInterrupt(sensor2),intfun,LOW);
    
 
  
 }

  
 
 }

}
