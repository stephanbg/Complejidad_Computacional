#pragma once

#include <algorithm>
#include <sstream>

#include "../comprobarFicheroAutomata.h"
#include "../../automataDePila/APv/APv.h"

class ComprobarFormatoAPv : public ComprobarFicheroAutomata {
 public:
  ComprobarFormatoAPv();
  virtual void analizarFicheroAutomata(const std::string&) override;
 private:
  void eliminarComentarios(std::string&) const;
  bool lineaCompletaDeEspacios(const std::string&) const;
  void analizarYRellenarConjuntoDeEstados(const std::string&);
  void analizarYRellenarAlfabeto(const std::string&);
  void analizarYRellenarAlfabetoPila(const std::string&);
  void analizarYRellenarEstadoInicial(const std::string&);
  void analizarYRellenarSimboloInicialPila(const std::string&);
  void analizarYRellenarTransiciones(const std::string&);
  bool existeTransicion(const std::string&) const;
};