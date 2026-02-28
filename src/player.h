#pragma once
#include <raylib.h>

typedef struct Player
{
    Vector2 position;
    Rectangle bounds;
    float speed;
} Player;

void Player_Init(Player* player);
void Player_Update(Player* player, float dt);
void Player_Draw(Player* player);