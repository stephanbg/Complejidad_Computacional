/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file automataDePila.h
 * @brief Declaración de la clase AutomataDePila que representa un autómata con pila.
 * 
 * Esta clase es la base para implementar un autómata de pila, proporcionando
 * la estructura y las operaciones necesarias para procesar cadenas de entrada
 * y determinar su aceptación según las transiciones definidas.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>

#include "./alfabeto/alfabeto.h"
#include "./estado/estado.h"
#include "./transicion/transicion.h"

/**
 * @brief Clase base para un autómata de pila.
 * 
 * Esta clase proporciona métodos virtuales y atributos que son necesarios
 * para implementar un autómata de pila. Las subclases deben implementar
 * el método `seAceptaCadena` para definir la lógica específica de
 * aceptación de cadenas.
 */
class AutomataDePila {
 public:
  AutomataDePila() {}
  virtual bool seAceptaCadena(const std::string&) = 0;
  // Getters
  const std::set<Estado*> getEstados() const { return estados_; }
  const Alfabeto getAlfabeto() const { return alfabeto_; }
  const Alfabeto getAlfabetoPila() const { return alfabetoPila_; }
  // Setters
  std::set<Estado*>& setEstados() { return estados_; }
  Alfabeto& setAlfabeto() { return alfabeto_; }
  Alfabeto& setAlfabetoPila() { return alfabetoPila_; }
  Estado*& setEstadoInicial() { return estadoInicial_; }
  char& setSimboloInicialPila() { return simboloInicialPila_; }
  virtual ~AutomataDePila() {}
 protected:
  std::set<Estado*> estados_;
  Alfabeto alfabeto_;
  Alfabeto alfabetoPila_;
  Estado* estadoInicial_;
  char simboloInicialPila_;
  std::stack<char> pila_;
  void mostrarPila(const std::stack<char>&) const;
  void mostrarTraza(const Estado*, const std::string&, const std::stack<char>&, const Transicion&) const;
};