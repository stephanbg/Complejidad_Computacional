#include "./multiplicacion.h"

int Multiplicacion::multiplicacionPrimitivaRecursiva(int num1, int num2) {
  ContarLlamadasAFunciones::setContador()++;
  if (num2 == 0) return casoBase(num1);
  return casoGeneral(num1, num2, multiplicacionPrimitivaRecursiva(num1, num2 - 1));
}

int Multiplicacion::casoBase(int num1) {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* FRB = new FuncionZero(num1);
  return FRB->getResultado();  
}

int Multiplicacion::casoGeneral(int num1, int num2, int mult) {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* proyeccion1;
  FuncionRecursivaBasica* proyeccion2;
  std::vector<int> parametros = {num1, num2, mult};
  proyeccion1 = new FuncionProyeccion(parametros, 0);
  proyeccion2 = new FuncionProyeccion(parametros, 2);
  FuncionPrimitivaRecursiva* FPR = new Suma(proyeccion1->getResultado(), proyeccion2->getResultado());
  return FPR->getResultado();
}