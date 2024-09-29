/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file zero.h
 * @brief Definición de la clase FuncionZero que hereda de FuncionRecursivaBasica,
 *        para poder crear la función zero
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#pragma once

#include "../funcionRecursivaBasica.h"

/**
 * @brief Clase FuncionZero que hereda de FuncionRecursivaBasica para modificar el resultado.
 */
class FuncionZero : public FuncionRecursivaBasica {
 public:
  /**
   * @brief Recibe cualquier número e igual el resultado a 0.
   * 
   * @param kNum Cualquier número natural.
   */
  FuncionZero(const int kNum) { 
    ContarLlamadasAFunciones::setContador()++;
    resultado_ = 0;
  }
};