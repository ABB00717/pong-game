#include "ball.h"

Ball::Ball(Vector2 position, Vector2 speed, float radius) {
  this->position = position;
  this->speed = speed;
  this->radius = radius;
}

void Ball::update() {
  position.x += speed.x;
  position.y += speed.y;

  if (position.y - radius <= 0 || position.y + radius >= GetScreenHeight())
    speed.y *= -1;
  if (position.x - radius <= 0 || position.x + radius >= GetScreenWidth())
    speed.x *= -1;

  if (position.x - radius <= 0) {
    computerScore++;
    position = {(float)screenWidth / 2, (float)screenHeight / 2};
  } else if (position.x + radius >= GetScreenWidth()) {
    playerScore++;
    position = {(float)screenWidth / 2, (float)screenHeight / 2};
  }
}

void Ball::draw() { DrawCircle(position.x, position.y, radius, Yellow); }

void Ball::paddleCollision() { speed.x *= -1; }