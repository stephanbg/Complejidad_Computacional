#include "./MT_MultiCinta.h"

MaquinaTuringMultiCinta::MaquinaTuringMultiCinta(const int kNumCintas) {
  numCintas_ = kNumCintas;
  cintas_.resize(numCintas_);
}

bool MaquinaTuringMultiCinta::procesar(const std::string& kCadena) {
  cintas_[0].iniciar(kCadena);
  for (size_t i = 1; i < numCintas_; ++i) {
    cintas_[i].rellenarDeBlancos(cintas_[0].getCinta().size());
  }
  bool esAceptada = false, transicionEncontrada = true;
  Estado estadoActual = estadoInicial_;
  while (!esAceptada && transicionEncontrada) {
    std::vector<char> simbolosLeidos;
    for (const auto& cinta : cintas_) simbolosLeidos.push_back(cinta.leer());
    auto transiciones = transiciones_.find(estadoActual);
    if (transiciones == transiciones_.end()) break; // No hay más transiciones, terminar
    transicionEncontrada = false;
    for (const auto& kTransicion : transiciones->second) {
      TransicionMultiCinta* transicion = dynamic_cast<TransicionMultiCinta*>(kTransicion);
      if (transicion->getSimbolosALeer() != simbolosLeidos) break;
      for (size_t i = 0; i < numCintas_; ++i) {
        cintas_[i].escribir(transicion->getSimbolosAEscribir()[i]);
        cintas_[i].moverCabezal(transicion->getMovimientosARealizar()[i]);
      }
      estadoActual = transicion->getEstadoFin();
      transicionEncontrada = true;
      break;
    }
  }
  if (estadosFinales_.count(estadoActual)) esAceptada = true;
  return esAceptada;
}

void MaquinaTuringMultiCinta::mostrarMT() const {
  std::cout << "Máquina de Turing MultiCinta" << std::endl;
  MaquinaTuring::mostrarMT();
}

void MaquinaTuringMultiCinta::mostrarCinta() const {
  for (size_t i = 0; i < cintas_.size(); ++i) {
    std::cout << "Cinta " << i << ": ";
    cintas_[i].imprimir();
  }  
}