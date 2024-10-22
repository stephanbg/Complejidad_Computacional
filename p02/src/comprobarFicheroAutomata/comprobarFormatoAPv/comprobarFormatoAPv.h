/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file comprobarFormatoAPv.h
 * @brief Clase para comprobar y analizar el formato de archivos de autómatas de pila (APv).
 * 
 * Esta clase hereda de `ComprobarFicheroAutomata` y proporciona la implementación
 * para analizar archivos específicos del formato de autómatas de pila con el algoritmo de vaciado de pila. Incluye 
 * métodos para validar y extraer los diferentes componentes de la definición del 
 * autómata.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#pragma once

#include <algorithm>
#include <sstream>

#include "../comprobarFicheroAutomata.h"
#include "../../automataDePila/APv/APv.h"

/**
 * @brief Clase para comprobar el formato de un autómata de pila (APv).
 * 
 * Esta clase proporciona métodos para analizar un archivo de definición de un 
 * autómata de pila, extrayendo y validando su contenido, como estados, 
 * alfabeto y transiciones.
 */
class ComprobarFormatoAPv : public ComprobarFicheroAutomata {
 public:
  ComprobarFormatoAPv();
  virtual void analizarFicheroAutomata(const std::string&) override;
 private:
  void eliminarComentarios(std::string&) const;
  bool lineaCompletaDeEspacios(const std::string&) const;
  void analizarYRellenarConjuntoDeEstados(const std::string&);
  void analizarYRellenarAlfabeto(const std::string&);
  void analizarYRellenarAlfabetoPila(const std::string&);
  void analizarYRellenarEstadoInicial(const std::string&);
  void analizarYRellenarSimboloInicialPila(const std::string&);
  void analizarYRellenarTransiciones(const std::string&);
  bool existeTransicion(const std::string&) const;
};