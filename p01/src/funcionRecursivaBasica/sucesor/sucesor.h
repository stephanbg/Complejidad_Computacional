#pragma once

#include "../funcionRecursivaBasica.h"

class FuncionSucesor : public FuncionRecursivaBasica {
 public:
  FuncionSucesor(int num) { 
    ContarLlamadasAFunciones::setContador()++;
    resultado_ = num + 1;
  }
};