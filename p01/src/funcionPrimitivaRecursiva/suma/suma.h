#pragma once

#include "../funcionPrimitivaRecursiva.h"
#include "../../funcionRecursivaBasica/funcionRecursivaBasica.h"
#include "../../funcionRecursivaBasica/proyeccion/proyeccion.h"
#include "../../funcionRecursivaBasica/sucesor/sucesor.h"

class Suma : public FuncionPrimitivaRecursiva {
 public:
  Suma(int num1, int num2) { resultado_ = sumaPrimitivaRecursiva(num1, num2); }
 private:
  int sumaPrimitivaRecursiva(int, int);
  int casoBase(int);
  int casoGeneral(int, int, int);
};