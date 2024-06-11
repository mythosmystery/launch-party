#include "Platform.h"

Platform::Platform(raylib::Vector2 position, raylib::Vector2 size,
                   raylib::Color color) {
  this->position = position;
  this->size = size;
  this->color = color;
}

raylib::Rectangle Platform::getBounds() {
  return raylib::Rectangle{this->position.x, this->position.y, this->size.x,
                           this->size.y};
}

void Platform::draw() { DrawRectangleRec(this->getBounds(), this->color); }

void Platform::update() {
  this->position.x += this->speed.x;
  this->position.y += this->speed.y;
}
