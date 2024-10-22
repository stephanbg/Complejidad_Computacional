/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file main.cc
 * @brief Programa principal para simular un autómata con pila.
 * 
 * Este programa se encarga de leer la definición de un autómata con pila desde un archivo, 
 * analizarlo y verificar si ciertas cadenas son aceptadas por el autómata. 
 * Utiliza la clase `ComprobarParametros` para manejar parámetros de línea de comandos 
 * y la clase `ComprobarFicheroAutomata` para la validación del autómata.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#include <iostream>

#include "./comprobarParametros/comprobarParametros.h"
#include "./comprobarFicheroAutomata/comprobarFicheroAutomata.h"
#include "./comprobarFicheroAutomata/comprobarFormatoAPv/comprobarFormatoAPv.h"

/**
 * @brief Función principal del programa.
 * 
 * Esta función se encarga de comprobar los parámetros de entrada, 
 * leer el archivo que define el autómata, analizar el autómata y 
 * verificar la aceptación de varias cadenas.
 * 
 * @param argc Número de argumentos de la línea de comandos.
 * @param argv Array de argumentos de la línea de comandos.
 * @return int Devuelve 0 si el programa se ejecuta correctamente, 
 * o un código de error en caso de excepciones.
 */
int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobarErrores(argc, argv[1]);
    ComprobarFicheroAutomata* comprobarAutomata = new ComprobarFormatoAPv();
    comprobarAutomata->analizarFicheroAutomata(argv[1]);
    const AutomataDePila* automataConst = comprobarAutomata->getAutomataDePila();
    const APv* kAutomataConst = dynamic_cast<const APv*>(automataConst);
    APv* kAutomata = const_cast<APv*>(kAutomataConst);
    bool cadenaValida;
    std::cout << *kAutomata << std::endl;
    for (int i = 2; i < argc; ++i) {
      cadenaValida = kAutomata->seAceptaCadena(argv[i]);
      #ifdef TRAZA
        std::cout << std::endl;
      #endif
      std::cout << "La cadena " << argv[i] << ": ";
      if (cadenaValida) std::cout << "ACEPTADA";
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