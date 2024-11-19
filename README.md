
# 🎮 Pong Game en Windows - Hecho en C

<div align="center"> 
  <img src="https://github.com/user-attachments/assets/dfcfd32a-726f-4372-885c-9145cddc1165" alt="pong-game" width="400">
</div>

## 📝 Descripción

Este proyecto es una implementación del clásico juego **Pong**, desarrollado en el lenguaje de programación **C** y utilizando la biblioteca gráfica **raylib**. Disfruta de una experiencia retro con gráficos simples pero efectivos.

### 🏆 Objetivo del Juego

Cada jugador controla una paleta que debe evitar que la pelota pase por su lado de la pantalla. ¡El primer jugador en alcanzar el puntaje máximo será el ganador!

---

## ✨ Características

- **Modo de dos jugadores**: Ideal para competencias rápidas.
- **Física de colisiones precisa**: La pelota rebota dinámicamente en las paletas y los bordes.
- **Gráficos minimalistas**: Renderizados con **raylib** para garantizar rendimiento y simplicidad.

---

## 📋 Requisitos del Proyecto

- **Compilador C**: Cualquier compilador compatible como GCC o MinGW.
- **raylib**: Biblioteca gráfica para C. Descárgala desde [raylib](https://www.raylib.com/).
- **CMake** *(opcional)*: Para generar archivos de compilación automatizados.

---

## 🛠️ Instrucciones de Instalación

### 1️⃣ Clonar el Repositorio

```bash
git clone https://github.com/sebanovo/pong-game.git
cd pong-game
```

### 2️⃣ Compilación del Proyecto

#### Opción 1: Usando CMake

```bash
mkdir build
cd build

# Configura el proyecto
cmake ..

# Compila el proyecto
cmake --build .
```

#### Opción 2: Usando GCC

```bash
mkdir build

# Compila, enlaza y genera el ejecutable
gcc -std=c11 -Wall -I./include -L./lib -o build/game src/main.c lib/libraylib.a -lopengl32 -lgdi32 -lkernel32 -lwinmm
```

---

## 🎮 Controles del Juego

- **Jugador 1**:
  - Mover hacia arriba: `W`
  - Mover hacia abajo: `S`
- **Jugador 2**:
  - Mover hacia arriba: `↑`
  - Mover hacia abajo: `↓`

---

## ▶️ Ejecuta el Juego

```bash
./build/game.exe
```

---

## 📦 Librerías y Recursos

Si encuentras problemas al compilar debido a las librerías de **raylib**, puedes compilarlas manualmente desde su repositorio oficial: [raylib GitHub](https://github.com/raysan5/raylib/releases/tag/5.5).

---

## 💡 Contribuciones

¡Tu ayuda es bienvenida! 🎉  
Si tienes ideas, encuentras errores o deseas agregar características, abre un **issue** o envía un **pull request**.

---

<div align="center">
  Hecho con ❤️ por [Tu Nombre o Alias]  
  ¡Gracias por apoyar este proyecto! 🚀
</div>
