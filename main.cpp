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

    DrawCircle(screenWidth/2, screenHeight/2, 20, WHITE);
    DrawRectangle(10, screenHeight/2-60, 25, 120, WHITE);
    DrawRectangle(screenWidth-35, screenHeight/2-60, 25, 120, WHITE);
    DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
    
    EndDrawing();
  }

  CloseWindow();
  return 0;
}