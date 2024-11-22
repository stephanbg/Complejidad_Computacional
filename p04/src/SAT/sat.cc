
#include "sat.h"

SAT::SAT(const nlohmann::json& json) : num_variables_(json["number_variables"]) {
  for (const auto& clause_json : json["clauses"]) {
    clauses_.emplace_back(clause_json);
  }
}


std::ostream& operator<<(std::ostream& output, const SAT& sat) {
  output << "Número de variables: " << sat.num_variables_ << std::endl;
  for (size_t i = 0; i < sat.clauses_.size(); i++) {
    output << sat.clauses_[i];
    if (i < sat.clauses_.size() - 1) output << " ^ ";
  }
  return output;
}