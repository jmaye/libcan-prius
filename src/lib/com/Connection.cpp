#include "Connection.h"

#include "TypesFactory.h"

#include <string.h>

using namespace std;

Connection::Connection(uint32_t u32Bitrate, uint32_t u32QuantaPerBit,
  float f32SamplingPoint) : mpCANDevice(0),
                            mu32Bitrate(u32Bitrate),
                            mu32QuantaPerBit(u32QuantaPerBit),
                            mf32SamplingPoint(f32SamplingPoint) {
}

Connection::~Connection() {
  close();
}

void Connection::open() throw(IOException) {
  config_t config;
  config_init(&config);
  config_set_int(&config, CAN_CPC_PARAMETER_BITRATE, mu32Bitrate);
  config_set_int(&config, CAN_CPC_PARAMETER_QUANTA_PER_BIT, mu32QuantaPerBit);
  config_set_float(&config, CAN_CPC_PARAMETER_SAMPLING_POINT,
    mf32SamplingPoint);
  mpCANDevice = (can_device_p)malloc(sizeof(can_device_t));
  can_init(mpCANDevice, &config);

  if (can_open(mpCANDevice))
    throw IOException("Connection::open: CAN port opening failed");
}

bool Connection::isOpen() const {
  return (mpCANDevice != 0);
}

void Connection::close() throw(IOException) {
  if (can_close(mpCANDevice))
    throw IOException("Connection::close: CAN port closing failed");
  free(mpCANDevice);
  mpCANDevice = 0;
}

const Message* Connection::readMessage()
  throw(IOException, MessageCreationException) {
  if(mpCANDevice == 0)
    open();
  can_message_t message;
  memset(message.content, 0, sizeof(char) * 8);
  int ret = can_receive_message(mpCANDevice, &message);
  if (ret != 0)
   throw IOException("Connection::readMessage: CAN read failed");
  Message *messageRead = TypesFactory::createMessage(message.id);
  messageRead->formatMessage(message.content);
  return messageRead;
}
