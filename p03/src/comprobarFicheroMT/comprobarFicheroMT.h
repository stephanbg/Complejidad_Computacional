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
 * @file comprobarFicheroMT.h
 * @brief Clase para validar y procesar archivos de definición de Máquinas de Turing.
 * 
 * Esta clase proporciona métodos para analizar la estructura y los componentes
 * de un archivo que define una Máquina de Turing, como estados, alfabetos,
 * transiciones, etc. Se utiliza para crear instancias de Máquina de Turing
 * y detectar errores en la definición del archivo.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../MT/MT.h"

class ComprobarFicheroMT_LRS;
class ComprobarFicheroMT_MultiCinta;

/**
 * @brief Clase base para verificar la validez de archivos de definición de
 * Máquinas de Turing de un solo cinta o múltiples cintas.
 */
class ComprobarFicheroMT {
 public:
  static ComprobarFicheroMT* crearComprobador(const std::string& kNombreFichero);
  MaquinaTuring*& setMaquinaTuring() { return maquinaTuring_; }
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
  static std::unordered_map<std::string, std::function<ComprobarFicheroMT*(const std::string&, const int)>> tipoMaquina_;
};