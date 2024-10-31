#pragma once

#include <unordered_map>

#include "./componentes_MT/estado.h"
#include "./componentes_MT/alfabeto.h"
#include "./componentes_MT/transicion/transicion.h"

class MaquinaTuring {
 public:
  MaquinaTuring() {}
  virtual bool procesar(const std::string&) const = 0;
  const char getSimboloBlanco() const { return simboloBlanco_; }
  const std::set<Estado>& getEstados() const { return estados_; }
  Alfabeto& setAlfabetoEntrada() { return alfabetoEntrada_; }
  Alfabeto& setAlfabetoCinta() { return alfabetoCinta_; }
  std::set<Estado>& setEstados() { return estados_; }
  std::set<Estado>& setEstadosFinales() { return estadosFinales_; }
  Estado& setEstadoInicial() { return estadoInicial_; }
  virtual ~MaquinaTuring() {}
 protected:
  std::set<Estado> estados_;
  Alfabeto alfabetoEntrada_;
  Alfabeto alfabetoCinta_;
  Estado estadoInicial_;
  std::set<Estado> estadosFinales_;
  char simboloBlanco_ = '.';
  std::unordered_map<Estado, Transicion*> transiciones_;
  void agregarTransicion(const Estado& kEstadoIni, Transicion*& transicion) {
    transiciones_[kEstadoIni] = transicion;
  }
};