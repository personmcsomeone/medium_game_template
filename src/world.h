#pragma once
#include <raylib.h>

typedef struct Wall{
    
} Wall;


typedef struct World{
    int level;
    Vector2 playerSpawn;
    Wall Walls[99];
} World;