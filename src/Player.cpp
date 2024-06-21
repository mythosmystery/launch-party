#include "Player.h"
#include "Constants.h"
#include "GameObject.h"
#include "raylib.h"

Player::Player() {
  this->position = SCREEN_CENTER;
  this->speed = Vector2{0.0f, 0.0f};
  this->camera.zoom = 1.0f;
  this->camera.target = this->position;
  this->camera.offset = Vector2{0, 0};
}

Rectangle Player::getBounds() {
  return Rectangle{this->position.x, this->position.y, PLAYER_SIZE,
                   PLAYER_SIZE};
}

bool Player::collidesWith(GameObject *other) {
  Vector2 otherPos = other->getPosition();
  Vector2 otherSize = {other->getBounds().width, other->getBounds().height};

  return otherPos.x <= this->position.x &&
         otherPos.x + otherSize.x >= this->position.x &&
         otherPos.y >= this->position.y &&
         otherPos.y <= this->position.y + this->speed.y;
}

void Player::handleCollision(GameObject *other) {
  this->isGrounded = true;
  this->jumps = 2;
  this->speed.y = 0;
  this->position.y = other->getPosition().y - PLAYER_SIZE;
}

void Player::handleFall() { this->isGrounded = false; }

void Player::draw() { DrawRectangleRec(this->getBounds(), RED); }

void Player::update() {
  this->clampSpeed();
  this->handleInput();
  this->handleFriction();
  this->handleGravity();

  this->position.x += this->speed.x * GetFrameTime();
  this->position.y += this->speed.y * GetFrameTime();

  this->updateCamera();
}

void Player::updateCamera() {
  static Vector2 bbox = {0.2f, 0.2f};
  int width = GetRenderWidth();
  int height = GetRenderHeight();

  Vector2 bboxWorldMin = GetScreenToWorld2D(
      (Vector2){(1 - bbox.x) * 0.5f * width, (1 - bbox.y) * 0.5f * height},
      this->camera);
  Vector2 bboxWorldMax = GetScreenToWorld2D(
      (Vector2){(1 + bbox.x) * 0.5f * width, (1 + bbox.y) * 0.5f * height},
      this->camera);
  this->camera.offset =
      (Vector2){(1 - bbox.x) * 0.5f * width, (1 - bbox.y) * 0.5f * height};

  if (this->getPosition().x < bboxWorldMin.x)
    this->camera.target.x = this->getPosition().x;
  if (this->getPosition().y < bboxWorldMin.y)
    this->camera.target.y = this->getPosition().y;
  if (this->getPosition().x > bboxWorldMax.x)
    this->camera.target.x =
        bboxWorldMin.x + (this->getPosition().x - bboxWorldMax.x);
  if (this->getPosition().y > bboxWorldMax.y)
    this->camera.target.y =
        bboxWorldMin.y + (this->getPosition().y - bboxWorldMax.y);
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

  if (this->speed.x < 0.3f && this->speed.x > -0.3f) {
    this->speed.x = 0;
  }
}
