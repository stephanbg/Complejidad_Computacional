#pragma once

#include "../funcionRecursivaBasica.h"

class FuncionZero : public FuncionRecursivaBasica {
 public:
  FuncionZero(int num) { 
    ContarLlamadasAFunciones::setContador()++;
    resultado_ = 0;
  }
};