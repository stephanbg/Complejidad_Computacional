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
 * @file transicion.h
 * @brief Definición de la clase Transicion.
 *
 * Esta clase representa una transición en una máquina de Turing, 
 * definiendo el estado inicial y el estado final de la transición.
 * Proporciona métodos para acceder a estos estados y una interfaz 
 * virtual para mostrar la transición.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include "../estado/estado.h"

/**
 * @brief Clase base que representa una transición en una máquina de Turing.
 */
class Transicion {
 public:
  Transicion(const Estado& estadoIni, const Estado& estadoFin)
      : estadoIni_(estadoIni), estadoFin_(estadoFin) {}
  const Estado getEstadoIni() const { return estadoIni_; }
  const Estado getEstadoFin() const { return estadoFin_; }
  virtual void mostrar() const = 0;
  virtual ~Transicion() {}
 protected:
  Estado estadoIni_;
  Estado estadoFin_;
};