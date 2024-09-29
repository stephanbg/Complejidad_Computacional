/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file potencia.h
 * @brief Definición de la clase Potencia que hereda de FuncionPrimitivaRecursiva
 *        para poder realizar la potencia de forma primitiva recursiva
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#pragma once

#include "../funcionPrimitivaRecursiva.h"
#include "../multiplicacion/multiplicacion.h"
#include "../../funcionRecursivaBasica/funcionRecursivaBasica.h"
#include "../../funcionRecursivaBasica/zero/zero.h"
#include "../../funcionRecursivaBasica/proyeccion/proyeccion.h"

/**
 * @brief Clase Potencia que hereda de FuncionPrimitivaRecursiva para realizar la potencia.
 */
class Potencia : public FuncionPrimitivaRecursiva {
 public:
  /**
   * @brief Recibe dos números y almacena la potencia en el resultado.
   * 
   * @param kNum1 El primer número natural.
   * @param kNum2 El segundo número natural.
   */  
  Potencia(const int kNum1, const int kNum2) { resultado_ = potenciaPrimitivaRecursiva(kNum1, kNum2); }
 private:
  const int potenciaPrimitivaRecursiva(const int, const int);
  const int casoBase(const int) const;
  const int casoGeneral(const int, const int, const int) const;
};