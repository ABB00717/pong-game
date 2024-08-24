#include <iostream>
#include <raylib.h>

const int screenWidth = 1280;
const int screenHeight = 800;
const char* title = "Pong!";
const int targetFPS = 144;
int playerScore = 0;
int computerScore = 0;

class Ball {
public:
  Ball(Vector2 position, Vector2 speed, float radius) {
    this->position = position;
    this->speed = speed;
    this->radius = radius;
  }

  void update() {
    position.x += speed.x;
    position.y += speed.y;

    if (position.y-radius <= 0 || position.y+radius >= GetScreenHeight()) speed.y *= -1;
    if (position.x-radius <= 0 || position.x+radius >= GetScreenWidth()) speed.x *= -1;

    if (position.x-radius <= 0) {
      computerScore++;
      position = {(float)screenWidth/2, (float)screenHeight/2};
    } else if (position.x+radius >= GetScreenWidth()) {
      playerScore++;
      position = {(float)screenWidth/2, (float)screenHeight/2};
    }
  }

  void draw() { 
    DrawCircle(position.x, position.y, radius, WHITE); 
  }
  
  void paddleCollision() {
    speed.x *= -1;
  }

  Vector2 getPosition() { return position; }
  float getRadius() { return radius; }

protected:
  Vector2 position;
  Vector2 speed;
  float radius;
  
};

class Paddle {
public:
  Paddle(Vector2 position, float speed, float width, float height) {
    this->position = position;
    this->speed = speed;
    this->width = width;
    this->height = height;
  }

  virtual void draw() {
    DrawRectangle(position.x, position.y, width, height, WHITE);
  }

  virtual void update() {
    if (IsKeyDown(KEY_E) && position.y >= 20) position.y -= speed;
    if (IsKeyDown(KEY_D) && position.y+height <= GetScreenHeight()-20) position.y += speed;
  }

  Rectangle getPaddle() {
    Rectangle paddle = {position.x, position.y, width, height};

    return paddle;
  }

protected:
  Vector2 position;
  float speed;
  float width;
  float height;

};

class CpuPaddle: public Paddle {
public:
  CpuPaddle(Vector2 position, float speed, float width, float height)
    : Paddle(position, speed, width, height) {}

  void update(Vector2 ballPosition) {
    if (ballPosition.y > position.y+height/2 && position.y+height < GetScreenHeight()-15) position.y += speed;
    if (ballPosition.y < position.y+height/2 && position.y > 15) position.y -= speed;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;

  InitWindow(screenWidth, screenHeight, title);
  SetTargetFPS(targetFPS);
  
  Ball ball({(float)screenWidth/2, (float)screenHeight/2}, {3, 3}, 20);
  Paddle player({20, (float)screenHeight/2-60}, 4, 25, 120);
  CpuPaddle computer({(float)screenWidth-45, (float)screenHeight/2-60}, 4, 25, 120);

  while (WindowShouldClose() == false) {
    BeginDrawing();
    ball.update();
    player.update();
    computer.update(ball.getPosition());

    if (CheckCollisionCircleRec(ball.getPosition(),ball.getRadius(),player.getPaddle())) ball.paddleCollision();
    if (CheckCollisionCircleRec(ball.getPosition(),ball.getRadius(),computer.getPaddle())) ball.paddleCollision();

    ClearBackground(BLACK);
    ball.draw();
    player.draw();
    computer.draw();
    
    DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
    DrawText(TextFormat("%i", playerScore), screenWidth*3/4-20, 20, 80, WHITE);
    DrawText(TextFormat("%i", computerScore), screenWidth/4-20, 20, 80, WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}