/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 3 de Octubre de 2024
 * @file comprobarParametros.cc
 * @brief Implementación de la clase ComprobarParametros en la que se comprueban los parámetros de entrada
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11667/mod_resource/content/19/CC_2425_Practica1.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p01}
 */

#include "comprobarParametros.h"

/**
 * @brief Comprueba si hay errores en los parámetros de entrada.
 * 
 * @param kArgc Cantidad de argumentos pasados al programa.
 * @param argv Array de cadenas de caracteres que representan los argumentos pasados al programa.
 */
void ComprobarParametros::comprobarErrores(const int kArgc,
                                           char* argv[]) {
  comprobarCantidadParametros(kArgc);
  comprobarNumeroNatural(argv[1]);
  comprobarNumeroNatural(argv[2]);
}

/**
 * @brief Comprueba si la cantidad de parámetros es válida.
 * 
 * @param kArgc Cantidad de argumentos pasados al programa.
 * @throw Lanza una excepción si no son 3 parámetros.
 */
void ComprobarParametros::comprobarCantidadParametros(const int kArgc) {
  const std::string kError = "Cantidad de parámetros.";
  if (kArgc != 3) throw kError;
}

/**
 * @brief Comprueba si el parámetro de entrada es un número natural.
 * 
 * @param kParametro el parámetro de entrada.
 * @throw Lanza una excepción si no es un número natural.
 */
void ComprobarParametros::comprobarNumeroNatural(const std::string& kParametro) {
  int indice = 0;
  std::string mensaje_error;
  if (kParametro[0] == '+') indice = 1;
  else if (kParametro[0] == '-') {
    mensaje_error = "No puede ser número negativo.";
    throw mensaje_error;
  }
  for (; indice < kParametro.size(); ++indice) {
    if (!std::isdigit(kParametro[indice])) {
      mensaje_error = "Algún caracter no numérico.";
      throw mensaje_error;
    }
  }
}

/**
 * @brief Lanza un mensaje de ayuda al usuario.
 */
void ComprobarParametros::help() {
  std::cout << "El programa tiene que ser ejecutado de la siguiente manera:" << std::endl;
  std::cout << "./main x (primer número natural) y (segundo número natural)" << std::endl;
  std::cout << "Luego se realizará la potencia x^y y saldrá por pantalla el" << std::endl;
  std::cout << "resultado y el número de llamadas a funciones que se han realizado." << std::endl;
  std::cout << "Además, el 0 también se incluye como número natural." << std::endl;
}