/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 3:
 *
 * @author Stephan Brommer Gutiérrez
 * @since 31 de Octubre de 2024
 * @file comprobarFicheroMT_LRS.cc
 * @brief
 */

#include "./comprobarFicheroMT_LRS.h"

ComprobarFicheroMT_LRS::ComprobarFicheroMT_LRS(const std::string& kNombreFichero) {
  maquinaTuring_ = new MaquinaTuringLRS;
  analizarFicheroMT(kNombreFichero);
}

void ComprobarFicheroMT_LRS::analizarFicheroMT(const std::string& kNombreFichero) {
  ComprobarFicheroMT::analizarFicheroMT(kNombreFichero);
}

void ComprobarFicheroMT_LRS::analizarYRellenarTransiciones(const std::string& kLinea) {
  std::cout << "analizarYRellenarTransiciones LRS" ;
}
