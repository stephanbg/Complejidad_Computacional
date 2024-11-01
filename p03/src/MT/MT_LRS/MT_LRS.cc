#include "./MT_LRS.h"

bool MaquinaTuringLRS::procesar(const std::string& kCadena) {
  inicializarCinta(kCadena);
  bool esAceptada = false, transicionEncontrada = true;
  Estado estadoActual = estadoInicial_;
  while (!esAceptada && transicionEncontrada) {
    const char kSimboloActual = leer();    
    auto transiciones = transiciones_.find(estadoActual);
    // No hay más transiciones, terminar procesamiento
    if (transiciones == transiciones_.end()) break;
    transicionEncontrada = false;
    for (const auto& kTransicion : transiciones->second) {
      TransicionCintaUnicaLRS* transicionLRS = dynamic_cast<TransicionCintaUnicaLRS*>(kTransicion);
      if (transicionLRS->getSimboloALeer() == kSimboloActual) {
        escribir(transicionLRS->getSimboloAEscribir());
        moverCabezal(transicionLRS->getMovimientoARealizar());
        estadoActual = transicionLRS->getEstadoFin();  
        transicionEncontrada = true;
        break;
      }
    }
    if (estadosFinales_.count(estadoActual)) esAceptada = true;
  }
  return esAceptada;
}

void MaquinaTuringLRS::escribir(const char kSimbolo) {
  if (posicionCabezal_ < 0) {
    cinta_.insert(cinta_.begin(), kSimbolo);
    posicionCabezal_ = 0;
  } else if (posicionCabezal_ >= cinta_.size()) cinta_.push_back(kSimbolo);
  else cinta_[posicionCabezal_] = kSimbolo;
}


char MaquinaTuringLRS::leer() const {
  if (posicionCabezal_ < 0 || posicionCabezal_ >= cinta_.size()) return simboloBlanco_;
  return cinta_[posicionCabezal_];
}

void MaquinaTuringLRS::inicializarCinta(const std::string& kCadena) {
  posicionCabezal_ = 1;
  cinta_.clear();
  cinta_.push_back('.');
  for (char c : kCadena) cinta_.push_back(c);
  cinta_.push_back('.');
}

void MaquinaTuringLRS::moverCabezal(const Direccion& kDir) {
  MaquinaTuring::moverCabezal(kDir);
}

void MaquinaTuringLRS::mostrar() const {
  std::cout << "Máquina de Turing LRS" << std::endl;
  MaquinaTuring::mostrar();
}

void MaquinaTuringLRS::imprimirCinta() const {
  std::cout << "Cinta: |";
  for (auto a : cinta_) {
    std::cout << a << "|";
  }
  std::cout << std::endl;
}