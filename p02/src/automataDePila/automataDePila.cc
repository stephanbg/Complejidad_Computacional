/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file automataDePila.cc
 * @brief Implementación de la clase AutomataDePila.
 * 
 * Este archivo contiene las implementaciones de los métodos de la clase
 * AutomataDePila, que permiten manejar el estado y las operaciones de
 * un autómata con pila.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#include "automataDePila.h"

/**
 * @brief Muestra el contenido de la pila en la salida estándar.
 * 
 * Este método imprime los elementos de la pila desde el tope hasta la base,
 * permitiendo visualizar su estado actual.
 * 
 * @param kPila Referencia constante a la pila cuyo contenido se desea mostrar.
 */
void AutomataDePila::mostrarPila(const std::stack<char>& kPila) const {
  std::vector<char> elementos;
  std::stack<char> pilaCopia = kPila;
  while (!pilaCopia.empty()) {
    char elemento = pilaCopia.top();
    elementos.push_back(elemento);
    pilaCopia.pop();
  }
  for (auto a : elementos) {
    std::cout << a;
  }
  std::cout << std::endl;
}

/**
 * @brief Muestra la traza de la ejecución del autómata.
 * 
 * Este método imprime el estado actual del autómata, la cadena que se
 * está evaluando, el contenido de la pila y la transición que se está
 * llevando a cabo, si aplica. La impresión se realiza solo si la macro
 * TRAZA está definida.
 * 
 * @param kEstadoActual Puntero al estado actual del autómata.
 * @param kCadena Cadena de entrada en evaluación.
 * @param kPila Pila actual del autómata.
 * @param kTransicion Transición actual que se está procesando.
 */
void AutomataDePila::mostrarTraza(
  const Estado* kEstadoActual, const std::string& kCadena,
  const std::stack<char>& kPila, const Transicion& kTransicion
) const {
  #ifdef TRAZA
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "Estado:" << *kEstadoActual << std::endl;
    std::cout << std::left << std::setw(15) << "Cadena:" << kCadena << std::endl;
    std::cout << std::left << std::setw(15) << "Pila:";
    mostrarPila(kPila);
    if (!kTransicion.isEmpty()) std::cout << std::left << std::setw(15) << "Transición:" << kTransicion;
  #endif
}