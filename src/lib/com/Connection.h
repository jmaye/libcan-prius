#ifndef CONNECTION_H
#define CONNECTION_H

#include "IOException.h"
#include "MessageCreationException.h"
#include "Message.h"

extern "C" {
  #include <libcan/can_cpc.h>
  #include <tulibs/config.h>
}

class Connection {
  Connection(const Connection &other);
  Connection& operator = (const Connection &other);

  can_device_p mpCANDevice;
  uint32_t mu32Bitrate;
  uint32_t mu32QuantaPerBit;
  float mf32SamplingPoint;

public:
  Connection(uint32_t u32Bitrate = 500, uint32_t u32QuantaPerBit = 16,
    float f32SamplingPoint = 0.875);
  ~Connection();

  void open() throw(IOException);

  bool isOpen() const;

  void close() throw(IOException);

  const Message* readMessage() throw(IOException, MessageCreationException);

protected:

};

#endif // CONNECTION_H
