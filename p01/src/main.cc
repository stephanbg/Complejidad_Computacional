/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file main.cc
 * @brief Función principal del programa donde se ejecuta el método de la potencia
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#include <iostream>

#include "./comprobarParametros/comprobarParametros.h"
#include "./funcionPrimitivaRecursiva/funcionPrimitivaRecursiva.h"
#include "./funcionPrimitivaRecursiva/potencia/potencia.h"

/**
 * @brief Función principal.
 * 
 * @param argc Cantidad de argumentos pasados al programa.
 * @param argv Array de cadenas de caracteres que representan los argumentos pasados al programa.
 */
int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobarErrores(argc, argv);
    FuncionPrimitivaRecursiva* FPR = new Potencia(std::stoi(argv[1]), std::stoi(argv[2]));
    std::cout << "El resultado de " << argv[1] << "^" << argv[2] << " es " << FPR->getResultado() << std::endl;
    std::cout << "El número de llamadas a funciones es " << ContarLlamadasAFunciones::getContador() << std::endl;
    return 0;
  } catch (const std::string& mensaje) {
    std::cout << "Error: " << mensaje << std::endl << std::endl;
    ComprobarParametros::help();
    return EXIT_FAILURE;
  }
}