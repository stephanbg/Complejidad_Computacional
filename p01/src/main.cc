#include <iostream>

#include "./comprobarParametros/comprobarParametros.h"
#include "./funcionPrimitivaRecursiva/funcionPrimitivaRecursiva.h"
#include "./funcionPrimitivaRecursiva/potencia/potencia.h"

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