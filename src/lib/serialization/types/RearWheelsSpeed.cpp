#include "RearWheelsSpeed.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const RearWheelsSpeed RearWheelsSpeed::mProto;

RearWheelsSpeed::RearWheelsSpeed() : Message(0xb3) {
}

RearWheelsSpeed::RearWheelsSpeed(const RearWheelsSpeed &other)
  : Message(other) {
}

RearWheelsSpeed::~RearWheelsSpeed() {
}

void RearWheelsSpeed::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu16RightSpeed;
  stream << " ";
  stream << mu16LeftSpeed;
  stream << endl;
}

void RearWheelsSpeed::formatMessage(uint8_t *au8Buffer) {
  mu16RightSpeed = (au8Buffer[0] << 8) | (au8Buffer[1] << 0);
  mu16LeftSpeed = (au8Buffer[2] << 8) | (au8Buffer[3] << 0);
}

RearWheelsSpeed* RearWheelsSpeed::clone() const {
  return new RearWheelsSpeed(*this);
}
