#pragma once

#include "./transicion.h"
#include "./direccion.h"

class TransicionMTCintaUnicaLRS : public Transicion {
 public:
  TransicionMTCintaUnicaLRS(
    const Estado& kEstadoIni, const char kSimboloLeido,
    const Estado& kEstadoFin, const char kSimboloEscrito, const Direccion& kDireccion)
      : Transicion(kEstadoIni, kEstadoFin),
        simboloLeido_(kSimboloLeido), simboloEscrito_(kSimboloEscrito), direccion_(kDireccion) {}
  const char getSimboloLeido() const { return simboloLeido_; }
  const char getSimboloEscrito() const { return simboloEscrito_; }
  const Direccion getDireccion() const { return direccion_; }
 private:
  char simboloLeido_;
  char simboloEscrito_;
  Direccion direccion_;
};