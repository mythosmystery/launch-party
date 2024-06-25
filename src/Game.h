#define GAME_H

#include "raylib.h"

struct Game {
  Game();

  void draw();
  void update();

  Color backgroundColor = Color{115, 145, 250, 255};
};
