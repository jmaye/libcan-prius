#include "TypesFactory.h"

#include "Message.h"

using namespace std;

map<int32_t, const Message*> TypesFactory::mTypesMap;

TypesFactory::TypesFactory() {
}

TypesFactory& TypesFactory::getInstance() {
  static TypesFactory instance;
  return instance;
}

void TypesFactory::registerType(const Message *MessagePtr, int32_t i32TypeID) {
  if (mTypesMap.find(i32TypeID) == mTypesMap.end())
    mTypesMap[i32TypeID] = MessagePtr;
}

Message* TypesFactory::createMessage(int32_t i32TypeID)
  throw(MessageCreationException)
{
  if (mTypesMap.find(i32TypeID) != mTypesMap.end())
    return mTypesMap[i32TypeID]->clone();
  else
    throw MessageCreationException("TypesFactory: Unknown Message ID");
}
