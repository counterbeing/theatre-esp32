// #include <Arduino.h>
// #include <RCSwitch.h>
// #include "HomeSpan.h"
// #include "dev_screen.h"



// RCSwitch mySwitch = RCSwitch();
// RCSwitch mySwitch2 = RCSwitch();

// #define RXD2 27
// #define RF_TX 26

// unsigned long startTime;


// void setup() {
//   Serial.begin(115200);

//   homeSpan.begin(Category::Lighting,"Projector Screen");
  
//   new SpanAccessory(); 
  
//     new Service::AccessoryInformation(); 
//       new Characteristic::Identify();                
//     new PROJECTOR_SCREEN(RF_TX); 
//       new SpanAccessory(); 
//     new Service::AccessoryInformation();    
//       new Characteristic::Identify();   

//   pinMode(RXD2, INPUT);

//   mySwitch.enableReceive(digitalPinToInterrupt(RXD2));
//   // mySwitch2.enableTransmit(RF_TX);

//   startTime = millis();
// }

// // The repeating section of the code
// void loop() {
//     homeSpan.poll();

//     if (mySwitch.available()) {
    
//     Serial.print("Received ");
//     Serial.print( mySwitch.getReceivedValue() );
//     Serial.print(" / ");
//     Serial.print( mySwitch.getReceivedBitlength() );
//     Serial.print("bit ");
//     Serial.print("Protocol: ");
//     Serial.println( mySwitch.getReceivedProtocol() );

//     mySwitch.resetAvailable();
//   }

//   //   if (millis() - startTime >= 5000) {
//   //      Serial.println("SENDING");
//   //     // mySwitch2.send(5321684, 24);
//   //     // mySwitch2.send(5321682, 24);
//   //     startTime = millis();
//   // }
// }