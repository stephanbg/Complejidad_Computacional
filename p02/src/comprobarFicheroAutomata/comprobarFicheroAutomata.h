/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file comprobarFicheroAutomata.h
 * @brief Interfaz para la comprobación y análisis de archivos de autómatas con pila.
 * 
 * Esta clase abstracta define los métodos necesarios para analizar la definición de un 
 * autómata con pila a partir de un archivo. Las clases derivadas deben implementar 
 * el método `analizarFicheroAutomata` para proporcionar la funcionalidad específica.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../automataDePila/automataDePila.h"

/**
 * @brief Clase abstracta para la comprobación de archivos de autómatas con pila.
 * 
 * Esta clase proporciona una interfaz para analizar la definición de un autómata 
 * con pila a partir de un archivo. Contiene métodos para obtener el autómata 
 * resultante y manejar mensajes de error.
 */
class ComprobarFicheroAutomata {
 public:
  virtual void analizarFicheroAutomata(const std::string&) = 0;
  const AutomataDePila* getAutomataDePila() const { return automataDePila_; }
 protected:
  AutomataDePila* automataDePila_;
  std::string mensajeError_ = "";
};