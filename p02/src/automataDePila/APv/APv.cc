#include "./APv.h"

bool APv::seAceptaCadena(const std::string& kCadena) const {
  for (const char c : kCadena) {
    if (alfabeto_.getConjuntoAlfabeto().count(c) == 0) return false;
  }
  // 1. Inicializar la pila con el símbolo inicial de la pila.
  std::stack<char> pila;
  pila.push(simboloInicialPila_);
  // 2. Establecer el estado actual como el estado inicial del autómata.
  // 3. Definir una función auxiliar (recursiva) para explorar las transiciones.
  std::function<bool(size_t, Estado, std::stack<char>)> explorar = [&](size_t indiceCadena, Estado estadoActual, std::stack<char> pila) {
    // Salta los puntos ('.') en la cadena de entrada
    while (indiceCadena < kCadena.size() && kCadena[indiceCadena] == '.') indiceCadena++;    
    // 4. Comprobar si hemos procesado toda la cadena.
    if (indiceCadena == kCadena.size()) return pila.empty();
    // 6. Recorrer las transiciones disponibles desde el estado actual.
    for (const Transicion& cadaTransicion : transiciones_) {
      // 7. Comprobar si la transición es válida.
      if (cadaTransicion.getEstadoOrigen() == estadoActual && 
        ((cadaTransicion.getSimboloTransicion() == kCadena[indiceCadena] || cadaTransicion.getSimboloTransicion() == '.') && 
        ((!pila.empty() && pila.top() == cadaTransicion.getElementoAExtraerDePila()) || cadaTransicion.getElementoAExtraerDePila() == '.'))) {
        // 8. Actualizar el estado actual al estado destino de la transición.
        Estado nuevoEstado = cadaTransicion.getEstadoDestino();
        // 9. Realizar el pop en la pila si es necesario.
        if (!pila.empty() && cadaTransicion.getElementoAExtraerDePila() != '.') pila.pop();
        for (const char c : cadaTransicion.getSimbolosAIntroducirEnPila()) {
          if (c != '.') pila.push(c);
        }
        // NO SE SI TENGO QUE ELIMINAR LOS PUNTOS PREVIAMENTE DE LA CADENA O CUANDO LOS LEA TRANSITAR PERO NO CONTAR O ALGO
        if (cadaTransicion.getSimboloTransicion() != '.'/* || kCadena[indiceCadena] == '.'*/) indiceCadena++;
        // 10. Llamar recursivamente a la función auxiliar para procesar el siguiente símbolo de la cadena.
        if (explorar(indiceCadena, nuevoEstado, pila)) return true;
      }
    }
    // 11. Si no se encontraron transiciones válidas, retornar false.
    return false;
  };
  // 12. Llamar a la función auxiliar comenzando desde el primer símbolo de la cadena.
  return explorar(0, estadoInicial_, pila);
}

std::ostream& operator<<(std::ostream& os, const APv& kAutomata) {
  os << "Autómata por Vacíado de Pila" << std::endl;
  os << "----------------------------" << std::endl;
  os << "Estados: {";
  bool primero = true;
  for (const auto& kEstado : kAutomata.estados_) {
    if (!primero) os << ", ";
    os << kEstado;
    primero = false;
  }
  os << "}" << std::endl;
  os << "Alfabeto: " << kAutomata.alfabeto_;
  os << "Alfabeto Pila: " << kAutomata.alfabetoPila_;
  os << "Estado Inicial: " << kAutomata.estadoInicial_ << std::endl;
  os << "Símbolo Inicial Pila: " << kAutomata.simboloInicialPila_ << std::endl;
  os << "Transiciones:\n";
  for (const auto& kTransicion : kAutomata.transiciones_) { os << kTransicion; }
  os << std::endl;
  return os;
}