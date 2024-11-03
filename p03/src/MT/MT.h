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
 * @file MT.h
 * @brief Definición de la clase MaquinaTuring.
 *
 * Esta clase representa una máquina de Turing abstracta y define
 * los métodos y atributos que deben ser implementados por las
 * clases derivadas.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <unordered_map>

#include "./componentes_MT/estado/estado.h"
#include "./componentes_MT/alfabeto/alfabeto.h"
#include "./componentes_MT/transicion/transicion.h"
#include "./componentes_MT/cinta/cinta.h"
#include "./componentes_MT/transicion/direccion.h"

/**
 * @brief Clase abstracta que representa una máquina de Turing.
 */
class MaquinaTuring {
 public:
  MaquinaTuring() : simboloBlanco_('.'), numCintas_(1) {}
  virtual bool procesar(const std::string&) = 0;
  virtual void rellenarCintas(const std::string&) = 0;
  virtual void mostrarMT() const = 0;
  virtual void mostrarCintas() const = 0;
  void agregarTransicion(const Estado&, Transicion*&);
  const char getSimboloBlanco() const { return simboloBlanco_; }
  const std::set<Estado>& getEstados() const { return estados_; }
  const std::set<Estado>& getEstadosFinales() const { return estadosFinales_; }
  const Alfabeto& getAlfabetoEntrada() const { return alfabetoEntrada_; }
  const Alfabeto& getAlfabetoCinta() const { return alfabetoCinta_; }
  const std::unordered_map<Estado, std::vector<Transicion*>> getTransiciones() const { return transiciones_; }
  const int getNumCintas() const { return numCintas_; }
  Alfabeto& setAlfabetoEntrada() { return alfabetoEntrada_; }
  Alfabeto& setAlfabetoCinta() { return alfabetoCinta_; }
  std::set<Estado>& setEstados() { return estados_; }
  std::set<Estado>& setEstadosFinales() { return estadosFinales_; }
  Estado& setEstadoInicial() { return estadoInicial_; }
  virtual ~MaquinaTuring() {}
 protected:
  std::set<Estado> estados_;
  Alfabeto alfabetoEntrada_;
  Alfabeto alfabetoCinta_;
  Estado estadoInicial_;
  std::set<Estado> estadosFinales_;
  char simboloBlanco_;
  std::unordered_map<Estado, std::vector<Transicion*>> transiciones_;
  int numCintas_;
};