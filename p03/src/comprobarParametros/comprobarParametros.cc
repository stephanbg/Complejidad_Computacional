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
 * @file comprobarParametros.cc
 * @brief Clase para gestionar y validar los parámetros de entrada de la Máquina de Turing.
 * 
 * Esta clase proporciona métodos estáticos para comprobar la cantidad de parámetros 
 * proporcionados en la línea de comandos, verificar la existencia de archivos y 
 * mostrar información de ayuda al usuario.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
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
 * @throws std::string Lanza una excepción si son menos de 3 parámetros.
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
  std::cout << "El programa debe ejecutarse de la siguiente manera:" << std::endl;
  std::cout << "./main <Fichero_MT> <cadenas_infinita_separadas_por_espacios>" << std::endl;
  std::cout << "\nNOTA: Si el fichero es de tipo MultiCinta:" << std::endl;
  std::cout << "1. Para representar una cinta vacía, utiliza '..' en la línea de comandos." << std::endl;
  std::cout << "2. Para indicar qué cadenas van en diferentes cintas, separa las cadenas" << std::endl;
  std::cout << "   utilizando un único punto ('.')." << std::endl;
}