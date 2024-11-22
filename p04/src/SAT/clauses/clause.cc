
#include "clause.h"


/**
 * @brief Constructor de la clase Clause
 * @param json Objeto JSON con la información de la cláusula
 */
Clause::Clause(const nlohmann::json& json) {
  for (const auto& var_json : json) {
    variables_.emplace_back(var_json);
  }
}


/**
 * @brief Sobrecarga del operador de salida
 * @param output Flujo de salida
 * @param clause Objeto Clause
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& output, const Clause& clause) {
  output << "(";
  for (size_t i = 0; i < clause.variables_.size(); i++) {
    output << clause.variables_[i];
    if (i < clause.variables_.size() - 1) output << " v ";
  }
  output << ")";
  return output;
}