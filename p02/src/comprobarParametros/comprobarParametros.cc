/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file comprobarParametros.cc
 * @brief Implementación de la clase ComprobarParametros en la que se comprueban los parámetros de entrada
 * 
 * @see 
 */

#include "comprobarParametros.h"

/**
 * @brief Comprueba si hay errores en los parámetros de entrada.
 * 
 * @param kArgc Cantidad de argumentos pasados al programa.
 * @param argv Array de cadenas de caracteres que representan los argumentos pasados al programa.
 */
void ComprobarParametros::comprobarErrores(const int kArgc, const std::string& kRutaFichero) {
  comprobarCantidadParametros(kArgc);
  comprobarExistenciaFichero(kRutaFichero);
}

/**
 * @brief Comprueba si la cantidad de parámetros es válida.
 * 
 * @param kArgc Cantidad de argumentos pasados al programa.
 * @throw Lanza una excepción si no son más de 1 parámetro.
 */
void ComprobarParametros::comprobarCantidadParametros(const int kArgc) {
  const std::string kError = "Cantidad de parámetros.";
  if (kArgc <= 2) throw kError;
}

void ComprobarParametros::comprobarExistenciaFichero(const std::string& kRutaFichero) {
  const std::string kError = "Error en Ruta del fichero APv. (" + kRutaFichero + ").";
  std::filesystem::path rutaFichero(kRutaFichero);
  if (!std::filesystem::exists(rutaFichero)) throw(kError);
}

/**
 * @brief Lanza un mensaje de ayuda al usuario.
 */
void ComprobarParametros::help() {
  std::cout << "El programa tiene que ser ejecutado de la siguiente manera:" << std::endl;
  std::cout << "./main (Fichero APv) (cadenas infinitas separadas por espacios)" << std::endl;
}