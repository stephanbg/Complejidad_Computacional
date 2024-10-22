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
  while (stream >> estado) automataDePila_->setEstados().insert(new Estado(estado));
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
    else if (elemento[0] == '.') throw (kErrorSimbProhibido);
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
  // Verifica que no haya más de un estado inicial.
  if (stream >> estado) throw (kErrorNoHaySoloUno);
  // Buscar el puntero del estado correspondiente en el conjunto de estados.
  Estado* estadoInicialPtr = nullptr;
  for (const auto& a : automataDePila_->getEstados()) {
    if (a->getId() == estado) {
      estadoInicialPtr = a;
      break;
    }
  }
  // Si no se encuentra el estado, lanzar una excepción.
  if (estadoInicialPtr == nullptr) throw (kErrorNoExiste);
  // Asignar el puntero al estado inicial.
  automataDePila_->setEstadoInicial() = estadoInicialPtr;
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

  if (existeTransicion(kLinea)) throw kErrorExiste;
  std::istringstream stream(kLinea);
  const int kLimiteElemTransicion = 5;
  int contador = 0;
  const std::set<Estado*>& kEstados = automataDePila_->getEstados();
  const std::set<char>& kConjuntoAlfabeto = automataDePila_->getAlfabeto().getConjuntoAlfabeto();
  const std::set<char>& kConjuntoAlfabetoPila = automataDePila_->getAlfabetoPila().getConjuntoAlfabeto();
  Estado* estadoOrigen = nullptr;
  Estado* estadoDestino = nullptr;
  char simboloTransicion, elementoAExtraerDePila;
  std::string elemento, simbolosAIntroducirEnPila;
  while (stream >> elemento) {
    switch (contador) {
      case 0: {
        auto it = std::find_if(kEstados.begin(), kEstados.end(), [&elemento](Estado* estado) { return estado->getId() == elemento; });
        if (it == kEstados.end()) throw kErrorEstado;
        estadoOrigen = *it;  // Obtener el puntero al estado encontrado
        break;
      }
      case 1:
        // Validar símbolo de transición
        if (elemento.size() != 1) throw kErrorSímboloAlfabetoSize1;
        if (kConjuntoAlfabeto.find(elemento[0]) == kConjuntoAlfabeto.end()) throw kErrorSimboloAlfabeto;
        simboloTransicion = elemento[0];
        break;
      case 2:
        // Validar símbolo a extraer de la pila
        if (elemento.size() != 1) throw kErrorSímboloAlfabetoPilaSize1;
        if (kConjuntoAlfabetoPila.find(elemento[0]) == kConjuntoAlfabetoPila.end()) throw kErrorSimboloAlfabetoPila;
        elementoAExtraerDePila = elemento[0];
        break;
      case 3: {
        // Buscar estado destino en el conjunto de punteros
        auto it = std::find_if(kEstados.begin(), kEstados.end(), [&elemento](Estado* estado) { return estado->getId() == elemento; });
        if (it == kEstados.end()) throw kErrorEstado;
        estadoDestino = *it;  // Obtener el puntero al estado encontrado
        break;
      }
      case 4:
        // Validar símbolos a insertar en la pila
        for (char simbolo : elemento) {
          if (kConjuntoAlfabetoPila.find(simbolo) == kConjuntoAlfabetoPila.end()) throw kErrorSimboloInsertarEnPila;
        }
        simbolosAIntroducirEnPila = elemento;
        break;
      default:
        break;
    }
    contador++;
  }
  // Verificar si se ingresaron exactamente 5 elementos
  if (contador != kLimiteElemTransicion) throw kErrorCantidadElementos;
  // Agregar la nueva transición al autómata
  Transicion nuevaTransicion(estadoOrigen, simboloTransicion, elementoAExtraerDePila, estadoDestino, simbolosAIntroducirEnPila);
  // Añadir la transición al estado de origen
  estadoOrigen->agregarTransicion(nuevaTransicion);
}

bool ComprobarFormatoAPv::existeTransicion(const std::string& kLinea) const {
  std::string elemento;
  const int kLimiteElementosTransicion = 5;
  int contadorElemento;
  bool existeTransicion;
  for (const Estado* estado : automataDePila_->getEstados()) {
    for (int i = 0; i < estado->getTransiciones().size(); ++i) {
      existeTransicion = true;
      contadorElemento = 0;
      // Reinicia el flujo de entrada para cada transición
      std::istringstream stream(kLinea);    
      while (stream >> elemento) {
        switch (contadorElemento) {
          case 0: // Comparando estado origen
            if (elemento != estado->getId()) existeTransicion = false;
            break;
          case 1: // Comparando símbolo transición
            if (
              elemento.size() != 1 ||
              elemento[0] != estado->getTransiciones()[i].getSimboloTransicion()
            ) existeTransicion = false;
            break;
          case 2: // Comparando símbolo a extraer de la pila
            if (
              elemento.size() != 1 ||
              elemento[0] != estado->getTransiciones()[i].getElementoAExtraerDePila()
            ) existeTransicion = false;          
            break;
          case 3: // Comparando estado destino
            if (estado->getTransiciones()[i].getEstadoDestino() != nullptr && 
              elemento != estado->getTransiciones()[i].getEstadoDestino()->getId()
            ) existeTransicion = false;
            break;
          case 4: // Comparando símbolos a introducir en la pila
            if (elemento != estado->getTransiciones()[i].getSimbolosAIntroducirEnPila()) existeTransicion = false;
            break;
          default: // Te pasas del límite seguro que no existe
            existeTransicion = false;
            break;
        }
        contadorElemento++;
      }
      if (existeTransicion && contadorElemento == kLimiteElementosTransicion) return true;
    }
  }
  return false;
}