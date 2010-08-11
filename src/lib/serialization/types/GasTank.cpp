#include "GasTank.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const GasTank GasTank::mProto;

GasTank::GasTank() : Message(0x5a4) {
}

GasTank::GasTank(const GasTank &other)
  : Message(other) {
}

GasTank::~GasTank() {
}

void GasTank::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu8GasTank;
  stream << endl;
}

void GasTank::formatMessage(uint8_t *au8Buffer) {
  mu8GasTank = au8Buffer[1];
}

GasTank* GasTank::clone() const {
  return new GasTank(*this);
}
