#pragma once

#include "raylib.h"

enum class GO_Types { Standable, Entity, Player };

class GameObject {
public:
  virtual void draw() = 0;
  virtual void update() = 0;

  virtual Rectangle getBounds() = 0;
  virtual bool collidesWith(GameObject *other) = 0;

  Rectangle getCollisionBounds() { return this->getBounds(); };
  GO_Types getType() { return this->type; }
  Vector2 getPosition() { return this->position; }
  Vector2 getSpeed() { return this->speed; }

protected:
  Vector2 position;
  Vector2 speed;

  GO_Types type;
};
