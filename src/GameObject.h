#pragma once

#include "raylib-cpp.hpp"

enum class GO_Types { Standable, Entity, Player };

class GameObject {
public:
  virtual void draw() = 0;
  virtual void update() = 0;

  virtual raylib::Rectangle getBounds() = 0;
  virtual bool collidesWith(GameObject *other) = 0;

  GO_Types getType() { return this->type; }
  raylib::Vector2 getPosition() { return this->position; }
  raylib::Vector2 getSpeed() { return this->speed; }

protected:
  raylib::Vector2 position;
  raylib::Vector2 speed;

  GO_Types type;
};
