#include "player.h"

void Player_Update(Player* player, float dt)
{
    if (IsKeyDown(KEY_D)) player->position.x += player->speed * dt;
    if (IsKeyDown(KEY_A)) player->position.x -= player->speed * dt;
    if (IsKeyDown(KEY_W)) player->position.y -= player->speed * dt;
    if (IsKeyDown(KEY_S)) player->position.y += player->speed * dt;

    //gravity
    float grav = 20;
    player->position.y += 20 * dt;

    player->bounds.x = player->position.x;
    player->bounds.y = player->position.y;
}

void Player_Draw(Player* player)
{
    DrawRectangleRec(player->bounds, BLUE);
}

void Player_Init(Player* player){
    player->position.x = 400;
    player->position.y = 400;
    player->bounds.x = player->position.x;
    player->bounds.y = player->position.y;
    player->bounds.width = 100;
    player->bounds.height = 100;
    player->speed = 200.0f;
}