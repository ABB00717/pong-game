#include <iostream>
#include <raylib.h>

int main() {
  std::cout << "Hello, World!" << std::endl;

  const int screenWidth = 1280;
  const int screenHeight = 800;
  const char* title = "Pong!";
  const int targetFPS = 144;
  InitWindow(screenWidth, screenHeight, title);
  SetTargetFPS(targetFPS);

  while (WindowShouldClose() == false) {
    BeginDrawing();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}