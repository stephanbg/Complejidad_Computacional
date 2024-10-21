#pragma once

#include <set>

class Alfabeto {
 public:
  Alfabeto() : conjuntoAlfabeto_{'.'} {}
  const std::set<char> getConjuntoAlfabeto() const { return conjuntoAlfabeto_; }
  void insertar(const char kElemento) { conjuntoAlfabeto_.insert(kElemento); }
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& kAlfabeto) {
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
 private:
  std::set<char> conjuntoAlfabeto_;
};