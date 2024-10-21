#pragma once

#include "../estado/estado.h"

class Transicion {
 public:
  Transicion(
    const Estado& kEstadoOrigen,
    const char kSimboloTransicion,
    const char kElementoAExtraerDePila,
    const Estado& kEstadoDestino,
    const std::string& kSimbolosAIntroducirEnPila
  ) {
    estadoOrigen_ = kEstadoOrigen;
    simboloTransicion_ = kSimboloTransicion;
    elementoAExtraerDePila_ = kElementoAExtraerDePila;
    estadoDestino_ = kEstadoDestino;
    simbolosAIntroducirEnPila_ = kSimbolosAIntroducirEnPila;
  }
  const Estado getEstadoOrigen() const { return estadoOrigen_; }
  const char getSimboloTransicion() const { return simboloTransicion_; }
  const char getElementoAExtraerDePila() const { return elementoAExtraerDePila_; }
  const Estado getEstadoDestino() const { return estadoDestino_; }
  const std::string getSimbolosAIntroducirEnPila() const { return simbolosAIntroducirEnPila_; }
  friend std::ostream& operator<<(std::ostream& os, const Transicion& kTransicion) {
    os << "(" << kTransicion.estadoDestino_ << ", " << kTransicion.simbolosAIntroducirEnPila_;
    os << ") ∈ δ (" << kTransicion.estadoOrigen_ << ", " << kTransicion.simboloTransicion_ << ", ";
    os << kTransicion.elementoAExtraerDePila_ << ")" << std::endl;
    return os;
  }  
 private:
  Estado estadoOrigen_;
  char simboloTransicion_;
  char elementoAExtraerDePila_;
  Estado estadoDestino_;
  std::string simbolosAIntroducirEnPila_;
};