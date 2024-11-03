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
 * @file comprobarFicheroMT_MultiCinta.h
 * @brief Clase para comprobar y analizar archivos de Máquina de Turing Multicinta.
 * 
 * Esta clase se encarga de verificar la validez de los archivos de definición
 * de máquinas de Turing multicinta, heredando de la clase base 
 * `ComprobarFicheroMT`. Implementa métodos específicos para analizar 
 * transiciones y otras características necesarias para la configuración 
 * de la máquina de Turing multicinta.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <algorithm>
#include <sstream>

#include "../comprobarFicheroMT.h"
#include "../../MT/MT_MultiCinta/MT_MultiCinta.h"

/**
 * @class ComprobarFicheroMT_MultiCinta
 * @brief Clase derivada para manejar la verificación de archivos de máquinas de Turing multicinta.
 *
 * Esta clase proporciona la implementación de métodos para analizar
 * los archivos de configuración de máquinas de Turing multicinta,
 * asegurando que los estados, alfabetos y transiciones sean válidos
 * y se ajusten a las reglas definidas para la máquina de Turing.
 */
class ComprobarFicheroMT_MultiCinta : public ComprobarFicheroMT {
 public:
  ComprobarFicheroMT_MultiCinta(const std::string&, const int);
 protected:
  virtual void analizarFicheroMT(const std::string&) override;
  virtual void analizarYRellenarTransiciones(const std::string&) override;
};