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
 * @file MT.cc
 * @brief Implementación de la clase MaquinaTuring.
 *
 * Este archivo contiene la implementación de los métodos
 * definidos en la clase MaquinaTuring.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./MT.h"

/**
 * @brief Agregar una transición a la máquina de Turing.
 * @param kEstadoIni Estado inicial de la transición.
 * @param transicion Puntero a la transición a agregar.
 */
void MaquinaTuring::agregarTransicion(const Estado& kEstadoIni, Transicion*& transicion) {
  transiciones_[kEstadoIni].push_back(transicion);
}

/**
 * @brief Mostrar la configuración de la máquina de Turing.
 */
void MaquinaTuring::mostrarMT() const {
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Estados: {";
  bool primero = true;
  for (const Estado& kEstado : estados_) {
    if (!primero) std::cout << ", ";
    std::cout << kEstado;
    primero = false;
  }
  std::cout << "}" << std::endl;
  std::cout << "Alfabeto de Entrada: " << alfabetoEntrada_;
  std::cout << "Alfabeto de Cinta: " << alfabetoCinta_;
  std::cout << "Estado Inicial: " << estadoInicial_ << std::endl;
  std::cout << "Símbolo Blanco: " << simboloBlanco_ << std::endl;
  std::cout << "Número de Cintas: " << numCintas_ << std::endl;
  std::cout << "Estados Finales: {";
  primero = true;
  for (const Estado& kEstado : estadosFinales_) {
    if (!primero) std::cout << ", ";
    std::cout << kEstado;
    primero = false;
  }
  std::cout << "}" << std::endl;
  std::cout << "Transiciones:" << std::endl;
  for (const auto& kPar : transiciones_) {
    for (const auto& kTransicion : kPar.second) {
      kTransicion->mostrar();
    }
  }
}