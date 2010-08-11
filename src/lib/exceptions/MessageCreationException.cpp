#include "MessageCreationException.h"

using namespace std;

MessageCreationException::MessageCreationException(const string &msg)
  : range_error(msg) {
}
