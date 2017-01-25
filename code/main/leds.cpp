#include "leds.h"
#include "Tlc5940.h"

void Leds::init() {
  Tlc.init(0);
}

void Leds::update() {
  while(Tlc.update());
}

void Leds::on(Key* key, LayoutKey* layout) {
  Tlc.set(key->rPin, gammaCorrectionR[layout->color.r] * 8 * layout->color.a);
  Tlc.set(key->gPin, gammaCorrectionG[layout->color.g] * 8 * layout->color.a);
  Tlc.set(key->bPin, gammaCorrectionB[layout->color.b] * 8 * layout->color.a);
}

void Leds::off(Key* key) {
  Tlc.set(key->rPin, 0);
  Tlc.set(key->gPin, 0);
  Tlc.set(key->bPin, 0);
}
