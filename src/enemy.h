#pragma once
#include <raylib.h>

typedef struct Enemy
{
    Vector2 position;
    Rectangle bounds;
    float speed;
} Enemy;

void Enemy_Init(Enemy* enemy);
void Enemy_Update(Enemy* enemy, float dt);
void Enemy_Draw(Enemy* enemy);