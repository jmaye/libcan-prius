#ifndef EMCURRENT_H
#define EMCURRENT_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class EMCurrent : public Message {
  EMCurrent();
  EMCurrent(const EMCurrent &other);
  EMCurrent& operator = (const EMCurrent &other);

  virtual void write(std::ofstream &stream) const;

  uint16_t mu16Current;
  uint16_t mu16Voltage;

public:
  ~EMCurrent();

  virtual EMCurrent* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const EMCurrent mProto;

protected:
};

#endif // EMCURRENT_H
