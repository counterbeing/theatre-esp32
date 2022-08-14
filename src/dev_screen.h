#include <RCSwitch.h>
#define RF_TX 26

RCSwitch transmitterX = RCSwitch();

struct PROJECTOR_SCREEN: Service::Outlet {
  int ledPin; 
  SpanCharacteristic * power; 

  PROJECTOR_SCREEN(int ledPin): Service::Outlet() {
    power = new Characteristic::On();
    this -> ledPin = ledPin; 

		transmitterX = RCSwitch();
    transmitterX.enableTransmit(RF_TX);
  }

  boolean update() {
    int value = power -> getNewVal();
    Serial.println(value);
    digitalWrite(ledPin,value);        

    if (value == 1) {
      Serial.println("UP");
      transmitterX.send(5321684, 24);
    } else {
      Serial.println("DOWN");
      transmitterX.send(5321682, 24);
    }
    
    return(true);
  }
};