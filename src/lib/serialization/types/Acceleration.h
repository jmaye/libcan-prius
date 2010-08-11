#ifndef ACCELERATION_H
#define ACCELERATION_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class Acceleration : public Message {
  Acceleration();
  Acceleration(const Acceleration &other);
  Acceleration& operator = (const Acceleration &other);

  virtual void write(std::ofstream &stream) const;

  uint16_t mu16Sensor1;
  uint16_t mu16Sensor2;

public:
  ~Acceleration();

  virtual Acceleration* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const Acceleration mProto;

protected:
};

#endif // ACCELERATION_H
