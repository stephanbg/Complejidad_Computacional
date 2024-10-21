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