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

#include "./comprobarFicheroMT_MultiCinta.h"

ComprobarFicheroMT_MultiCinta::ComprobarFicheroMT_MultiCinta(
  const std::string& kNombreFichero, const int kNumCintas
) {
  maquinaTuring_ = new MaquinaTuringMultiCinta(kNumCintas);
  analizarFicheroMT(kNombreFichero);
}

void ComprobarFicheroMT_MultiCinta::analizarFicheroMT(const std::string& kNombreFichero) {
  ComprobarFicheroMT::analizarFicheroMT(kNombreFichero);
}

void ComprobarFicheroMT_MultiCinta::analizarYRellenarTransiciones(const std::string& kLinea) {
  //std::cout << "analizarYRellenarTransiciones Multi" ;
}