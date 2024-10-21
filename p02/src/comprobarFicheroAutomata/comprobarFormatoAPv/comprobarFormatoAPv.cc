#include "./comprobarFormatoAPv.h"

ComprobarFormatoAPv::ComprobarFormatoAPv() { automataDePila_ = new APv; }

void ComprobarFormatoAPv::analizarFicheroAutomata(const std::string& kNombreFichero) {
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
    eliminarComentarios(linea);
    if (linea == "") continue;
    if (lineaCompletaDeEspacios(linea)) continue;
    // Comprobar Datos y Rellenar APv
    switch(contador) {
      case 0: // Conjunto de estados
        analizarYRellenarConjuntoDeEstados(linea);
        break;
      case 1: // Alfabeto
        analizarYRellenarAlfabeto(linea);
        break;
      case 2: // Alfabeto Pila
        analizarYRellenarAlfabetoPila(linea);
        break;
      case 3: // Estado Inicial
        analizarYRellenarEstadoInicial(linea);
        break;
      case 4: // Simbolo Inicial Pila
        analizarYRellenarSimboloInicialPila(linea);
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

void ComprobarFormatoAPv::eliminarComentarios(std::string& linea) const {
  const std::size_t kPosComentario = linea.find('#');
  if (kPosComentario != std::string::npos) linea = linea.substr(0, kPosComentario);
}

bool ComprobarFormatoAPv::lineaCompletaDeEspacios(const std::string& kLinea) const {
  return (std::all_of(kLinea.begin(), kLinea.end(), ::isspace)) ? true : false;
}

void ComprobarFormatoAPv::analizarYRellenarConjuntoDeEstados(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string estado;
  while (stream >> estado) automataDePila_->setEstados().insert(Estado(estado));
}

void ComprobarFormatoAPv::analizarYRellenarAlfabeto(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoChar = "Algún símbolo del alfabeto no es un char.",
                    kErrorSimbProhibido = "Algún símbolo del alfabeto es '.' o mayúscula.";
  char simbolo;
  while (stream >> elemento) {
    if (elemento.size() != 1) throw (kErrorNoChar);
    else if (elemento[0] == '.' || (elemento[0] >= 'A' && elemento[0] <= 'Z')) throw (kErrorSimbProhibido);
    simbolo = elemento[0];
    automataDePila_->setAlfabeto().insertar(simbolo);
  }
}

void ComprobarFormatoAPv::analizarYRellenarAlfabetoPila(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoChar = "Algún símbolo del alfabeto de pila no es un char.",
                    kErrorSimbProhibido = "Algún símbolo del alfabeto de pila es '.' o minúscula.";
  char simbolo;
  while (stream >> elemento) {
    if (elemento.size() != 1) throw (kErrorNoChar);
    else if (elemento[0] == '.' /* (elemento[0] >= 'a' && elemento[0] <= 'z') */) throw (kErrorSimbProhibido);
    simbolo = elemento[0];
    automataDePila_->setAlfabetoPila().insertar(simbolo);
  }
}

void ComprobarFormatoAPv::analizarYRellenarEstadoInicial(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoExiste = "No existe el Estado Inicial.",
                    kErrorNoHaySoloUno = "Tiene que existir solo un Estado Inicial.";
  std::string estado;
  stream >> estado;
  if (stream >> estado) throw (kErrorNoHaySoloUno);
  bool estadoExiste = false;
  for (const auto& a : automataDePila_->getEstados()) {
    if (a.getId() == estado) {
      estadoExiste = true;
      break;
    }
  }
  if (!estadoExiste) throw (kErrorNoExiste);
  automataDePila_->setEstadoInicial() = Estado(estado);
}

void ComprobarFormatoAPv::analizarYRellenarSimboloInicialPila(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoExiste = "No existe el Símbolo Inicial de la Pila.",
                    kErrorNoHaySoloUno = "Tiene que existir solo un Símbolo Inicial de la Pila.";
  stream >> elemento;
  if (stream >> elemento) throw (kErrorNoHaySoloUno);
  char simbolo = elemento[0];
  bool simboloExiste = false;
  for (const auto& a : automataDePila_->getAlfabetoPila().getConjuntoAlfabeto()) {
    if (a == simbolo) {
      simboloExiste = true;
      break;
    }
  }
  if (!simboloExiste) throw (kErrorNoExiste);
  automataDePila_->setSimboloInicialPila() = simbolo;
}

void ComprobarFormatoAPv::analizarYRellenarTransiciones(const std::string& kLinea) {
  const std::string kErrorExiste = "No pueden existir transiciones repetidas.",
                    kErrorCantidadElementos = "Una transición sólo puede estar formada por 5 elementos.",
                    kErrorEstado = "Algún estado desconocido.",
                    kErrorSimboloAlfabeto = "Algún símbolo del alfabeto desconocido.",
                    kErrorSimboloAlfabetoPila = "Algún símbolo del alfabeto de la pila desconocido.",
                    kErrorSímboloAlfabetoSize1 = "Algún símbolo del alfabeto tiene size > 1.",
                    kErrorSímboloAlfabetoPilaSize1 = "Algún símbolo del alfabeto de la pila tiene size > 1.",
                    kErrorSimboloInsertarEnPila = "Algún símbolo a introducir en la pila desconocido.";
  if (existeTransicion(kLinea)) throw (kErrorExiste);
  std::istringstream stream(kLinea);
  const int kLimiteElemTransicion = 5;
  int contador = 0;
  const std::set<Estado>& kEstados = automataDePila_->getEstados();
  const std::set<char>& kConjuntoAlfabeto = automataDePila_->getAlfabeto().getConjuntoAlfabeto();
  const std::set<char>& kConjuntoAlfabetoPila = automataDePila_->getAlfabetoPila().getConjuntoAlfabeto();
  Estado estadoOrigen, estadoDestino;
  char simboloTransicion, elementoAExtraerDePila;
  std::string elemento, simbolosAIntroducirEnPila;
  while (stream >> elemento) {
    switch (contador) {
      case 0:
        if (kEstados.find(Estado(elemento)) == kEstados.end()) throw (kErrorEstado);
        else estadoOrigen.setId() = elemento;
        break;
      case 1:
        if (elemento.size() != 1) throw (kErrorSímboloAlfabetoSize1);
        else if (kConjuntoAlfabeto.find(elemento[0]) == kConjuntoAlfabeto.end()) throw (kErrorSimboloAlfabeto);
        else simboloTransicion = elemento[0];
        break;
      case 2:
        if (elemento.size() != 1) throw (kErrorSímboloAlfabetoPilaSize1);
        else if (kConjuntoAlfabetoPila.find(elemento[0]) == kConjuntoAlfabetoPila.end()) throw (kErrorSimboloAlfabetoPila);      
        else elementoAExtraerDePila = elemento[0];
        break;
      case 3:
        if (kEstados.find(Estado(elemento)) == kEstados.end()) throw (kErrorEstado);
        else estadoDestino.setId() = elemento;
        break;        
      case 4:
        for (int i = 0; i < elemento.size(); ++i) {
          if (kConjuntoAlfabetoPila.find(elemento[i]) == kConjuntoAlfabetoPila.end()) throw (kErrorSimboloInsertarEnPila);
        }
        simbolosAIntroducirEnPila = elemento;
        break;
      default:
        break;
    }
    contador++;
  }
  if (contador != kLimiteElemTransicion) throw (kErrorCantidadElementos);
  automataDePila_->setTransiciones().push_back(
    Transicion(estadoOrigen, simboloTransicion, elementoAExtraerDePila, estadoDestino, simbolosAIntroducirEnPila)
  );
}

bool ComprobarFormatoAPv::existeTransicion(const std::string& kLinea) const {
  std::istringstream stream(kLinea);
  std::string elemento;
  const int kLimiteElementosTransicion = 5;
  int contadorElemento;
  bool existeTransicion;
  for (int i = automataDePila_->getTransiciones().size() - 1; i >= 0; --i) {
    existeTransicion = true;
    contadorElemento = 0;
    while (stream >> elemento) {
      switch (contadorElemento) {
        case 0: // Comparando estado origen
          if (elemento != automataDePila_->getTransiciones()[i].getEstadoOrigen().getId()) existeTransicion = false;
          break;
        case 1: // Comparando símbolo transición
          if (
            elemento.size() != 1 ||
            elemento[0] != automataDePila_->getTransiciones()[i].getSimboloTransicion()
          ) existeTransicion = false;
          break;
        case 2: // Comparando símbolo a extraer de la pila
          if (
            elemento.size() != 1 ||
            elemento[0] != automataDePila_->getTransiciones()[i].getElementoAExtraerDePila()
          ) existeTransicion = false;          
          break;
        case 3: // Comparando estado destino
          if (elemento != automataDePila_->getTransiciones()[i].getEstadoDestino().getId()) existeTransicion = false;
          break;
        case 4: // Comparando símbolos a introducir en la pila
          if (elemento != automataDePila_->getTransiciones()[i].getSimbolosAIntroducirEnPila()) existeTransicion = false;
          break;
        default: // Te pasas del límite seguro que no existe
          existeTransicion = false;
          break;
      }
      contadorElemento++;
    }
    if (existeTransicion && contadorElemento == kLimiteElementosTransicion) return true;
  }
  return false;
}