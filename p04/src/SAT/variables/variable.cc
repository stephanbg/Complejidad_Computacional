
#include "variable.h"

/**
 * @brief Constructor de la clase Variable
 * @param json Objeto JSON con la información de la variable
 */
Variable::Variable(const nlohmann::json& json) {
  if (!json.contains("variable") || !json["variable"].is_number_integer()) {
    throw std::invalid_argument("Error: Formato incorrecto de variable.");
  }
  if (!json.contains("format") || !json["format"].is_number_integer()) {
    throw std::invalid_argument("Error: Formato incorrecto del formato de variable.");
  }
  id_ = json["variable"];
  is_negated_ = json["format"].get<int>() == 1;
}


/**
 * @brief Sobrecarga del operador de salida
 * @param output Flujo de salida
 * @param variable Objeto Variable
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& output, const Variable& variable) {
  output << (variable.is_negated_ ? "-" : "") << variable.id_;
  return output;
}