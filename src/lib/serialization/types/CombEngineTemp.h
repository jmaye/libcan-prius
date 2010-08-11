#ifndef COMBENGINETEMP_H
#define COMBENGINETEMP_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class CombEngineTemp : public Message {
  CombEngineTemp();
  CombEngineTemp(const CombEngineTemp &other);
  CombEngineTemp& operator = (const CombEngineTemp &other);

  virtual void write(std::ofstream &stream) const;

  uint8_t mu8Temp;

public:
  ~CombEngineTemp();

  virtual CombEngineTemp* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const CombEngineTemp mProto;

protected:
};

#endif // COMBENGINETEMP_H
