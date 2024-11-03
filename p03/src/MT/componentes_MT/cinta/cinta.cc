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
 * @file cinta.cc
 * @brief Implementación de la clase Cinta.
 *
 * Este archivo contiene la implementación de los métodos de la clase
 * Cinta, que gestiona la lectura, escritura y movimiento del cabezal
 * en una cinta de una máquina de Turing.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./cinta.h"

/**
 * @brief Inicializa la cinta con una cadena de símbolos.
 *
 * Este método establece la posición del cabezal al inicio (1),
 * limpia el contenido actual de la cinta y añade el símbolo en
 * blanco antes y después de la cadena proporcionada.
 * 
 * @param kCadena La cadena de símbolos a escribir en la cinta.
 */
void Cinta::iniciar(const std::string& kCadena) {
  posicionCabezal_ = 1;
  cinta_.clear();
  cinta_.push_back(simboloBlanco_);
  for (char c : kCadena) cinta_.push_back(c);
  cinta_.push_back(simboloBlanco_);
}

/**
 * @brief Rellena la cinta con símbolos en blanco.
 *
 * Este método reinicia la cinta, limpiando su contenido
 * y asegurando que tenga al menos tres posiciones
 * con símbolos en blanco, y posiciona el cabezal al inicio.
 */
void Cinta::rellenarDeBlancos() {
  posicionCabezal_ = 1;
  cinta_.clear();
  cinta_.resize(3, simboloBlanco_);
}

/**
 * @brief Escribe un símbolo en la posición actual del cabezal.
 *
 * Este método coloca el símbolo proporcionado en la posición
 * del cabezal. Si el cabezal está fuera de los límites de la
 * cinta, se ajusta su posición y se añade el símbolo.
 * 
 * @param kSimbolo El símbolo que se escribirá en la cinta.
 */
void Cinta::escribir(const char kSimbolo) {
  if (posicionCabezal_ < 0) {
    cinta_.insert(cinta_.begin(), kSimbolo);
    posicionCabezal_ = 0;
  } else if (posicionCabezal_ >= cinta_.size()) cinta_.push_back(kSimbolo);
  else cinta_[posicionCabezal_] = kSimbolo;
}

/**
 * @brief Lee el símbolo en la posición actual del cabezal.
 *
 * Este método devuelve el símbolo en la posición actual del cabezal.
 * Si el cabezal está fuera de los límites de la cinta, devuelve
 * el símbolo en blanco.
 * 
 * @return El símbolo leído en la posición del cabezal.
 */
const char Cinta::leer() const {
  if (posicionCabezal_ < 0 || posicionCabezal_ >= cinta_.size()) return simboloBlanco_;
  return cinta_[posicionCabezal_];
}

/**
 * @brief Mueve el cabezal en la dirección especificada.
 *
 * Este método ajusta la posición del cabezal según la dirección
 * indicada (izquierda o derecha).
 * 
 * @param kDir La dirección a la que se moverá el cabezal.
 */
void Cinta::moverCabezal(const Direccion& kDir) {
  if (kDir.getValor() == Direccion::IZQUIERDA) posicionCabezal_--;
  else if (kDir.getValor() == Direccion::DERECHA) posicionCabezal_++;
}

/**
 * @brief Imprime el contenido actual de la cinta.
 *
 * Este método muestra todos los símbolos de la cinta y la
 * posición actual del cabezal.
 */
void Cinta::imprimir() const {
  std::cout << "|";
  for (auto a : cinta_) {
    std::cout << a << "|";
  }
  std::cout << std::endl;
  std::cout << "Posicion Cabezal: " << posicionCabezal_ << std::endl;
}