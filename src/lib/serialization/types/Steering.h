#ifndef STEERING_H
#define STEERING_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class Steering : public Message {
  Steering();
  Steering(const Steering &other);
  Steering& operator = (const Steering &other);

  virtual void write(std::ofstream &stream) const;

  int16_t mi16SteeringAngle;

public:
  ~Steering();

  virtual Steering* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const Steering mProto;

protected:
};

#endif // STEERING_H
