#include <Enes100Simulation.h>
#include <SimulatorClient.h>
#include <TankSimulation.h>

// https://playground.arduino.cc/uploads/Main/arduino_notebook_v1-1.pdf

void setup() {
  // run once
  // follow the declaration of any variables at beginning of program 
  // used to set pinMode or initialize serial communication 
  int pin = 2 ;
  pinMode(pin, OUTPUT) ; 
  // Sets the 'pin' as output 
  // pins default to input 

  // 20K ohms pullup resistors built into the atmega chip and can be accessed 
  pinMode(pin, INPUT) ; 
  digitalWrite(pin, HIGH) ;
  // used for connecting inputs like switches 


}

void loop() {
  // run repeatedly

  // turn 'pin' on 
  int pin = 2 ;
  digitalWrite(pin, HIGH) ; 

  // pause for one second
  delay(1000) ; 

  // turns 'pin' off 
  digitalWrite(pin, LOW) ; 

}

void makingFuctions(void) { 

// type functionName(parameters) { 
  
  // FUNCTIONS 
  // insert statements ; 
  
} 

int delayVal() { 
   // used to set a delay value in a program by reading the value of a potentiometer 
   // integer between 0 and 1023 divided by 4 

   int v ; 

   // read potentiometer
   int pot = 5 ;
   v = analogRead(pot) ; 

   // convert numbers 0-1023 to 0-255 
   v /= 4 ; 
   
   return v ; 
}


/* this is how you make a block comment
 *  you can type out whatever for as long as you want 
 *  the comment will end when you want 
 */

int AssigningVariables(void) { 

  // declare and assign variable to value 
  int inputVariable = 0 ; 

  // set variable to value of analog pin 2 
  inputVariable = analogRead(2) ; 

  // use conditional to reassign variables 
  if (inputVariable < 200) { 
    
    inputVariable = 200 ; 
   
  }

  // use new variable as a delay 
  delay(inputVariable) ; 

  // for loops 
  float sum = 0 ; 
  for (int i = 0; i<20; i++) {
    sum+=i ; 
  }

  return 0 ; 
}

int typesOfVariables(void) { 

  // types of variables

  // byte stores 8-bit numerical value without decimal points, range of 0-255 
  byte someVariable = 180 ; 

  // int, 16-bit value, range 32767 to -32678
  int somVariable = 1500 ;

  // long, datatype for long integers without decimal points, 32-bit, 2147483647 to -2147483647
  long somevariable = 90000 ; 

  //float, floating-point with decimal point, 32-bit, range 3.4028235E+38 to -3.4028235E+38
  float SomeVariable = 3.14 ; 
}


int arrays(void) { 

  // declare array with 6 positions 
  int myArray[5] ; 
  
  // assign variables, in this case assign '6' to the 4th position 
  myArray[3] = 6 ; 


  // Using arrays to flicker an LED 
  int ledPin = 10 ; 
  byte flicker[] = {180, 30, 255, 200, 10, 90, 150, 60} ;

   void setup() ;
   { 
    pinMode(ledPin, OUTPUT) ; 
   } 

//   void loop() {
    for (int i=0 ; 1<8 ; i++) {
      analogWrite(ledPin, flicker[i]) ; 
      delay(200) ; 
//    }
  return 0 ; 
}

int operators(void) ;
{

   // x is equal to y 
   // x == y 

   // x is not equal to y 
   // x != Y

   // x is less that y 
   // x < y 
   // ... > , <= , and >= 

  // logical AND
  // true only is both expressions are true 
  // if (x>0 && x<5) 

  // logical OR 
  // true is either expression is true 
  // if ( x<0 || y>0 ) 

  // logical NOT 
  // only true if expression is false 
  // if (!x > 0) 

   return 0;
}


int constants(void) ;
{ 
  int b = 0 ;
  // true/false 
  // true is 1, false is 0 
  if (b == true) {
    // doSomething ;
  }

  // High/low 
  // High is logic level 1, ON, or 5 volts 
  // Low is logic level 0, OFF, or 0 VOlts 
  digitalWrite(13,HIGH) ;

  // Input/Output
  // define the mode of the digital pin 
  pinMode(13, OUTPUT) ; 

  return 0 ;
}

int loops(void) ;
{

  // FOR loops 

  // for (initialization ; condition ; expression ) { 
  // doSomething ;
  }

  for (int i=0; i<20 ; i++ ) {
    // turn pin 13 on
    digitalWrite(13,HIGH) ;
    // pause for 1/4 second 
    delay(250) ; 
    //turn pin 13 off 
    digitalWrite(13,LOW) ; 
    delay(250) ;
  }

  // WHILE loops 

  int someVariable = 201 ;
  while (someVariable < 200) { 
    // if less than 200, the execute 
    // doSomething ; 
    someVariable++ ; 
  }

  /*
   * 
  do { 
    // x = readSensors() ; 
    int x = 200 ;
    delay(50) ;
  } while (x < 100) ; 
  *
  */

  return 0 ;
}


int onANDoff(void) { 

  int pin=5 ;
  int value = digitalRead(pin) ; 
  // sets 'value' equal to the input pin
  // reads the specified digital pin with the result of either HIGH or LOW 

  digitalWrite(pin, HIGH) ;
  // sets 'pin' to high 
  // outputs either logic level HIGH or LOW at (turns on or off) a specified digital pin
  // variable or constant of 0-13 

  // example reads a pushbotton connected to a digital input and turns on an LED connected to a digital output

  // connect LED to pin 13 
  int led = 13 ; 
  // connect pushbotton to pin 7 
  int botton = 7 ; 
  // create variable to store the read value 

  void setup() ;
  { 
    // sets pin 13 as output 
    pinMode(led, OUTPUT) ; 
    // sets pin 7 as input
    pinMode(botton, INPUT) ; 
  }

  void loop() ;
  { 
    // sets 'value' equal to the input pin 
    value = digitalRead(pin) ; 
    // sets 'led' to the button's value
    digitalWrite(led, value) ; 
  }

  return 0 ;
}


int readingData(void) { 

  // reads value from specified analog pin witha  10-bit resolution
  // works only for pins 1 through 5 
  // integer values 0 to 1023 

  int pin=5 ;
  int value = analogRead(pin) ; 
  // analog pins do not need to be first declared as INPUT or OUTPUT 

  // example reads an analog value from an analog input pin 
  // LED with 220 resistor on pin 10 
  int led = 10 ; 
  // potentiometer on analog pin 0
  int Pin =0; 
  // value for reading 
  int Value ; 

  void setup() ;
  {}
  
  //void loop { 
    // set value equal to pin  
    Value = analogRead(Pin) ; 
    // converts 0-1023 to 0-255 
    Value /= 4 ; 
    // outputs PWM signal to led 
    analogWrite(led, Value) ; 
  // }

  return 0 ;
}



int variousFunctions(void) { 

  int ms=0 ; int x=0 ;int y=0 ;int seed=0 ;

  delay(ms) ;

  millis() ; 

  min(x,y) ; 

  max(x,y) ; 

  // sets a value, or seed, as the starting point for the random() function 
  randomSeed(seed) ; 
  // can be used in this function including millis() or even analogRead() to read electrical noise through an analog
  int max = 200 ; int min = 1 ;
  random(max) ; 
  random(min, max) ; 
  // sets value to a random number between 100-200 
  int value = random(100,200) ; 
  // use this after using the randomSeed()

  // example 
  // variable to store the random value 
  int randNumber ; 
  // LED with 220 resistor on pin 10 
  int led = 10 ; 

  void setup() ;{} 

  void loop() ;
  { 
    // set millis() as seed 
    randomSeed(millis()) ; 
    // random number from 0 -255 
    int radndNumber = random(255) ; 
    // outputs PWM signal
    analogWrite(led, randNumber) ; 
    delay(500) ; 
    
  }
  
}

int serialStuff(void) { 

  // open serial port and sets the baud rate for serial data transmission 
  // typical baud rate for communicating with the computer is 9600 
  int rate = 0 ;
  Serial.begin(rate) ;

  void setup() ;
  {
    // opens serial prt and sets data rate to 9600 bps
    Serial.begin(9600) ;
  }

  // print data to the serial port, followed by an automatic carriage return and line feed 
  // send teh value of "analogValue"
  int analogValue = 0 ;
  Serial.print(analogValue) ; 

  // example - takes reading from analog pin and sends it to computer every second 

  void setup() ;
  { 
  // set serial to 9600 bps
  Serial.begin(9600) ;
  }

  void loop() ;
  {
    // send analog value 
    Serial.print(analogRead(0)) ; 
    delay(1000) ;
  }
  
}