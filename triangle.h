#pragma once
#include "raylib.h"
#include "globals.h"
struct Triangle {
    Vector2 a;
    Vector2 b;
    Vector2 c;
    Vector2 position;
    float rotation;
};
typedef struct Triangle Triangle;
Triangle CreateTriangle(float ax, float ay, float bx, float by, float cx, float cy);
void RenderTriangle(Triangle t);
void MoveTriangle(float x, float y, Triangle* t);
void RotateTriangle(float deg, Triangle* rec);