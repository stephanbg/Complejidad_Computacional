/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 3:
 *
 * @author Stephan Brommer Gutiérrez
 * @since 31 de Octubre de 2024
 * @file comprobarFicheroMT_LRS.h
 * @brief 
 */

#pragma once

#include <algorithm>
#include <sstream>

#include "../comprobarFicheroMT.h"
#include "../../MT/MT_MultiCinta/MT_MultiCinta.h"

class ComprobarFicheroMT_MultiCinta : public ComprobarFicheroMT {
 public:
  ComprobarFicheroMT_MultiCinta(const std::string&);
 protected:
  virtual void analizarFicheroMT(const std::string&) override;
  virtual void analizarYRellenarTransiciones(const std::string&) override;
};