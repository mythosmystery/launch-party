#include "Game.h"
#include "Constants.h"

Game::Game() {
  // Initialization
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Platformer Game");

  SetTargetFPS(60);
}

void Game::draw() {
  // Draw the game
  BeginDrawing();
  ClearBackground(this->backgroundColor);
  DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
  EndDrawing();
}

void Game::update() {
  // Update the game
}
