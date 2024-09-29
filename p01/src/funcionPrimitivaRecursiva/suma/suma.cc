#include "./suma.h"

int Suma::sumaPrimitivaRecursiva(int num1, int num2) {
  ContarLlamadasAFunciones::setContador()++;
  if (num2 == 0) return casoBase(num1);
  return casoGeneral(num1, num2, sumaPrimitivaRecursiva(num1, num2 - 1));
}

int Suma::casoBase(int num1) {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* FRB = new FuncionProyeccion(std::vector<int>{num1}, 0);
  return FRB->getResultado();  
}

int Suma::casoGeneral(int num1, int num2, int suma) {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* FRB = new FuncionProyeccion(std::vector<int>{num1, num2, suma}, 2);
  FRB = new FuncionSucesor(FRB->getResultado());
  return FRB->getResultado();   
}