#include "tetromino.h"
#include <cstdlib>
#include <ctime>

// Define piece shapes (relative coordinates)
const std::vector<std::pair<int, int>> Tetromino::I_SHAPES[4] = {
    {{-1, 0}, {0, 0}, {1, 0}, {2, 0}},
    {{0, -1}, {0, 0}, {0, 1}, {0, 2}},
    {{-1, 0}, {0, 0}, {1, 0}, {2, 0}},
    {{0, -1}, {0, 0}, {0, 1}, {0, 2}}
};

const std::vector<std::pair<int, int>> Tetromino::O_SHAPES[4] = {
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}}
};

const std::vector<std::pair<int, int>> Tetromino::T_SHAPES[4] = {
    {{-1, 0}, {0, 0}, {1, 0}, {0, 1}},
    {{0, -1}, {0, 0}, {0, 1}, {-1, 0}},
    {{-1, 0}, {0, 0}, {1, 0}, {0, -1}},
    {{0, -1}, {0, 0}, {0, 1}, {1, 0}}
};

const std::vector<std::pair<int, int>> Tetromino::S_SHAPES[4] = {
    {{0, 0}, {1, 0}, {-1, 1}, {0, 1}},
    {{0, -1}, {0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {-1, 1}, {0, 1}},
    {{0, -1}, {0, 0}, {1, 0}, {1, 1}}
};

const std::vector<std::pair<int, int>> Tetromino::Z_SHAPES[4] = {
    {{-1, 0}, {0, 0}, {0, 1}, {1, 1}},
    {{1, -1}, {0, 0}, {1, 0}, {0, 1}},
    {{-1, 0}, {0, 0}, {0, 1}, {1, 1}},
    {{1, -1}, {0, 0}, {1, 0}, {0, 1}}
};

const std::vector<std::pair<int, int>> Tetromino::J_SHAPES[4] = {
    {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}},
    {{0, -1}, {1, -1}, {0, 0}, {0, 1}},
    {{-1, -1}, {-1, 0}, {0, 0}, {1, 0}},
    {{0, -1}, {0, 0}, {-1, 1}, {0, 1}}
};

const std::vector<std::pair<int, int>> Tetromino::L_SHAPES[4] = {
    {{1, 0}, {-1, 1}, {0, 1}, {1, 1}},
    {{0, -1}, {0, 0}, {0, 1}, {1, 1}},
    {{-1, 0}, {0, 0}, {1, 0}, {-1, 1}},
    {{-1, -1}, {0, -1}, {0, 0}, {0, 1}}
};

Tetromino::Tetromino() : type(PieceType::NONE), rotation(0), x(5), y(0) {}

Tetromino::Tetromino(PieceType t) : type(t), rotation(0), x(5), y(0) {}

std::vector<std::pair<int, int>> Tetromino::getShape() const {
    switch (type) {
        case PieceType::I: return I_SHAPES[rotation];
        case PieceType::O: return O_SHAPES[rotation];
        case PieceType::T: return T_SHAPES[rotation];
        case PieceType::S: return S_SHAPES[rotation];
        case PieceType::Z: return Z_SHAPES[rotation];
        case PieceType::J: return J_SHAPES[rotation];
        case PieceType::L: return L_SHAPES[rotation];
        default: return std::vector<std::pair<int, int>>();
    }
}

int Tetromino::getTypeValue() const {
    return static_cast<int>(type) + 1;  // 1-7 for different pieces
}

void Tetromino::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

void Tetromino::moveLeft() {
    x--;
}

void Tetromino::moveRight() {
    x++;
}

void Tetromino::moveDown() {
    y++;
}

void Tetromino::moveUp() {
    y--;
}

void Tetromino::rotate() {
    // O piece doesn't rotate
    if (type != PieceType::O) {
        rotation = (rotation + 1) % 4;
    }
}

void Tetromino::generateRandomPiece() {
    int randomType = rand() % 7;
    type = static_cast<PieceType>(randomType);
    rotation = 0;
    x = 5;
    y = 0;
}

Tetromino Tetromino::createRandomPiece() {
    Tetromino piece;
    piece.generateRandomPiece();
    return piece;
}
