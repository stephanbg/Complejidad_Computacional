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
 * @file transicionCintaUnicaLRS.h
 * @brief Definición de la clase TransicionCintaUnicaLRS.
 *
 * Esta clase representa una transición en una máquina de Turing de una
 * cinta única que se mueve en direcciones específicas (izquierda, derecha
 * o quieto). Incluye información sobre el estado inicial y final, así
 * como los símbolos leídos y escritos durante la transición.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include "../transicion.h"
#include "../direccion.h"

/**
 * @brief Clase que representa una transición en una máquina de Turing
 * con una cinta única y direcciones LRS (izquierda, derecha, quieto).
 */
class TransicionCintaUnicaLRS : public Transicion {
 public:
  TransicionCintaUnicaLRS(
    const Estado& kEstadoIni, const char kSimboloLeido,
    const Estado& kEstadoFin, const char kSimboloEscrito, const Direccion& kMovimiento)
      : Transicion(kEstadoIni, kEstadoFin),
        simboloLeido_(kSimboloLeido), simboloEscrito_(kSimboloEscrito), movimiento_(kMovimiento) {}
  const char getSimboloALeer() const { return simboloLeido_; }
  const char getSimboloAEscribir() const { return simboloEscrito_; }
  const Direccion getMovimientoARealizar() const { return movimiento_; }
  virtual void mostrar() const override;
 private:
  char simboloLeido_;
  char simboloEscrito_;
  Direccion movimiento_;
};