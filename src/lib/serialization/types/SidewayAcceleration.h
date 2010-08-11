#ifndef SIDEWAYACCELERATION_H
#define SIDEWAYACCELERATION_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class SidewayAcceleration : public Message {
  SidewayAcceleration();
  SidewayAcceleration(const SidewayAcceleration &other);
  SidewayAcceleration& operator = (const SidewayAcceleration &other);

  virtual void write(std::ofstream &stream) const;

  uint16_t mu16Sensor1;
  uint16_t mu16Sensor2;

public:
  ~SidewayAcceleration();

  virtual SidewayAcceleration* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const SidewayAcceleration mProto;

protected:
};

#endif // SIDEWAYACCELERATION_H
