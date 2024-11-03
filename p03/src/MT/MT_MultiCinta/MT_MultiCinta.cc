/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Curso: 4º
 * Práctica 3: Programar un simulador de una Máquina de Turing determinista
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Octubre de 2024
 * @file MT_MultiCinta.cc
 * @brief Implementación de la clase MaquinaTuringMultiCinta.
 *
 * Esta clase extiende la funcionalidad de la clase MaquinaTuring
 * para manejar máquinas de Turing con múltiples cintas.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./MT_MultiCinta.h"

/**
 * @brief Constructor de la máquina de Turing multi cinta.
 * @param kNumCintas Número de cintas de la máquina.
 */
MaquinaTuringMultiCinta::MaquinaTuringMultiCinta(const int kNumCintas) {
  numCintas_ = kNumCintas;
  cintas_.resize(numCintas_);
}

/**
 * @brief Procesar una cadena de entrada.
 * @param kCadena Cadena a procesar.
 * @return true Si la cadena es aceptada.
 * @return false Si la cadena es rechazada.
 */
bool MaquinaTuringMultiCinta::procesar(const std::string& kCadena) {
  rellenarCintas(kCadena);
  bool transicionEncontrada = true;
  Estado estadoActual = estadoInicial_;
  while (!estadoActual.esEstadoAceptacion() && transicionEncontrada) {
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
  }
  return estadoActual.esEstadoAceptacion();
}

/**
 * @brief Rellenar las cintas con la cadena de entrada.
 * @param kCadenas Cadena a utilizar para rellenar las cintas.
 */
void MaquinaTuringMultiCinta::rellenarCintas(const std::string& kCadenas) {
  std::vector<std::string> cadenas;
  std::string cadenaTemporal;
  const std::string kBlanco = std::string(1, simboloBlanco_);
  int contarPuntos = 0;
  for (size_t i = 0; i < kCadenas.size(); ++i) {
    const char kSimbolo = kCadenas[i];
    if (kSimbolo == simboloBlanco_) {
      if (!cadenaTemporal.empty()) {
        cadenas.push_back(cadenaTemporal);
        cadenaTemporal.clear();
      }
      if (++contarPuntos == 2) {
        cadenas.push_back(kBlanco);
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
    if (i < kCadenasSize && cadenas[i] != kBlanco) cintas_[i].iniciar(cadenas[i]);
    else cintas_[i].rellenarDeBlancos();
  }
}

/**
 * @brief Mostrar la configuración de la máquina de Turing multi cinta.
 */
void MaquinaTuringMultiCinta::mostrarMT() const {
  std::cout << "Máquina de Turing MultiCinta" << std::endl;
  MaquinaTuring::mostrarMT();
}

/**
 * @brief Mostrar el contenido de las cintas.
 */
void MaquinaTuringMultiCinta::mostrarCintas() const {
  for (size_t i = 0; i < cintas_.size(); ++i) {
    std::cout << "Cinta " << i + 1 << ": ";
    cintas_[i].imprimir();
  }  
}