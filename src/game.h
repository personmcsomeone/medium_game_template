// game.h
#pragma once
#include "globals.h"
#include "player.h"
#include "enemy.h"
#include "world.h"
#include <raylib.h>

typedef struct Game
{
    Player player;
    Enemy enemies[MAX_ENEMIES];
    World world;

    float deltaTime;
    int score;
    bool isGameOver;
} Game;

void Game_Init(Game* game);
void Game_Update(Game* game);
void Game_Draw(Game* game);
void Game_Unload(Game* game);