#pragma once

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>


/**
 * @brief Clase que representa una variable
 */
class Variable {
 public:
  Variable() : id_(), is_negated_() {}
  Variable(const nlohmann::json& json);

  int GetId() const { return id_; }
  bool IsNegated() const { return is_negated_; }

  friend std::ostream& operator<<(std::ostream& output, const Variable& variable);

 private:
  int id_;
  bool is_negated_;
};