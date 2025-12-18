#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include "game.h"

int main() {
    srand(static_cast<unsigned>(time(0)));
    
    Game game;
    
    std::cout << "Welcome to TETRIS!\n";
    std::cout << "Controls:\n";
    std::cout << "  A - Move Left\n";
    std::cout << "  D - Move Right\n";
    std::cout << "  W - Rotate\n";
    std::cout << "  S - Move Down\n";
    std::cout << "  ESC - Quit\n";
    std::cout << "Press any key to start...\n";
    _getch();
    
    game.run();
    
    return 0;
}
