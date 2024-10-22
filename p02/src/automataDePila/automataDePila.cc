#include "automataDePila.h"

void AutomataDePila::mostrarPila(const std::stack<char>& pila) const {
  std::vector<char> elementos;
  std::stack<char> pilaCopia = pila;
  while (!pilaCopia.empty()) {
    char elemento = pilaCopia.top();
    elementos.push_back(elemento);
    pilaCopia.pop();
  }
  for (auto a : elementos) {
    std::cout << a;
  }
  std::cout << std::endl;
}

void AutomataDePila::mostrarTraza(
  const Estado* kEstadoActual, const std::string& kCadena,
  const std::stack<char>& kPila, const Transicion& kTransicion
) const {
  #ifdef TRAZA
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "Estado:" << *kEstadoActual << std::endl;
    std::cout << std::left << std::setw(15) << "Cadena:" << kCadena << std::endl;
    std::cout << std::left << std::setw(15) << "Pila:";
    mostrarPila(kPila);
    if (!kTransicion.isEmpty()) std::cout << std::left << std::setw(15) << "Transición:" << kTransicion;
  #endif
}