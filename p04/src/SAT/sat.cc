
#include "sat.h"

SAT::SAT(const nlohmann::json& json) : num_variables_(json["number_variables"]) {
  for (const auto& clause_json : json["clauses"]) {
    clauses_.emplace_back(clause_json);
  }
}


std::ostream& operator<<(std::ostream& output, const SAT& sat) {
  output << "Número de variables: " << sat.num_variables_ << std::endl;
  output << "Número de cláusulas: " << sat.clauses_.size() << std::endl;
  for (size_t i = 0; i < sat.clauses_.size(); i++) {
    output << sat.clauses_[i];
    if (i < sat.clauses_.size() - 1) output << " ^ ";
  }
  return output;
}


bool SAT::Solve(std::vector<bool>& solution, int var_index) const {
  if (var_index == num_variables_) return IsSatisfiable(solution);

  solution[var_index] = false;
  if (Solve(solution, var_index + 1)) return true;

  solution[var_index] = true;
  if (Solve(solution, var_index + 1)) return true;

  return false;
}


bool SAT::IsSatisfiable(const std::vector<bool>& solution) const {
  for (const auto& clause : clauses_) {
    bool clause_satisfied = false;
    for (const auto& variable : clause.GetVariables()) {
      bool value = solution[variable.GetId() - 1];
      if (variable.IsNegated()) value = !value;

      clause_satisfied = clause_satisfied || value;
      if (clause_satisfied) break;
    }
    if (!clause_satisfied) return false;
  }
  return true;
}