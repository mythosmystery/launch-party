#include "Player.h"
#include "Constants.h"

Player::Player() {
  this->position = SCREEN_CENTER;
  this->speed = raylib::Vector2{0.0f, 0.0f};
}

void Player::draw() {
  DrawRectangleV(this->position, raylib::Vector2{50.0f, 50.0f}, RED);
}

void Player::update() {
  this->handleCollision();
  this->clampSpeed();
  this->handleInput();

  this->position.x += this->speed.x;
  this->position.y += this->speed.y;
}

void Player::handleInput() {
  if (IsKeyPressed(KEY_SPACE) && this->jumps) {
    this->speed.y = this->isGrounded ? JUMP_FORCE : DOUBLE_JUMP_FORCE;
    this->isGrounded = false;
    this->jumps--;
  }

  float accel =
      this->isGrounded ? PLAYER_ACCELERATION : PLAYER_AIR_ACCELERATION;

  if (IsKeyDown(KEY_RIGHT)) {
    this->speed.x += accel;
  } else if (IsKeyDown(KEY_LEFT)) {
    this->speed.x -= accel;
  }

  this->handleFriction();
  this->handleGravity();
}

void Player::handleGravity() {
  if (!this->isGrounded) {
    this->speed.y += GRAVITY;
  }
}

void Player::handleFriction() {
  if (this->isGrounded) {
    if (this->speed.x > 0) {
      this->speed.x -= PLAYER_FRICTION;
    } else if (this->speed.x < 0) {
      this->speed.x += PLAYER_FRICTION;
    }
  }
}

void Player::handleCollision() {
  if (this->position.y >= GetRenderHeight() - 50) {
    this->position.y = GetRenderHeight() - 50;
    this->speed.y = 0;
    this->isGrounded = true;
    this->jumps = 2;
  }
}

void Player::clampSpeed() {
  if (this->isGrounded) {
    if (this->speed.x > PLAYER_GROUND_SPEED) {
      this->speed.x = PLAYER_GROUND_SPEED;
    } else if (this->speed.x < -PLAYER_GROUND_SPEED) {
      this->speed.x = -PLAYER_GROUND_SPEED;
    }
  } else {
    if (this->speed.x > PLAYER_AIR_SPEED) {
      this->speed.x = PLAYER_AIR_SPEED;
    } else if (this->speed.x < -PLAYER_AIR_SPEED) {
      this->speed.x = -PLAYER_AIR_SPEED;
    }
  }
}
