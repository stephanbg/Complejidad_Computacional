/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 3:
 *
 * @author Stephan Brommer Gutiérrez
 * @since 31 de Octubre de 2024
 * @file comprobarFicheroMT.h
 * @brief
 * 
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../MT/MT.h"

class ComprobarFicheroMT_LRS;
class ComprobarFicheroMT_MultiCinta;

class ComprobarFicheroMT {
 public:
  static ComprobarFicheroMT* crearComprobador(const std::string& kNombreFichero);
  const MaquinaTuring* getMaquinaTuring() const { return maquinaTuring_; }
 protected:
  MaquinaTuring* maquinaTuring_;
  std::string mensajeError_ = "";
  static void eliminarComentarios(std::string&);
  static bool lineaCompletaDeEspacios(const std::string&);
  void analizarYRellenarConjuntoDeEstados(const std::string&);
  void analizarYRellenarAlfabetoEntrada(const std::string&);
  void analizarYRellenarAlfabetoCinta(const std::string&);
  void analizarYRellenarEstadoInicial(const std::string&);
  void analizarSimboloBlanco(const std::string&) const;
  void analizarYRellenarConjuntoDeEstadosFinales(const std::string&);
  virtual void analizarYRellenarTransiciones(const std::string&) = 0;
  virtual void analizarFicheroMT(const std::string&) = 0;
 private:
  static std::unordered_map<std::string, std::function<ComprobarFicheroMT*(const std::string&)>> tipoMaquina_;
};