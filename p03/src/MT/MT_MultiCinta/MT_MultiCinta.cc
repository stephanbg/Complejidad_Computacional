#include "./MT_MultiCinta.h"

MaquinaTuringMultiCinta::MaquinaTuringMultiCinta(const int kNumCintas) {
  numCintas_ = kNumCintas;
  cintas_.resize(numCintas_);
}

bool MaquinaTuringMultiCinta::procesar(const std::string& kCadena) {
  rellenarCintas(kCadena);
  bool esAceptada = false, transicionEncontrada = true;
  Estado estadoActual = estadoInicial_;
  size_t contador = 0;
  while (!esAceptada && transicionEncontrada) {
    std::vector<char> simbolosLeidos;
    for (const auto& cinta : cintas_) simbolosLeidos.push_back(cinta.leer());
    auto transiciones = transiciones_.find(estadoActual);
    if (transiciones == transiciones_.end()) break; // No hay más transiciones, terminar
    transicionEncontrada = false;
    for (const auto& kTransicion : transiciones->second) {
      TransicionMultiCinta* transicion = dynamic_cast<TransicionMultiCinta*>(kTransicion);
      if (transicion->getSimbolosALeer() == simbolosLeidos) {
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
    if (contador++ == 20) exit(EXIT_FAILURE);
  }
  return esAceptada;
}

void MaquinaTuringMultiCinta::rellenarCintas(const std::string& kCadenas) {
  std::vector<std::string> cadenas;
  std::string cadenaTemporal;
  int contarPuntos = 0;
  for (size_t i = 0; i < kCadenas.size(); ++i) {
    const char kSimbolo = kCadenas[i];
    if (kSimbolo == '.') {
      if (!cadenaTemporal.empty()) {
        cadenas.push_back(cadenaTemporal);
        cadenaTemporal.clear();
      }
      if (++contarPuntos == 2) {
        cadenas.push_back(".");
        contarPuntos = 0;
      }
    } else {
      cadenaTemporal.push_back(kSimbolo);
      contarPuntos = 0;
    }
  }
  if (!cadenaTemporal.empty()) cadenas.push_back(cadenaTemporal);
  const int kCadenasSize = cadenas.size();
  if (kCadenasSize > numCintas_) {
    const std::string kErrorNumCadenasEnCinta = "No pueden haber más cadenas que cintas.";
    throw (kErrorNumCadenasEnCinta);
  }
  for (size_t i = 0; i < numCintas_; ++i) {
    if (i < kCadenasSize && cadenas[i] != ".") cintas_[i].iniciar(cadenas[i]);
    else cintas_[i].rellenarDeBlancos();
  }
}

void MaquinaTuringMultiCinta::mostrarMT() const {
  std::cout << "Máquina de Turing MultiCinta" << std::endl;
  MaquinaTuring::mostrarMT();
}

void MaquinaTuringMultiCinta::mostrarCintas() const {
  for (size_t i = 0; i < cintas_.size(); ++i) {
    std::cout << "Cinta " << i + 1 << ": ";
    cintas_[i].imprimir();
    std::cout << "Posicion Cabezal: " << cintas_[i].getPosicionCabezal() << std::endl;
  }  
}