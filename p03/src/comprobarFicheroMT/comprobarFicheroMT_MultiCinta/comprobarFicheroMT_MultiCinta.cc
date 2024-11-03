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
 * @file comprobarFicheroMT_MultiCinta.cc
 * @brief Implementación de la clase para comprobar y analizar archivos de Máquina de Turing multicinta.
 * 
 * Esta implementación proporciona los métodos necesarios para analizar
 * las transiciones y configuraciones de una Máquina de Turing multicinta
 * a partir de un archivo de definición. Se realizan verificaciones de
 * validez de estados, símbolos y movimientos en cada transición.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./comprobarFicheroMT_MultiCinta.h"

/**
 * @brief Constructor de la clase ComprobarFicheroMT_MultiCinta.
 * 
 * Inicializa la máquina de Turing multicinta y comienza el análisis
 * del archivo de configuración especificado.
 * 
 * @param kNombreFichero Ruta del archivo de configuración.
 * @param kNumCintas Número de cintas que tendrá la máquina de Turing.
 */
ComprobarFicheroMT_MultiCinta::ComprobarFicheroMT_MultiCinta(
  const std::string& kNombreFichero, const int kNumCintas
) {
  maquinaTuring_ = new MaquinaTuringMultiCinta(kNumCintas);
  analizarFicheroMT(kNombreFichero);
}

/**
 * @brief Método para analizar el archivo de configuración de la máquina de Turing multicinta.
 * 
 * Este método invoca la función de la clase base para realizar el análisis
 * del archivo.
 * 
 * @param kNombreFichero Ruta del archivo a analizar.
 */
void ComprobarFicheroMT_MultiCinta::analizarFicheroMT(const std::string& kNombreFichero) {
  ComprobarFicheroMT::analizarFicheroMT(kNombreFichero);
}

/**
 * @brief Analiza y llena las transiciones de la máquina de Turing multicinta.
 * 
 * Este método procesa una línea del archivo de configuración, extrayendo
 * el estado actual, los símbolos a leer, el estado destino, los símbolos
 * a escribir y los movimientos a realizar. Realiza verificaciones de
 * validez y crea nuevas transiciones.
 * 
 * @param kLinea Línea del archivo que contiene la definición de una transición.
 * 
 * @throw Si hay un error en la definición de la transición.
 */
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
  bool esEstadoAceptacionActual = maquinaTuring_->getEstadosFinales().find(estadoActual) != maquinaTuring_->getEstadosFinales().end();
  estadoActual = Estado(estadoActualStr, esEstadoAceptacionActual);  
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
  bool esEstadoAceptacionDestino = maquinaTuring_->getEstadosFinales().find(estadoDestino) != maquinaTuring_->getEstadosFinales().end();
  estadoDestino = Estado(estadoDestinoStr, esEstadoAceptacionDestino);    
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
      const std::string kErrorSimboloEscrito = "Símbolo escrito (" + simbolosEscritosStr[i] + ") no está en el alfabeto de la cinta.";
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
        transicionMulti->getEstadoFin() == estadoDestino) {
        const std::string kErrorNoDeterminista = "MT no determinista";
        throw (kErrorNoDeterminista);
      }
    }
  }
  // Agregar la nueva transición
  maquinaTuring_->agregarTransicion(estadoActual, nuevaTransicion);
}