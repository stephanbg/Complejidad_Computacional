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
 * @file clause.h
 * @brief Definición de la clase Clause, que representa una cláusula en un 
 *        problema de satisfacibilidad (SAT). Una cláusula es una disyunción de 
 *        variables booleanas, cada una de las cuales puede estar negada o no.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/edit/main/p04}
 */

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
  std::vector<Variable> GetVariables() const { return variables_; }
  friend std::ostream& operator<<(std::ostream& output, const Clause& clause);
 private:
  std::vector<Variable> variables_;
};
