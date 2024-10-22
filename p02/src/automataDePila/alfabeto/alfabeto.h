/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file alfabeto.h
 * @brief Definición de la clase Alfabeto para el simulador de un autómata con pila.
 * 
 * Esta clase representa el alfabeto utilizado por el autómata, permitiendo
 * la gestión de un conjunto de símbolos que el autómata puede procesar. (Alfabeto y alfabeto de Pila)
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#pragma once

#include <set>

/**
 * @brief Clase que representa el alfabeto de un autómata.
 * 
 * Esta clase gestiona un conjunto de caracteres que conforman el alfabeto
 * utilizado por el autómata. Permite insertar nuevos caracteres y obtener
 * el conjunto actual de símbolos.
 */
class Alfabeto {
 public:
  /**
   * @brief Constructor por defecto que inicializa el alfabeto con el símbolo '.'.
   */
  Alfabeto() : conjuntoAlfabeto_{'.'} {}
  const std::set<char> getConjuntoAlfabeto() const { return conjuntoAlfabeto_; }
  /**
   * @brief Inserta un nuevo símbolo en el alfabeto.
   * 
   * @param kElemento Símbolo a insertar en el alfabeto.
   */
  void insertar(const char kElemento) { conjuntoAlfabeto_.insert(kElemento); }
  /**
   * @brief Sobrecarga del operador de inserción para imprimir el alfabeto.
   * 
   * Este método permite la impresión del conjunto de símbolos en un flujo de salida.
   * 
   * @param os Flujo de salida donde se imprimirá el alfabeto.
   * @param kAlfabeto El alfabeto que se desea imprimir.
   * @return std::ostream& Flujo de salida modificado.
   */
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& kAlfabeto) {
    os << "{";
    bool primero = true;
    for (const auto& kSimbolo : kAlfabeto.conjuntoAlfabeto_) {
      if (!primero) os << ", ";
      os << kSimbolo;
      primero = false;
    }
    os << "}" << std::endl;
    return os;
  }
 private:
  std::set<char> conjuntoAlfabeto_;
};