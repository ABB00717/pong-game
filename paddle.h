#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>

class Paddle {
public:
  Paddle(Vector2 position, float speed, float width, float height);
  virtual void draw();
  virtual void update();
  Rectangle getPaddle() { return {position.x, position.y, width, height}; }

protected:
  Vector2 position;
  float speed;
  float width;
  float height;
};

class CpuPaddle : public Paddle {
public:
  CpuPaddle(Vector2 position, float speed, float width, float height);
  void update(Vector2 ballPosition);
};

#endif // PADDLE_H