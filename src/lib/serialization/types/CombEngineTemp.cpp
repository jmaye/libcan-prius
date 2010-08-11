#include "CombEngineTemp.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const CombEngineTemp CombEngineTemp::mProto;

CombEngineTemp::CombEngineTemp() : Message(0x39) {
}

CombEngineTemp::CombEngineTemp(const CombEngineTemp &other)
  : Message(other) {
}

CombEngineTemp::~CombEngineTemp() {
}

void CombEngineTemp::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu8Temp;
  stream << endl;
}

void CombEngineTemp::formatMessage(uint8_t *au8Buffer) {
  mu8Temp = au8Buffer[0];
}

CombEngineTemp* CombEngineTemp::clone() const {
  return new CombEngineTemp(*this);
}
