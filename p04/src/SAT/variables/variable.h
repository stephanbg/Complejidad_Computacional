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
  Variable(int id, bool is_negated) : id_(id), is_negated_(is_negated) {}
  Variable(const nlohmann::json& json) : id_(json["variable"]), is_negated_(json["format"].get<int>() == 1) {}

  int GetId() const { return id_; }
  bool IsNegated() const { return is_negated_; }

  friend std::ostream& operator<<(std::ostream& output, const Variable& variable);

 private:
  int id_;
  bool is_negated_;
};