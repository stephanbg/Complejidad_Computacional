#include "./MT.h"

void MaquinaTuring::agregarTransicion(const Estado& kEstadoIni, Transicion*& transicion) {
  transiciones_[kEstadoIni].push_back(transicion);
}

void MaquinaTuring::mostrarMT() const {
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Estados: {";
  bool primero = true;
  for (const Estado& kEstado : estados_) {
    if (!primero) std::cout << ", ";
    std::cout << kEstado;
    primero = false;
  }
  std::cout << "}" << std::endl;
  std::cout << "Alfabeto de Entrada: " << alfabetoEntrada_;
  std::cout << "Alfabeto de Cinta: " << alfabetoCinta_;
  std::cout << "Estado Inicial: " << estadoInicial_ << std::endl;
  std::cout << "Símbolo Blanco: " << simboloBlanco_ << std::endl;
  std::cout << "Número de Cintas: " << numCintas_ << std::endl;
  std::cout << "Estados Finales: {";
  primero = true;
  for (const Estado& kEstado : estadosFinales_) {
    if (!primero) std::cout << ", ";
    std::cout << kEstado;
    primero = false;
  }
  std::cout << "}" << std::endl;
  std::cout << "Transiciones:" << std::endl;
  for (const auto& kPar : transiciones_) {
    for (const auto& kTransicion : kPar.second) {
      kTransicion->mostrar();
    }
  }
}