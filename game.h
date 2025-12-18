#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "tetromino.h"
#include <chrono>

class Game {
private:
    Board board;
    Tetromino currentPiece;
    Tetromino nextPiece;
    int score;
    int level;
    int linesCleared;
    bool gameOver;
    std::chrono::high_resolution_clock::time_point lastMoveTime;
    
    static const int MOVE_DELAY_MS = 500;  // Milliseconds between auto-drops
    
public:
    Game();
    void run();
    void render();
    void update();
    void handleInput();
    void spawnNewPiece();
    void lockCurrentPiece();
    void clearLines();
    bool checkGameOver();
    void resetGame();
};

#endif
