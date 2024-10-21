#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../automataDePila/automataDePila.h"

class ComprobarFicheroAutomata {
 public:
  virtual void analizarFicheroAutomata(const std::string&) = 0;
  const AutomataDePila* getAutomataDePila() const { return automataDePila_; }
 protected:
  AutomataDePila* automataDePila_;
  std::string mensajeError_ = "";
};