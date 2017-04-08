/*
  Ammeter.h
*/
#ifndef Ammeter_h
#define Ammeter_h

#include "Arduino.h"

class Ammeter
{
  public:
    Ammeter(int pin, float scale);
    void zero();
    float get_amps();
    float read_raw();
  private:
    int _pin;
    float _baseline;
    float _b;
    float _m;
};

#endif
