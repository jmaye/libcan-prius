#include "SidewayAcceleration.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const SidewayAcceleration SidewayAcceleration::mProto;

SidewayAcceleration::SidewayAcceleration() : Message(0x22) {
}

SidewayAcceleration::SidewayAcceleration(const SidewayAcceleration &other)
  : Message(other) {
}

SidewayAcceleration::~SidewayAcceleration() {
}

void SidewayAcceleration::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu16Sensor1;
  stream << " ";
  stream << mu16Sensor2;
  stream << endl;
}

void SidewayAcceleration::formatMessage(uint8_t *au8Buffer) {
  mu16Sensor1 = (au8Buffer[0] << 8) | (au8Buffer[1] << 0);
  mu16Sensor2 = (au8Buffer[2] << 8) | (au8Buffer[3] << 0);
}

SidewayAcceleration* SidewayAcceleration::clone() const {
  return new SidewayAcceleration(*this);
}
