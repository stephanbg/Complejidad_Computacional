#include "./comprobarFicheroMT.h"
#include "./comprobarFicheroMT_LRS/comprobarFicheroMT_LRS.h"      // Agregar esta línea
#include "./comprobarFicheroMT_MultiCinta/comprobarFicheroMT_MultiCinta.h"  // Agregar esta línea

// Inicializa el mapa con criterios más flexibles
std::unordered_map<std::string, std::function<ComprobarFicheroMT*(const std::string&)>>
ComprobarFicheroMT::tipoMaquina_ = {
  {"LRS", [](const std::string& nombreFichero) { return new ComprobarFicheroMT_LRS(nombreFichero); }},
  {"Multicinta", [](const std::string& nombreFichero) { return new ComprobarFicheroMT_MultiCinta(nombreFichero); }}
  // Agrega más tipos de máquinas aquí
};

ComprobarFicheroMT* ComprobarFicheroMT::crearComprobador(const std::string& kNombreFichero) {
  std::ifstream fichero(kNombreFichero);
  if (!fichero.is_open()) throw std::runtime_error("Error al abrir el fichero.");
  std::string linea;
  int contadorLineas = 0;
  while (contadorLineas < 6 && std::getline(fichero, linea)) {
    ComprobarFicheroMT::eliminarComentarios(linea);
    if (ComprobarFicheroMT::lineaCompletaDeEspacios(linea)) continue;
    if (++contadorLineas == 6) {
      int numCintas;
      linea.erase(remove_if(linea.begin(), linea.end(), ::isspace), linea.end());
      std::istringstream iss(linea);
      iss >> numCintas;
      if (iss.fail() || (numCintas < 2)) return tipoMaquina_["LRS"](kNombreFichero);
      else return tipoMaquina_["Multicinta"](kNombreFichero);
    }
  }
  throw std::runtime_error("Fichero no contiene suficientes líneas válidas.");
}

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
          iss >> numCintas;
          if (!(iss.fail() || numCintas <= 0)) { // Si no falla era número
            std::getline(fichero, linea);
            contador++; // Fila opcional
          }
          analizarYRellenarConjuntoDeEstadosFinales(linea);
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

void ComprobarFicheroMT::eliminarComentarios(std::string& linea) {
  const std::size_t kPosComentario = linea.find('#');
  if (kPosComentario != std::string::npos) linea = linea.substr(0, kPosComentario);
}


bool ComprobarFicheroMT::lineaCompletaDeEspacios(const std::string& kLinea) {
  return (std::all_of(kLinea.begin(), kLinea.end(), ::isspace)) ? true : false;
}

void ComprobarFicheroMT::analizarYRellenarConjuntoDeEstados(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string estado;
  while (stream >> estado) maquinaTuring_->setEstados().insert(Estado(estado));
}
void ComprobarFicheroMT::analizarYRellenarAlfabetoEntrada(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoChar = "Algún símbolo del alfabeto de entrada no es un char.",
                    kErrorSimbProhibido = "Algún símbolo del alfabeto de entrada es 'b'.";
  char simbolo;
  while (stream >> elemento) {
    if (elemento.size() != 1) throw (kErrorNoChar);
    else if (elemento[0] == maquinaTuring_->getSimboloBlanco()) throw (kErrorSimbProhibido);
    simbolo = elemento[0];
    maquinaTuring_->setAlfabetoEntrada().insertar(simbolo);
  }
}

void ComprobarFicheroMT::analizarYRellenarAlfabetoCinta(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoChar = "Algún símbolo del alfabeto de cinta no es un char.";
  char simbolo;
  while (stream >> elemento) {
    if (elemento.size() != 1) throw (kErrorNoChar);
    simbolo = elemento[0];
    maquinaTuring_->setAlfabetoCinta().insertar(simbolo);
  }
}

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

void ComprobarFicheroMT::analizarSimboloBlanco(const std::string& kLinea) const {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoEsSimboloBlanco = "No es símbolo blanco.",
                    kErrorNoHaySoloUno = "Tiene que existir solo un símbolo blanco.";
  stream >> elemento;
  if (stream >> elemento) throw (kErrorNoHaySoloUno);
  else if (elemento.size() != 1 || elemento[0] != '.') throw (kErrorNoEsSimboloBlanco);
}

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