/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file suma.cc
 * @brief Implementación de la clase Suma que hereda de FuncionPrimitivaRecursiva
 *        para poder realizar la suma de forma primitiva recursiva
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#include "./suma.h"

/**
 * @brief Realiza la suma de manera primitiva recursiva.
 * 
 * @param kNum1 El primer número natural.
 * @param kNum2 El segundo número natural.
 * @return Devuelve de manerea recursiva el caso general hasta llegar al caso base.
 */ 
const int Suma::sumaPrimitivaRecursiva(const int kNum1, const int kNum2) {
  ContarLlamadasAFunciones::setContador()++;
  if (kNum2 == 0) return casoBase(kNum1);
  return casoGeneral(kNum1, kNum2, sumaPrimitivaRecursiva(kNum1, kNum2 - 1));
}

/**
 * @brief Realiza el caso base.
 * 
 * @param kNum1 El primer número.
 * @return Devuelve el primer número.
 */ 
const int Suma::casoBase(const int kNum1) const {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* FRB = new FuncionProyeccion(std::vector<int>{kNum1}, 0);
  return FRB->getResultado();  
}

/**
 * @brief Realiza el caso general.
 * 
 * @param kNum1 El primer número.
 * @param kNum2 El segundo número.
 * @param kSuma La suma (con -1 para realizar la recursividad).
 * @return A la suma - 1 le suma 1 es decir que devuelve la suma.
 */ 
const int Suma::casoGeneral(const int kNum1, const int kNum2, const int kSuma) const {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* FRB = new FuncionProyeccion(std::vector<int>{kNum1, kNum2, kSuma}, 2);
  FRB = new FuncionSucesor(FRB->getResultado());
  return FRB->getResultado();   
}