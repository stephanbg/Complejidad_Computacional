
#include "variable.h"

std::ostream& operator<<(std::ostream& output, const Variable& variable) {
  output << (variable.is_negated_ ? "-" : "") << variable.id_;
  return output;
}