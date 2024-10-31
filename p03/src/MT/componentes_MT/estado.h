#pragma once

#include <iostream>
#include <string>
#include <functional>

class Estado {
 public:
  Estado() : id_(""), estadoAceptacion_(false) {}
  Estado(const std::string& kId, bool kEstadoAceptacion = false)
    : id_(kId), estadoAceptacion_(kEstadoAceptacion) {}
  bool esEstadoAceptacion() const { return estadoAceptacion_; }    
  const bool operator==(const Estado& kOtro) const { return id_ == kOtro.id_; }
  const bool operator<(const Estado& kOtro) const { return id_ < kOtro.id_; }
  const std::string& getId() const { return id_; }
  friend std::ostream& operator<<(std::ostream& os, const Estado& kEstado) {
    std::cout << kEstado.id_;
    if (kEstado.estadoAceptacion_) os << " (EstadoFinal)";
    return os;
  }
 private:
  std::string id_;
  bool estadoAceptacion_;
};

namespace std {
  template <>
  struct hash<Estado> {
    std::size_t operator()(const Estado& estado) const {
      return hash<std::string>()(estado.getId());
    }
  };
}
