#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}

float VoltageSensor::read_raw() {
  float raw = analogRead(_pin);
  return raw;
}

