#include "game.h"
#include <raylib.h>


void Game_Update(Game* game)
{
    if (game->isGameOver) return;

    Player_Update(&game->player, game->deltaTime);
    //Enemy_UpdateAll(game->enemies, MAX_ENEMIES, game->deltaTime);
    //World_Update(&game->world, game->deltaTime);

    // Example collision check
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (CheckCollisionRecs(game->player.bounds, game->enemies[i].bounds))
        {
            game->isGameOver = true;
        }
    }
}

void Game_Draw(Game* game)
{
    BeginDrawing();
    ClearBackground(BLACK);

    for (int i = 0; i < MAX_ENEMIES; i++){
        //Enemy_Draw(&game->enemies[i]);
    }

    Player_Draw(&game->player);

    if (game->isGameOver){
        DrawText("GAME OVER", 500, 300, 40, RED);
    }
        
    EndDrawing();    
}

void Game_Init(Game* game){
    Player_Init(&(game->player));

    game->deltaTime = 0;

    game->isGameOver = false;

    game->score = 0;
}