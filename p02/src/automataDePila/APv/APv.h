/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file APv.h
 * @brief Definición de la clase APv para el simulador de un autómata con pila.
 * 
 * Esta clase hereda de la clase AutomataDePila y proporciona
 * la implementación para el método que determina si una cadena es aceptada
 * por el autómata. Además, permite la impresión del objeto en un flujo de salida.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#pragma once

#include <functional>

#include "../automataDePila.h"

/**
 * @brief Clase que representa un autómata con pila (APv).
 * 
 * Esta clase proporciona la funcionalidad para aceptar cadenas de entrada
 * y hereda las características de la clase base AutomataDePila.
 */
class APv : public AutomataDePila {
 public:
  virtual bool seAceptaCadena(const std::string&) override;
  friend std::ostream& operator<<(std::ostream&, const APv&);
};