#include "Game.h"

int main() {
  Game game;

  // Main game loop
  while (!WindowShouldClose()) {
    game.dt = GetFrameTime();

    // Draw
    game.draw();

    // Update
    game.update();
  }

  return 0;
}
