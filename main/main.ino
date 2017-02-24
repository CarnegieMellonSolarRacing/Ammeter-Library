#include <Ammeter.h>

Ammeter ammeter(1);

void setup()
{
  Serial.begin(9600);
  Serial.println("Setting Up");
  ammeter.zero();
}

void loop()
{
  float amps = ammeter.get_amps();
  Serial.print(amps); Serial.println(" amps");
  delay(500);
}
