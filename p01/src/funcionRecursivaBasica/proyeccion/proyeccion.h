/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file proyeccion.h
 * @brief Definición de la clase FuncionProyeccion que hereda de FuncionRecursivaBasica,
 *        para poder crear la función proyección
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#pragma once

#include "../funcionRecursivaBasica.h"

/**
 * @brief Clase FuncionZero que hereda de FuncionRecursivaBasica para modificar el resultado.
 */
class FuncionProyeccion : public FuncionRecursivaBasica {
 public:
  /**
   * @brief Recibe un vector y un índice e iguala el resultado al valor que apunta el índice.
   * 
   * @param kNumeros El vector de números.
   * @param kIndice El índice que apunta a alguna posición del vector.
   */ 
  FuncionProyeccion(const std::vector<int> kNumeros, const int kIndice) { 
    if (kIndice < 0) resultado_ = kNumeros[0];
    else if(kIndice >= kNumeros.size()) resultado_ = kNumeros[kNumeros.size() - 1];
    else resultado_ = kNumeros[kIndice];
    ContarLlamadasAFunciones::setContador()++;
  }
};