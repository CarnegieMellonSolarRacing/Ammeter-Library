#include "LightSensor.h"

LightSensor::LightSensor(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}

float LightSensor::read_raw() {
  float raw = analogRead(_pin);
  return raw;
}

float LightSensor::read_lux() {
  float raw = read_raw();
  float volt = raw*(5.0/1023.0);
  float amp = (float) volt / (float) 10.0;
  float lux = .609*pow(amp, 0.820825);
  return lux;
}
