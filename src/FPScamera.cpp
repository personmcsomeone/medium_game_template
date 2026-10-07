//FPScamera.c
#include "FPScamera.h"

float camera_yaw = 0.0f;
float camera_pitch = 0.0f;
float camera_sensitivity = 0.0007f;

Camera3D UpdateFPSCamera(Vector3 pos, Vector3 tgt, Vector3 up, float fov, int proj)
{
    //Intialize
    Camera3D camera = { 0 };
    camera.position = pos;  // Camera position
    camera.target = tgt;      // Camera looking at point
    camera.up = up;          // Camera up vector (rotation towards target)
    camera.fovy = fov;                                // Camera field-of-view Y
    camera.projection = proj;             // Camera mode type

    return camera;
}

void AdjustPitchAndYaw(Vector2 delta){
    // Update yaw (left/right)
        camera_yaw -= delta.x * camera_sensitivity;

        // Update pitch (up/down)
        camera_pitch -= delta.y * camera_sensitivity;

        // Prevent looking completely upside down
        if (camera_pitch > 1.5f){camera_pitch = 1.5f;}
        if (camera_pitch < -1.5f){camera_pitch = -1.5f;}
}

Vector3 GetCameraDirection(){
    
    return  (Vector3){
                cosf(camera_pitch) * sinf(camera_yaw),
                sinf(camera_pitch),
                cosf(camera_pitch) * cosf(camera_yaw)
            };
};

Vector3 GetMovementDirection(){
    
    return  (Vector3){
                sinf(camera_yaw), //cosf(camera_pitch) * sinf(camera_yaw),
                0,
                cosf(camera_yaw)// cosf(camera_pitch) * cosf(camera_yaw)
            };
};
