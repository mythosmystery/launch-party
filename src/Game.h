#define GAME_H

#include "Player.h"
#include <memory>
#include <vector>

struct Game {
  Game();

  void draw();
  void update();

  Color backgroundColor = Color{115, 145, 250, 255};

  std::unique_ptr<Player> player;

  std::vector<std::unique_ptr<GameObject>> gameObjects;

  float dt = 0;
};
