/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file transicion.cc
 * @brief Implementación de la clase Transicion.
 * 
 * Este archivo contiene la implementación de los métodos de la clase
 * Transicion, que representa las transiciones en un autómata de pila.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#include "transicion.h"

/**
 * @brief Constructor por defecto de la clase Transicion.
 * 
 * Inicializa todos los atributos de la transición a valores por
 * defecto (nulos o vacíos).
 */
Transicion::Transicion() {
  estadoOrigen_ = nullptr;
  simboloTransicion_ = '\0'; 
  elementoAExtraerDePila_ = '\0';
  estadoDestino_ = nullptr; 
  simbolosAIntroducirEnPila_ = "";
}

/**
 * @brief Constructor parametrizado para crear una transición.
 * 
 * @param kEstadoOrigen Puntero al estado de origen de la transición.
 * @param kSimboloTransicion Símbolo que provoca la transición.
 * @param kElementoAExtraerDePila Símbolo a extraer de la pila.
 * @param kEstadoDestino Puntero al estado de destino de la transición.
 * @param kSimbolosAIntroducirEnPila Cadena de símbolos a introducir en la pila.
 */
Transicion::Transicion(
  Estado*& kEstadoOrigen,
  const char kSimboloTransicion,
  const char kElementoAExtraerDePila,
  Estado*& kEstadoDestino,
  const std::string& kSimbolosAIntroducirEnPila
) {
  estadoOrigen_ = kEstadoOrigen;
  simboloTransicion_ = kSimboloTransicion;
  elementoAExtraerDePila_ = kElementoAExtraerDePila;
  estadoDestino_ = kEstadoDestino;
  simbolosAIntroducirEnPila_ = kSimbolosAIntroducirEnPila;
}

/**
 * @brief Comprueba si la transición está vacía.
 * 
 * @return true Si todos los atributos de la transición están vacíos o nulos.
 * @return false Si al menos un atributo tiene un valor válido.
 */
bool Transicion::isEmpty() const {
  return estadoOrigen_ == nullptr && simboloTransicion_ == '\0' &&
         elementoAExtraerDePila_ == '\0' && estadoDestino_ == nullptr &&
         simbolosAIntroducirEnPila_.empty();
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir una transición.
 * 
 * Imprime la información de la transición en un formato legible.
 * 
 * @param os Flujo de salida donde se imprimirá la transición.
 * @param kTransicion La transición que se va a imprimir.
 * @return std::ostream& El flujo de salida modificado.
 */
std::ostream& operator<<(std::ostream& os, const Transicion& kTransicion) {
  os << "(" << *(kTransicion.estadoDestino_) << ", " << kTransicion.simbolosAIntroducirEnPila_;
  os << ") ∈ δ (" << *(kTransicion.estadoOrigen_) << ", " << kTransicion.simboloTransicion_ << ", ";
  os << kTransicion.elementoAExtraerDePila_ << ")" << std::endl;
  return os;
}  