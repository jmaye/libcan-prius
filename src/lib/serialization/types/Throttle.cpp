#include "Throttle.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const Throttle Throttle::mProto;

Throttle::Throttle() : Message(0x244) {
}

Throttle::Throttle(const Throttle &other)
  : Message(other) {
}

Throttle::~Throttle() {
}

void Throttle::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu8Position;
  stream << endl;
}

void Throttle::formatMessage(uint8_t *au8Buffer) {
  mu8Position = au8Buffer[6];
}

Throttle* Throttle::clone() const {
  return new Throttle(*this);
}
