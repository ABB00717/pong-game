#include "pong_game.h"

const int screenWidth = 1280;
const int screenHeight = 800;
const char *title = "Pong!";
const int targetFPS = 144;
int playerScore = 0;
int computerScore = 0;

Color Green = Color{38, 185, 154, 255};
Color DarkGreen = Color{20, 160, 133, 255};
Color LightGreen = Color{129, 204, 154, 255};
Color Yellow = Color{243, 213, 91, 255};