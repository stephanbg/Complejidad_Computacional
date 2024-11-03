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
 * @file comprobarFicheroMT.cc
 * @brief Implementación de la clase ComprobarFicheroMT
 * 
 * Para validar y procesar archivos de definición de Máquinas de Turing.
 * 
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p03}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/blob/main/p03/doc/CC_2425_Practica3.pdf}
 */

#include "./comprobarFicheroMT.h"
#include "./comprobarFicheroMT_LRS/comprobarFicheroMT_LRS.h"
#include "./comprobarFicheroMT_MultiCinta/comprobarFicheroMT_MultiCinta.h"

// Inicializa el mapa que asocia los tipos de máquinas con sus respectivos comprobadores
std::unordered_map<std::string, std::function<ComprobarFicheroMT*(const std::string&, const int)>>
ComprobarFicheroMT::tipoMaquina_ = {
  {"LRS", [](const std::string& nombreFichero, const int) {
    return new ComprobarFicheroMT_LRS(nombreFichero); }
  },
  {"Multicinta", [](const std::string& nombreFichero, const int kNumCintas) {
    return new ComprobarFicheroMT_MultiCinta(nombreFichero, kNumCintas); }
  }
  // Se pueden agregar más tipos de máquinas aquí
};

/**
 * @brief Crea un comprobador basado en el nombre del archivo.
 * 
 * @param kNombreFichero Nombre del archivo a comprobar.
 * @return ComprobarFicheroMT* Puntero al objeto ComprobarFicheroMT creado.
 * 
 * @throws Si no se puede abrir el archivo o si el archivo
 *         no contiene suficientes líneas válidas.
 */
ComprobarFicheroMT* ComprobarFicheroMT::crearComprobador(const std::string& kNombreFichero) {
  std::ifstream fichero(kNombreFichero);
  if (!fichero.is_open()) {
    const std::string kErrorApertura = "Error al abrir el fichero: " + kNombreFichero;
    throw (kErrorApertura);
  }
  std::string linea;
  int contadorLineas = 0;
  while (contadorLineas < 7 && std::getline(fichero, linea)) {
    ComprobarFicheroMT::eliminarComentarios(linea);
    if (ComprobarFicheroMT::lineaCompletaDeEspacios(linea)) continue;
    if (++contadorLineas == 7) {
      int numCintas;
      linea.erase(remove_if(linea.begin(), linea.end(), ::isspace), linea.end());
      std::istringstream iss(linea);
      iss >> numCintas;
      if (iss.fail() || (numCintas < 2)) return tipoMaquina_["LRS"](kNombreFichero, 1);
      else return tipoMaquina_["Multicinta"](kNombreFichero, numCintas);
    }
  }
  fichero.close();
  if (fichero.is_open()) {
    const std::string kErrorCierre = "Error al cerrar el fichero: " + kNombreFichero;
    throw (kErrorCierre);
  }  
  const std::string kErrorCantidadLineas = "Fichero no contiene suficientes líneas válidas.";
  throw (kErrorCantidadLineas);
}

/**
 * @brief Analiza el archivo de la Máquina de Turing.
 * 
 * @param kNombreFichero Nombre del archivo a analizar.
 * 
 * @throws Si no se puede abrir o cerrar el archivo, o si hay
 *         un error durante el análisis de datos.
 */
void ComprobarFicheroMT::analizarFicheroMT(const std::string& kNombreFichero) {
  std::ifstream fichero(kNombreFichero);
  // Abrir Fichero
  if (!fichero.is_open()) {
    mensajeError_ = "Error al abrir el fichero: " + kNombreFichero;
    throw (mensajeError_);
  }
  // Análisis de Datos
  std::string linea;
  int contador = 0;
  while (std::getline(fichero, linea)) {
    // Limpiar línea
    if (linea == "") continue;
    ComprobarFicheroMT::eliminarComentarios(linea);
    if (linea == "") continue;
    if (ComprobarFicheroMT::lineaCompletaDeEspacios(linea)) continue;
    // Comprobar Datos y Rellenar MT
    int numCintas;
    std::istringstream iss(linea);
    switch(contador) {
      case 0: // Conjunto de estados
        analizarYRellenarConjuntoDeEstados(linea);
        break;
      case 1: // Alfabeto Entrada
        analizarYRellenarAlfabetoEntrada(linea);
        break;
      case 2: // Alfabeto Cinta
        analizarYRellenarAlfabetoCinta(linea);
        break;
      case 3: // Estado Inicial
        analizarYRellenarEstadoInicial(linea);
        break;
      case 4: // Simbolo Blanco
        analizarSimboloBlanco(linea);
        break;
      case 5: // Conjuntos de estados finales o número de cintas
        analizarYRellenarConjuntoDeEstadosFinales(linea);
        break;
      case 6:
        iss >> numCintas;
        if (!(iss.fail() || numCintas <= 0)) { // Saltarse Fila opcional
          contador++;
          while (std::getline(fichero, linea)) {
            ComprobarFicheroMT::eliminarComentarios(linea);
            if (!ComprobarFicheroMT::lineaCompletaDeEspacios(linea)) break;
          }            
        }
        analizarYRellenarTransiciones(linea);
        break;
      default: // Transiciones hasta final de fichero
        analizarYRellenarTransiciones(linea);
        break;
    }
    contador++;
  }
  // Cerrar Fichero
  fichero.close();
  if (fichero.is_open()) {
    mensajeError_ = "Error al cerrar el fichero: " + kNombreFichero;
    throw (mensajeError_);
  }
}

/**
 * @brief Elimina los comentarios de una línea.
 * 
 * @param linea Referencia a la línea de texto de la que se eliminarán los comentarios.
 */
void ComprobarFicheroMT::eliminarComentarios(std::string& linea) {
  const std::size_t kPosComentario = linea.find('#');
  if (kPosComentario != std::string::npos) linea = linea.substr(0, kPosComentario);
}

/**
 * @brief Verifica si una línea está compuesta solo por espacios.
 * 
 * @param kLinea Línea a verificar.
 * @return true Si la línea está compuesta solo por espacios.
 * @return false En caso contrario.
 */
bool ComprobarFicheroMT::lineaCompletaDeEspacios(const std::string& kLinea) {
  return (std::all_of(kLinea.begin(), kLinea.end(), ::isspace)) ? true : false;
}

/**
 * @brief Analiza y llena el conjunto de estados de la Máquina de Turing.
 * 
 * @param kLinea Línea que contiene el conjunto de estados.
 */
void ComprobarFicheroMT::analizarYRellenarConjuntoDeEstados(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string estado;
  while (stream >> estado) maquinaTuring_->setEstados().insert(Estado(estado));
}

/**
 * @brief Analiza y llena el alfabeto de entrada de la Máquina de Turing.
 * 
 * @param kLinea Línea que contiene el alfabeto de entrada.
 * 
 * @throws Si algún símbolo no es un carácter o si hay símbolos prohibidos.
 */
void ComprobarFicheroMT::analizarYRellenarAlfabetoEntrada(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoChar = "Algún símbolo del alfabeto de entrada no es un char.",
                    kErrorSimbProhibido = "Algún símbolo del alfabeto de entrada es '" +
                                          std::string(1, maquinaTuring_->getSimboloBlanco()) + "'.";
  char simbolo;
  while (stream >> elemento) {
    if (elemento.size() != 1) throw (kErrorNoChar);
    else if (elemento[0] == maquinaTuring_->getSimboloBlanco()) throw (kErrorSimbProhibido);
    simbolo = elemento[0];
    maquinaTuring_->setAlfabetoEntrada().insertar(simbolo);
  }
}

/**
 * @brief Analiza y llena el alfabeto de la cinta de la Máquina de Turing.
 * 
 * @param kLinea Línea que contiene el alfabeto de la cinta.
 * 
 * @throws Si hay un símbolo que no es un carácter y no existe el blanco o si no contiene el alfabeto de entrada.
 */
void ComprobarFicheroMT::analizarYRellenarAlfabetoCinta(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoChar = "Algún símbolo del alfabeto de cinta no es un char.",
                    kErrorNoContieneAlfabetoDeEntrada = "Alfabeto de Entrada no contenido en el de cinta.",
                    kErrorNoBlanco = "Tiene que existir el blanco en el alfabeto cinta.";
  char simbolo;
  bool existeBlanco = false;
  while (stream >> elemento) {
    if (elemento.size() != 1) throw (kErrorNoChar);
    simbolo = elemento[0];
    if (simbolo == maquinaTuring_->getSimboloBlanco()) existeBlanco = true;
    maquinaTuring_->setAlfabetoCinta().insertar(simbolo);
  }
  if (!existeBlanco) throw (kErrorNoBlanco);
  if (
    !maquinaTuring_->getAlfabetoCinta().contieneA(maquinaTuring_->getAlfabetoEntrada())
  ) throw(kErrorNoContieneAlfabetoDeEntrada);
}

/**
 * @brief Analiza y llena el estado inicial de la Máquina de Turing.
 * 
 * @param kLinea Línea que contiene el estado inicial.
 * 
 * @throws Si no existe el estado inicial o si hay más de uno.
 */
void ComprobarFicheroMT::analizarYRellenarEstadoInicial(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  const std::string kErrorNoExiste = "No existe el Estado Inicial.",
                    kErrorNoHaySoloUno = "Tiene que existir solo un Estado Inicial.";
  std::string estado;
  stream >> estado;
  // Verifica que no haya más de un estado inicial.
  if (stream >> estado) throw (kErrorNoHaySoloUno);
  // Buscar el puntero del estado correspondiente en el conjunto de estados.
  Estado estadoAux;
  bool existeEstadoInicial = false;
  for (const Estado& kEstado : maquinaTuring_->getEstados()) {
    if (kEstado.getId() == estado) {
      estadoAux = kEstado;
      existeEstadoInicial = true;
      break;
    }
  }
  // Si no se encuentra el estado, lanzar una excepción.
  if (existeEstadoInicial == false) throw (kErrorNoExiste);
  maquinaTuring_->setEstadoInicial() = estadoAux;
}

/**
 * @brief Analiza el símbolo blanco a partir de una línea de entrada.
 * 
 * Este método verifica si el primer símbolo de la línea es el símbolo blanco
 * esperado. Si hay más de un símbolo, lanza una excepción indicando que solo
 * debe existir un símbolo blanco. También verifica que el símbolo leído
 * coincida con el símbolo blanco definido en la máquina de Turing.
 * 
 * @param kLinea Línea de entrada que contiene el símbolo blanco.
 * @throws Si el símbolo no es el esperado o hay más de uno.
 */
void ComprobarFicheroMT::analizarSimboloBlanco(const std::string& kLinea) const {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoEsSimboloBlanco = "No es símbolo blanco.",
                    kErrorNoHaySoloUno = "Tiene que existir solo un símbolo blanco.";
  stream >> elemento;
  if (stream >> elemento) throw (kErrorNoHaySoloUno);
  else if (elemento.size() != 1 || elemento[0] != maquinaTuring_->getSimboloBlanco()) throw (kErrorNoEsSimboloBlanco);
}

/**
 * @brief Analiza y rellena el conjunto de estados finales a partir de una línea de entrada.
 * 
 * Este método extrae los estados finales de la línea de entrada. Si algún estado 
 * no existe en el conjunto de estados de la máquina de Turing, lanza una excepción.
 * También verifica que haya al menos un estado final definido. Los estados 
 * finales se insertan en un conjunto que se asigna a la máquina de Turing.
 * 
 * @param kLinea Línea de entrada que contiene los estados finales.
 * @throws Si algún estado no existe o si no hay estados finales definidos.
 */
void ComprobarFicheroMT::analizarYRellenarConjuntoDeEstadosFinales(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string estado;
  const std::string kErrorNoExisteAlgúnEstadoFinal = "No existe algún Estado Final.",
                    kErrorMinimoTieneQueSerUno = "Tiene que existir al menos un Estado Final.";  
  std::set<Estado> estadosFinales;
  while (stream >> estado) {
    Estado estadoNuevo(estado, true);
    if (maquinaTuring_->getEstados().find(estadoNuevo) == maquinaTuring_->getEstados().end()) {
      throw(kErrorNoExisteAlgúnEstadoFinal);
    } else estadosFinales.insert(estadoNuevo);
  }
  if (estadosFinales.empty()) throw(kErrorMinimoTieneQueSerUno);
  maquinaTuring_->setEstadosFinales() = estadosFinales;
}