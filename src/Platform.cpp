#include "Platform.h"

Platform::Platform(Vector2 position, Vector2 size, Color color) {
  this->position = position;
  this->size = size;
  this->color = color;
}

Rectangle Platform::getBounds() {
  return Rectangle{this->position.x, this->position.y, this->size.x,
                   this->size.y};
}

void Platform::draw() { DrawRectangleRec(this->getBounds(), this->color); }

void Platform::update() {
  this->position.x += this->speed.x;
  this->position.y += this->speed.y;
}
