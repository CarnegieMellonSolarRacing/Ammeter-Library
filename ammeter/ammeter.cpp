#include "Arduino.h"
#include "ammeter.h"

Ammeter::Ammeter(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _m = 1.0f;
  _b = 0.0f;
}

Ammeter::read_raw() {
  float raw = analogRead(_pin);
  return raw;
}

Ammeter::get_amps() {
  return (read_raw() - _baseline)*_m + _b;
}

Ammeter::zero() {
  _baseline = read_raw();
}

