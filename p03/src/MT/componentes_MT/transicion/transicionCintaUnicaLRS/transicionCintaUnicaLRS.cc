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
 * @file transicionCintaUnicaLRS.cc
 * @brief Implementación de la clase TransicionCintaUnicaLRS.
 *
 * Este archivo contiene la implementación de los métodos de la clase 
 * TransicionCintaUnicaLRS, que representa una transición en una máquina
 * de Turing con una cinta única.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./transicionCintaUnicaLRS.h"

/**
 * @brief Método para mostrar la transición en un formato legible.
 * 
 * Este método imprime en consola la transición en la forma:
 * δ (estadoIni, simboloLeido) = (estadoFin, simboloEscrito, movimiento).
 */
void TransicionCintaUnicaLRS::mostrar() const {
  std::cout << "δ (" << estadoIni_ << ", " << simboloLeido_ << ") = ("
  << estadoFin_ << ", " << simboloEscrito_ << ", " << movimiento_ << ")" << std::endl;
}