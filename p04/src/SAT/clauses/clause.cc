
#include "clause.h"

Clause::Clause(const nlohmann::json& json) {
  for (const auto& var_json : json) {
    variables_.emplace_back(var_json);
  }
}


std::ostream& operator<<(std::ostream& output, const Clause& clause) {
  output << "(";
  for (size_t i = 0; i < clause.variables_.size(); i++) {
    output << clause.variables_[i];
    if (i < clause.variables_.size() - 1) output << " v ";
  }
  output << ")";
  return output;
}