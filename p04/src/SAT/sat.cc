
#include "sat.h"

/**
 * @brief Constructor de la clase SAT
 * @param json Objeto JSON con la información del problema SAT
 */
SAT::SAT(const nlohmann::json& json) {
  if (!json.contains("number_variables") || !json["number_variables"].is_number_integer() || json["number_variables"] <= 0) {
    throw std::invalid_argument("Error: Formato incorrecto de número de variables.");
  }
  num_variables_ = json["number_variables"];

  if (!json.contains("clauses") || !json["clauses"].is_array() || json["clauses"].empty()) {
    throw std::invalid_argument("Error: Formato incorrecto de cláusulas.");
  }

  for (const auto& clause_json : json["clauses"]) {
    clauses_.emplace_back(clause_json);
  }
}


/**
 * @brief Sobrecarga del operador de salida
 * @param output Flujo de salida
 * @param sat Objeto SAT
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& output, const SAT& sat) {
  output << "Número de variables: " << sat.num_variables_ << std::endl;
  output << "Número de cláusulas: " << sat.clauses_.size() << std::endl;
  for (size_t i = 0; i < sat.clauses_.size(); i++) {
    output << sat.clauses_[i];
    if (i < sat.clauses_.size() - 1) output << " ^ ";
  }
  return output;
}


/**
 * @brief Resuelve el problema SAT
 * @param solution Vector con la solución
 * @param var_index Índice de la variable
 * @return true si es satisfacible, false en caso contrario
 */
bool SAT::Solve(std::vector<bool>& solution, int var_index) const {
  if (var_index == num_variables_) return IsSatisfiable(solution);

  solution[var_index] = false;
  if (Solve(solution, var_index + 1)) return true;

  solution[var_index] = true;
  if (Solve(solution, var_index + 1)) return true;

  return false;
}


/**
 * @brief Comprueba si una asignación es satisfacible
 * @param solution Asignación
 * @return true si es satisfacible, false en caso contrario
 */
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