@echo off
REM Build script for Tetris game

echo Building Tetris Game...
g++ -std=c++17 -O2 -o tetris main.cpp game.cpp board.cpp tetromino.cpp

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful!
    echo Running Tetris...
    .\tetris.exe
) else (
    echo Build failed!
    pause
)