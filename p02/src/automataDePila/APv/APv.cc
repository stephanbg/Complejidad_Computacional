#include "./APv.h"

bool APv::seAceptaCadena(const std::string& kCadena) {
  for (const char c : kCadena) {
    if (alfabeto_.getConjuntoAlfabeto().count(c) == 0) return false;
  }
  // 1. Inicializar la pila con el símbolo inicial de la pila.
  pila_ = std::stack<char>();
  pila_.push(simboloInicialPila_);
  // 2. Definir una función auxiliar (recursiva) para explorar las transiciones.
  std::function<bool(size_t, Estado, std::stack<char>)> explorar = [&](size_t indiceCadena, Estado estadoActual, std::stack<char> pila) {
    // 3. Salta los puntos ('.') en la cadena de entrada
    while (indiceCadena < kCadena.size() && kCadena[indiceCadena] == '.') indiceCadena++;    
    // 4. Comprobar si hemos procesado toda la cadena.
    if (indiceCadena == kCadena.size()) {
      #ifdef TRAZA
        std::cout << "----------------------------------------" << std::endl;
        std::cout << std::left << std::setw(20) << "Estado final:" 
                  << estadoActual << std::endl;
        std::cout << std::left << std::setw(20) << "Cadena procesada:" 
                  << kCadena << std::endl;
        std::cout << std::left << std::setw(20) << "Pila final:";
        mostrarPila(pila);
      #endif     
      return pila.empty();
    }
    // 5. Recorrer las transiciones disponibles desde el estado actual.
    for (const Transicion& cadaTransicion : transiciones_) {
      // 6. Comprobar si la transición es válida.
      if (cadaTransicion.getEstadoOrigen() == estadoActual && 
        ((cadaTransicion.getSimboloTransicion() == kCadena[indiceCadena] || cadaTransicion.getSimboloTransicion() == '.') && 
        ((!pila.empty() && pila.top() == cadaTransicion.getElementoAExtraerDePila()) || cadaTransicion.getElementoAExtraerDePila() == '.'))) {
        #ifdef TRAZA
          const std::string kCopiaCadena = kCadena.substr(indiceCadena, kCadena.size());
          std::cout << "----------------------------------------" << std::endl;
          std::cout << std::left << std::setw(15) << "Estado:" 
                    << estadoActual << std::endl;
          std::cout << std::left << std::setw(15) << "Cadena:" 
                    << kCopiaCadena << std::endl;
          std::cout << std::left << std::setw(15) << "Pila:";
          mostrarPila(pila);
          std::cout << std::left << std::setw(15) << "Transición:" 
                    << cadaTransicion;
        #endif          
        // 7. Actualizar el estado actual al estado destino de la transición.
        Estado nuevoEstado = cadaTransicion.getEstadoDestino();
        // 8. Realizar el pop en la pila si es necesario.
        if (!pila.empty() && cadaTransicion.getElementoAExtraerDePila() != '.') pila.pop();
        /*for (int i = cadaTransicion.getSimbolosAIntroducirEnPila().size() - 1; i >= 0; --i) {
          const char kSimbolo = cadaTransicion.getSimbolosAIntroducirEnPila()[i];
          if (kSimbolo != '.') pila.push(kSimbolo);
        }*/
        for (auto c : cadaTransicion.getSimbolosAIntroducirEnPila()) {
          if (c != '.') pila.push(c);
        }
        // NO SE SI TENGO QUE ELIMINAR LOS PUNTOS PREVIAMENTE DE LA CADENA O CUANDO LOS LEA TRANSITAR PERO NO CONTAR O ALGO
        if (cadaTransicion.getSimboloTransicion() != '.'/* || kCadena[indiceCadena] == '.'*/) indiceCadena++;
        // 9. Llamar recursivamente a la función auxiliar para procesar el siguiente símbolo de la cadena.
        if (explorar(indiceCadena, nuevoEstado, pila)) return true;
      }
    }
    // 10. Si no se encontraron transiciones válidas, retornar false.
    return false;
  };
  // 11. Llamar a la función auxiliar comenzando desde el primer símbolo de la cadena.
  return explorar(0, estadoInicial_, pila_);
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