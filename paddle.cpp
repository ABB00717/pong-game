#include "paddle.h"

Paddle::Paddle(Vector2 position, float speed, float width, float height) {
  this->position = position;
  this->speed = speed;
  this->width = width;
  this->height = height;
}

void Paddle::draw() {
  DrawRectangle(position.x, position.y, width, height, WHITE);
}

void Paddle::update() {
  if (IsKeyDown(KEY_E) && position.y >= 20)
    position.y -= speed;
  if (IsKeyDown(KEY_D) && position.y + height <= GetScreenHeight() - 20)
    position.y += speed;
}

CpuPaddle::CpuPaddle(Vector2 position, float speed, float width, float height)
    : Paddle(position, speed, width, height) {}

void CpuPaddle::update(Vector2 ballPosition) {
  if (ballPosition.y > position.y + height / 2 &&
      position.y + height < GetScreenHeight() - 15)
    position.y += speed;
  if (ballPosition.y < position.y + height / 2 && position.y > 15)
    position.y -= speed;
}
