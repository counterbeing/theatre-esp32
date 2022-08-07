#include <Arduino.h>
#include "HomeSpan.h"
#include "dev_fairy.h"

#define T1 27
#define T2 26



unsigned long startTime;


void setup() {
  Serial.begin(115200);
  homeSpan.begin(Category::Lighting,"Fairy Lights");
  new SpanAccessory(); 
  
    new Service::AccessoryInformation(); 
      new Characteristic::Identify();                
    new FAIRY_LIGHTS(); 
      new SpanAccessory(); 
    new Service::AccessoryInformation();    
      new Characteristic::Identify();   

  pinMode(T1, OUTPUT);
  pinMode(T2, OUTPUT);
}

void loop() {
    homeSpan.poll();
}