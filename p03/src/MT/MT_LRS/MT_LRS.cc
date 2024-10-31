#include "./MT_LRS.h"

bool MaquinaTuringLRS::procesar(const std::string& kCadena) const {

}

void MaquinaTuringLRS::escribir(const char kSimbolo) { /// No estoy seguro si crece o algo
  if (posicionCabezal_ < 0) posicionCabezal_ = 0;
  if (posicionCabezal_ >= cinta_.size()) cinta_.resize(posicionCabezal_ + 1, simboloBlanco_);
  cinta_[posicionCabezal_] = kSimbolo;
}

char MaquinaTuringLRS::leer() const {
  if (posicionCabezal_ < 0 || posicionCabezal_ >= cinta_.size()) return simboloBlanco_;
  return cinta_[posicionCabezal_];
}

void MaquinaTuringLRS::moverCabezal(const Direccion& kDireccion) {
  switch (kDireccion) {
    case Direccion::IZQUIERDA:
      posicionCabezal_--;
      break;
    case Direccion::DERECHA:
      posicionCabezal_++;
      break;
    case Direccion::QUIETO:
      break;
  }
}