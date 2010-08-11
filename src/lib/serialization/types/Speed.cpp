#include "Speed.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const Speed Speed::mProto;

Speed::Speed() : Message(0x3ca) {
}

Speed::Speed(const Speed &other)
  : Message(other) {
}

Speed::~Speed() {
}

void Speed::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu8Speed;
  stream << endl;
}

void Speed::formatMessage(uint8_t *au8Buffer) {
  mu8Speed = au8Buffer[2];
}

Speed* Speed::clone() const {
  return new Speed(*this);
}
