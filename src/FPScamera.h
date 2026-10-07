// FPScamera.h
#pragma once
#include "raylib.h"
#include "raymath.h"

extern float camera_yaw;
extern float camera_pitch;
extern float camera_sensitivity;

Camera3D UpdateFPSCamera(Vector3 pos, Vector3 tgt, Vector3 up, float fov, int proj);
void AdjustPitchAndYaw(Vector2 delta);
Vector3 GetCameraDirection();
Vector3 GetMovementDirection();