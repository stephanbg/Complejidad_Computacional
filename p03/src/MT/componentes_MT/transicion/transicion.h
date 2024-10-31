#pragma once

#include "../estado.h"

class Transicion {
 public:
  Transicion(const Estado& estadoIni, const Estado& estadoFin)
      : estadoIni_(estadoIni), estadoFin_(estadoFin) {}
  const Estado getEstadoIni() const { return estadoIni_; }
  const Estado getEstadoFin() const { return estadoFin_; }
  virtual ~Transicion() {}
 private:
  Estado estadoIni_;
  Estado estadoFin_;
};