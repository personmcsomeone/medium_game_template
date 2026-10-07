// bullet.h
#pragma once
#include "raylib.h"
#include "raymath.h"

constexpr int maxBullets = 10;
constexpr int maxBulletLife = 10;
constexpr float bulletSpeed = 10.0f;

typedef struct {
    Vector3 pos;
    Vector3 dir;
    unsigned int isActive;
    float lifetime;
}Bullet;

void InitializeBullet(Bullet bullet[maxBullets], Vector3 pos, Vector3 dir);
void UpdateBullets(Bullet bullet[maxBullets]);