/*
  Ammeter.h
*/
#ifndef Ammeter_h
#define Ammeter_h

#include "Arduino.h"

class Ammeter
{
  public:
    Ammeter(int pin);
    void zero();
    float get_amps();
  private:
    int _pin;
    float _baseline;
    float _b; 
    float _m;
    float read_raw();
};

#endif
