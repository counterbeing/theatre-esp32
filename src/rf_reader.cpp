#include <Arduino.h>
#include <RCSwitch.h>


RCSwitch mySwitch = RCSwitch();

#define RXD2 27


void setup() {
  Serial.begin(115200);
  Serial.print("Ready to receive.");  

  pinMode(RXD2, INPUT);

  mySwitch.enableReceive(digitalPinToInterrupt(RXD2));
}

// The repeating section of the code
void loop() {
    if (mySwitch.available()) {
    
    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );

    mySwitch.resetAvailable();
  }
}