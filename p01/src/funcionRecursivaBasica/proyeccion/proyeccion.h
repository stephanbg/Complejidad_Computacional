#pragma once

#include "../funcionRecursivaBasica.h"

class FuncionProyeccion : public FuncionRecursivaBasica {
 public:
  FuncionProyeccion(std::vector<int> numeros, int indice) { 
    if (indice < 0) resultado_ = numeros[0];
    else if(indice >= numeros.size()) resultado_ = numeros[numeros.size() - 1];
    else resultado_ = numeros[indice];
    ContarLlamadasAFunciones::setContador()++;
  }
};