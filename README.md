# TETRIS Puzzle Game | C++

A professional implementation of the classic Tetris game in C++ with a well-structured object-oriented design.

## Features

### Game Engine
- **Loop Control**: Sophisticated game loop with time-based piece movement and input handling
- **Piece Rotation Mechanics**: Full rotation support for all 7 tetromino types (I, O, T, S, Z, J, L)
- **Collision Detection**: Advanced collision handling for walls, floors, and locked pieces
- **Scoring System**: Dynamic scoring with level progression

### Architecture
- **Object-Oriented Design**: Clean separation of concerns with dedicated classes
- **Efficient Data Structures**: 2D grid-based board representation for optimal performance
- **Modular Components**:
  - `Game`: Main game loop and controller
  - `Board`: Game grid and collision logic
  - `Tetromino`: Piece shapes and movements

## Project Structure

```
tetris/
├── main.cpp           # Entry point
├── game.h/cpp         # Game engine and logic
├── board.h/cpp        # Board and collision detection
├── tetromino.h/cpp    # Piece definitions and movements
├── CMakeLists.txt     # Build configuration
├── build.bat          # Build script for Windows
└── README.md          # This file
```

## Building the Project

### Prerequisites
- C++ 17 compiler
- CMake 3.10 or higher
- Windows OS (for console-based gameplay)

### Build Instructions

#### Method 1: Using build.bat (Recommended for Windows)
```bash
cd tetris
build.bat
```

#### Method 2: Manual CMake build
```bash
cd tetris
mkdir build
cd build
cmake ..
cmake --build . --config Release
.\Release\tetris.exe
```

#### Method 3: Direct compilation with g++ or MSVC
```bash
g++ -std=c++17 main.cpp game.cpp board.cpp tetromino.cpp -o tetris.exe
tetris.exe
```

## Game Controls

| Control | Action |
|---------|--------|
| **A** | Move piece left |
| **D** | Move piece right |
| **W** | Rotate piece |
| **S** | Move piece down faster |
| **ESC** | Quit game |

## Gameplay

- Pieces fall automatically from the top of the screen
- Move and rotate pieces to create complete horizontal lines
- Complete lines are cleared and add to your score
- The game ends when pieces reach the top of the board
- Score increases with more lines cleared simultaneously
- Level increases every 10 lines cleared

## Scoring System

- **1 Line**: 40 × Level points
- **2 Lines**: 100 × Level points
- **3 Lines**: 300 × Level points
- **4 Lines (Tetris)**: 1200 × Level points

## Technical Implementation

### Game Loop
The game uses a time-based update system with approximately 2 moves per second (500ms intervals) for automatic piece dropping. User input is processed asynchronously using Windows console API.

### Collision Detection
All movement and rotation operations validate against:
- Board boundaries (10×20 grid)
- Previously locked pieces
- Floor and walls

### Piece System
Seven tetromino types with full rotation states:
- **I-piece**: 4 blocks in a line
- **O-piece**: 2×2 square (no rotation)
- **T-piece**: T-shaped
- **S-piece**: S-shaped
- **Z-piece**: Z-shaped
- **J-piece**: J-shaped
- **L-piece**: L-shaped

Each piece maintains its own position, rotation state, and shape definition for efficient rendering and collision checking.

## Performance Optimization

- **Efficient Shapes**: Pre-defined shape arrays reduce computation
- **Minimal Redraws**: Console is cleared once per frame
- **Optimized Data**: Vector-based grid for memory efficiency
- **Smart Collision**: Early exit conditions prevent unnecessary checks

## Future Enhancements

- Sound effects
- Pause/Resume functionality
- High score persistence
- Different difficulty levels
- Graphical UI (SDL/SFML)
- Network multiplayer

**Enjoy the game!**
