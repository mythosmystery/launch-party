#define PLAYER_H

#include "GameObject.h"
#include "raylib.h"

class Player : public GameObject {
public:
  Player();

  void draw() override;
  void update() override;

  bool collidesWith(GameObject *other) override;

  Rectangle getBounds() override;

  void handleInput();
  void handleFriction();
  void handleGravity();

  void handleCollision();
  void clampSpeed();

  void updateCamera();
  Camera2D getCamera() { return this->camera; }

private:
  Camera2D camera;
  bool isGrounded = false;
  int jumps = 2;
  GO_Types type = GO_Types::Player;
};
