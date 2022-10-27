#include <Arduino.h>
#include <HWCDC.h>
#include "config.h"
#include "stepper.h"
HWCDC USBSerial;
Stepper stpA(AIN1,AIN2,AIN3,AIN4);
Stepper stpB(BIN1,BIN2,BIN3,BIN4);
void setup()
{
    USBSerial.begin();
    USBSerial.println("v1.0.0");
    // pinMode(IO_PRESS,INPUT_PULLUP);
    pinMode(IO_PWR,OUTPUT);
    pinMode(IO_BOOT,OUTPUT);
    
    digitalWrite(IO_BOOT,LOW);
}
void loop()
{
    stpA.step();
    stpB.step();
    delay(5);
}