#pragma once

#include "../transicion.h"
#include "../direccion.h"

class TransicionCintaUnicaLRS : public Transicion {
 public:
  TransicionCintaUnicaLRS(
    const Estado& kEstadoIni, const char kSimboloLeido,
    const Estado& kEstadoFin, const char kSimboloEscrito, const Direccion& kMovimiento)
      : Transicion(kEstadoIni, kEstadoFin),
        simboloLeido_(kSimboloLeido), simboloEscrito_(kSimboloEscrito), movimiento_(kMovimiento) {}
  const char getSimboloLeido() const { return simboloLeido_; }
  const char getSimboloEscrito() const { return simboloEscrito_; }
  const Direccion getMovimiento() const { return movimiento_; }
  virtual void mostrar() const override;
 private:
  char simboloLeido_;
  char simboloEscrito_;
  Direccion movimiento_;
};