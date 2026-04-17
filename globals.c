#include "globals.h"
Vector2 RotatePoint(Vector2 p, Vector2 center, float angle) {
    float s = sinf(angle);
    float c = cosf(angle);
    p.x -= center.x;
    p.y -= center.y;
    float xnew = p.x * c - p.y * s;
    float ynew = p.x * s + p.y * c;
    return (Vector2){ xnew + center.x, ynew + center.y };
}