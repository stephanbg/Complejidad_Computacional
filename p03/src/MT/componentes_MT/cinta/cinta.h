#pragma once

#include <iostream>
#include <vector>

#include "../transicion/direccion.h"

class Cinta {
 public:
  void iniciar(const std::string&);
  void rellenarDeBlancos(const int);
  void escribir(const char);
  const char leer() const;
  void moverCabezal(const Direccion&);
  void imprimir() const;
  const std::vector<char> getCinta() const { return cinta_; }
 private:
  std::vector<char> cinta_;
  int posicionCabezal_ = 1;
  char simboloBlanco_ = '.';
};