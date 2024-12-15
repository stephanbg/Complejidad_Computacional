/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Curso: 4º
 * Práctica 4: Resolver algoritmo SAT
 *
 * @author Aday Cuesta Correa
 * @author Stephan Brommer Gutiérrez
 * @author Sofía De Fuentes Rosella
 * @since 1 de Diciembre de 2024
 * @file variable.cc
 * @brief Implementación de la clase Variable, que representa una variable booleana en 
 *        un problema de satisfacibilidad (SAT). Cada variable tiene un identificador 
 *        único y una propiedad que indica si está negada o no.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/edit/main/p04}
 */

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
