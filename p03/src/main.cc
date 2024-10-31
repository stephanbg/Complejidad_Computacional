/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Octubre de 2024
 * @file main.cc
 * @brief 
 * 
 * @see {}
 */

#include <iostream>

#include "./comprobarParametros/comprobarParametros.h"
#include "./comprobarFicheroMT/comprobarFicheroMT.h"

/**
 * @brief Función principal.
 * 
 * @param argc Cantidad de argumentos pasados al programa.
 * @param argv Array de cadenas de caracteres que representan los argumentos pasados al programa.
 */
int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobarErrores(argc, argv);
    ComprobarFicheroMT* comprobarMT = ComprobarFicheroMT::crearComprobador(argv[1]);
    //const MaquinaTuring* maquinaTuringConst = comprobarMT->getMaquinaTuring();
    //const MaquinaTuringBasica* kMaquinaTuringConst = dynamic_cast<const MaquinaTuringBasica*>(maquinaTuringConst);
  } catch (const std::string& mensaje) {
    std::cout << "Error: " << mensaje << std::endl << std::endl;
    ComprobarParametros::help();
    return EXIT_FAILURE;
  }
  return 0;
}