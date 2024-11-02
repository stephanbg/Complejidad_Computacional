#include "./cinta.h"

void Cinta::iniciar(const std::string& kCadena) {
  posicionCabezal_ = 1;
  cinta_.clear();
  cinta_.push_back(simboloBlanco_);
  for (char c : kCadena) cinta_.push_back(c);
  cinta_.push_back(simboloBlanco_);
}

void Cinta::rellenarDeBlancos() {
  posicionCabezal_ = 1;
  cinta_.clear();
  cinta_.resize(3, simboloBlanco_);
}

void Cinta::escribir(const char kSimbolo) {
  if (posicionCabezal_ < 0) {
    cinta_.insert(cinta_.begin(), kSimbolo);
    posicionCabezal_ = 0;
  } else if (posicionCabezal_ >= cinta_.size()) cinta_.push_back(kSimbolo);
  else cinta_[posicionCabezal_] = kSimbolo;
}

const char Cinta::leer() const {
  if (posicionCabezal_ < 0 || posicionCabezal_ >= cinta_.size()) return simboloBlanco_;
  return cinta_[posicionCabezal_];
}

void Cinta::moverCabezal(const Direccion& kDir) {
  if (kDir.getValor() == Direccion::IZQUIERDA) posicionCabezal_--;
  else if (kDir.getValor() == Direccion::DERECHA) posicionCabezal_++;
}

void Cinta::imprimir() const {
  std::cout << "|";
  for (auto a : cinta_) {
    std::cout << a << "|";
  }
  std::cout << std::endl;
}