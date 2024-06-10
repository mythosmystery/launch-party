#define GAME_H

#include "Player.h"
#include "raylib-cpp.hpp"
#include <memory>

struct Game {
  Game();

  void draw();
  void update();

  raylib::Color backgroundColor = RAYWHITE;
  std::unique_ptr<raylib::Window> window;

  Player player;
};
