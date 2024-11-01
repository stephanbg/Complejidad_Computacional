#include "./MT_MultiCinta.h"

bool MaquinaTuringMultiCinta::procesar(const std::string& kCadena) const {

}

void MaquinaTuringMultiCinta::mostrar() const {
  std::cout << "Máquina de Turing MultiCinta" << std::endl;
  MaquinaTuring::mostrar();
}

void MaquinaTuringMultiCinta::escribir(const char kSimbolo) { /// No estoy seguro si crece o algo
  //if (posicionCabezal_ < 0) posicionCabezal_ = 0;
  //if (posicionCabezal_ >= cinta_.size()) cinta_.resize(posicionCabezal_ + 1, simboloBlanco_);
  //cinta_[posicionCabezal_] = kSimbolo;
}

char MaquinaTuringMultiCinta::leer() const {
  //if (posicionCabezal_ < 0 || posicionCabezal_ >= cinta_.size()) return simboloBlanco_;
  //return cinta_[posicionCabezal_];
}