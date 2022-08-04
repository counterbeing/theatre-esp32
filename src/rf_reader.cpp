#include <Arduino.h>
#include <RCSwitch.h>


RCSwitch mySwitch = RCSwitch();
RCSwitch mySwitch2 = RCSwitch();

#define RXD2 27

unsigned long startTime;


void setup() {
  Serial.begin(115200);
  Serial.print("Ready to receive.");  

  pinMode(RXD2, INPUT);

  mySwitch.enableReceive(digitalPinToInterrupt(RXD2));
  mySwitch2.enableTransmit(26);

  startTime = millis();
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

    if (millis() - startTime >= 5000) {
       Serial.println("SENDING");
      mySwitch2.send(5321684, 24);
      startTime = millis();
  }
}