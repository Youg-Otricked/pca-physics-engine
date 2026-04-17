#pragma once
#include "raylib.h"
#include "globals.h"
#include <stdio.h>
struct Rect {
    Vector2 position;
    float width;
    float height;
    float rotation;
};
typedef struct Rect Rect;
Rect CreateRect(float x, float y, float width, float height);
void RenderRect(Rect r);
void MoveRect(float x, float y, Rect* rec);
void RotateRect(float deg, Rect* rec);