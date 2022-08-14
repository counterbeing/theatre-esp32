#include <IRsend.h>

const uint16_t kIrLed = 4;
IRsend irsend(kIrLed);

struct RECEIVER: Service::Outlet {
  SpanCharacteristic * power; 

  RECEIVER(): Service::Outlet() {
    irsend.begin();
    power = new Characteristic::On();
  }

  boolean update() {
    int value = power -> getNewVal();
    Serial.println(value);
    if (value == 1) {
      Serial.println("RECEIVER ON");
      irsend.sendNEC(0x7E817E81);
    } else {
      Serial.println("RECEIVER OFF");
      irsend.sendNEC(0x7E81FE01);
    }
    
    return(true);
  }
};