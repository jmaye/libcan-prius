#include "Acceleration.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const Acceleration Acceleration::mProto;

Acceleration::Acceleration() : Message(0x23) {
}

Acceleration::Acceleration(const Acceleration &other)
  : Message(other) {
}

Acceleration::~Acceleration() {
}

void Acceleration::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu16Sensor1;
  stream << " ";
  stream << mu16Sensor2;
  stream << endl;
}

void Acceleration::formatMessage(uint8_t *au8Buffer) {
  mu16Sensor1 = (au8Buffer[0] << 8) | (au8Buffer[1] << 0);
  mu16Sensor2 = (au8Buffer[2] << 8) | (au8Buffer[3] << 0);
}

Acceleration* Acceleration::clone() const {
  return new Acceleration(*this);
}
