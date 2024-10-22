/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file estado.h
 * @brief Definición de la clase Estado para el simulador de un autómata con pila.
 * 
 * Esta clase representa un estado en un autómata y gestiona las transiciones asociadas a dicho estado.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#pragma once

#include <vector>
#include <string>

class Transicion;

/**
 * @brief Clase que representa un estado en un autómata.
 */
class Estado {
 public:
  /**
   * @brief Constructor por defecto que inicializa el estado como no final.
   * 
   * @param kEstadoFinal Indica si el estado es final (por defecto es false).
   */
  Estado(const bool kEstadoFinal = false) : estadoFinal_(kEstadoFinal) {}
  /**
   * @brief Constructor que inicializa el estado con un identificador y estado final.
   * 
   * @param kId Identificador del estado.
   * @param kEstadoFinal Indica si el estado es final (por defecto es false).
   */
  Estado(const std::string& kId, const bool kEstadoFinal = false) {
    id_ = kId;
    estadoFinal_ = kEstadoFinal;
  }
  /**
   * @brief Agrega una transición al estado.
   * 
   * @param kTransicion La transición que se va a agregar.
   */
  void agregarTransicion(const Transicion& kTransicion) { transiciones_.push_back(kTransicion); }
  const std::string getId() const {return id_; }
  const std::vector<Transicion> getTransiciones() const { return transiciones_; }
  std::string& setId() {return id_; }
  /**
   * @brief Sobrecarga del operador de inserción para imprimir el estado.
   * 
   * @param os Flujo de salida.
   * @param kEstado Estado a imprimir.
   * @return std::ostream& Flujo de salida modificado.
   */
  friend std::ostream& operator<<(std::ostream& os, const Estado& kEstado) {
    std::cout << kEstado.id_;
    if (kEstado.estadoFinal_) os << " (EstadoFinal)";
    return os;
  }
 private:
  std::string id_;
  bool estadoFinal_; 
  std::vector<Transicion> transiciones_;
};