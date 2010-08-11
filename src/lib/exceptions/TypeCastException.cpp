#include "TypeCastException.h"

using namespace std;

TypeCastException::TypeCastException(const string &msg) : runtime_error(msg) {
}
