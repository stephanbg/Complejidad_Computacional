/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file transicion.h
 * @brief Definición de la clase Transicion.
 * 
 * Este archivo define la clase Transicion, que representa una transición
 * en un autómata de pila. Cada transición está asociada a un estado de
 * origen, un símbolo de transición, un símbolo a extraer de la pila,
 * un estado de destino y un conjunto de símbolos a introducir en la pila.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#pragma once

#include <iostream>

#include "../estado/estado.h"

/**
 * @brief Clase que representa una transición en un autómata de pila.
 * 
 * La clase Transicion almacena la información necesaria para definir
 * una transición desde un estado a otro en un autómata, incluyendo
 * los símbolos involucrados en la transición.
 */
class Transicion {
 public:
  Transicion();
  Transicion(Estado*&, const char, const char, Estado*&, const std::string&);
  bool isEmpty() const;
  const char getSimboloTransicion() const { return simboloTransicion_; }
  const char getElementoAExtraerDePila() const { return elementoAExtraerDePila_; }
  const Estado* getEstadoDestino() const { return estadoDestino_; }
  const std::string getSimbolosAIntroducirEnPila() const { return simbolosAIntroducirEnPila_; } 
  friend std::ostream& operator<<(std::ostream&, const Transicion&);
 private:
  Estado* estadoOrigen_;
  char simboloTransicion_;
  char elementoAExtraerDePila_;
  Estado* estadoDestino_;
  std::string simbolosAIntroducirEnPila_;
};