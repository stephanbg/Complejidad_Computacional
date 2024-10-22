/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file comprobarParametros.h
 * @brief Clase para gestionar y validar los parámetros de entrada del simulador de autómatas con pila.
 * 
 * Esta clase proporciona métodos estáticos para comprobar la cantidad de parámetros 
 * proporcionados en la línea de comandos, verificar la existencia de archivos y 
 * mostrar información de ayuda al usuario.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
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
  static void comprobarErrores(const int, const std::string&);
  static void help();
 private:
  static void comprobarCantidadParametros(const int);
  static void comprobarExistenciaFichero(const std::string&);
};