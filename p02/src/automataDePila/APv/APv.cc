#include "./APv.h"

bool APv::seAceptaCadena(const std::string& kCadena) {
  // Verificar si todos los caracteres de la cadena están en el alfabeto
  for (const char c : kCadena) {
    if (alfabeto_.getConjuntoAlfabeto().count(c) == 0) return false;
  }
  // Inicializar la pila y agregar el símbolo inicial
  pila_ = std::stack<char>();
  pila_.push(simboloInicialPila_);
  // Definir la función recursiva explorar
  std::function<bool(size_t, const Estado*, std::stack<char>)> explorar = [&](size_t indiceCadena, const Estado* estadoActual, std::stack<char> pila) {
    // Saltar los caracteres '.' en la cadena
    while (indiceCadena < kCadena.size() && kCadena[indiceCadena] == '.') indiceCadena++;
    // Si hemos procesado toda la cadena y la pila está vacía, la cadena es aceptada
    if (indiceCadena == kCadena.size() && pila.empty()) {
      mostrarTraza(estadoActual, "", pila, Transicion());
      return true;
    }
    // Si la pila está vacía pero no hemos terminado la cadena, devolver falso
    if (pila.empty()) {
      mostrarTraza(estadoActual, kCadena.substr(indiceCadena, kCadena.size()), pila, Transicion());
      return false;
    }
    // Obtener el símbolo actual de la cadena
    const char simbolo = (indiceCadena < kCadena.size()) ? kCadena[indiceCadena] : '.';
    const char kTopPila = pila.top(); // Obtener el elemento en la parte superior de la pila
    // Iterar sobre las transiciones del estado actual
    for (const Transicion& kTransicion : estadoActual->getTransiciones()) {
      const char kSimboloTransicion = kTransicion.getSimboloTransicion();
      const char kElementoAExtraer = kTransicion.getElementoAExtraerDePila();
      // Verificar si la transición es válida
      if ((kSimboloTransicion == simbolo || kSimboloTransicion == '.') && 
          (kTopPila == kElementoAExtraer || kElementoAExtraer == '.')) {
        mostrarTraza(estadoActual, kCadena.substr(indiceCadena, kCadena.size()), pila, kTransicion);
        pila.pop();
        std::stack<char> pilaTemp = pila;
        // Agregar los símbolos que se introducirán en la pila
        const std::string& kSimbolosAInsertar = kTransicion.getSimbolosAIntroducirEnPila();
        for (auto it = kSimbolosAInsertar.rbegin(); it != kSimbolosAInsertar.rend(); ++it) {
          if (*it != '.') pilaTemp.push(*it);
        }
        // Llamar recursivamente a explorar con el nuevo estado y pila
        if (explorar(indiceCadena + (kTransicion.getSimboloTransicion() != '.'), kTransicion.getEstadoDestino(), pilaTemp)) return true;
        pila.push(kTopPila); // Restaurar la pila original en caso de que la exploración no tenga éxito
      }
    }
    return false; // Si no se encontró una transición válida, devolver falso
  };
  return explorar(0, estadoInicial_, pila_); // Iniciar la exploración desde el estado inicial y la pila
}

std::ostream& operator<<(std::ostream& os, const APv& kAutomata) {
  os << "Autómata por Vacíado de Pila" << std::endl;
  os << "----------------------------" << std::endl;
  os << "Estados: {";
  bool primero = true;
  for (const auto& kEstado : kAutomata.estados_) {
    if (!primero) os << ", ";
    os << *kEstado;
    primero = false;
  }
  os << "}" << std::endl;
  os << "Alfabeto: " << kAutomata.alfabeto_;
  os << "Alfabeto Pila: " << kAutomata.alfabetoPila_;
  os << "Estado Inicial: " << *kAutomata.estadoInicial_ << std::endl;
  os << "Símbolo Inicial Pila: " << kAutomata.simboloInicialPila_ << std::endl;
  os << "Transiciones:\n";
  for (const Estado* kEstado : kAutomata.estados_) {
    for (const Transicion& kTransicion : kEstado->getTransiciones()) os << kTransicion;
  }
  os << std::endl;
  return os;
}