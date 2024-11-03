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
 * @file comprobarParametros.h
 * @brief Clase para gestionar y validar los parámetros de entrada de la Máquina de Turing
 * 
 * Esta clase proporciona métodos estáticos para comprobar la cantidad de parámetros 
 * proporcionados en la línea de comandos, verificar la existencia de archivos y 
 * mostrar información de ayuda al usuario.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <iostream>
#include <filesystem>
#include <string>

/**
 * @brief Clase para comprobar parámetros de entrada.
 * 
 * Esta clase contiene métodos estáticos que permiten verificar la validez 
 * de los parámetros proporcionados al programa, así como ayudar al usuario 
 * en caso de error.
 */
class ComprobarParametros {
 public:
  static void comprobarErrores(const int, char* []);
  static void help();
 private:
  static void comprobarCantidadParametros(const int);
  static void comprobarExistenciaFichero(const std::string&);
};