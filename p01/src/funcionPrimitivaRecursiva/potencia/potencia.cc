/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file potencia.cc
 * @brief Implementación de la clase Potencia que hereda de FuncionPrimitivaRecursiva
 *        para poder realizar la potencia de forma primitiva recursiva
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#include "./potencia.h"

/**
 * @brief Realiza la potencia de manera primitiva recursiva.
 * 
 * @param kBase La base.
 * @param kExp El exponente.
 * @return Devuelve de manerea recursiva el caso general hasta llegar al caso base.
 */ 
const int Potencia::potenciaPrimitivaRecursiva(const int kBase, const int kExp) {
  ContarLlamadasAFunciones::setContador()++;
  if (kExp == 0) return casoBase(kBase);
  return casoGeneral(kBase, kExp, potenciaPrimitivaRecursiva(kBase, kExp - 1));
}

/**
 * @brief Realiza el caso base.
 * 
 * @param kBase La base.
 * @return Devuelve un 1.
 */ 
const int Potencia::casoBase(const int kBase) const {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* FRB = new FuncionZero(kBase);
  FRB = new FuncionSucesor(FRB->getResultado());
  return FRB->getResultado();  
}

/**
 * @brief Realiza el caso general.
 * 
 * @param kBase La base.
 * @param kExp El exponente.
 * @param kPotencia La potencia (con -1 en el exponente para realizar la recursividad).
 * @return Devuelve la multiplicación entre la base y la potencia entre la base y exponente -1.
 */
const int Potencia::casoGeneral(const int kBase, const int kExp, const int kPotencia) const {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* proyeccion1;
  FuncionRecursivaBasica* proyeccion2;
  const std::vector<int> kParametros = {kBase, kExp, kPotencia};
  proyeccion1 = new FuncionProyeccion(kParametros, 0);
  proyeccion2 = new FuncionProyeccion(kParametros, 2);
  FuncionPrimitivaRecursiva* FPR = new Multiplicacion(proyeccion1->getResultado(), proyeccion2->getResultado());
  return FPR->getResultado();
}