#define PLATFORM_H
#include "GameObject.h"

class Platform : public GameObject {
public:
  Platform(Vector2 position, Vector2 size, Color color);

  void draw() override;
  void update() override;

  Rectangle getBounds() override;

  bool collidesWith(GameObject *other) override { return false; }

private:
  GO_Types type = GO_Types::Standable;

  Vector2 size;
  Color color;
};
