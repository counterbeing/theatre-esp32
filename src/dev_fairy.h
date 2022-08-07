// #define T1 27
// #define T2 26

#include "extras/PwmPin.h" 

struct FAIRY_LIGHTS : Service::LightBulb {     

  LedPin *ledPin;                              
  SpanCharacteristic *power;                   
  SpanCharacteristic *level;                   
  
  FAIRY_LIGHTS() : Service::LightBulb(){       

    power=new Characteristic::On();     
                
    level=new Characteristic::Brightness(50);       
    level->setRange(5,100,1);                       

    this->ledPin=new LedPin(27);                  
    
  } 

  boolean update(){                              
    int powerVal = power->getNewVal();
    int levelVal = level->getNewVal();

    

    int val = levelVal * powerVal;

    Serial.println(val);

    // if(val > 60){
    //   digitalWrite(27, HIGH);
    // } else {
    //   digitalWrite(27, LOW);
    // }

    ledPin->set(val);    
   
    return(true);                               
  
  } 
};