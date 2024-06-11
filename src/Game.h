#define GAME_H

#include "Player.h"
#include "raylib-cpp.hpp"
#include <memory>

struct Game {
  Game();

  void draw();
  void update();

  raylib::Color backgroundColor = raylib::Color{115, 145, 250, 255};

  std::unique_ptr<raylib::Window> window;
  std::unique_ptr<Player> player;
};
