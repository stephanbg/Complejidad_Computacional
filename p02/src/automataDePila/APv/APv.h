#pragma once

#include <functional>

#include "../automataDePila.h"

class APv : public AutomataDePila {
 public:
  virtual bool seAceptaCadena(const std::string&) const override; // Implementar algoritmo APv
  friend std::ostream& operator<<(std::ostream&, const APv&);
};