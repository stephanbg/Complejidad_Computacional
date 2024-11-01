#include "./transicionCintaUnicaLRS.h"

void TransicionCintaUnicaLRS::mostrar() const {
  std::cout << "δ (" << estadoIni_ << ", " << simboloLeido_ << ") = ("
  << estadoFin_ << ", " << simboloEscrito_ << ", " << movimiento_ << ")" << std::endl;
}