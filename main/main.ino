#include <Ammeter.h>
#include <OperatorBridge.h>

Ammeter ammeterA(1, 2.928f);
Ammeter ammeterB(0, 4.28f);
OperatorBridge *bridge;
OperatorBridge::PacketOut out;
OperatorBridge::PacketIn *in;

void setup()
{
  bridge = new OperatorBridge();
  ammeterA.zero();
  ammeterB.zero();
}

void loop()
{
  float ampsA = ammeterA.get_amps();
  float ampsB = ammeterB.get_amps();
  //Serial.print(ammeterB.read_raw()); Serial.println(" raw");
  //Serial.print(ampsA); Serial.print(" "); Serial.print(ampsB); Serial.println(" amps");
  out.current[0] = ampsA;
  out.current[1] = ampsB;
  out.current[2] = ampsA;
  out.temp[0] = 444.4;
  out.temp[1] = 333.3;
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
