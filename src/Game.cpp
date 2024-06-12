#include "Game.h"
#include "Constants.h"
#include "Ground.h"
#include "Platform.h"
#include "raylib.h"

Game::Game() {
  // Initialization
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Platformer Game");

  ToggleFullscreen();

  SetTargetFPS(60);

  this->player = std::make_unique<Player>();

  this->gameObjects.push_back(std::make_unique<Ground>());
  this->gameObjects.push_back(std::make_unique<Platform>(
      Vector2{600, 600}, Vector2{200, 50}, Color{255, 0, 0, 255}));
}

void Game::draw() {
  // Draw the game
  BeginDrawing();
  {
    ClearBackground(this->backgroundColor);
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
