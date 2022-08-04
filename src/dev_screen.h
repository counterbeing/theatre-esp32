#include <RCSwitch.h>
#define RF_TX 26

// RCSwitch transmitterX;
RCSwitch transmitterX = RCSwitch();

struct PROJECTOR_SCREEN: Service::LightBulb {
  int ledPin; 
  SpanCharacteristic * power; 

  PROJECTOR_SCREEN(int ledPin): Service::LightBulb() {
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

    // digitalWrite(ledPin,power->getNewVal());        

    // return true to indicate the update was successful (otherwise create code
    // to return false if some reason you could not turn on the LED)
    return(true);
  }
};