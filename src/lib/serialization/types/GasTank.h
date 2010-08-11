#ifndef GasTank_H
#define GasTank_H

#include "Message.h"

#include <iosfwd>

#include <stdint.h>

class GasTank : public Message {
  GasTank();
  GasTank(const GasTank &other);
  GasTank& operator = (const GasTank &other);

  virtual void write(std::ofstream &stream) const;

  uint8_t mu8GasTank;

public:
  ~GasTank();

  virtual GasTank* clone() const;

  virtual void formatMessage(uint8_t *au8Buffer);

  static const GasTank mProto;

protected:
};

#endif // GasTank_H
