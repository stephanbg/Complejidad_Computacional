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
 * @file cinta.h
 * @brief Definición de la clase Cinta.
 *
 * Esta clase representa la cinta de una máquina de Turing, permitiendo
 * la lectura, escritura y movimiento del cabezal sobre la cinta.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <iostream>
#include <vector>

#include "../transicion/direccion.h"

/**
 * @brief Clase que representa la cinta de una máquina de Turing.
 * 
 * La cinta permite almacenar símbolos y controlar el movimiento del
 * cabezal que lee y escribe en ella.
 */
class Cinta {
 public:
  Cinta(): posicionCabezal_(1), simboloBlanco_('.') {}
  void iniciar(const std::string&);
  void rellenarDeBlancos();
  void escribir(const char);
  const char leer() const;
  void moverCabezal(const Direccion&);
  void imprimir() const;
  const std::vector<char> getCinta() const { return cinta_; }
  const int getPosicionCabezal() const { return posicionCabezal_; }
 private:
  std::vector<char> cinta_;
  int posicionCabezal_;
  char simboloBlanco_;
};