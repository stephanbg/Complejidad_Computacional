#include "alfabeto.h"

void Alfabeto::insertar(const char kElemento) {
  conjuntoAlfabeto_.insert(kElemento);
}

std::ostream& operator<<(std::ostream& os, const Alfabeto& kAlfabeto) {
  os << "{";
  bool primero = true;
  for (const auto& kSimbolo : kAlfabeto.conjuntoAlfabeto_) {
    if (!primero) os << ", ";
    os << kSimbolo;
    primero = false;
  }
  os << "}" << std::endl;
  return os;
}