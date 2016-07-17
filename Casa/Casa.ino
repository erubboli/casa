#include <Process.h>

const int buttonPin = 6; 
const int ringPin =  12; 
const int ledPin = 13;

const int ringLenght = 800; //milliseconds

int buttonState = 0;
int ringAllowed = 1;
int countTicks = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ringPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Bridge.begin();
  Serial.begin(9600);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) { // use pull-up resistor   
    if(ringAllowed == 1){
      if(countTicks < 10){
        countTicks++;
      }else{
        notify();
        ring();    
      }
    }
    
  } else {
    if(ringAllowed==0)
      delay(600); //avoid to ring on release
    ringAllowed = 1;
    countTicks = 0;
  }
  
}

void notify(){
  Process p; // send message to the queue on the Linux Side
  p.runShellCommandAsynchronously("/usr/bin/notify_ring.py");
}

void ring(){
  digitalWrite(ledPin, HIGH);
  digitalWrite(ringPin, HIGH);
  delay(ringLenght);
  digitalWrite(ledPin, LOW);
  digitalWrite(ringPin, LOW);
  countTicks = 0;
  ringAllowed = 0;
}
