#pragma once

#include <vector>
#include <string>

class Transicion;

class Estado {
 public:
  Estado(const bool kEstadoFinal = false) : estadoFinal_(kEstadoFinal) {}
  Estado(const std::string& kId, const bool kEstadoFinal = false) {
    id_ = kId;
    estadoFinal_ = kEstadoFinal;
  }
  void agregarTransicion(const Transicion& kTransicion) { transiciones_.push_back(kTransicion); }
  const std::string getId() const {return id_; }
  const std::vector<Transicion> getTransiciones() const { return transiciones_; }
  std::string& setId() {return id_; }
  bool operator<(const Estado& kOtro) const { return id_ < kOtro.id_; }
  bool operator==(const Estado& kOtro) const { return id_ == kOtro.id_; }
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