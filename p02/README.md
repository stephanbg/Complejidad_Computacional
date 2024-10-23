# PRÁCTICA 2:  Programar un simulador de un autómata con pila

## Objetivo de la Práctica

El objetivo de la práctica consiste en programar un simulador de un autómata con pila, realizando un diseño orientado a objetos. En este caso, he decidido implementar el **autómata de pila con finalización por vaciado de pila (APv)**.

---

## Compilación

Para compilar el programa, simplemente navega al directorio `src` y ejecuta el siguiente comando en la terminal:
```bash
make
```
Si quiere ejecutarlo con el modo traza:
```bash
make traza
```
En caso de que le de algún tipo de problema:
```bash
make -B traza
```

---

## Ejecución

Una vez que el programa haya sido compilado correctamente, podrás ejecutarlo proporcionando los siguientes parámetros a través de la línea de comandos:

```bash
./main (Fichero APv) (cadenas infinitas separadas por espacios)
```
- Segundo parámetro: Este parámetro debe contener la ruta al archivo que describe el autómata. Este archivo contiene la definición del autómata, incluyendo sus estados, transiciones, y otros elementos relevantes necesarios para su funcionamiento.
- A partir del tercer parámetro: A partir de este punto, los parámetros que se proporcionen serán las cadenas que se desean comprobar. El autómata utilizará estas cadenas para determinar si son aceptadas o no, basándose en las reglas y la estructura definidas en el archivo del autómata.

En caso de que se produzca algún error en la entrada de los parámetros, el programa mostrará un mensaje de error informando al usuario sobre la naturaleza del problema.

---

## Resultado

Cuando se introducen parámetros válidos en el programa, este realizará lo siguiente:

- **Evaluación de Cadenas**: Para cada cadena proporcionada, el programa determinará si es aceptada por el autómata definido en el archivo especificado.
  - **Resultado Aceptado**: Si la cadena es aceptada, el programa mostrará el mensaje "ACEPTADA".
  - **Resultado No Aceptado**: Si la cadena no es aceptada, se mostrará un "X".
  - **Opcional Modo Traza**: Si el programa se compila usando el comando `make traza`, se activará una funcionalidad adicional. En este modo, para cada cadena evaluada, el programa mostrará una traza detallada del proceso de decisión del autómata. Esto incluye información sobre las transiciones que realiza y cómo llega a su decisión final.
    
Este enfoque permite tanto una verificación simple de las cadenas como una comprensión más profunda del funcionamiento interno del autómata cuando se desea observar su comportamiento.

---

## Notas Adicionales

- **Modo Traza**: En el modo traza, el programa muestra las transiciones que se seleccionan en cada momento del proceso de evaluación. Gracias a la funcionalidad de backtracking, se pueden visualizar todos los caminos que el autómata explora, incluso aquellos que no conducen a un resultado final correcto. Esto permite una comprensión más profunda del proceso de decisión del autómata y de cómo maneja las diferentes posibilidades.
- **Uso del Símbolo Vacío**: Aunque, teóricamente, los alfabetos de los autómatas no incluyen el símbolo vacío (representado como "."), he decidido incluirlo en el constructor de mi alfabeto. Esta elección simplifica la implementación del programa y facilita el manejo de ciertas operaciones.

---
