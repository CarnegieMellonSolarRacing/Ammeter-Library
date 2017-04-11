#include <Ammeter.h>
#include <OperatorBridge.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LightSensor.h>

#include "PinMap.h"

/* Declare Sensors Here */
Ammeter ammeterA(AMMETER_A_PIN, 2.928f);
Ammeter ammeterB(AMMETER_B_PIN, 4.28f);

OneWire tempAOneWire(TEMPERATURE_A_PIN);
DallasTemperature tempASensor(&tempAOneWire);

LightSensor lightASensor(LIGHT_A_PIN);

/* Bridge to Tablet */
OperatorBridge *bridge;
OperatorBridge::PacketOut out;
OperatorBridge::PacketIn *in;

void setup()
{
  bridge = new OperatorBridge();
  ammeterA.zero();
  ammeterB.zero();
}

void sendPacket()
{
  
}
void loop()
{
  /* Prepare for sensor measurement */
  tempASensor.requestTemperatures();

  /* Collect Measurements */
  float ampsA = ammeterA.get_amps();
  float ampsB = ammeterB.get_amps();

  float tempA = tempASensor.getTempCByIndex(0);
  float lightA = lightASensor.read_lux();
  
  out.current[0] = ampsA;
  out.current[1] = ampsB;
  out.current[2] = ampsA;
  out.temp[0] = tempA;
  out.temp[1] = tempA;
  out.light[0] = lightA;
  
  bridge->send(out);

  in = bridge->read();
  if (in != nullptr) {
    Serial.println(in->testValue);
    delete in;
  } else {
    // Serial.println("Recieved Null Pointer");
  }
  delay(1000);
}
