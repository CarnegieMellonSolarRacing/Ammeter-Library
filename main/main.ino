#include <Ammeter.h>
#include <OperatorBridge.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LightSensor.h>
#include <VoltageSensor.h>

#include "PinMap.h"

/* Declare Sensors Here */
Ammeter ammeterA(AMMETER_A_PIN, 2.928f);
Ammeter ammeterB(AMMETER_B_PIN, 4.28f);
Ammeter ammeterC(AMMETER_C_PIN, 4.726f);

OneWire tempAOneWire(TEMPERATURE_A_PIN);
DallasTemperature tempASensor(&tempAOneWire);
OneWire tempBOneWire(TEMPERATURE_B_PIN);
DallasTemperature tempBSensor(&tempBOneWire);

VoltageSensor voltageASensor(VOLTAGE_A_PIN);
VoltageSensor voltageBSensor(VOLTAGE_B_PIN);
VoltageSensor voltageCSensor(VOLTAGE_C_PIN);

/* Bridge to Tablet */
OperatorBridge *bridge;
OperatorBridge::PacketOut out;
OperatorBridge::PacketIn *in;

void setup()
{
  bridge = new OperatorBridge();
  ammeterA.zero();
  ammeterB.zero();
  ammeterC.zero();
}

void sendPacket()
{
  
}
void loop()
{
  /* Prepare for sensor measurement */
  tempASensor.requestTemperatures();
  tempBSensor.requestTemperatures();

  /* Collect Measurements */
  float ampsA = ammeterA.read_raw();
  float ampsB = ammeterB.read_raw();
  float ampsC = ammeterC.read_raw();

  float tempA = tempASensor.getTempCByIndex(0);
  float tempB = tempBSensor.getTempCByIndex(0);

  float voltA = voltageASensor.read_raw();
  float voltB = voltageBSensor.read_raw();
  float voltC = voltageCSensor.read_raw();

  out.current[0] = ampsA;
  out.current[1] = ampsB;
  out.current[2] = ampsC;
  out.temp[0] = tempA;
  out.temp[1] = tempB;
  out.volt[0] = voltA;
  out.volt[1] = voltB;
  out.volt[2] = voltC;

  bridge->send(out);

  in = bridge->read();
  if (in != nullptr) {
    Serial.println(in->testValue);
    delete in;
  } else {
    // Serial.println("Recieved Null Pointer");
  }
  delay(500);
}
