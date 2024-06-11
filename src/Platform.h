#define PLATFORM_H
#include "GameObject.h"

class Platform : public GameObject {
public:
  Platform(raylib::Vector2 position, raylib::Vector2 size, raylib::Color color);

  void draw() override;
  void update() override;

  raylib::Rectangle getBounds() override;

  bool collidesWith(GameObject *other) override { return false; }

private:
  GO_Types type = GO_Types::Standable;

  raylib::Vector2 size;
  raylib::Color color;
};
