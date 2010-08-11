#ifndef THROTTLE_H
#define THROTTLE_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class Throttle : public Message {
  Throttle();
  Throttle(const Throttle &other);
  Throttle& operator = (const Throttle &other);

  virtual void write(std::ofstream &stream) const;

  uint8_t mu8Position;

public:
  ~Throttle();

  virtual Throttle* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const Throttle mProto;

protected:
};

#endif // THROTTLE_H
