#pragma once

class ContarLlamadasAFunciones {
 public:
  static int getContador() { return contador_; }
  static int& setContador() { return contador_; }
 private:
  static int contador_;
};