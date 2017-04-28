/*
  VoltageSensor.h
*/
#ifndef VoltageSensor_h
#define VoltageSensor_h

#include "Arduino.h"

class VoltageSensor
{
  public:
    VoltageSensor(int pin);
    float read_raw();
  private:
    int _pin;
};

#endif
