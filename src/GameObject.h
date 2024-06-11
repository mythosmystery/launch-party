#define GAMEOBJECT_H

#include "raylib-cpp.hpp"

class GameObject {
public:
  virtual void draw() = 0;
  virtual void update() = 0;

  virtual raylib::Vector2 getPosition() = 0;
  virtual raylib::Vector2 getSpeed() = 0;
  virtual raylib::Rectangle getBounds() = 0;

  virtual bool collidesWith(GameObject *other) = 0;

  virtual ~GameObject() = default;

protected:
  raylib::Vector2 position;
  raylib::Vector2 speed;
};
