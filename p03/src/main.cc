/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Curso: 4º
 * Práctica 3: Programar un simulador de una Máquina de Turing determinista
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Octubre de 2024
 * @file main.cc
 * @brief Programa principal para procesar cadenas a través de una máquina de Turing.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include <iostream>

#include "./comprobarParametros/comprobarParametros.h"
#include "./comprobarFicheroMT/comprobarFicheroMT.h"

/**
 * @brief Función principal.
 * 
 * Esta función se encarga de gestionar los argumentos de entrada,
 * crear la máquina de Turing y procesar las cadenas dadas.
 *
 * @param argc Cantidad de argumentos pasados al programa.
 * @param argv Array de cadenas de caracteres que representan los argumentos pasados al programa.
 * @return int Código de salida del programa.
 */
int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobarErrores(argc, argv);
    ComprobarFicheroMT* comprobarMT = ComprobarFicheroMT::crearComprobador(argv[1]);
    MaquinaTuring* maquinaTuring = comprobarMT->setMaquinaTuring();
    maquinaTuring->mostrarMT();
    std::cout << std::endl;
    bool esAceptada;
    std::string cadena;
    for (int i = 2; i < argc; ++i) {
      cadena = argv[i];
      esAceptada = maquinaTuring->procesar(cadena);
      std::cout << cadena << ": " << (esAceptada ? "ACEPTADA" : "RECHAZADA") << std::endl;
      maquinaTuring->mostrarCintas();
      std::cout << std::endl;
    }
  } catch (const std::string& mensaje) {
    std::cout << "Error: " << mensaje << std::endl << std::endl;
    ComprobarParametros::help();
    return EXIT_FAILURE;
  }
  return 0;
}