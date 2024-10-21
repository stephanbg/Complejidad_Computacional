#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "./alfabeto/alfabeto.h"
#include "./estado/estado.h"
#include "./transicion/transicion.h"

class AutomataDePila {
 public:
  AutomataDePila() {}
  virtual bool seAceptaCadena(const std::string&) = 0;
  // Getters
  const std::set<Estado> getEstados() const { return estados_; }
  const Alfabeto getAlfabeto() const { return alfabeto_; }
  const Alfabeto getAlfabetoPila() const { return alfabetoPila_; }
  const std::vector<Transicion> getTransiciones() { return transiciones_; }
  // Setters
  std::set<Estado>& setEstados() { return estados_; }
  Alfabeto& setAlfabeto() { return alfabeto_; }
  Alfabeto& setAlfabetoPila() { return alfabetoPila_; }
  Estado& setEstadoInicial() { return estadoInicial_; }
  char& setSimboloInicialPila() { return simboloInicialPila_; }
  std::vector<Transicion>& setTransiciones() { return transiciones_; }
  virtual ~AutomataDePila() {}
 protected:
  std::set<Estado> estados_;
  Alfabeto alfabeto_;
  Alfabeto alfabetoPila_;
  Estado estadoInicial_;
  char simboloInicialPila_;
  std::vector<Transicion> transiciones_;
  std::stack<char> pila_;
};