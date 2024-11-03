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
 * @file direccion.h
 * @brief Definición de la clase Direccion.
 *
 * Esta clase representa las direcciones posibles en las que 
 * puede moverse una cabeza de lectura/escritura en una máquina 
 * de Turing, incluyendo las direcciones "izquierda", "derecha" 
 * y "quieto".
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <string>
#include <ostream>

/**
 * @brief Clase que representa la dirección de movimiento de una cabeza 
 * de lectura/escritura en una máquina de Turing.
 */
class Direccion {
 public:
  enum Valor {
    IZQUIERDA, // Representa L
    DERECHA,   // Representa R
    QUIETO     // Representa S
  };
  Direccion() {}
  Direccion(const Valor& kDir) : direccion_(kDir) {}
  const std::string toString() const {
    switch (direccion_) {
      case IZQUIERDA: return "L";
      case DERECHA:   return "R";
      case QUIETO:    return "S";
      default:        return ""; // No debería ocurrir
    }
  }
  const bool operator==(const Direccion& kDir) const { return direccion_ == kDir.direccion_; }
  const Valor getValor() const { return direccion_; }  
  static Direccion Izquierda() { return Direccion(IZQUIERDA); }
  static Direccion Derecha() { return Direccion(DERECHA); }
  static Direccion Quieto() { return Direccion(QUIETO); }
  friend std::ostream& operator<<(std::ostream& os, const Direccion& kDir) {
    os << kDir.toString();
    return os;
  }
 private:
  Valor direccion_;
};