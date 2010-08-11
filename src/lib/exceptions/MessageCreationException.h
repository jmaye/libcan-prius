#ifndef MESSAGECREATIONEXCEPTION_H
#define MESSAGECREATIONEXCEPTION_H

#include <stdexcept>
#include <string>

class MessageCreationException : public std::range_error {
  MessageCreationException& operator = (const MessageCreationException &other);

public:
  MessageCreationException(const std::string &msg = "");
  MessageCreationException(const MessageCreationException &other);

protected:

};

#endif // MESSAGECREATIONEXCEPTION_H
