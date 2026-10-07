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

#include "raylib.h"
#include "raymath.h"
#include "stdio.h"
#include "bullet.h"
#include "C:\Users\chunj\Desktop\RAYLIB_HOME\FPS_test\src\FPScamera.h"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "raylib example - 3d camera mode");
    //float yaw = 0.0f;
    //float pitch = 0.0f;
    //float sensitivity = 0.0007f;

    // Define the camera to look into our 3d world
    Vector3 playerPos = (Vector3){ 0.0f, 10.0f, 10.0f };
    Camera3D camera = UpdateFPSCamera(
        playerPos, 
        (Vector3){ 0.0f, 0.0f, 0.0f }, 
        (Vector3){ 0.0f, 1.0f, 0.0f },
        45.0f, 
        CAMERA_PERSPECTIVE
    );
    Bullet bulletArray[10] = {0};
    //Texture2D crosshair = LoadTexture("crosshair.png");
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
        // Get mouse movement
        Vector2 mouseDelta = GetMouseDelta();

        AdjustPitchAndYaw(mouseDelta);
        
        Vector3 cameraDirection = GetCameraDirection();
        Vector3 forwardDirection = GetMovementDirection();

        //player movement
        if(IsKeyDown(KEY_W)){
            playerPos.x += forwardDirection.x;
            playerPos.z += forwardDirection.z;
        }
        if(IsKeyDown(KEY_S)){
            playerPos.x -= forwardDirection.x;
            playerPos.z -= forwardDirection.z;
        }
        if(IsKeyDown(KEY_D)){
            playerPos.x -= forwardDirection.z;
            playerPos.z += forwardDirection.x;
        }
        if(IsKeyDown(KEY_A)){
            playerPos.x += forwardDirection.z;
            playerPos.z -= forwardDirection.x;
        }
        //sync player and camera
        camera = UpdateFPSCamera(
            playerPos, 
            Vector3Add(playerPos, cameraDirection), 
            (Vector3){ 0.0f, 1.0f, 0.0f }, //camera up??
            45.0f, //fov
            CAMERA_PERSPECTIVE
        );
        //update bullets
        UpdateBullets(bulletArray);

        // shooting
        static unsigned int shootingAvailable = 1;
        static float shootingTimer = 0.0;
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            if(shootingAvailable){
                //shoot
                InitializeBullet(bulletArray, playerPos, cameraDirection);

                //reset availiability to shooting/fire rate
                shootingTimer = .5;
                shootingAvailable = 0;
            }
            else{
                shootingTimer -= 1/GetFPS();
            }
            if(shootingTimer <= 0.0){
                shootingAvailable = 1;
            }
        }
        else{
            shootingAvailable = 1;
            shootingTimer = 0.0;
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

                for(int i = 0; i < maxBullets; i++){
                    if(bulletArray[i].isActive){
                        DrawSphere(bulletArray[i].pos, .5, BLACK);
                    }
                }

                DrawGrid(50, 1.0f);

            EndMode3D();
            DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);
            //DrawTextureEx(crosshair,(Vector2){screenWidth/2 - 64, screenHeight/2 - 64}, 0.0, 8, WHITE);
            //Rectangle crosshairSingle = (Rectangle){0,0,50,10};
            //DrawRectanglePro(crosshairSingle,(Vector2){screenWidth/2 - 5, screenHeight/2 - 50 - 25}, 90.0, BLACK);
            int crossLen{40};
            int crossThk{6};
            int crossGap{16};
            DrawRectangle(screenWidth - crossThk/2, screenHeight - crossLen - crossGap, crossThk, crossLen, BLACK);
            DrawRectangle(screenWidth - crossThk/2, screenHeight + crossGap, crossThk, crossLen, BLACK);
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