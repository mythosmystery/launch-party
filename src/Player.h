#define PLAYER_H

#include "GameObject.h"
#include "raylib-cpp.hpp"

class Player : public GameObject {
public:
  Player();

  void draw() override;
  void update() override;

  bool collidesWith(GameObject *other) override;

  raylib::Rectangle getBounds() override;

  void handleInput();
  void handleFriction();
  void handleGravity();

  void handleCollision();
  void clampSpeed();

  void updateCamera();
  raylib::Camera2D getCamera() { return this->camera; }

private:
  raylib::Camera2D camera;
  bool isGrounded = false;
  int jumps = 2;
  GO_Types type = GO_Types::Player;
};
