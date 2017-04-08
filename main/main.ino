#include <Ammeter.h>

Ammeter ammeterA(1, 2.928f);
Ammeter ammeterB(0, 4.28f);

void setup()
{
  Serial.begin(9600);
  Serial.println("Setting Up");
  ammeterA.zero();
  ammeterB.zero();
}

void loop()
{
  float ampsA = ammeterA.get_amps();
  float ampsB = ammeterB.get_amps();
  Serial.print(ammeterB.read_raw()); Serial.println(" raw");
  //Serial.print(ampsA); Serial.print(" "); Serial.print(ampsB); Serial.println(" amps");
  delay(500);
}
