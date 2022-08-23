#include <IRsend.h>

const uint16_t irLED = 4;
IRsend irsend2(irLED);

struct PROJECTOR: Service::Outlet {
  SpanCharacteristic * power; 

  PROJECTOR(): Service::Outlet() {
    irsend2.begin();
    power = new Characteristic::On();
  }

  boolean update() {
    int value = power -> getNewVal();
    Serial.println(value);
    if (value == 1) {
      Serial.println("PROJECTOR ON");
      irsend2.sendNEC(0x4CB340BF);
      delay(1000);
      irsend2.sendNEC(0x4CB340BF);
    } else {
      Serial.println("PROJECTOR OFF");
      delay(500);
      irsend2.sendNEC(0x4CB3748B);
      delay(1000);
      irsend2.sendNEC(0x4CB3748B);
      delay(1000);
      irsend2.sendNEC(0x4CB3748B);
      delay(1000);
      irsend2.sendNEC(0x4CB3748B);
    }
    
    return(true);
  }
};