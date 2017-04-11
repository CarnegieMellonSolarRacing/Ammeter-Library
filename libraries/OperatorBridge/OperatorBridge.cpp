#include <stdlib.h>
#include <avr/pgmspace.h>
#include "OperatorBridge.h"

OperatorBridge::OperatorBridge() {
  Serial.begin(9600);
  Serial.setTimeout(300);
}

OperatorBridge::~OperatorBridge() {
  Serial.end();
}

OperatorBridge::PacketIn *OperatorBridge::read() {
  if (Serial.available() > 30) {
    if (!Serial.find((char*)"BEGIN_PACKET")) return nullptr;
    if (!Serial.find((char*)"TEST_VAL1:")) return nullptr;
    float testValue = Serial.parseFloat();
    if (!Serial.find((char*)"END_PACKET")) return nullptr;
    Serial.readStringUntil('\n');

    PacketIn *packet = new PacketIn();
    Serial.println((int)packet);
    packet->testValue = testValue;
    return packet;
  }
  return nullptr;
}

bool OperatorBridge::send(OperatorBridge::PacketOut packet) {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  JsonArray& current_data = root.createNestedArray("currents");
  for (int i = 0; i < NUM_CURRENT_SENSORS; i++) {
    current_data.add(double_with_n_digits(packet.current[i], 6));
  }
  JsonArray& temp_data = root.createNestedArray("temps");
  for (int i = 0; i < NUM_TEMP_SENSORS; i++) {
    temp_data.add(double_with_n_digits(packet.temp[i], 6));
  }
  JsonArray& light_data = root.createNestedArray("lights");
  for (int i = 0; i < NUM_LIGHT_SENSORS; i++) {
    light_data.add(double_with_n_digits(packet.light[i], 6));
  }
  root.printTo(Serial);
  Serial.println();
  return true;
}
