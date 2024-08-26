#ifndef BALL_H
#define BALL_H

#include "pong_game.h"
#include <raylib.h>

class Ball {
public:
  Ball(Vector2 position, Vector2 speed, float radius);
  void update();
  void draw();
  void paddleCollision();

  Vector2 getPosition() { return position; }
  float getRadius() { return radius; }

protected:
  Vector2 position;
  Vector2 speed;
  float radius;
};

#endif // BALL_H