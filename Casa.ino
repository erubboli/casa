#include <Bridge.h>
#include <Process.h>

const int buttonPin = 6; 
const int ledPin =  12; 
const int ringLenght = 1000;


int buttonState = 0;
int ringAllowed = 1;
int pressCount = 0;

void setup() {
  Bridge.begin();
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  while (!Serial);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) { // use pull-up resistor
    if(ringAllowed == 1){
      if(pressCount < 10){
        pressCount++
      }else{
        pressCount=0
        ring();    
      }
    }
  } else {
    if(ringAllowed==0)
      delay(600); //avoid to ring on release
    ringAllowed = 1;
    pressCount = 0
  }
}

void ring(){
  ringAllowed = 0;
  Process p;
  p.runShellCommand("/usr/bin/notify.py");

  digitalWrite(ledPin, HIGH);
  delay(ringLenght);
  digitalWrite(ledPin, LOW);
}

