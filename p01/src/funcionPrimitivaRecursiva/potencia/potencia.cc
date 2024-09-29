#include "./potencia.h"

int Potencia::potenciaPrimitivaRecursiva(int base, int exp) {
  ContarLlamadasAFunciones::setContador()++;
  if (exp == 0) return casoBase(base);
  return casoGeneral(base, exp, potenciaPrimitivaRecursiva(base, exp - 1));
}

int Potencia::casoBase(int base) {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* FRB = new FuncionZero(base);
  FRB = new FuncionSucesor(FRB->getResultado());
  return FRB->getResultado();  
}

int Potencia::casoGeneral(int base, int exp, int potencia) {
  ContarLlamadasAFunciones::setContador()++;
  FuncionRecursivaBasica* proyeccion1;
  FuncionRecursivaBasica* proyeccion2;
  std::vector<int> parametros = {base, exp, potencia};
  proyeccion1 = new FuncionProyeccion(parametros, 0);
  proyeccion2 = new FuncionProyeccion(parametros, 2);
  FuncionPrimitivaRecursiva* FPR = new Multiplicacion(proyeccion1->getResultado(), proyeccion2->getResultado());
  return FPR->getResultado();
}