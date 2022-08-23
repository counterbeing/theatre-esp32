#include <Arduino.h>
#include <RCSwitch.h>
#include "HomeSpan.h"
#include "dev_screen.h"
#include "dev_receiver.h"
#include "dev_projector.h"



#define RXD2 27
#define RF_TX 26

unsigned long startTime;


void setup() {
  Serial.begin(115200);

  homeSpan.begin(Category::Outlets,"Projector Screen");
  
  new SpanAccessory(); 
    new Service::AccessoryInformation(); 
      new Characteristic::Name("Projector Screen");
      new Characteristic::Manufacturer("Cory"); 
      new Characteristic::SerialNumber("123-ABC");   
      new Characteristic::Model("Projector Screen");
      new Characteristic::FirmwareRevision("1");
      new Characteristic::Identify();                
    new PROJECTOR_SCREEN(RF_TX); 

  new SpanAccessory(); 
    new Service::AccessoryInformation(); 
      new Characteristic::Name("Receiver");
      new Characteristic::Manufacturer("Cory"); 
      new Characteristic::SerialNumber("123-ABC");   
      new Characteristic::Model("Yamaha RX-v373");
      new Characteristic::Identify();                
      new RECEIVER(); 

  new SpanAccessory(); 
    new Service::AccessoryInformation(); 
      new Characteristic::Name("Projector");
      new Characteristic::Manufacturer("Cory"); 
      new Characteristic::SerialNumber("123-ABC");   
      new Characteristic::Model("Projector");
      new Characteristic::Identify();                
      new PROJECTOR(); 
    // pinMode(4, OUTPUT);
}

void loop() {
    homeSpan.poll();
    // digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
    // delay(3000);                       // wait for a second
    // digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
    // delay(1000);     
}