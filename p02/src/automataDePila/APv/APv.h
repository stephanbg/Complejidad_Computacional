#pragma once

#include <functional>

#include "../automataDePila.h"

class APv : public AutomataDePila {
 public:
  virtual bool seAceptaCadena(const std::string&) override;
  friend std::ostream& operator<<(std::ostream&, const APv&);
};