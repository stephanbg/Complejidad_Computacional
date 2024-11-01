#pragma once

#include <iostream>
#include <set>

class Alfabeto {
 public:
  const std::set<char>& getConjuntoAlfabeto() const { return conjuntoAlfabeto_; }
  void insertar(const char);
  friend std::ostream& operator<<(std::ostream&, const Alfabeto&);
 private:
  std::set<char> conjuntoAlfabeto_;
};