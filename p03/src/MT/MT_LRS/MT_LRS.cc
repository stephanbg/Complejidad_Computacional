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
 * @file MT_LRS.cc
 * @brief Implementación de la clase MaquinaTuringLRS.
 *
 * Esta clase extiende la funcionalidad de la clase MaquinaTuring
 * para manejar máquinas de Turing con una cinta que procesan
 * cadenas en una dirección específica (LRS), escriben y se mueven
 * simultáneamente, y la cinta es infinita en ambas direcciones.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./MT_LRS.h"

/**
 * @brief Procesar una cadena de entrada.
 * @param kCadena Cadena a procesar.
 * @return true Si la cadena es aceptada.
 * @return false Si la cadena es rechazada.
 */
bool MaquinaTuringLRS::procesar(const std::string& kCadena) {
  cinta_.iniciar(kCadena);
  bool transicionEncontrada = true;
  Estado estadoActual = estadoInicial_;
  while (!estadoActual.esEstadoAceptacion() && transicionEncontrada) {
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
  }
  return estadoActual.esEstadoAceptacion();
}

/**
 * @brief Mostrar la configuración de la máquina de Turing LRS.
 */
void MaquinaTuringLRS::mostrarMT() const {
  std::cout << "Máquina de Turing LRS" << std::endl;
  MaquinaTuring::mostrarMT();
}

/**
 * @brief Mostrar el contenido de la cinta.
 */
void MaquinaTuringLRS::mostrarCintas() const {
  std::cout << "Cinta: ";
  cinta_.imprimir();
}