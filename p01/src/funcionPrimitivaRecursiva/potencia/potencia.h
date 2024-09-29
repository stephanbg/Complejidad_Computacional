#pragma once

#include "../funcionPrimitivaRecursiva.h"
#include "../multiplicacion/multiplicacion.h"
#include "../../funcionRecursivaBasica/funcionRecursivaBasica.h"
#include "../../funcionRecursivaBasica/zero/zero.h"
#include "../../funcionRecursivaBasica/proyeccion/proyeccion.h"

class Potencia : public FuncionPrimitivaRecursiva {
 public:
  Potencia(int num1, int num2) { resultado_ = potenciaPrimitivaRecursiva(num1, num2); }
 private:
  int potenciaPrimitivaRecursiva(int, int);
  int casoBase(int);
  int casoGeneral(int, int, int);
};