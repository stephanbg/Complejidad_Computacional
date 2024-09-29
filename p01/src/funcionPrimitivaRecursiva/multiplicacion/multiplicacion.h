/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file multiplicación.h
 * @brief Definición de la clase Multiplicacion que hereda de FuncionPrimitivaRecursiva
 *        para poder realizar la multiplicación de forma primitiva recursiva
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#pragma once

#include "../funcionPrimitivaRecursiva.h"
#include "../suma/suma.h"
#include "../../funcionRecursivaBasica/funcionRecursivaBasica.h"
#include "../../funcionRecursivaBasica/zero/zero.h"
#include "../../funcionRecursivaBasica/proyeccion/proyeccion.h"

/**
 * @brief Clase Multiplicacion que hereda de FuncionPrimitivaRecursiva para realizar la multiplicación.
 */
class Multiplicacion : public FuncionPrimitivaRecursiva {
 public:
  /**
   * @brief Recibe dos números y almacena la multiplicación en el resultado.
   * 
   * @param kNum1 El primer número natural.
   * @param kNum2 El segundo número natural.
   */  
  Multiplicacion(const int kNum1, const int kNum2) { resultado_ = multiplicacionPrimitivaRecursiva(kNum1, kNum2); }
 private:
  const int multiplicacionPrimitivaRecursiva(const int, const int);
  const int casoBase(const int) const;
  const int casoGeneral(const int, const int, const int) const;
};