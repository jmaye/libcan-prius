#include "Steering.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const Steering Steering::mProto;

Steering::Steering() : Message(0x25) {
}

Steering::Steering(const Steering &other)
  : Message(other) {
}

Steering::~Steering() {
}

void Steering::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mi16SteeringAngle;
  stream << endl;
}

void Steering::formatMessage(uint8_t *au8Buffer) {
  uint16_t u16Msg = (au8Buffer[0] << 8) | (au8Buffer[1] << 0);
  if (u16Msg <= 0x1B7)
    mi16SteeringAngle = u16Msg;
  else
    mi16SteeringAngle = -(4096 - u16Msg);
}

Steering* Steering::clone() const {
  return new Steering(*this);
}
