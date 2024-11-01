/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 3:
 *
 * @author Stephan Brommer Gutiérrez
 * @since 31 de Octubre de 2024
 * @file comprobarFicheroMT_LRS.cc
 * @brief
 */

#include "./comprobarFicheroMT_LRS.h"

ComprobarFicheroMT_LRS::ComprobarFicheroMT_LRS(const std::string& kNombreFichero) {
  maquinaTuring_ = new MaquinaTuringLRS;
  analizarFicheroMT(kNombreFichero);
}

void ComprobarFicheroMT_LRS::analizarFicheroMT(const std::string& kNombreFichero) {
  ComprobarFicheroMT::analizarFicheroMT(kNombreFichero);
}

void ComprobarFicheroMT_LRS::analizarYRellenarTransiciones(const std::string& kLinea) {
  std::istringstream iss(kLinea);
  std::string estadoActualStr, simboloLeidoStr, estadoDestinoStr, simboloEscritoStr, movimientoStr;
  // Comprobar si se han leído todos los elementos
  if (!(iss >> estadoActualStr >> simboloLeidoStr >> estadoDestinoStr >> simboloEscritoStr >> movimientoStr)) {
    const std::string kErrorFormato = "Pocos elementos en alguna transición.";
    throw (kErrorFormato);
  }
  // Comprobar si hay más elementos en el flujo
  std::string extraElemento;
  if (iss >> extraElemento) {
    const std::string kErrorExcesoElementos = "Demasiados elementos en alguna transición.";
    throw (kErrorExcesoElementos);
  }  
  Estado estadoActual(estadoActualStr);
  // Comprobar si el estado actual existe
  if (maquinaTuring_->getEstados().find(estadoActual) == maquinaTuring_->getEstados().end()) {
    const std::string kErrorEstadoActual = "Estado actual (" + estadoActualStr + ") no existe.";
    throw (kErrorEstadoActual);
  }
  // Comprobar si el símbolo leído es válido
  if (simboloLeidoStr.size() != 1) {
    const std::string kErrorSizeSimboloLeido = "Símbolo leído (" + simboloLeidoStr + ") tamaño != 1";
    throw (kErrorSizeSimboloLeido);
  } else if (
    maquinaTuring_->getAlfabetoCinta().getConjuntoAlfabeto().find(simboloLeidoStr[0]) == 
    maquinaTuring_->getAlfabetoCinta().getConjuntoAlfabeto().end()
  ) {
    const std::string kErrorSimboloLeido = "Símbolo leído (" + simboloLeidoStr + ") no está en el alfabeto de la cinta.";
    throw (kErrorSimboloLeido);
  }
  Estado estadoDestino(estadoDestinoStr);
  // Comprobar si el estado destino existe
  if (maquinaTuring_->getEstados().find(estadoDestino) == maquinaTuring_->getEstados().end()) {
    const std::string kErrorEstadoDestino = "Estado destino (" + estadoDestinoStr + ") no existe.";
    throw (kErrorEstadoDestino);
  }
  // Comprobar si el símbolo escrito es válido
  if (simboloEscritoStr.size() != 1) {
    const std::string kErrorSizeSimboloEscrito = "Símbolo escrito (" + simboloEscritoStr + ")tamaño != 1";
    throw (kErrorSizeSimboloEscrito);
  } else if (
    (maquinaTuring_->getAlfabetoEntrada().getConjuntoAlfabeto().find(simboloEscritoStr[0]) == 
    maquinaTuring_->getAlfabetoEntrada().getConjuntoAlfabeto().end()) &&
    simboloEscritoStr[0] != maquinaTuring_->getSimboloBlanco()
  ) {
    const std::string kErrorSimboloEscrito = "Símbolo escrito (" + simboloEscritoStr + ") no está en el alfabeto de entrada.";
    throw (kErrorSimboloEscrito);
  }
  // Comprobar si es válido el movimiento
  Direccion movimiento;
  if (movimientoStr == "L") movimiento = Direccion::IZQUIERDA;
  else if (movimientoStr == "R") movimiento = Direccion::DERECHA;
  else if (movimientoStr == "S") movimiento = Direccion::QUIETO;
  else {
    const std::string kErrorMovimiento = "Movimiento (" + movimientoStr + ") no es válido.";
    throw kErrorMovimiento;
  }
  Transicion* nuevaTransicion = new TransicionCintaUnicaLRS(
    estadoActual, simboloLeidoStr[0], estadoDestino, simboloEscritoStr[0], movimiento
  );
  // Comprobar si ya existe una transición igual
  for (const auto& [_, vTransicion] : maquinaTuring_->getTransiciones()) {
    for (const auto& kTransicion : vTransicion) {
      TransicionCintaUnicaLRS* transicionLRS = dynamic_cast<TransicionCintaUnicaLRS*>(kTransicion);
      if (transicionLRS != nullptr && // Comprobar que el cast fue exitoso
        transicionLRS->getEstadoIni() == estadoActual &&
        transicionLRS->getSimboloLeido() == simboloLeidoStr[0] &&
        transicionLRS->getEstadoFin() == estadoDestino &&
        transicionLRS->getSimboloEscrito() == simboloEscritoStr[0] &&
        transicionLRS->getMovimiento() == movimiento) {
        delete nuevaTransicion; // Liberar memoria en caso de error
        const std::string kErrorDuplicado = "Transición duplicada";
        throw (kErrorDuplicado);
      }
    }
  }
  // Agregar la nueva transición
  maquinaTuring_->agregarTransicion(estadoActual, nuevaTransicion);
}
