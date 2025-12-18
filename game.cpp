#include "game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

Game::Game() : score(0), level(1), linesCleared(0), gameOver(false) {
    currentPiece = Tetromino::createRandomPiece();
    nextPiece = Tetromino::createRandomPiece();
    lastMoveTime = std::chrono::high_resolution_clock::now();
}

void Game::run() {
    while (!gameOver) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
            currentTime - lastMoveTime).count();
        
        if (elapsed >= MOVE_DELAY_MS) {
            update();
            lastMoveTime = currentTime;
        }
        
        handleInput();
        render();
        
        Sleep(50);  // Small delay to prevent CPU spinning
    }
    
    system("cls");
    std::cout << "GAME OVER!\n";
    std::cout << "Final Score: " << score << "\n";
    std::cout << "Lines Cleared: " << linesCleared << "\n";
    std::cout << "Level: " << level << "\n";
}

void Game::render() {
    system("cls");
    
    // Draw border and board
    std::cout << "TETRIS\n";
    std::cout << "Score: " << score << "  Lines: " << linesCleared << "  Level: " << level << "\n\n";
    
    // Top border
    std::cout << "+";
    for (int x = 0; x < board.getWidth(); ++x) {
        std::cout << "-";
    }
    std::cout << "+\n";
    
    // Game board
    for (int y = 0; y < board.getHeight(); ++y) {
        std::cout << "|";
        for (int x = 0; x < board.getWidth(); ++x) {
            bool isCurrentPiece = false;
            auto shape = currentPiece.getShape();
            for (const auto& block : shape) {
                if (currentPiece.getX() + block.first == x && 
                    currentPiece.getY() + block.second == y) {
                    isCurrentPiece = true;
                    break;
                }
            }
            
            if (isCurrentPiece) {
                std::cout << "O";
            } else if (board.isOccupied(x, y)) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "|\n";
    }
    
    // Bottom border
    std::cout << "+";
    for (int x = 0; x < board.getWidth(); ++x) {
        std::cout << "-";
    }
    std::cout << "+\n\n";
    
    // Next piece preview
    std::cout << "Next: ";
    auto nextShape = nextPiece.getShape();
    for (const auto& block : nextShape) {
        if (block.first == -1 && block.second == 0) {
            std::cout << "[O]";
        }
    }
    std::cout << "\n";
}

void Game::update() {
    auto shape = currentPiece.getShape();
    
    // Try to move piece down
    currentPiece.moveDown();
    
    if (!board.canPlacePiece(shape, currentPiece.getX(), currentPiece.getY())) {
        // Revert move and lock piece
        currentPiece.moveUp();  // We need to add this method
        lockCurrentPiece();
        clearLines();
        spawnNewPiece();
    }
}

void Game::handleInput() {
    if (_kbhit()) {
        char key = _getch();
        key = tolower(key);
        
        auto shape = currentPiece.getShape();
        
        switch (key) {
            case 'a':  // Move left
                currentPiece.moveLeft();
                if (!board.canPlacePiece(shape, currentPiece.getX(), currentPiece.getY())) {
                    currentPiece.moveRight();
                }
                break;
                
            case 'd':  // Move right
                currentPiece.moveRight();
                if (!board.canPlacePiece(shape, currentPiece.getX(), currentPiece.getY())) {
                    currentPiece.moveLeft();
                }
                break;
                
            case 's':  // Move down faster
                currentPiece.moveDown();
                if (!board.canPlacePiece(shape, currentPiece.getX(), currentPiece.getY())) {
                    currentPiece.moveUp();
                    lockCurrentPiece();
                    clearLines();
                    spawnNewPiece();
                }
                break;
                
            case 'w': {  // Rotate
                currentPiece.rotate();
                auto rotatedShape = currentPiece.getShape();
                if (!board.canPlacePiece(rotatedShape, currentPiece.getX(), currentPiece.getY())) {
                    currentPiece.rotate();  // Revert rotation
                    currentPiece.rotate();
                    currentPiece.rotate();
                }
                break;
            }
                
            case 27:   // ESC to quit
                gameOver = true;
                break;
        }
    }
}

void Game::spawnNewPiece() {
    currentPiece = nextPiece;
    nextPiece = Tetromino::createRandomPiece();
    
    auto shape = currentPiece.getShape();
    if (!board.canPlacePiece(shape, currentPiece.getX(), currentPiece.getY())) {
        gameOver = true;
    }
}

void Game::lockCurrentPiece() {
    auto shape = currentPiece.getShape();
    board.placePiece(shape, currentPiece.getX(), currentPiece.getY(), 
                     currentPiece.getTypeValue());
}

void Game::clearLines() {
    auto completedLines = board.getCompletedLines();
    if (!completedLines.empty()) {
        board.clearLines(completedLines);
        
        int numLines = completedLines.size();
        linesCleared += numLines;
        
        // Scoring: 1 line = 40, 2 lines = 100, 3 lines = 300, 4 lines = 1200
        int baseScore[] = {0, 40, 100, 300, 1200};
        if (numLines <= 4) {
            score += baseScore[numLines] * level;
        }
        
        // Update level every 10 lines
        level = (linesCleared / 10) + 1;
    }
}

bool Game::checkGameOver() {
    return gameOver;
}

void Game::resetGame() {
    board.clearBoard();
    score = 0;
    level = 1;
    linesCleared = 0;
    gameOver = false;
    currentPiece = Tetromino::createRandomPiece();
    nextPiece = Tetromino::createRandomPiece();
}
