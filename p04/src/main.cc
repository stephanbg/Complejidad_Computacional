/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Curso: 4º
 * Práctica 4: Resolver algoritmo SAT
 *
 * @author Aday Cuesta Correa
 * @author Stephan Brommer Gutiérrez
 * @author Sofía De Fuentes Rosella
 * @since 1 de Diciembre de 2024
 * @file main.cc
 * @brief Fichero principal para resolver el problema del algoritmo SAT.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/edit/main/p04}
 */

#include <iostream>

#include "SAT/sat.h"

/**
 * @brief Muestra el uso del programa.
 * @param argc Número de argumentos.
 * @param argv Argumentos.
 */
void Usage(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Error: Número de parámetros incorrecto.\nPruebe --help para más información." << std::endl;
    exit(EXIT_FAILURE);
  }
  if (std::string(argv[1]) == "--help") {
    std::cout << "Uso: " << argv[0] << " <fichero_entrada.json>" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief Función principal.
 * @param argc Número de argumentos.
 * @param argv Argumentos.
 * @return Código de salida.
 */
int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero de entrada." << std::endl;
    return 1;
  }
  nlohmann::json json;
  input >> json;
  try {
    SAT sat(json);
    std::cout << sat << std::endl;
    std::vector<bool> solution(sat.GetNumVariables());
    if (sat.Solve(solution)) {
      std::cout << "Satisfacible." << std::endl;
      for (size_t i = 0; i < solution.size(); i++) {
        std::cout << "x" << i + 1 << " = " << (solution[i] ? "True" : "False") << std::endl;
      }
    } else std::cout << "Insatisfacible." << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
