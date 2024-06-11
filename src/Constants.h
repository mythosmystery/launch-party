#pragma once

#include "raylib.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

const float PLAYER_SIZE = 100.0f;

const float GRAVITY = 2.5f;
const float JUMP_FORCE = -35.0f;
const float DOUBLE_JUMP_FORCE = -43.0f;
const float PLAYER_GROUND_SPEED = 18.0f;
const float PLAYER_AIR_SPEED = 19.0f;
const float PLAYER_ACCELERATION = 1.2f;
const float PLAYER_AIR_ACCELERATION = 3.2f;
const float PLAYER_FRICTION = 0.65f;

const Vector2 SCREEN_CENTER = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
