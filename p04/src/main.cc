
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

  SAT sat(json);
  std::cout << sat << std::endl;

  return 0;
}