#pragma once

#include <vector>

#include "../MT.h"
#include "../componentes_MT/transicion/direccion.h"
#include "../componentes_MT/transicion/transicionCintaUnicaLRS/transicionCintaUnicaLRS.h"

class MaquinaTuringLRS : public MaquinaTuring {
 public: 
  MaquinaTuringLRS() {}
  virtual bool procesar(const std::string&) override;
  virtual void rellenarCintas(const std::string&) override {}
  virtual void mostrarMT() const override;
  virtual void mostrarCintas() const override;
 private:
  Cinta cinta_;
};