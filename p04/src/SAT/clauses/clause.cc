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
 * @file clause.cc
 * @brief Implementación de la clase Clause, que representa una cláusula en un 
 *        problema de satisfacibilidad (SAT). Una cláusula es una disyunción de 
 *        variables booleanas, cada una de las cuales puede estar negada o no.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/edit/main/p04}
 */

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
