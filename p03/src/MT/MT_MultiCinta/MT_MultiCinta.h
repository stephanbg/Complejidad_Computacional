#pragma once

#include <vector>

#include "../MT.h"
#include "../componentes_MT/transicion/direccion.h"

class MaquinaTuringMultiCinta : public MaquinaTuring {
 public:
  MaquinaTuringMultiCinta(const int kNumCintas) : cinta_(kNumCintas) {}
  virtual bool procesar(const std::string&) const override;
  virtual void mostrar() const override;
 private:
  std::vector<std::vector<char>> cinta_;
  void escribir(const char);
  char leer() const;
};