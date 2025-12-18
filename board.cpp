#include "board.h"

Board::Board() : grid(HEIGHT, std::vector<int>(WIDTH, 0)) {}

bool Board::isOccupied(int x, int y) const {
    return isValid(x, y) && grid[y][x] != 0;
}

int Board::getCell(int x, int y) const {
    if (isValid(x, y)) {
        return grid[y][x];
    }
    return 0;
}

void Board::setCell(int x, int y, int value) {
    if (isValid(x, y)) {
        grid[y][x] = value;
    }
}

void Board::clearCell(int x, int y) {
    if (isValid(x, y)) {
        grid[y][x] = 0;
    }
}

void Board::clearBoard() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            grid[y][x] = 0;
        }
    }
}

bool Board::isValid(int x, int y) const {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

bool Board::canPlacePiece(const std::vector<std::pair<int, int>>& blocks, 
                          int offsetX, int offsetY) const {
    for (const auto& block : blocks) {
        int x = offsetX + block.first;
        int y = offsetY + block.second;
        
        // Check bounds
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            return false;
        }
        
        // Check collision with existing blocks
        if (grid[y][x] != 0) {
            return false;
        }
    }
    return true;
}

void Board::placePiece(const std::vector<std::pair<int, int>>& blocks, 
                       int offsetX, int offsetY, int pieceType) {
    for (const auto& block : blocks) {
        int x = offsetX + block.first;
        int y = offsetY + block.second;
        
        if (isValid(x, y)) {
            grid[y][x] = pieceType;
        }
    }
}

std::vector<int> Board::getCompletedLines() {
    std::vector<int> completedLines;
    
    for (int y = 0; y < HEIGHT; ++y) {
        bool isComplete = true;
        for (int x = 0; x < WIDTH; ++x) {
            if (grid[y][x] == 0) {
                isComplete = false;
                break;
            }
        }
        if (isComplete) {
            completedLines.push_back(y);
        }
    }
    
    return completedLines;
}

void Board::clearLines(const std::vector<int>& lines) {
    for (int line : lines) {
        // Shift all lines above down
        for (int y = line; y > 0; --y) {
            for (int x = 0; x < WIDTH; ++x) {
                grid[y][x] = grid[y - 1][x];
            }
        }
        // Clear top line
        for (int x = 0; x < WIDTH; ++x) {
            grid[0][x] = 0;
        }
    }
}
