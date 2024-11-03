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
 * @file comprobarFicheroMT_LRS.h
 * @brief Definición de la clase para comprobar y analizar archivos de Máquina de Turing de línea recta y sencilla (LRS).
 * 
 * Esta clase hereda de ComprobarFicheroMT y se encarga de validar y analizar
 * las configuraciones específicas para una Máquina de Turing LRS. 
 * Incluye métodos para el análisis de archivos de entrada y la validación
 * de transiciones.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <algorithm>
#include <sstream>

#include "../comprobarFicheroMT.h"
#include "../../MT/MT_LRS/MT_LRS.h"
#include "../../MT/componentes_MT/transicion/transicionCintaUnicaLRS/transicionCintaUnicaLRS.h"

/**
 * @class ComprobarFicheroMT_LRS
 * @brief Clase para comprobar archivos de Máquina de Turing LRS.
 * 
 * Esta clase se encarga de analizar la configuración de una Máquina de Turing
 * de línea recta y sencilla (LRS), asegurándose de que las transiciones y
 * los estados cumplen con los requisitos necesarios.
 */
class ComprobarFicheroMT_LRS : public ComprobarFicheroMT {
 public:
  ComprobarFicheroMT_LRS(const std::string&);
 protected:
  virtual void analizarFicheroMT(const std::string&) override;
  virtual void analizarYRellenarTransiciones(const std::string&) override;
};