# Pong Game en Windows hecho en c

## Descripción
Este proyecto es una implementación del clásico juego de Pong utilizando el lenguaje de programación C y la biblioteca gráfica raylib. El objetivo del juego es simple: dos jugadores controlan paletas para golpear una pelota y evitar que pase por sus respectivos lados de la pantalla. El primer jugador en alcanzar el puntaje máximo gana el juego.

## Características
- **Modo de dos jugadores**: Cada jugador controla una paleta.
- **Detección de colisiones**: La pelota rebota en las paletas y los bordes de la pantalla.
- **Interfaz gráfica**: Utiliza raylib para renderizar gráficos simples y efectivos.

## Requisitos
- **Compilador C**: GCC o cualquier otro compilador compatible.
- **raylib**: Biblioteca gráfica para C. Puedes descargarla e instalarla desde [raylib](https://www.raylib.com/).

## Instalación

1. Clona este repositorio:

```bash
git clone https://github.com/sebanovo/pong-game.git

cd pong-game
```

2. Compila el código:

- 1ra Forma con `cmake`:

```powershell
mkdir build

cd build
cmake ..
cmake --build .
```

- 2da Forma  con `gcc`

```powershell

mkdir build

gcc -std=c11 -Wall -I./include -L./lib -o build/game src/main.c lib/libraylib.a -lopengl32 -lgdi32 -lkernel32 -lwinmm
```

## Controles
- `Jugador 1`: Usa las teclas W y S para mover la paleta hacia arriba y hacia abajo.

- `Jugador 2`: Usa las teclas de flecha Arriba y Abajo para mover la paleta hacia arriba y hacia abajo.


## Correlo 🚀

```
./build/game.exe
```

## Fuentes de Código

- En caso de que tu compilador no reconozca las librerias de raylib de este repositorio puedes compilar las librerias por tí mismo

- Puedes encontrar el código fuente de raylib en su repositorio oficial de GitHub [raylib github](https://github.com/raysan5/raylib/releases/tag/5.5)

# Contribuciones
¡Siéntete libre de contribuir mejorando el codigo! Abre un problema o envía una solicitud de extracción.