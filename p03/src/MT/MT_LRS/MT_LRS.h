#pragma once

#include <vector>

#include "../MT.h"
#include "../componentes_MT/transicion/direccion.h"

class MaquinaTuringLRS : public MaquinaTuring {
 public:
  MaquinaTuringLRS() : cinta_{}, posicionCabezal_(0) {}
  virtual bool procesar(const std::string&) const override;
 private:
  std::vector<char> cinta_;
  int posicionCabezal_;
  void escribir(const char);
  char leer() const;
  void moverCabezal(const Direccion&);  
};