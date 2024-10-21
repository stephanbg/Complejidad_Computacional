#include "./automataDePila.h"

void AutomataDePila::mostrarPila(const std::stack<char>& kPila) const {
  std::stack<char> copiaPila = kPila;
  std::vector<char> elementos;
  while (!copiaPila.empty()) {
    elementos.push_back(copiaPila.top());
    copiaPila.pop();
  }
  std::cout << "Contenido de la pila: ";
  for (int i = 0; i < elementos.size(); ++i) {
    std::cout << elementos[i] << " ";
  }
  std::cout << std::endl;
}