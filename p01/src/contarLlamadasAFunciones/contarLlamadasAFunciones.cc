/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file contarLlamadasAFunciones.cc
 * @brief Implementación de la clase ContarLlamadasAFunciones que se encarga de crear
 *        un contador para las llamadas a funciones.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */


#include "contarLlamadasAFunciones.h"

// Inicializar a 0 el contador
int ContarLlamadasAFunciones::contador_ = 0;