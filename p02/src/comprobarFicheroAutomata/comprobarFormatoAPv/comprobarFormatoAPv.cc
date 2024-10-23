/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * Práctica 2: Programar un simulador de un autómata con pila
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Octubre de 2024
 * @file comprobarFormatoAPv.cc
 * @brief Implementación de la clase ComprobarFormatoAPv para analizar archivos de autómatas de pila (APv).
 * 
 * Esta clase proporciona la funcionalidad para leer y validar la estructura
 * de un archivo que define un autómata de pila, asegurando que cumpla con
 * el formato esperado y que los datos sean correctos.
 * 
 * @see {@link https://campusingenieriaytecnologia2425.ull.es/pluginfile.php/11658/mod_resource/content/25/CC_2425_Practica2.pdf}
 * @see {@link https://github.com/stephanbg/Complejidad_Computacional/tree/main/p02}
 */

#include "./comprobarFormatoAPv.h"

/**
 * @brief Constructor de la clase ComprobarFormatoAPv que inicializa un nuevo objeto
 *        de tipo APv para almacenar el autómata de pila que se está analizando.
 */
ComprobarFormatoAPv::ComprobarFormatoAPv() { automataDePila_ = new APv; }

/**
 * @brief Analiza un archivo de autómata de pila.
 * 
 * Este método abre el archivo especificado y lee su contenido línea por línea,
 * procesando cada línea para extraer la información del autómata de pila, como
 * estados, alfabeto y transiciones. Lanza excepciones si se encuentra algún
 * error durante el análisis.
 * 
 * @param kNombreFichero Ruta del archivo que se desea analizar.
 * @throws std::string Si ocurre un error al abrir o cerrar el archivo, o si el contenido es inválido.
 */
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

/**
 * @brief Elimina comentarios de una línea de texto.
 * 
 * Este método procesa una línea de texto y elimina cualquier comentario
 * que comience con el carácter '#', dejando solo el contenido relevante.
 * 
 * @param linea Referencia a la línea de texto de la cual se eliminarán los comentarios.
 */
void ComprobarFormatoAPv::eliminarComentarios(std::string& linea) const {
  const std::size_t kPosComentario = linea.find('#');
  if (kPosComentario != std::string::npos) linea = linea.substr(0, kPosComentario);
}

/**
 * @brief Comprueba si una línea está compuesta únicamente por espacios.
 * 
 * @param kLinea Línea a evaluar.
 * @return true Si la línea está vacía o contiene solo espacios.
 * @return false Si la línea contiene algún carácter no blanco.
 */
bool ComprobarFormatoAPv::lineaCompletaDeEspacios(const std::string& kLinea) const {
  return (std::all_of(kLinea.begin(), kLinea.end(), ::isspace)) ? true : false;
}

/**
 * @brief Analiza y rellena el conjunto de estados del autómata.
 * 
 * Este método toma una línea que contiene el conjunto de estados y los
 * añade al autómata.
 * 
 * @param kLinea Línea que contiene la información del conjunto de estados.
 */
void ComprobarFormatoAPv::analizarYRellenarConjuntoDeEstados(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string estado;
  while (stream >> estado) automataDePila_->setEstados().insert(new Estado(estado));
}

/**
 * @brief Analiza y rellena el alfabeto del autómata.
 * 
 * Este método toma una línea que contiene el alfabeto y valida que todos
 * los símbolos sean caracteres válidos. Lanza excepciones si encuentra
 * símbolos prohibidos.
 * 
 * @param kLinea Línea que contiene la información del alfabeto.
 * @throws std::string Si algún símbolo no es un carácter o es un símbolo prohibido.
 */
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

/**
 * @brief Analiza y rellena el alfabeto de la pila del autómata.
 * 
 * Este método toma una línea que contiene el alfabeto de la pila y valida que
 * todos los símbolos sean caracteres válidos, lanzando excepciones si encuentra
 * símbolos prohibidos.
 * 
 * @param kLinea Línea que contiene la información del alfabeto de pila.
 * @throws std::string Si algún símbolo no es un carácter o es un símbolo prohibido.
 */
void ComprobarFormatoAPv::analizarYRellenarAlfabetoPila(const std::string& kLinea) {
  std::istringstream stream(kLinea);
  std::string elemento;
  const std::string kErrorNoChar = "Algún símbolo del alfabeto de pila no es un char.",
                    kErrorSimbProhibido = "Algún símbolo del alfabeto de pila es '.'.";
  char simbolo;
  while (stream >> elemento) {
    if (elemento.size() != 1) throw (kErrorNoChar);
    else if (elemento[0] == '.') throw (kErrorSimbProhibido);
    simbolo = elemento[0];
    automataDePila_->setAlfabetoPila().insertar(simbolo);
  }
}

/**
 * @brief Analiza y rellena el estado inicial del autómata.
 * 
 * Este método toma una línea que contiene el estado inicial y verifica que
 * exista en el conjunto de estados, lanzando excepciones si no se encuentra
 * o si se proporciona más de un estado inicial.
 * 
 * @param kLinea Línea que contiene la información del estado inicial.
 * @throws std::string Si el estado inicial no existe o si hay más de uno.
 */
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

/**
 * @brief Analiza y rellena el símbolo inicial de la pila del autómata.
 * 
 * Este método toma una línea que contiene el símbolo inicial de la pila y
 * verifica que exista en el alfabeto de la pila, lanzando excepciones si no se
 * encuentra o si se proporciona más de uno.
 * 
 * @param kLinea Línea que contiene la información del símbolo inicial de la pila.
 * @throws std::string Si el símbolo inicial no existe o si hay más de uno.
 */
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
    if (a == simbolo && a != '.') {
      simboloExiste = true;
      break;
    }
  }
  if (!simboloExiste) throw (kErrorNoExiste);
  automataDePila_->setSimboloInicialPila() = simbolo;
}

/**
 * @brief Analiza y rellena las transiciones del autómata.
 * 
 * Este método toma una línea que describe una transición y valida que cada
 * elemento de la transición sea correcto, lanzando excepciones si hay errores.
 * 
 * @param kLinea Línea que contiene la información de la transición.
 * @throws std::string Si hay transiciones repetidas o elementos inválidos.
 */
void ComprobarFormatoAPv::analizarYRellenarTransiciones(const std::string& kLinea) {
  const std::string kErrorExiste = "No pueden existir transiciones repetidas.",
                    kErrorCantidadElementos = "Una transición sólo puede estar formada por 5 elementos.",
                    kErrorEstado = "Algún estado desconocido.",
                    kErrorSimboloAlfabeto = "Algún símbolo del alfabeto desconocido.",
                    kErrorSimboloAlfabetoPila = "Algún símbolo del alfabeto de la pila desconocido.",
                    kErrorSímboloAlfabetoPilaVacio = "No se puede extraer vacío de la pila.",
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
        if (elemento[0] == '.') throw kErrorSímboloAlfabetoPilaVacio;
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

/**
 * @brief Verifica si una transición ya existe en el autómata.
 * 
 * Este método compara la línea de transición dada con las transiciones ya
 * existentes en el autómata para evitar duplicados.
 * 
 * @param kLinea Línea que describe la transición a verificar.
 * @return true Si la transición ya existe.
 * @return false Si la transición no existe.
 */
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