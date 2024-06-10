#define GAME_H

#include "raylib-cpp.hpp"

struct Game {
  Game();

  void draw();
  void update();

  raylib::Color backgroundColor = RAYWHITE;
  std::unique_ptr<raylib::Window> window;
};
