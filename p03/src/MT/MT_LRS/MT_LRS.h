#pragma once

#include <vector>

#include "../MT.h"
#include "../componentes_MT/transicion/direccion.h"

class MaquinaTuringLRS : public MaquinaTuring {
 public:
  MaquinaTuringLRS() : cinta_{} {}
  virtual bool procesar(const std::string&) const override;
  virtual void mostrar() const override;
 private:
  std::vector<char> cinta_;
  void escribir(const char);
  char leer() const;
};