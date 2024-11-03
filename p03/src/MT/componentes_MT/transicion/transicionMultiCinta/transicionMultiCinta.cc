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
 * @file transicionMultiCinta.cc
 * @brief Implementación de la clase TransicionMultiCinta.
 *
 * Este archivo contiene la implementación de los métodos de la clase
 * TransicionMultiCinta, que representa transiciones en una máquina de Turing
 * de múltiples cintas.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./transicionMultiCinta.h"

/**
 * @brief Muestra la transición en un formato legible.
 * 
 * Este método imprime los detalles de la transición, incluyendo el estado inicial,
 * los símbolos leídos, el estado final, los símbolos escritos y los movimientos
 * a realizar en cada cinta.
 */
void TransicionMultiCinta::mostrar() const {
  std::cout << "δ (" << estadoIni_ << ", ";
  for (size_t i = 0; i < simbolosLeidos_.size(); ++i) {
    std::cout << simbolosLeidos_[i];
    if (i < simbolosLeidos_.size() - 1) std::cout << ", ";
  }
  std::cout << ") = (" << estadoFin_ << ", ";
  for (size_t i = 0; i < simbolosEscritos_.size(); ++i) {
    std::cout << simbolosEscritos_[i];
    if (i < simbolosEscritos_.size() - 1) std::cout << ", ";
  }
  std::cout << ", ";
  for (size_t i = 0; i < movimientos_.size(); ++i) {
    std::cout << movimientos_[i];
    if (i < movimientos_.size() - 1) std::cout << ", ";
  }
  std::cout << ")" << std::endl;
}