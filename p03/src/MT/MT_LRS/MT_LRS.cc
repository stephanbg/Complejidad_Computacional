#include "./MT_LRS.h"

bool MaquinaTuringLRS::procesar(const std::string& kCadena) {
  cinta_.iniciar(kCadena);
  bool esAceptada = false, transicionEncontrada = true;
  Estado estadoActual = estadoInicial_;
  while (!esAceptada && transicionEncontrada) {
    const char kSimboloActual = cinta_.leer();    
    auto transiciones = transiciones_.find(estadoActual);
    // No hay más transiciones, terminar procesamiento
    if (transiciones == transiciones_.end()) break;
    transicionEncontrada = false;
    for (const auto& kTransicion : transiciones->second) {
      TransicionCintaUnicaLRS* transicionLRS = dynamic_cast<TransicionCintaUnicaLRS*>(kTransicion);
      if (transicionLRS->getSimboloALeer() == kSimboloActual) {
        cinta_.escribir(transicionLRS->getSimboloAEscribir());
        cinta_.moverCabezal(transicionLRS->getMovimientoARealizar());
        estadoActual = transicionLRS->getEstadoFin();  
        transicionEncontrada = true;
        break;
      }
    }
    if (estadosFinales_.count(estadoActual)) esAceptada = true;
  }
  return esAceptada;
}

void MaquinaTuringLRS::mostrarMT() const {
  std::cout << "Máquina de Turing LRS" << std::endl;
  MaquinaTuring::mostrarMT();
}

void MaquinaTuringLRS::mostrarCintas() const {
  std::cout << "Cinta: ";
  cinta_.imprimir();
}