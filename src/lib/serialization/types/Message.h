#ifndef MESSAGE_H
#define MESSAGE_H

#include "MessageCreationException.h"
#include "TypeCastException.h"

#include <iosfwd>

#include <stdint.h>

class Message {
  friend std::ofstream& operator << (std::ofstream &stream,
    const Message &obj);

  virtual void write(std::ofstream &stream) const = 0;

public:
  virtual ~Message();

  virtual Message* clone() const = 0;

  virtual int32_t getTypeID() const;

  virtual void formatMessage(uint8_t *au8Buffer) = 0;

  template<class O> const O& typeCast() const throw(TypeCastException) {
    if (this->mi32TypeID == O::mProto.mi32TypeID)
      return (const O&)*this;
    else
      throw TypeCastException("Message: Cast failed");
  }

  template<class O> O& typeCast() throw(TypeCastException) {
    if (this->mi32TypeID == O::mProto.mi32TypeID)
      return (O&)*this;
    else
      throw TypeCastException("Message: Cast failed");
  }

  template<class O> bool instanceof() const {
    if (this->mi32TypeID == O::mProto.mi32TypeID)
      return true;
    else
      return false;
  }

  template<class O> bool instanceof() {
    if (this->mi32TypeID == O::mProto.mi32TypeID)
      return true;
    else
      return false;
  }

protected:
  Message() throw(MessageCreationException);
  Message(int32_t i32TypeID);
  Message(const Message &other);
  Message& operator = (const Message &other);

  const int32_t mi32TypeID;

};

#endif // MESSAGE_H
