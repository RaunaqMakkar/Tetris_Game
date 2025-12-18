#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    static const int WIDTH = 10;
    static const int HEIGHT = 20;
    std::vector<std::vector<int>> grid;
    
public:
    Board();
    
    // Getters
    int getWidth() const { return WIDTH; }
    int getHeight() const { return HEIGHT; }
    bool isOccupied(int x, int y) const;
    int getCell(int x, int y) const;
    
    // Setters
    void setCell(int x, int y, int value);
    void clearCell(int x, int y);
    
    // Board operations
    void clearBoard();
    bool canPlacePiece(const std::vector<std::pair<int, int>>& blocks, int offsetX, int offsetY) const;
    void placePiece(const std::vector<std::pair<int, int>>& blocks, int offsetX, int offsetY, int pieceType);
    std::vector<int> getCompletedLines();
    void clearLines(const std::vector<int>& lines);
    
    // Collision detection
    bool isValid(int x, int y) const;
};

#endif
