#include <Servo.h> 

Servo ultrasonic ;
// create servo object for the servo that will be controling the movements of the ultrasonic sensor 
// 3.3V power 
int pos = 0 ; 
int delayTime = 100  ;
int degreeRange = 90 ; 


// Ultrasonic Sensor 
#define triggerPin 8 
#define echoPin 7
long duration ; 
long distance ; 

void setup() {
  
  ultrasonic.attach(10) ; 
  // servo controlling movements of ultrasonic sensor is is attached on pin 9 

  Serial.begin(9600) ; 
  pinMode(echoPin, INPUT) ; 
  pinMode(triggerPin, OUTPUT) ; 
  
}

void loop() {
  
    for ( pos = 0 ; pos <=degreeRange ; pos+=5) { 
        // goes from 0 to 180 degrees 
        
        ultrasonic.write(pos) ; 
         // tell servo to go to position "pos" 
    
        delay(delayTime) ; 

        // ultrasonic sensor measure distance 
        digitalWrite(triggerPin, LOW) ; 
        delayMicroseconds(2) ; 
        digitalWrite(triggerPin, HIGH) ; 
        delayMicroseconds(10) ; 
      
        digitalWrite(triggerPin, LOW) ; 
        duration = pulseIn(echoPin, HIGH) ; 
        distance = duration/58.2 ; 

        Serial.print("  ") ; 
        Serial.print(distance) ; 
        delayMicroseconds(50) ;
        
      }
  
    for ( pos = degreeRange ; pos >=0 ; pos-=5) { 
        // goes from 0 to 180 degrees 
        
        ultrasonic.write(pos) ; 
         // tell servo to go to position "pos" 
    
        delay(delayTime) ; 

        // ultrasonic sensor measure distance 
        digitalWrite(triggerPin, LOW) ; 
        delayMicroseconds(2) ; 
        digitalWrite(triggerPin, HIGH) ; 
        delayMicroseconds(10) ; 
      
        digitalWrite(triggerPin, LOW) ; 
        duration = pulseIn(echoPin, HIGH) ; 
        distance = duration/58.2 ; 

        Serial.print(" " ) ; 
        Serial.print(distance) ; 
        delayMicroseconds(50) ;
        
      }  


}
