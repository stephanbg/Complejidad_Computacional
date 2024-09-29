/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file multiplicación.cc
 * @brief Implementación de la clase Multiplicacion que hereda de FuncionPrimitivaRecursiva
 *        para poder realizar la multiplicación de forma primitiva recursiva
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#include "./multiplicacion.h"

/**
 * @brief Realiza la multiplicación de manera primitiva recursiva.
 * 
 * @param kNum1 El primer número natural.
 * @param kNum2 El segundo número natural.
 * @return Devuelve de manerea recursiva el caso general hasta llegar al caso base.
 */ 
const int Multiplicacion::multiplicacionPrimitivaRecursiva(const int kNum1, const int kNum2) {
  ContarLlamadasAFunciones::setContador()++;
  if (kNum2 == 0) return casoBase(kNum1);
  return casoGeneral(kNum1, kNum2, multiplicacionPrimitivaRecursiva(kNum1, kNum2 - 1));
}

/**
 * @brief Realiza el caso base.
 * 
 * @param kNum1 El primer número.
 * @return Devuelve 0.
 */ 
const int Multiplicacion::casoBase(const int kNum1) const {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* FRB = new FuncionZero(kNum1);
  return FRB->getResultado();  
}

/**
 * @brief Realiza el caso general.
 * 
 * @param kNum1 El primer número.
 * @param kNum2 El segundo número.
 * @param kSuma La multiplicación (con -1 en el segundo número para realizar la recursividad).
 * @return Devuelve la suma del primer número con la multiplicación del primer número con el segundo -1.
 */
const int Multiplicacion::casoGeneral(const int kNum1, const int kNum2, const int kMult) const {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* proyeccion1;
  FuncionRecursivaBasica* proyeccion2;
  const std::vector<int> kParametros = {kNum1, kNum2, kMult};
  proyeccion1 = new FuncionProyeccion(kParametros, 0);
  proyeccion2 = new FuncionProyeccion(kParametros, 2);
  FuncionPrimitivaRecursiva* FPR = new Suma(proyeccion1->getResultado(), proyeccion2->getResultado());
  return FPR->getResultado();
}