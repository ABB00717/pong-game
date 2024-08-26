#!/bin/bash

# Compile all cpp files
g++ -c main.cpp pong_game.cpp ball.cpp paddle.cpp -std=c++17

# Link object files and create executable
g++ main.o pong_game.o ball.o paddle.o -o pong.out -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Run the game
./pong.out

# Clean up
rm *.o
rm *.out