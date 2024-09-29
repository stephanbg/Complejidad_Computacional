/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file funcionPrimitivaRecursiva.h
 * @brief Definición de la clase base FuncionPrimitivaRecursiva que
 *        servirá para poder crear cualquier función primitiva recursiva
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#pragma once

#include <vector>

#include "../contarLlamadasAFunciones/contarLlamadasAFunciones.h"

/**
 * @brief Clase base FuncionPrimitivaRecursiva para poder crear cualquier función
 *        primitiva recursiva
 */
class FuncionPrimitivaRecursiva {
 public:
  const int getResultado() const { return resultado_; }
 protected:
  int resultado_;
};