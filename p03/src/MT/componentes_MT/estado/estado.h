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
 * @file estado.h
 * @brief Definición de la clase Estado.
 *
 * Esta clase representa un estado en una máquina de Turing, incluyendo su
 * identificador y si es un estado de aceptación. También se proporciona
 * sobrecargas para la comparación de estados y su impresión.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#pragma once

#include <iostream>
#include <string>
#include <functional>

/**
 * @brief Clase que representa un estado en una máquina de Turing.
 */
class Estado {
 public:
  Estado() : id_(""), estadoAceptacion_(false) {}
  Estado(const std::string& kId, bool kEstadoAceptacion = false)
    : id_(kId), estadoAceptacion_(kEstadoAceptacion) {}
  const bool esEstadoAceptacion() const { return estadoAceptacion_; }      
  const bool operator==(const Estado& kOtro) const { return id_ == kOtro.id_; }
  const bool operator<(const Estado& kOtro) const { return id_ < kOtro.id_; }
  const std::string& getId() const { return id_; }
  friend std::ostream& operator<<(std::ostream& os, const Estado& kEstado) {
    std::cout << kEstado.id_;
    return os;
  }
 private:
  std::string id_;
  bool estadoAceptacion_;
};

namespace std {
  template <>
  struct hash<Estado> {
    /**
     * @brief Función que calcula el hash de un estado.
     *
     * Esta función utiliza el identificador del estado para generar
     * un valor de hash, lo que permite que los objetos de la clase 
     * Estado puedan ser utilizados como claves en estructuras de 
     * datos que requieren hashing, como std::unordered_map.
     *
     * @param kEstado Referencia constante al estado del cual se 
     *               quiere calcular el hash.
     * @return std::size_t Valor de hash del estado.
     */    
    std::size_t operator()(const Estado& kEstado) const {
      return hash<std::string>()(kEstado.getId());
    }
  };
}
