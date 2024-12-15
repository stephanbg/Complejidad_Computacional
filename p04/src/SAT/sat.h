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
 * @file sat.h
 * @brief Definición de la clase SAT, que representa un problema de satisfacibilidad
 *        booleana (SAT) y proporciona métodos para su resolución. Permite manejar
 *        el número de variables y las cláusulas que conforman el problema, y ofrece 
 *        una función para resolver el problema mediante backtracking.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/edit/main/p04}
 */

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
  int GetNumVariables() const { return num_variables_; }
  friend std::ostream& operator<<(std::ostream& output, const SAT& sat);
  bool Solve(std::vector<bool>& solution, int var_index = 0) const;
 private:
  int num_variables_;
  std::vector<Clause> clauses_;
  bool IsSatisfiable(const std::vector<bool>& assignment) const;
};
