# Tic-Tac-Toe Game

![C++](https://img.shields.io/badge/C++-17-blue)
![CMake](https://img.shields.io/badge/CMake-Build-green)
![Platform](https://img.shields.io/badge/platform-console-lightgrey)

## Description

Tic-Tac-Toe Game is a simple console-based game written in C++.

The project was created as a university assignment to practice object-oriented programming, basic game logic, console input/output, and project organization using CMake.

## Features

- Classic 3x3 Tic-Tac-Toe board
- Console-based gameplay
- Player move handling
- Basic AI move implementation
- Win and draw detection
- Input validation
- CMake build configuration

## Technologies

- C++
- CMake
- Git

## Project Structure

```text
Tic-Tac-Toe-Game/
│
├── include/          # Header files
├── src/              # Source files
├── main.cpp          # Main entry point
├── CMakeLists.txt    # CMake configuration
└── README.md
```

## Build and Run

### Requirements

Make sure you have installed:

- C++ compiler, for example `g++`, `clang++` or MSVC
- CMake

Check CMake version:

```bash
cmake --version
```

### Clone Repository

```bash
git clone https://github.com/1maciek90/Tic-Tac-Toe-Game.git
cd Tic-Tac-Toe-Game
```

### Build Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run Application

On Linux or macOS:

```bash
./TicTacToe
```

On Windows:

```bash
TicTacToe.exe
```

> The executable name may be different depending on the name defined in `CMakeLists.txt`.

## How to Play

The game is played on a 3x3 board.

Players take turns placing their symbols on the board. The goal is to place three symbols in a row: horizontally, vertically, or diagonally.

The game ends when one player wins or when the board is full and the result is a draw.

## Example

```text
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9

Choose your move: 5
```

## Author

Created by [Maciej Drywa](https://github.com/1maciek90)
