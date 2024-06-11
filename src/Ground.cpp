#include "Ground.h"

Ground::Ground() {
  this->position = Vector2{0, GetRenderHeight() * 1.0f};
  this->speed = Vector2{0, 0};
}

raylib::Rectangle Ground::getBounds() {
  return raylib::Rectangle{this->position.x, this->position.y,
                           GetRenderWidth() * 1.0f, GetRenderHeight() * 0.1f};
}

void Ground::draw() { DrawRectangleRec(this->getBounds(), GREEN); }

void Ground::update() {
  this->position.x += this->speed.x;
  this->position.y += this->speed.y;
}
