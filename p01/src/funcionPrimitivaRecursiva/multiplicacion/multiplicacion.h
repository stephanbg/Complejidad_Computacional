#pragma once

#include "../funcionPrimitivaRecursiva.h"
#include "../suma/suma.h"
#include "../../funcionRecursivaBasica/funcionRecursivaBasica.h"
#include "../../funcionRecursivaBasica/zero/zero.h"
#include "../../funcionRecursivaBasica/proyeccion/proyeccion.h"

class Multiplicacion : public FuncionPrimitivaRecursiva {
 public:
  Multiplicacion(int num1, int num2) { resultado_ = multiplicacionPrimitivaRecursiva(num1, num2); }
 private:
  int multiplicacionPrimitivaRecursiva(int, int);
  int casoBase(int);
  int casoGeneral(int, int, int);
};