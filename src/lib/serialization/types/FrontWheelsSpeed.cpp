#include "FrontWheelsSpeed.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const FrontWheelsSpeed FrontWheelsSpeed::mProto;

FrontWheelsSpeed::FrontWheelsSpeed() : Message(0xb1) {
}

FrontWheelsSpeed::FrontWheelsSpeed(const FrontWheelsSpeed &other)
  : Message(other) {
}

FrontWheelsSpeed::~FrontWheelsSpeed() {
}

void FrontWheelsSpeed::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu16RightSpeed;
  stream << " ";
  stream << mu16LeftSpeed;
  stream << endl;
}

void FrontWheelsSpeed::formatMessage(uint8_t *au8Buffer) {
  mu16RightSpeed = (au8Buffer[0] << 8) | (au8Buffer[1] << 0);
  mu16LeftSpeed = (au8Buffer[2] << 8) | (au8Buffer[3] << 0);
}

FrontWheelsSpeed* FrontWheelsSpeed::clone() const {
  return new FrontWheelsSpeed(*this);
}
