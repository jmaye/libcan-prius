#ifndef FRONTWHEELSSPEED_H
#define FRONTWHEELSSPEED_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class FrontWheelsSpeed : public Message {
  FrontWheelsSpeed();
  FrontWheelsSpeed(const FrontWheelsSpeed &other);
  FrontWheelsSpeed& operator = (const FrontWheelsSpeed &other);

  virtual void write(std::ofstream &stream) const;

  uint16_t mu16RightSpeed;
  uint16_t mu16LeftSpeed;

public:
  ~FrontWheelsSpeed();

  virtual FrontWheelsSpeed* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const FrontWheelsSpeed mProto;

protected:
};

#endif // FRONTWHEELSSPEED_H
