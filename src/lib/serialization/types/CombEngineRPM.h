#ifndef COMBENGINERPM_H
#define COMBENGINERPM_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class CombEngineRPM : public Message {
  CombEngineRPM();
  CombEngineRPM(const CombEngineRPM &other);
  CombEngineRPM& operator = (const CombEngineRPM &other);

  virtual void write(std::ofstream &stream) const;

  uint8_t mu8RPM;

public:
  ~CombEngineRPM();

  virtual CombEngineRPM* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const CombEngineRPM mProto;

protected:
};

#endif // COMBENGINERPM_H
