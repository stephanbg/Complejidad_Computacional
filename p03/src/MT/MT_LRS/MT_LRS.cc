#include "./MT_LRS.h"

bool MaquinaTuringLRS::procesar(const std::string& kCadena) const {

}

void MaquinaTuringLRS::mostrar() const {
  std::cout << "Máquina de Turing LRS" << std::endl;
  MaquinaTuring::mostrar();
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