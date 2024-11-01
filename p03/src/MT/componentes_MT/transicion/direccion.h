#pragma once

#include <string>
#include <ostream>

class Direccion {
 public:
  enum Valor {
    IZQUIERDA, // Representa L
    DERECHA,   // Representa R
    QUIETO     // Representa S
  };
  Direccion() {}
  Direccion(const Valor& kDir) : direccion_(kDir) {}
  const std::string toString() const {
    switch (direccion_) {
      case IZQUIERDA: return "L";
      case DERECHA:   return "R";
      case QUIETO:    return "S";
      default:        return ""; // No debería ocurrir
    }
  }
  const bool operator==(const Direccion& kDir) const { return direccion_ == kDir.direccion_; }
  const Valor getValor() const { return direccion_; }  
  static Direccion Izquierda() { return Direccion(IZQUIERDA); }
  static Direccion Derecha() { return Direccion(DERECHA); }
  static Direccion Quieto() { return Direccion(QUIETO); }
  friend std::ostream& operator<<(std::ostream& os, const Direccion& kDir) {
    os << kDir.toString();
    return os;
  }
 private:
  Valor direccion_;
};