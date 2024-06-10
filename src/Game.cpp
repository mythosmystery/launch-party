#include "Game.h"
#include "Constants.h"

Game::Game() {
  // Initialization
  std::unique_ptr<raylib::Window> window = std::make_unique<raylib::Window>(
      SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Game");

  window->ToggleFullscreen();

  SetTargetFPS(60);

  this->player = Player();
  this->window = std::move(window);
}

void Game::draw() {
  // Draw the game
  BeginDrawing();

  this->backgroundColor.ClearBackground();

  this->player.draw();

  EndDrawing();
}

void Game::update() {
  // Update the game
  this->player.update();
}
