/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file main.cc
 * @brief
 * 
 * @see 
 * @see 
 */

#include <iostream>

#include "./comprobarParametros/comprobarParametros.h"
#include "./comprobarFicheroAutomata/comprobarFicheroAutomata.h"
#include "./comprobarFicheroAutomata/comprobarFormatoAPv/comprobarFormatoAPv.h"

int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobarErrores(argc, argv[1]);
    ComprobarFicheroAutomata* comprobarAutomata = new ComprobarFormatoAPv();
    comprobarAutomata->analizarFicheroAutomata(argv[1]);
    // Todo correcto aqui y sería analizar palabras
    const APv* kAutomata = dynamic_cast<const APv*>(comprobarAutomata->getAutomataDePila());
    std::cout << *kAutomata << std::endl;
    for (int i = 2; i < argc; ++i) {
      std::cout << "La cadena " << argv[i] << ": ";
      if (kAutomata->seAceptaCadena(argv[i])) std::cout << "ACEPTADA";
      else std::cout << "X";
      std::cout << std::endl;
    }
    return 0;
  } catch (const std::string& mensaje) {
    std::cout << "Error: " << mensaje << std::endl << std::endl;
    ComprobarParametros::help();
    return EXIT_FAILURE;
  }
}