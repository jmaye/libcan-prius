#include "Message.h"

#include "TypesFactory.h"

#include <fstream>

using namespace std;

Message::Message() throw(MessageCreationException) : mi32TypeID(0xffff) {
  throw MessageCreationException("Message: Wrong creation");
}

Message::Message(int32_t i32TypeID) : mi32TypeID(i32TypeID) {
  TypesFactory::getInstance().registerType(this, i32TypeID);
}

Message::Message(const Message &other) : mi32TypeID(other.mi32TypeID) {
}

Message::~Message() {
}

int32_t Message::getTypeID() const {
  return mi32TypeID;
}

ofstream& operator << (ofstream &stream,
  const Message &obj) {
  obj.write(stream);
  return stream;
}
