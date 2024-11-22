# **Día 1: Introducción a la Programación Reactiva en C++**

## **Objetivo**

Establecer los fundamentos de la programación reactiva y configurar el entorno para trabajar con la biblioteca RxCpp. Al finalizar este día, habrás:

- Configurado la biblioteca RxCpp en tu proyecto.
- Compilado y ejecutado tu primer programa reactivo en C++.
- Comprendido los conceptos básicos de observables y suscriptores.

---

## **Configuración del Proyecto**

### **Estructura del Proyecto**

```plaintext
cpp_project/
├── day1/
│   ├── README.md
│   ├── RxCpp -> /mnt/e/git/RxCpp
│   └── src/
│       └── main.cpp
├── build/
└── README.md
```

## **Dependencias**

- Biblioteca RxCpp.
- Compilador compatible con C++17 (g++ recomendado).
- Entorno WSL con Debian.

## **Pasos de Configuración**

1. Clona la biblioteca RxCpp:

```bash
git clone https://github.com/ReactiveX/RxCpp.git /mnt/e/git/RxCpp
```

2. Crea un enlace simbólico hacia RxCpp en tu proyecto:

```bash
ln -s /mnt/e/git/RxCpp RxCpp
```

3. Verifica que el archivo _rx.hpp_ esté en la ruta _RxCpp/Rx/v2/src_.

## **Comando de Compilación**

Para compilar el programa, usa el siguiente comando:

```bash
g++ -std=c++17 -I./RxCpp/Rx/v2/src src/main.cpp -o ../build/main
```

Para ejecutar el programa:

```bash
../build/main
```

---

## **Explicación detallada del código**

El programa utiliza la biblioteca RxCpp para crear y manejar flujos de datos de manera reactiva. A continuación, desglosamos cada parte clave del código:

```cpp
#include <rx.hpp>
#include <iostream>
using namespace rxcpp;
```

- #include <rx.hpp>: Incluye la cabecera principal de RxCpp, que contiene las definiciones de los operadores, observables y suscriptores.
- using namespace rxcpp;: Facilita el uso de las clases y funciones de RxCpp sin necesidad de prefijarlas con rxcpp::.

### **Creación de un Observable**

```cpp
auto observable = rxcpp::observable<>::from(10, 20, 30, 40);
```

- observable<>::from(...):
  - Este método crea un Observable que emite una secuencia de valores proporcionados como parámetros (en este caso, 10, 20, 30, 40).
  - Un Observable es el origen del flujo de datos, y se utiliza para emitir eventos o valores que otros componentes pueden observar y procesar.

---

### **Suscribiendo al Observable**

```cpp
observable.subscribe(
    [](int value) { std::cout << "Next: " << value << std::endl; },
    []() { std::cout << "Completed!" << std::endl; }
);
```

El método subscribe permite que un Suscriptor observe los valores emitidos por el Observable y defina cómo reaccionar ante ellos.

**Parámetros de** **subscribe**

1. Primer parámetro: una función lambda para manejar cada valor emitido:

```cpp
[](int value) { std::cout << "Next: " << value << std::endl; }
```

- Aquí, cada valor emitido por el Observable (10, 20, 30, 40) se recibe como value.
- La función imprime el valor en la salida estándar.

2. Segundo parámetro: una función lambda para manejar la finalización:

```cpp
[]() { std::cout << "Completed!" << std::endl; }
```

- Esta función se ejecuta cuando el Observable ha terminado de emitir valores.
- Es útil para realizar tareas de limpieza o notificar que el flujo ha concluido.


### **Flujo del programa**

1. El Observable emite los valores 10, 20, 30 y 40 en orden.
2. El Suscriptor procesa cada valor utilizando la función lambda correspondiente.
3. Cuando el Observable ha emitido todos los valores, se ejecuta la función de finalización.

La salida del programa es:

```plaintext
Copy code
Next: 10
Next: 20
Next: 30
Next: 40
Completed!
```

---

## **Conceptos abordados hoy**

1. **Programación Reactiva**
La programación reactiva es un paradigma que se centra en trabajar con flujos de datos y eventos asíncronos. En este modelo:

- Los datos se representan como secuencias (streams) que se pueden observar y transformar.
- Los componentes responden automáticamente a los cambios en los datos.

2. **Elementos clave de RxCpp**

- Observable: Es el origen del flujo de datos. Puede emitir:
  - Valores (onNext): Los datos del flujo.
  - Errores (onError): Notificación de fallos.
  - Finalización (onCompleted): Señal de que no se emitirán más datos.
- Suscriptor (Subscriber): Observa el flujo y define cómo procesar los valores, errores y la finalización.

3. **Ventajas de este enfoque**

- **Declaratividad**: Permite describir "qué hacer" con los datos, no "cómo hacerlo".
- **Manejo de asíncronía**: Simplifica el trabajo con datos que llegan de forma asíncrona.
- **Escalabilidad**: Es ideal para aplicaciones con múltiples eventos concurrentes, como sistemas en tiempo real.
