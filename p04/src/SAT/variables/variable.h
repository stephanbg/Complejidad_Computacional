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
 * @file variable.h
 * @brief Definición de la clase Variable, que representa una variable booleana en 
 *        un problema de satisfacibilidad (SAT). Cada variable tiene un identificador 
 *        único y una propiedad que indica si está negada o no.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/edit/main/p04}
 */

#pragma once

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

/**
 * @brief Clase que representa una variable
 */
class Variable {
 public:
  Variable() : id_(), is_negated_() {}
  Variable(const nlohmann::json& json);
  int GetId() const { return id_; }
  bool IsNegated() const { return is_negated_; }
  friend std::ostream& operator<<(std::ostream& output, const Variable& variable);
 private:
  int id_;
  bool is_negated_;
};
