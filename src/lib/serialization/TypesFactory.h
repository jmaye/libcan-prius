#ifndef TYPESFACTORY_H
#define TYPESFACTORY_H

#include "MessageCreationException.h"

#include <map>

#include <stdint.h>

class Message;

class TypesFactory {
  static std::map<int32_t, const Message*> mTypesMap;

  TypesFactory();

public:
  static void registerType(const Message *MessagePtr, int32_t i32TypeID);

  static Message* createMessage(int32_t i32TypeID)
    throw(MessageCreationException);

  static TypesFactory& getInstance();

protected:

};

#endif // TYPESFACTORY_H
