/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file comprobarParametros.h
 * @brief Definición de la clase ComprobarParametros en la que se comprueban los parámetros de entrada
 * 
 * @see 
 */

#pragma once

#include <iostream>
#include <filesystem>
#include <string>

/**
 * @brief Clase ComprobarParametros estática que proporciona métodos
 *        para la validación de los parámetros de entrada del programa.
 */
class ComprobarParametros {
 public:
  static void comprobarErrores(const int, const std::string&);
  static void help();
 private:
  static void comprobarCantidadParametros(const int);
  static void comprobarExistenciaFichero(const std::string&);
};