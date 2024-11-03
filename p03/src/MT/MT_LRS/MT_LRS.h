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
 * @file MT_LRS.h
 * @brief Definición de la clase MaquinaTuringLRS.
 *
 * Esta clase extiende la funcionalidad de la clase MaquinaTuring
 * para manejar máquinas de Turing con una cinta y que procesan
 * cadenas en una dirección específica (LRS), escribe y se mueve simultáneamente
 * y la cinta es infinita en ambas direcciones
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <vector>

#include "../MT.h"
#include "../componentes_MT/transicion/direccion.h"
#include "../componentes_MT/transicion/transicionCintaUnicaLRS/transicionCintaUnicaLRS.h"

/**
 * @brief Clase que representa una máquina de Turing con una cinta infinita en ambas direcciones (LRS)
 * y con escritura y movimiento simultáneamente.
 */
class MaquinaTuringLRS : public MaquinaTuring {
 public: 
  MaquinaTuringLRS(): MaquinaTuring() {}
  virtual bool procesar(const std::string&) override;
  virtual void rellenarCintas(const std::string&) override {}
  virtual void mostrarMT() const override;
  virtual void mostrarCintas() const override;
 private:
  Cinta cinta_;
};