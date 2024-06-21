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

  Camera2D getCamera() { return this->camera; }

  void handleCollision(GameObject *other);
  void handleFall();

private:
  void handleInput();
  void handleFriction();
  void handleGravity();
  void clampSpeed();
  void updateCamera();

  bool isGrounded = false;
  int jumps = 2;
  Camera2D camera;
  GO_Types type = GO_Types::Player;
};
