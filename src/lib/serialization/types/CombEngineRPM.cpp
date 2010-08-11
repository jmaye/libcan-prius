#include "CombEngineRPM.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

const CombEngineRPM CombEngineRPM::mProto;

CombEngineRPM::CombEngineRPM() : Message(0x3c8) {
}

CombEngineRPM::CombEngineRPM(const CombEngineRPM &other)
  : Message(other) {
}

CombEngineRPM::~CombEngineRPM() {
}

void CombEngineRPM::write(ofstream &stream) const {
  stream << mi32TypeID;
  stream << " ";
  stream << mu8RPM;
  stream << endl;
}

void CombEngineRPM::formatMessage(uint8_t *au8Buffer) {
  mu8RPM = au8Buffer[2];
}

CombEngineRPM* CombEngineRPM::clone() const {
  return new CombEngineRPM(*this);
}
