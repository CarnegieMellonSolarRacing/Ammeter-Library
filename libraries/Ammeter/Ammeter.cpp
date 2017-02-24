#include "Arduino.h"
#include "Ammeter.h"

Ammeter::Ammeter(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _m = 1.0f;
  _b = 0.0f;
}

float Ammeter::read_raw() {
  float raw = analogRead(_pin);
  return raw;
}

float Ammeter::get_amps() {
  return (read_raw() - _baseline)*_m + _b;
}

void Ammeter::zero() {
  _baseline = read_raw();
}

