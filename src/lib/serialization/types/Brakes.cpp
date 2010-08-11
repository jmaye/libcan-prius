#include "Brakes.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const Brakes Brakes::mProto;

Brakes::Brakes() : Message(0x30) {
}

Brakes::Brakes(const Brakes &other)
  : Message(other) {
}

Brakes::~Brakes() {
}

void Brakes::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu8Pressed;
  stream << " ";
  stream << mu8Force;
  stream << endl;
}

void Brakes::formatMessage(uint8_t *au8Buffer) {
  mu8Pressed = au8Buffer[0];
  mu8Force = au8Buffer[4];
}

Brakes* Brakes::clone() const {
  return new Brakes(*this);
}
