/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Curso: 4º
 * Práctica 3: Programar un simulador de una Máquina de Turing determinista
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Octubre de 2024
 * @file alfabeto.h
 * @brief Clase que representa un alfabeto para una máquina de Turing.
 *
 * Esta clase permite gestionar un conjunto de símbolos que forman 
 * el alfabeto de una máquina de Turing, proporcionando métodos 
 * para insertar nuevos símbolos y obtener el conjunto actual.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

/**
 * @brief Clase que representa un alfabeto para una máquina de Turing.
 */
class Alfabeto {
 public:
  const std::set<char>& getConjuntoAlfabeto() const { return conjuntoAlfabeto_; }
  void insertar(const char);
  bool contieneA(const Alfabeto&) const;
  friend std::ostream& operator<<(std::ostream&, const Alfabeto&);
 private:
  std::set<char> conjuntoAlfabeto_;
};