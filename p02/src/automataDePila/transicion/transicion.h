#pragma once

#include "../estado/estado.h"

class Transicion {
 public:
  Transicion() 
    : estadoOrigen_(nullptr), simboloTransicion_('\0'), 
      elementoAExtraerDePila_('\0'), estadoDestino_(nullptr), 
      simbolosAIntroducirEnPila_("") {}
  Transicion(
    Estado*& kEstadoOrigen,
    const char kSimboloTransicion,
    const char kElementoAExtraerDePila,
    Estado*& kEstadoDestino,
    const std::string& kSimbolosAIntroducirEnPila
  ) {
    estadoOrigen_ = kEstadoOrigen;
    simboloTransicion_ = kSimboloTransicion;
    elementoAExtraerDePila_ = kElementoAExtraerDePila;
    estadoDestino_ = kEstadoDestino;
    simbolosAIntroducirEnPila_ = kSimbolosAIntroducirEnPila;
  }
  const char getSimboloTransicion() const { return simboloTransicion_; }
  const char getElementoAExtraerDePila() const { return elementoAExtraerDePila_; }
  const Estado* getEstadoDestino() const { return estadoDestino_; }
  const std::string getSimbolosAIntroducirEnPila() const { return simbolosAIntroducirEnPila_; }
  bool isEmpty() const {
    return estadoOrigen_ == nullptr && simboloTransicion_ == '\0' &&
           elementoAExtraerDePila_ == '\0' && estadoDestino_ == nullptr &&
           simbolosAIntroducirEnPila_.empty();
  }  
  friend std::ostream& operator<<(std::ostream& os, const Transicion& kTransicion) {
    os << "(" << *(kTransicion.estadoDestino_) << ", " << kTransicion.simbolosAIntroducirEnPila_;
    os << ") ∈ δ (" << *(kTransicion.estadoOrigen_) << ", " << kTransicion.simboloTransicion_ << ", ";
    os << kTransicion.elementoAExtraerDePila_ << ")" << std::endl;
    return os;
  }  
 private:
  Estado* estadoOrigen_;
  char simboloTransicion_;
  char elementoAExtraerDePila_;
  Estado* estadoDestino_;
  std::string simbolosAIntroducirEnPila_;
};