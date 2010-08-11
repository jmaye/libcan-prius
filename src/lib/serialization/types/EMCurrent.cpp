#include "EMCurrent.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const EMCurrent EMCurrent::mProto;

EMCurrent::EMCurrent() : Message(0x3b) {
}

EMCurrent::EMCurrent(const EMCurrent &other)
  : Message(other) {
}

EMCurrent::~EMCurrent() {
}

void EMCurrent::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu16Current;
  stream << " ";
  stream << mu16Voltage;
  stream << endl;
}

void EMCurrent::formatMessage(uint8_t *au8Buffer) {
  mu16Current = (au8Buffer[0] << 8) | (au8Buffer[1] << 0);
  mu16Voltage = (au8Buffer[2] << 8) | (au8Buffer[3] << 0);
}

EMCurrent* EMCurrent::clone() const {
  return new EMCurrent(*this);
}
