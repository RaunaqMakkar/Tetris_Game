#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include <utility>

enum class PieceType {
    I, O, T, S, Z, J, L, NONE
};

class Tetromino {
private:
    PieceType type;
    int rotation;  // 0-3 for different rotation states
    int x, y;      // Position on board
    
    // Shape definitions (relative positions)
    static const std::vector<std::pair<int, int>> I_SHAPES[4];
    static const std::vector<std::pair<int, int>> O_SHAPES[4];
    static const std::vector<std::pair<int, int>> T_SHAPES[4];
    static const std::vector<std::pair<int, int>> S_SHAPES[4];
    static const std::vector<std::pair<int, int>> Z_SHAPES[4];
    static const std::vector<std::pair<int, int>> J_SHAPES[4];
    static const std::vector<std::pair<int, int>> L_SHAPES[4];
    
public:
    Tetromino();
    Tetromino(PieceType t);
    
    // Getters
    PieceType getType() const { return type; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getRotation() const { return rotation; }
    std::vector<std::pair<int, int>> getShape() const;
    int getTypeValue() const;
    
    // Setters
    void setPosition(int newX, int newY);
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    void rotate();
    
    // Other
    void generateRandomPiece();
    static Tetromino createRandomPiece();
};

#endif
