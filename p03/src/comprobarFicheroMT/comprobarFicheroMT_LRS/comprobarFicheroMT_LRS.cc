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
 * @file comprobarFicheroMT_LRS.cc
 * @brief Implementación de la clase ComprobarFicheroMT_LRS para el análisis de archivos de Máquina de Turing de cinta única con LRS.
 * 
 * Esta clase se encarga de verificar y rellenar las transiciones de una Máquina de Turing de cinta única, asegurándose de que
 * todos los estados y símbolos sean válidos según el alfabeto definido.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./comprobarFicheroMT_LRS.h"

/**
 * @brief Constructor de la clase ComprobarFicheroMT_LRS.
 * 
 * Inicializa una nueva Máquina de Turing de cinta única (LRS) y analiza el archivo especificado.
 * 
 * @param kNombreFichero Ruta del archivo a analizar.
 */
ComprobarFicheroMT_LRS::ComprobarFicheroMT_LRS(const std::string& kNombreFichero) {
  maquinaTuring_ = new MaquinaTuringLRS;
  analizarFicheroMT(kNombreFichero);
}

/**
 * @brief Analiza el archivo de Máquina de Turing.
 * 
 * Llama al método de la clase base para realizar el análisis inicial del archivo.
 * 
 * @param kNombreFichero Ruta del archivo a analizar.
 */
void ComprobarFicheroMT_LRS::analizarFicheroMT(const std::string& kNombreFichero) {
  ComprobarFicheroMT::analizarFicheroMT(kNombreFichero);
}

/**
 * @brief Analiza una línea de transiciones y las rellena en la Máquina de Turing.
 * 
 * Este método extrae los componentes de una línea que define una transición de la Máquina de Turing,
 * valida cada uno de ellos, y si todo es correcto, agrega la transición a la máquina.
 * 
 * @param kLinea Línea que contiene la definición de la transición.
 * @throws Si hay errores en la definición de la transición.
 */
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
  bool esEstadoAceptacionActual = maquinaTuring_->getEstadosFinales().find(estadoActual) != maquinaTuring_->getEstadosFinales().end();
  estadoActual = Estado(estadoActualStr, esEstadoAceptacionActual);
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
  bool esEstadoAceptacionDestino = maquinaTuring_->getEstadosFinales().find(estadoDestino) != maquinaTuring_->getEstadosFinales().end();
  estadoDestino = Estado(estadoDestinoStr, esEstadoAceptacionDestino);
  // Comprobar si el símbolo escrito es válido
  if (simboloEscritoStr.size() != 1) {
    const std::string kErrorSizeSimboloEscrito = "Símbolo escrito (" + simboloEscritoStr + ") tamaño != 1";
    throw (kErrorSizeSimboloEscrito);
  } else if (
    maquinaTuring_->getAlfabetoCinta().getConjuntoAlfabeto().find(simboloEscritoStr[0]) == 
    maquinaTuring_->getAlfabetoCinta().getConjuntoAlfabeto().end()
  ) {
    const std::string kErrorSimboloEscrito = "Símbolo escrito (" + simboloEscritoStr + ") no está en el alfabeto de la cinta.";
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
        transicionLRS->getSimboloALeer() == simboloLeidoStr[0] &&
        transicionLRS->getEstadoFin() == estadoDestino) {
        const std::string kErrorNoDeterminista = "MT no determinista";
        throw (kErrorNoDeterminista);
      }
    }
  }
  // Agregar la nueva transición
  maquinaTuring_->agregarTransicion(estadoActual, nuevaTransicion);
}