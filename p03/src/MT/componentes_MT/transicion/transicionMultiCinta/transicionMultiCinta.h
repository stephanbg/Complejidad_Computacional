#pragma once

#include "../transicion.h"
#include "../direccion.h"

class TransicionMultiCinta : public Transicion {
 public:
  TransicionMultiCinta(
    const Estado& kEstadoIni, 
    const std::vector<char>& kSimbolosLeidos,
    const Estado& kEstadoFin, 
    const std::vector<char>& kSimbolosEscritos,
    const std::vector<Direccion>& kMovimientos)
  : Transicion(kEstadoIni, kEstadoFin),
    simbolosLeidos_(kSimbolosLeidos), 
    simbolosEscritos_(kSimbolosEscritos), 
    movimientos_(kMovimientos) {}

  const std::vector<char>& getSimbolosLeidos() const { return simbolosLeidos_; }
  const std::vector<char>& getSimbolosEscritos() const { return simbolosEscritos_; }
  const std::vector<Direccion>& getMovimientos() const { return movimientos_; }
  virtual void mostrar() const override;
 private:
  std::vector<char> simbolosLeidos_;
  std::vector<char> simbolosEscritos_;
  std::vector<Direccion> movimientos_;
};