#pragma once

#include "clauses/clause.h"

/**
 * @brief Clase que representa un problema SAT
 */
class SAT {
 public:
  SAT() : num_variables_(), clauses_() {}
  SAT(const int num_variables) : num_variables_(num_variables), clauses_() {}
  SAT(const nlohmann::json& json);

  friend std::ostream& operator<<(std::ostream& output, const SAT& sat);
 private:
  int num_variables_;
  std::vector<Clause> clauses_;
};