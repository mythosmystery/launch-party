#include "Game.h"
#include "Constants.h"

Game::Game() {
  // Initialization
  std::unique_ptr<raylib::Window> window = std::make_unique<raylib::Window>(
      SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Game");

  SetTargetFPS(60);

  this->window = std::move(window);
}

void Game::draw() {
  // Draw the game
  BeginDrawing();

  this->backgroundColor.ClearBackground();

  DrawText("Press [SPACE] to start", 20, 20, 20, BLACK);

  EndDrawing();
}

void Game::update() {
  // Update the game
}
