
//#if defined(PLATFORM_WEB)
//    #include <emscripten/emscripten.h>
//#endif
/*
#include <raylib.h>
#include "game.h"
#include "globals.h"

void mainLoop(Game* game);

int main(void)
{
    InitWindow(800, 450, "My Game");
    SetTargetFPS(60);
    Game game = {0};
    //Game_Init(&game);

    while (!WindowShouldClose())
    {
        mainLoop(&game);
    }

    //Game_Unload(&game);
    CloseWindow();
}

void mainLoop(Game* game){
    /*
    game->deltaTime = GetFrameTime();
    Game_Update(game);
    Game_Draw(game);
    //
    static int init{0};
    static Vector3 pos;
    static Camera3D playerPOV = {0};
//    if(!init){
        pos = (Vector3){0.0,10.0,0.0};
        playerPOV.position = pos;
        playerPOV.fovy = 45.0; //Field of view
        playerPOV.projection = CAMERA_PERSPECTIVE;
        playerPOV.target = (Vector3){0.0,0.0,0.0};
        playerPOV.up = (Vector3){0.0,1.0f,0.0};
        init = 1;
//    }

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(playerPOV);

            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
            DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

            DrawGrid(10, 1.0f);

        EndMode3D();

        DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

        DrawFPS(10, 10);

    EndDrawing();


}
*/
/*
void introLoop(int targetFPS)
{
    
    int logoPositionX = screenWidth/2 - 128;
    int logoPositionY = screenHeight/2 - 128;

    int framesCounter = 0;
    int lettersCount = 0;

    int topSideRecWidth = 16;
    int leftSideRecHeight = 16;

    int bottomSideRecWidth = 16;
    int rightSideRecHeight = 16;

    int state = 0;                  // Tracking animation states (State Machine)
    float alpha = 1.0f;             // Useful for fading

    // Main game loop
    while (game_state == STATE_INTRO)    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (state == 0)                 // State 0: Small box blinking
        {
            framesCounter++;

            if (framesCounter == targetFPS)
            {
                state = 1;
                framesCounter = 0;      // Reset counter... will be used later...
            }
        }
        else if (state == 1)            // State 1: Top and left bars growing
        {
            topSideRecWidth += 2;
            leftSideRecHeight += 2;

            if (topSideRecWidth == 256) state = 2;
        }
        else if (state == 2)            // State 2: Bottom and right bars growing
        {
            bottomSideRecWidth += 2;
            rightSideRecHeight += 2;

            if (bottomSideRecWidth == 256) state = 3;
        }
        else if (state == 3)            // State 3: Letters appearing (one by one)
        {
            framesCounter++;

            if (framesCounter/24)       // Every 12 frames, one more letter!
            {
                lettersCount++;
                framesCounter = 0;
            }

            if (lettersCount >= 24)     // When all letters have appeared, just fade out everything
            {
                alpha -= 0.01f;

                if (alpha <= 0.0f)
                {
                    alpha = 0.0f;
                    state = 4;
                }
            }
        }
        else if (state == 4)            // State 4: Reset and Replay
        {
            GAME_STATE = STATE_MENU;
            break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (state == 0)
            {
                if ((framesCounter/15)%4) DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
            }
            else if (state == 1)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
            }
            else if (state == 2)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
                DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);

                DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
                DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
            }
            else if (state == 3)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha));
                DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha));

                DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha));
                DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha));

                DrawRectangle(GetScreenWidth()/2 - 112, GetScreenHeight()/2 - 112, 224, 224, Fade(RAYWHITE, alpha));

                DrawText(TextSubtext("raylib", 0, lettersCount), GetScreenWidth()/2 - 44, GetScreenHeight()/2 + 48, 50, Fade(BLACK, alpha));
            }
            else if (state == 4)
            {
                //redundancy
                GAME_STATE = STATE_MENU;
                break;
            }

        EndDrawing();
        }
}
*/

/*******************************************************************************************
*
*   raylib [core] example - 3d camera mode
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
/*
#include "raylib.h"
#include "raymath.h"
#include "stdio.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera mode");
    float yaw = 0.0f;
    float pitch = 0.0f;

    float sensitivity = 0.003f;
    // Define the camera to look into our 3d world
    Vector3 playerPos = (Vector3){ 0.0f, 10.0f, 10.0f };
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    SetMousePosition(screenWidth/2,screenHeight/2);
    DisableCursor();
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        

        static float sens{.1};
        //update sens
        if(IsKeyDown(KEY_RIGHT)){
            sens += .01;
        }
        if(IsKeyDown(KEY_LEFT)){
            sens -= .01;
        }

        //update yaw
        if(IsKeyPressed(KEY_SPACE)){
            SetMousePosition(screenWidth/2,screenHeight/2);
        }
        
        Vector2 delta = GetMouseDelta();
        if(delta.x){ //yaw
            camera.target.x += delta.x * sens;
        }
        if(delta.y){ //pitch
            camera.target.y -= delta.y * sens;
        }
        //update postion
        Vector3 cameraViewVector = Vector3Subtract(camera.target, camera.position);
        Vector3 cameraViewUnitVector = Vector3Scale(cameraViewVector, (1.0 / Vector3Length(cameraViewVector)));
        printf("TargVector  X:%.2f  Y:%.2f Z:%.2f \n",camera.target.x,camera.target.y,camera.target.z);
        printf("UnitVector  X:%.2f  Y:%.2f Z:%.2f \n",cameraViewUnitVector.x,cameraViewUnitVector.y,cameraViewUnitVector.z);
        if(IsKeyDown(KEY_W)){
            //Vector3Add(camera.position, cameraViewUnitVector);
            //camera.position.x += 1;
            //camera.target.x += 1;
            camera.position.x += cameraViewUnitVector.x;
            //camera.position.y += cameraViewUnitVector.y;
            camera.position.z += cameraViewUnitVector.z;
            camera.target.x += cameraViewUnitVector.x;
            //camera.position.y += cameraViewUnitVector.y;
            camera.target.z += cameraViewUnitVector.z;
            
        }
        if(IsKeyDown(KEY_S)){
            //camera.position.x -= 1;
            //camera.target.x -= 1;
            camera.position.x -= cameraViewUnitVector.x;
            //camera.position.y += cameraViewUnitVector.y;
            camera.position.z -= cameraViewUnitVector.z;
            camera.target.x -= cameraViewUnitVector.x;
            //camera.position.y += cameraViewUnitVector.y;
            camera.target.z -= cameraViewUnitVector.z;
        }
        if(IsKeyDown(KEY_D)){
            //camera.position.z += 1;
            //camera.target.z += 1;
            camera.position.x -= cameraViewUnitVector.z;
            //camera.position.y += cameraViewUnitVector.y;
            camera.position.z += cameraViewUnitVector.x;
            camera.target.x -= cameraViewUnitVector.z;
            //camera.position.y += cameraViewUnitVector.y;
            camera.target.z += cameraViewUnitVector.x;
        }
        if(IsKeyDown(KEY_A)){
            //camera.position.z -= 1;
            //camera.target.z -= 1;
            camera.position.x += cameraViewUnitVector.z;
            //camera.position.y += cameraViewUnitVector.y;
            camera.position.z -= cameraViewUnitVector.x;
            camera.target.x += cameraViewUnitVector.z;
            //camera.position.y += cameraViewUnitVector.y;
            camera.target.z -= cameraViewUnitVector.x;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                //x
                DrawLine3D((Vector3){0.0,0.0,0.0},(Vector3){5.0,0.0,0.0},BLUE);
                //y
                DrawLine3D((Vector3){0.0,0.0,0.0},(Vector3){0.0,5.0,0.0},GREEN);
                //z
                DrawLine3D((Vector3){0.0,0.0,0.0},(Vector3){0.0,0.0,5.0},YELLOW);
                
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawCube(Vector3Add(cubePosition, (Vector3){10.0f, 0.0f, 10.0f}), 2.0f, 2.0f, 2.0f, BLUE);
                DrawCubeWires(Vector3Add(cubePosition, (Vector3){10.0f, 0.0f, 10.0f}), 2.0f, 2.0f, 2.0f, DARKBLUE);

                DrawCube(Vector3Add(cubePosition, (Vector3){-10.0f, 0.0f, 10.0f}), 2.0f, 2.0f, 2.0f, GREEN);
                DrawCubeWires(Vector3Add(cubePosition, (Vector3){-10.0f, 0.0f, 10.0f}), 2.0f, 2.0f, 2.0f, LIME);

                DrawCube(Vector3Add(cubePosition, (Vector3){10.0f, 0.0f, -10.0f}), 2.0f, 2.0f, 2.0f, PURPLE);
                DrawCubeWires(Vector3Add(cubePosition, (Vector3){10.0f, 0.0f, -10.0f}), 2.0f, 2.0f, 2.0f, DARKPURPLE);

                DrawCube(Vector3Add(cubePosition, (Vector3){-10.0f, 0.0f, -10.0f}), 2.0f, 2.0f, 2.0f, YELLOW);
                DrawCubeWires(Vector3Add(cubePosition, (Vector3){-10.0f, 0.0f, -10.0f}), 2.0f, 2.0f, 2.0f, GOLD);


                DrawGrid(10, 1.0f);

            EndMode3D();

            if(IsKeyDown(KEY_RIGHT)){
                DrawCircle(700, 200, 30, RED);
            }   
            if(IsKeyDown(KEY_LEFT)){
                DrawCircle(100, 200, 30, GREEN);
            }
            DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
    */