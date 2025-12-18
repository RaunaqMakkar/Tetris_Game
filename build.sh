#!/usr/bin/env bash
# Build script for Tetris game (Linux/Mac)

if [ ! -d "build" ]; then
    mkdir build
fi

cd build
echo "Building Tetris Game..."
cmake ..
cmake --build . --config Release

if [ $? -eq 0 ]; then
    echo ""
    echo "Build successful!"
    if [ -f "./tetris" ]; then
        echo "Running Tetris..."
        ./tetris
    fi
else
    echo "Build failed!"
fi

cd ..
