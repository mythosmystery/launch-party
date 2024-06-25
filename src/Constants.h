#pragma once

#include "raylib.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

const float PLAYER_SIZE = 100.0f;

const float GRAVITY = 200.0f;
const float JUMP_FORCE = -550.0f;
const float DOUBLE_JUMP_FORCE = -630.0f;
const float PLAYER_GROUND_SPEED = 180.0f;
const float PLAYER_AIR_SPEED = 190.0f;
const float PLAYER_ACCELERATION = 10.2f;
const float PLAYER_AIR_ACCELERATION = 30.2f;
const float PLAYER_FRICTION = 6.5f;

const Vector2 SCREEN_CENTER = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
