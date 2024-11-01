#pragma once

#include <vector>

#include "../MT.h"
#include "../componentes_MT/transicion/direccion.h"
#include "../componentes_MT/transicion/transicionMultiCinta/transicionMultiCinta.h"

class MaquinaTuringMultiCinta : public MaquinaTuring {
 public:
  MaquinaTuringMultiCinta(const int);
  virtual bool procesar(const std::string&) override;
  virtual void mostrarMT() const override;
  virtual void mostrarCinta() const override;
 private:
  std::vector<Cinta> cintas_;
};