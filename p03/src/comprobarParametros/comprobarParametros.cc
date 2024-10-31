/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file comprobarParametros.cc
 * @brief Clase para gestionar y validar los parámetros de entrada del simulador de autómatas con pila.
 * 
 * Esta clase proporciona métodos estáticos para comprobar la cantidad de parámetros 
 * proporcionados en la línea de comandos, verificar la existencia de archivos y 
 * mostrar información de ayuda al usuario.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#include "comprobarParametros.h"

/**
 * @brief Comprueba si hay errores en los parámetros de entrada.
 * 
 * @param kArgc Cantidad de argumentos pasados al programa.
 * @param argv Array de cadenas de caracteres que representan los argumentos pasados al programa.
 */
void ComprobarParametros::comprobarErrores(const int kArgc, char* kArgv[]) {
  comprobarCantidadParametros(kArgc);
  comprobarExistenciaFichero(kArgv[1]);
}

/**
 * @brief Comprueba si la cantidad de parámetros es válida.
 * 
 * @param kArgc Cantidad de argumentos pasados al programa.
 * @throws std::string Lanza una excepción si no son más de 3 parámetro.
 */
void ComprobarParametros::comprobarCantidadParametros(const int kArgc) {
  const std::string kError = "Cantidad de parámetros.";
  if (kArgc <= 2) throw kError;
}

/**
 * @brief Comprueba la existencia del archivo especificado.
 * 
 * Este método verifica si el archivo indicado en la ruta proporcionada 
 * existe en el sistema de archivos. Si el archivo no se encuentra, 
 * se lanza una excepción con un mensaje de error correspondiente.
 * 
 * @param kRutaFichero Ruta del archivo que se desea verificar.
 * @throws std::string Mensaje de error si el archivo no existe.
 */
void ComprobarParametros::comprobarExistenciaFichero(const std::string& kRutaFichero) {
  const std::string kError = "Error en Ruta del fichero MT. (" + kRutaFichero + ").";
  std::filesystem::path rutaFichero(kRutaFichero);
  if (!std::filesystem::exists(rutaFichero)) throw(kError);
}

/**
 * @brief Lanza un mensaje de ayuda al usuario.
 */
void ComprobarParametros::help() {
  std::cout << "El programa tiene que ser ejecutado de la siguiente manera:" << std::endl;
  std::cout << "./main (Fichero MT) (cadenas infinitas separadas por espacios)" << std::endl;
}