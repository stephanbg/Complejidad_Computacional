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
 * @file MT_MultiCinta.h
 * @brief Definición de la clase MaquinaTuringMultiCinta.
 *
 * Esta clase extiende la funcionalidad de la clase MaquinaTuring
 * para manejar máquinas de Turing con múltiples cintas.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <vector>

#include "../MT.h"
#include "../componentes_MT/transicion/direccion.h"
#include "../componentes_MT/transicion/transicionMultiCinta/transicionMultiCinta.h"

/**
 * @brief Clase que representa una máquina de Turing de múltiples cintas.
 */
class MaquinaTuringMultiCinta : public MaquinaTuring {
 public:
  MaquinaTuringMultiCinta(const int);
  virtual bool procesar(const std::string&) override;
  virtual void rellenarCintas(const std::string&) override;
  virtual void mostrarMT() const override;
  virtual void mostrarCintas() const override;
 private:
  std::vector<Cinta> cintas_;
};