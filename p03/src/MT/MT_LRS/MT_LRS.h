#pragma once

#include <vector>

#include "../MT.h"
#include "../componentes_MT/transicion/direccion.h"
#include "../componentes_MT/transicion/transicionCintaUnicaLRS/transicionCintaUnicaLRS.h"

class MaquinaTuringLRS : public MaquinaTuring {
 public:
  MaquinaTuringLRS() : cinta_{} {}
  virtual bool procesar(const std::string&) override;
  virtual void mostrar() const override;
  virtual void imprimirCinta() const override;
 private:
  std::vector<char> cinta_;
  void escribir(const char);
  char leer() const;
 protected:
  virtual void inicializarCinta(const std::string&) override;
  virtual void moverCabezal(const Direccion&) override;
};