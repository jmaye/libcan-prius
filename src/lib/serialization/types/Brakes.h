#ifndef BRAKES_H
#define BRAKES_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class Brakes : public Message {
  Brakes();
  Brakes(const Brakes &other);
  Brakes& operator = (const Brakes &other);

  virtual void write(std::ofstream &stream) const;

  uint8_t mu8Pressed;
  uint8_t mu8Force;

public:
  ~Brakes();

  virtual Brakes* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const Brakes mProto;

protected:
};

#endif // BRAKES_H
