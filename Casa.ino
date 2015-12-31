#include <Bridge.h>

const int buttonPin = 2; 
const int ledPin =  12; 
const int ringLenght = 1100;


int buttonState = 0;
int ringAllowed = 1;

void setup() {
//  Serial.begin(9600);
//  Bridge.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) { // use pull-up resistor
    if(ringAllowed == 1){
      ring();    
    }
  } else {
    if(ringAllowed==0)
      delay(600); //avoid to ring on release
    ringAllowed = 1;
  }
}

void ring(){
  ringAllowed = 0;
//  Serial.println("RING!");
  digitalWrite(ledPin, HIGH);
  delay(ringLenght);
  digitalWrite(ledPin, LOW);
}

