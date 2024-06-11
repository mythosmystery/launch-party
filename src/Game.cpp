#include "Game.h"
#include "Constants.h"
#include "Ground.h"
#include "Platform.h"
#include "raylib.h"

Game::Game() {
  // Initialization
  std::unique_ptr<raylib::Window> window = std::make_unique<raylib::Window>(
      SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Game");

  window->ToggleFullscreen();

  SetTargetFPS(60);

  this->player = std::make_unique<Player>();
  this->window = std::move(window);

  this->gameObjects.push_back(std::make_unique<Ground>());
  this->gameObjects.push_back(std::make_unique<Platform>(
      raylib::Vector2{600, 600}, raylib::Vector2{200, 50},
      raylib::Color{255, 0, 0, 255}));
}

void Game::draw() {
  // Draw the game
  BeginDrawing();
  {
    this->backgroundColor.ClearBackground();
    BeginMode2D(this->player->getCamera());

    this->player->draw();

    for (auto &gameObject : this->gameObjects) {
      gameObject->draw();
    }

    EndMode2D();
  }
  EndDrawing();
}

void Game::update() {
  // Update the game
  for (auto &gameObject : this->gameObjects) {
    gameObject->update();
    this->player->collidesWith(gameObject.get());
  }
  this->player->update();
}
