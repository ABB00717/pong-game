#include <iostream>
#include <raylib.h>
#include <vector>

class Ball {
public:
  Ball(std::vector<double> position, std::vector<double> speed, double radius) {
    this->position = position;
    this->speed = speed;
    this->radius = radius;
  }

  void Update() {
    position[0] += speed[0];
    position[1] += speed[1];
  }

  void Draw() {
    DrawCircle(position[0], position[1], radius, WHITE);
  }

private:
  std::vector<double> position;
  std::vector<double> speed;
  double radius;
  
};

int main() {
  std::cout << "Hello, World!" << std::endl;

  const int screenWidth = 1280;
  const int screenHeight = 800;
  const char* title = "Pong!";
  const int targetFPS = 144;
  InitWindow(screenWidth, screenHeight, title);
  SetTargetFPS(targetFPS);
  
  Ball ball({(double)screenWidth/2, (double)screenHeight/2}, {1, 1}, 20);

  while (WindowShouldClose() == false) {
    BeginDrawing();
    ball.Update();

    ClearBackground(BLACK);

    ball.Draw();
    DrawRectangle(10, screenHeight/2-60, 25, 120, WHITE);
    DrawRectangle(screenWidth-35, screenHeight/2-60, 25, 120, WHITE);
    DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
    
    EndDrawing();
  }

  CloseWindow();
  return 0;
}