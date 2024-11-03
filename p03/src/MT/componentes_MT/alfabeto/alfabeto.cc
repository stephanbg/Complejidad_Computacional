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
 * @file alfabeto.cc
 * @brief Implementación de la clase Alfabeto.
 *
 * Este archivo contiene las definiciones de los métodos de la clase
 * Alfabeto, que gestiona un conjunto de símbolos para una máquina de 
 * Turing, permitiendo insertar símbolos y representarlos en forma 
 * legible.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "alfabeto.h"

/**
 * @brief Inserta un nuevo símbolo en el alfabeto.
 * 
 * Este método agrega el símbolo proporcionado al conjunto de 
 * caracteres del alfabeto, asegurando que no haya duplicados 
 * gracias a la estructura de datos std::set.
 * 
 * @param kElemento El símbolo a insertar en el alfabeto.
 */
void Alfabeto::insertar(const char kElemento) {
  conjuntoAlfabeto_.insert(kElemento);
}

/**
 * @brief Comprueba si el alfabeto actual contiene todos los símbolos de otro alfabeto.
 *
 * Este método utiliza `std::includes` para verificar que todos los elementos
 * del alfabeto `kOtro` están presentes en el alfabeto actual (`conjuntoAlfabeto_`).
 *
 * @param kOtro El alfabeto que se va a comprobar si está contenido en el actual.
 * @return true Si el alfabeto actual contiene todos los símbolos de `kOtro`.
 * @return false Si el alfabeto actual no contiene todos los símbolos de `kOtro`.
 */
bool Alfabeto::contieneA(const Alfabeto& kOtro) const {
  return std::includes(
    conjuntoAlfabeto_.begin(),
    conjuntoAlfabeto_.end(),
    kOtro.conjuntoAlfabeto_.begin(),
    kOtro.conjuntoAlfabeto_.end()
  );
}

/**
 * @brief Sobrecarga del operador de inserción para la impresión.
 * 
 * Permite mostrar el contenido del alfabeto de manera legible, 
 * formateando los símbolos en un conjunto. Cada símbolo se 
 * separa por comas.
 * 
 * @param os Flujo de salida donde se imprimirá el alfabeto.
 * @param kAlfabeto Referencia constante al objeto Alfabeto que 
 *                  se va a imprimir.
 * @return std::ostream& Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Alfabeto& kAlfabeto) {
  os << "{";
  bool primero = true;
  for (const auto& kSimbolo : kAlfabeto.conjuntoAlfabeto_) {
    if (!primero) os << ", ";
    os << kSimbolo;
    primero = false;
  }
  os << "}" << std::endl;
  return os;
}