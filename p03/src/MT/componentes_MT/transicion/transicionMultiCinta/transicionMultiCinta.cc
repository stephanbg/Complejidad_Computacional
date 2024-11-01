#include "./transicionMultiCinta.h"

void TransicionMultiCinta::mostrar() const {
  std::cout << "δ (" << estadoIni_ << ", ";
  for (size_t i = 0; i < simbolosLeidos_.size(); ++i) {
    std::cout << simbolosLeidos_[i];
    if (i < simbolosLeidos_.size() - 1) std::cout << ", ";
  }
  std::cout << ") = (" << estadoFin_ << ", ";
  for (size_t i = 0; i < simbolosEscritos_.size(); ++i) {
    std::cout << simbolosEscritos_[i];
    if (i < simbolosEscritos_.size() - 1) std::cout << ", ";
  }
  std::cout << ", ";
  for (size_t i = 0; i < movimientos_.size(); ++i) {
    std::cout << movimientos_[i];
    if (i < movimientos_.size() - 1) std::cout << ", ";
  }
  std::cout << ")" << std::endl;
}