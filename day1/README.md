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

---

## **Comando de Compilación**

Para compilar el programa, usa el siguiente comando:
```bash
g++ -std=c++17 -I./RxCpp/Rx/v2/src src/main.cpp -o ../build/main
```

Para ejecutar el programa:
```bash
../build/main
```