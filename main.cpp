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

    if (position[1]-radius <= 0 || position[1]+radius >= GetScreenHeight()) speed[1] *= -1;
    if (position[0]-radius <= 0 || position[0]+radius >= GetScreenWidth()) speed[0] *= -1;
  }

  void Draw() {
    DrawCircle(position[0], position[1], radius, WHITE);
  }

private:
  std::vector<double> position;
  std::vector<double> speed;
  double radius;
  
};

class Paddle {
public:
  Paddle(std::vector<double> position, double speed, double width, double height) {
    this->position = position;
    this->speed = speed;
    this->width = width;
    this->height = height;
  }

  void Draw() {
    DrawRectangle(position[0], position[1], width, height, WHITE);
  }

  void Update() {
    if (IsKeyDown(KEY_E) && position[1] >= 15) position[1] -= speed;
    if (IsKeyDown(KEY_D) && position[1]+height <= GetScreenHeight()-15) position[1] += speed;
  }

private:
  std::vector<double>  position;
  double speed;
  double width;
  double height;

};

int main() {
  std::cout << "Hello, World!" << std::endl;

  const int screenWidth = 1280;
  const int screenHeight = 800;
  const char* title = "Pong!";
  const int targetFPS = 144;
  InitWindow(screenWidth, screenHeight, title);
  SetTargetFPS(targetFPS);
  
  Ball ball({(double)screenWidth/2, (double)screenHeight/2}, {3, 3}, 20);
  Paddle player({10, (double)screenHeight/2-60}, 4, 25, 120);

  while (WindowShouldClose() == false) {
    BeginDrawing();
    ball.Update();
    player.Update();

    ClearBackground(BLACK);

    ball.Draw();
    player.Draw();
    DrawRectangle(screenWidth-35, screenHeight/2-60, 25, 120, WHITE);
    DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
    
    EndDrawing();
  }

  CloseWindow();
  return 0;
}