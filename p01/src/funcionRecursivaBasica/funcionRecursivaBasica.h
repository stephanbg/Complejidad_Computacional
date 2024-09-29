#pragma once

#include <vector>
#include "../contarLlamadasAFunciones/contarLlamadasAFunciones.h"

class FuncionRecursivaBasica {
 public:
  int getResultado() { return resultado_; }
 protected:
  int resultado_;
};