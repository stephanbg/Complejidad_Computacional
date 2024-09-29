/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file comprobarParametros.h
 * @brief 
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link link de la practica de github aqui}
 */

#pragma once

#include <iostream>
#include <string>

/**
 * @brief Clase ComprobarParametros estática que proporciona métodos
 *        para la validación de los parámetros de entrada del programa.
 */
class ComprobarParametros {
 public:
  static void comprobarErrores(const int, char* []);
  static void help();
 private:
  static void comprobarCantidadParametros(const int);
  static void comprobarNumeroNatural(const std::string&);
};