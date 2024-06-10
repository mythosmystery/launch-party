#define PLAYER_H

#include "raylib-cpp.hpp"

class Player {
public:
  Player();

  void draw();
  void update();

  void handleInput();
  void handleFriction();
  void handleGravity();

  void handleCollision();
  void clampSpeed();

private:
  raylib::Vector2 position;
  raylib::Vector2 speed;
  bool isGrounded = false;
  int jumps = 2;
};
