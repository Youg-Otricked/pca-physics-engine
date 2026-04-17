#include "line.h"
Line CreateLine(float x1, float y1, float x2, float y2) {
    return (Line){
        (Vector2){x1, y1},
        (Vector2){x2, y2},
        (Vector2){
            (x1 + x2) * 0.5f,
            (y1 + y2) * 0.5f
        }
    };
}
void RenderLine(Line l) {
    float rad = l.rotation * DEG2RAD;

    Vector2 center = {
        (l.a.x + l.b.x) * 0.5f,
        (l.a.y + l.b.y) * 0.5f
    };

    Vector2 a = RotatePoint(l.a, center, rad);
    Vector2 b = RotatePoint(l.b, center, rad);

    DrawLineV(a, b, default_color);
}
void MoveLine(float x, float y, Line* l) {
    l->a.x += x;
    l->a.y += y;
    l->b.x += x;
    l->b.y += y;
    l->position = (Vector2){
        (l->a.x + l->b.x) * 0.5f,
        (l->a.y + l->b.y) * 0.5f
    };
}
void RotateLine(float deg, Line* l) {
    l->rotation += deg;
    if (l->rotation >= 360) l->rotation -= 360;
    if (l->rotation < 0) l->rotation += 360;
}