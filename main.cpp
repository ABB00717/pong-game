#include <iostream>
#include <raylib.h>

int main() {
  std::cout << "Hello, World!" << std::endl;

  const int screenWidth = 1280;
  const int screenHeight = 800;
  const char* title = "Pong!";
  InitWindow(screenWidth, screenHeight, title);

  CloseWindow();
  return 0;
}
