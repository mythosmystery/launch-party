#include "Game.h"
#include "Constants.h"
#include "raylib.h"

Game::Game() {
  // Initialization
  std::unique_ptr<raylib::Window> window = std::make_unique<raylib::Window>(
      SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Game");

  window->ToggleFullscreen();

  SetTargetFPS(60);

  this->player = std::make_unique<Player>();
  this->window = std::move(window);
}

void Game::draw() {
  // Draw the game
  BeginDrawing();
  {
    this->backgroundColor.ClearBackground();
    BeginMode2D(this->player->getCamera());

    this->player->draw();
    DrawRectangle(0, GetRenderHeight(), GetRenderWidth(), 100, BLACK);

    EndMode2D();
  }
  EndDrawing();
}

void Game::update() {
  // Update the game
  this->player->update();
}
