/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file sucesor.h
 * @brief Definición de la clase FuncionSucesor que hereda de FuncionRecursivaBasica,
 *        para poder crear la función sucesor
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#pragma once

#include "../funcionRecursivaBasica.h"

/**
 * @brief Clase FuncionSucesor que hereda de FuncionRecursivaBasica para modificar el resultado.
 */
class FuncionSucesor : public FuncionRecursivaBasica {
 public:
  /**
   * @brief Recibe cualquier número e iguala el resultado a el número de entrada + 1.
   * 
   * @param kNum Cualquier número natural.
   */ 
  FuncionSucesor(const int kNum) { 
    ContarLlamadasAFunciones::setContador()++;
    resultado_ = kNum + 1;
  }
};