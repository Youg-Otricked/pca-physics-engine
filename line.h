#pragma once
#include "raylib.h"
#include "globals.h"
struct Line {
    Vector2 a;
    Vector2 b;
    Vector2 position;
    float rotation;
};
typedef struct Line Line;
Line CreateLine(float x1, float y1, float x2, float y2);
void RenderLine(Line l);
void MoveLine(float x, float y, Line* t);
void RotateLine(float deg, Line* t);