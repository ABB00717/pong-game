#include "ball.h"
#include "paddle.h"
#include "pong_game.h"
#include <iostream>
#include <raylib.h>

int main() {
  std::cout << "Hello, World!" << std::endl;

  InitWindow(screenWidth, screenHeight, title);
  SetTargetFPS(targetFPS);

  Ball ball({(float)screenWidth / 2, (float)screenHeight / 2}, {3, 3}, 20);
  Paddle player({20, (float)screenHeight / 2 - 60}, 4, 25, 120);
  CpuPaddle computer({(float)screenWidth - 45, (float)screenHeight / 2 - 60}, 4,
                     25, 120);

  while (WindowShouldClose() == false) {
    BeginDrawing();
    ball.update();
    player.update();
    computer.update(ball.getPosition());

    if (CheckCollisionCircleRec(ball.getPosition(), ball.getRadius(),
                                player.getPaddle()))
      ball.paddleCollision();
    if (CheckCollisionCircleRec(ball.getPosition(), ball.getRadius(),
                                computer.getPaddle()))
      ball.paddleCollision();

    ClearBackground(DarkGreen);

    DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, Green);
    DrawCircle(screenWidth / 2, screenHeight / 2, 150, LightGreen);
    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
    ball.draw();
    player.draw();
    computer.draw();
    DrawText(TextFormat("%i", playerScore), screenWidth * 3 / 4 - 20, 20, 80,
             WHITE);
    DrawText(TextFormat("%i", computerScore), screenWidth / 4 - 20, 20, 80,
             WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}