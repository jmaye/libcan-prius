#ifndef REARWHEELSSPEED_H
#define REARWHEELSSPEED_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class RearWheelsSpeed : public Message {
  RearWheelsSpeed();
  RearWheelsSpeed(const RearWheelsSpeed &other);
  RearWheelsSpeed& operator = (const RearWheelsSpeed &other);

  virtual void write(std::ofstream &stream) const;

  uint16_t mu16RightSpeed;
  uint16_t mu16LeftSpeed;

public:
  ~RearWheelsSpeed();

  virtual RearWheelsSpeed* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const RearWheelsSpeed mProto;

protected:
};

#endif // REARWHEELSSPEED_H
