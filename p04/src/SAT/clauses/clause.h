#pragma once

#include <vector>

#include "../variables/variable.h"

/**
 * @brief Clase que representa una cláusula
 */
class Clause {
 public:
  Clause() : variables_() {}
  Clause(const nlohmann::json& json);

  friend std::ostream& operator<<(std::ostream& output, const Clause& clause);
 private:
  std::vector<Variable> variables_;
  // bool isValidClause() const;
};