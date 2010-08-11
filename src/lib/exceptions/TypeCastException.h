#ifndef TYPECASTEXCEPTION_H
#define TYPECASTEXCEPTION_H

#include <stdexcept>
#include <string>

class TypeCastException : public std::runtime_error {
  TypeCastException& operator = (const TypeCastException &other);

public:
  TypeCastException(const std::string &msg = "");
  TypeCastException(const TypeCastException &other);

protected:

};

#endif // TYPECASTEXCEPTION_H
