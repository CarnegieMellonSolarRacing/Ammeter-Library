/*
  Ammeter.h
*/
#ifndef LightSensor_h
#define LightSensor_h

#include "Arduino.h"

class LightSensor
{
  public:
    LightSensor(int pin);
    float read_raw();
    float read_lux();
  private:
    int _pin;
};

#endif
