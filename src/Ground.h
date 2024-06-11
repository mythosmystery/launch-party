#define GROUND_H

#include "GameObject.h"

class Ground : public GameObject {
public:
  Ground();

  void draw() override;
  void update() override;

  raylib::Rectangle getBounds() override;

  bool collidesWith(GameObject *other) override { return false; }

private:
  GO_Types type = GO_Types::Standable;
};
