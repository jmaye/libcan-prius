#ifndef SPEED_H
#define SPEED_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class Speed : public Message {
  Speed();
  Speed(const Speed &other);
  Speed& operator = (const Speed &other);

  virtual void write(std::ofstream &stream) const;

  uint8_t mu8Speed;

public:
  ~Speed();

  virtual Speed* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const Speed mProto;

protected:
};

#endif // SPEED_H
