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

#include "./comprobarFicheroMT_MultiCinta.h"

ComprobarFicheroMT_MultiCinta::ComprobarFicheroMT_MultiCinta(
  const std::string& kNombreFichero, const int kNumCintas
) {
  maquinaTuring_ = new MaquinaTuringMultiCinta(kNumCintas);
  analizarFicheroMT(kNombreFichero);
}

void ComprobarFicheroMT_MultiCinta::analizarFicheroMT(const std::string& kNombreFichero) {
  ComprobarFicheroMT::analizarFicheroMT(kNombreFichero);
}

void ComprobarFicheroMT_MultiCinta::analizarYRellenarTransiciones(const std::string& kLinea) {
  const int kNumCintas = maquinaTuring_->getNumCintas();
  std::istringstream iss(kLinea);
  std::string estadoActualStr, estadoDestinoStr;
  std::vector<std::string> simbolosLeidosStr(kNumCintas);
  std::vector<std::string> simbolosEscritosStr(kNumCintas);
  std::vector<std::string> movimientosStr(kNumCintas);
  // Estado actual
  if (!(iss >> estadoActualStr)) {
    const std::string kErrorFaltaEstadoActual = "Falta el estado actual.";
    throw (kErrorFaltaEstadoActual);
  }
  Estado estadoActual(estadoActualStr);
  if (maquinaTuring_->getEstados().find(estadoActual) == maquinaTuring_->getEstados().end()) {
    const std::string kErrorEstadoActual = "Estado actual (" + estadoActualStr + ") no existe.";
    throw (kErrorEstadoActual);
  }  
  // Símbolos a leer
  for (int i = 0; i < kNumCintas; ++i) {
    if (!(iss >> simbolosLeidosStr[i])) {
      const std::string kErrorFaltaSimbLeido = "Falta un símbolo leído para la cinta " + std::to_string(i + 1);
      throw (kErrorFaltaSimbLeido);
    } 
    if (simbolosLeidosStr[i].size() != 1) {
      const std::string kErrorSizeSimboloLeido = "Símbolo leído (" + simbolosLeidosStr[i] + ") tamaño != 1";
      throw (kErrorSizeSimboloLeido);
    } else if (
      maquinaTuring_->getAlfabetoCinta().getConjuntoAlfabeto().find(simbolosLeidosStr[i][0]) == 
      maquinaTuring_->getAlfabetoCinta().getConjuntoAlfabeto().end()
    ) {
      const std::string kErrorSimboloLeido = "Símbolo leído (" + simbolosLeidosStr[i] + ") no está en el alfabeto de la cinta.";
      throw (kErrorSimboloLeido);
    }
  }
  // Estado destino
  if (!(iss >> estadoDestinoStr)) {
    const std::string kErrorFaltaEstadoDestino = "Falta el estado destino.";
    throw (kErrorFaltaEstadoDestino);
  }
  Estado estadoDestino(estadoDestinoStr);
  if (maquinaTuring_->getEstados().find(estadoDestino) == maquinaTuring_->getEstados().end()) {
    const std::string kErrorEstadoDestino = "Estado destino (" + estadoDestinoStr + ") no existe.";
    throw (kErrorEstadoDestino);
  }  
  // Símbolos a escribir
  for (int i = 0; i < kNumCintas; ++i) {  
    if (!(iss >> simbolosEscritosStr[i])) {
      const std::string kErrorFaltaSimbEscrito = "Falta un símbolo escrito para la cinta " + std::to_string(i + 1);
      throw (kErrorFaltaSimbEscrito);
    }
    if (simbolosEscritosStr[i].size() != 1) {
      const std::string kErrorSizeSimboloEscrito = "Símbolo escrito (" + simbolosEscritosStr[i] + ") tamaño != 1";
      throw (kErrorSizeSimboloEscrito);
    } else if (
      maquinaTuring_->getAlfabetoCinta().getConjuntoAlfabeto().find(simbolosEscritosStr[i][0]) == 
      maquinaTuring_->getAlfabetoCinta().getConjuntoAlfabeto().end()
    ) {
      const std::string kErrorSimboloEscrito = "Símbolo escrito (" + simbolosEscritosStr[i] + ") no está en el alfabeto de entrada.";
      throw (kErrorSimboloEscrito);
    }    
  }
  // Movimientos a realizar
  std::vector<Direccion> movimientos(kNumCintas);
  for (int i = 0; i < kNumCintas; ++i) {    
    if (!(iss >> movimientosStr[i])) {
      const std::string kErrorFaltaMovimiento = "Falta un movimiento para la cinta " + std::to_string(i + 1);
      throw (kErrorFaltaMovimiento);
    } 
    if (movimientosStr[i] == "L") movimientos[i] = Direccion::IZQUIERDA;
    else if (movimientosStr[i] == "R") movimientos[i] = Direccion::DERECHA;
    else if (movimientosStr[i] == "S") movimientos[i] = Direccion::QUIETO;
    else {
      const std::string kErrorMovimiento = "Movimiento (" + movimientosStr[i] + ") no es válido.";
      throw kErrorMovimiento;
    }       
  } 
  // Comprobar si hay más elementos en el flujo
  std::string extraElemento;
  if (iss >> extraElemento) {
    const std::string kErrorExcesoElementos = "Demasiados elementos en alguna transición.";
    throw (kErrorExcesoElementos);
  }
  // Crear transicion
  std::vector<char> simbolosLeidos;
  std::vector<char> simbolosEscritos;
  for (int i = 0; i < kNumCintas; ++i) {
    simbolosLeidos.push_back(simbolosLeidosStr[i][0]);
    simbolosEscritos.push_back(simbolosEscritosStr[i][0]);
  }
  Transicion* nuevaTransicion = new TransicionMultiCinta(
    estadoActual, simbolosLeidos, estadoDestino, simbolosEscritos, movimientos
  );
  // Comprobar si ya existe una transición igual
  for (const auto& [_, vTransicion] : maquinaTuring_->getTransiciones()) {
    for (const auto& kTransicion : vTransicion) {
      TransicionMultiCinta* transicionMulti = dynamic_cast<TransicionMultiCinta*>(kTransicion);
      if (transicionMulti != nullptr &&
        transicionMulti->getEstadoIni() == estadoActual &&
        transicionMulti->getSimbolosALeer() == simbolosLeidos &&
        transicionMulti->getEstadoFin() == estadoDestino &&
        transicionMulti->getSimbolosAEscribir() == simbolosEscritos &&
        transicionMulti->getMovimientosARealizar() == movimientos) {
        delete nuevaTransicion; // Liberar memoria en caso de error
        const std::string kErrorDuplicado = "Transición duplicada";
        throw (kErrorDuplicado);
      }
    }
  }
  // Agregar la nueva transición
  maquinaTuring_->agregarTransicion(estadoActual, nuevaTransicion);
}