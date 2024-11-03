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
 * @file transicionMultiCinta.h
 * @brief Definición de la clase TransicionMultiCinta.
 *
 * Esta clase representa una transición en una máquina de Turing de múltiples cintas,
 * donde se pueden leer y escribir múltiples símbolos simultáneamente en diferentes cintas.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include "../transicion.h"
#include "../direccion.h"

/**
 * @brief Clase que representa una transición en una máquina de Turing de múltiples cintas.
 */
class TransicionMultiCinta : public Transicion {
 public:
  TransicionMultiCinta(
    const Estado& kEstadoIni, 
    const std::vector<char>& kSimbolosLeidos,
    const Estado& kEstadoFin, 
    const std::vector<char>& kSimbolosEscritos,
    const std::vector<Direccion>& kMovimientos)
  : Transicion(kEstadoIni, kEstadoFin),
    simbolosLeidos_(kSimbolosLeidos), 
    simbolosEscritos_(kSimbolosEscritos), 
    movimientos_(kMovimientos) {}
  const std::vector<char>& getSimbolosALeer() const { return simbolosLeidos_; }
  const std::vector<char>& getSimbolosAEscribir() const { return simbolosEscritos_; }
  const std::vector<Direccion>& getMovimientosARealizar() const { return movimientos_; }
  virtual void mostrar() const override;
 private:
  std::vector<char> simbolosLeidos_;
  std::vector<char> simbolosEscritos_;
  std::vector<Direccion> movimientos_;
};