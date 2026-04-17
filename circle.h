#pragma once
#include "raylib.h"
#include "globals.h"
struct Circle {
    Vector2 position;
    float radius;
    float rotation;
};
typedef struct Circle Circle;
Circle CreateCircle(float x, float y, float radius);
void RenderCircle(Circle c);
void MoveCircle(float x, float y, Circle* cir);
void RotateCircle(float deg, Circle* rec);