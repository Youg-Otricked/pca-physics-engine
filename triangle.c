#include "triangle.h"
Triangle CreateTriangle(float x1, float y1, float x2, float y2,float x3, float y3) {
    Vector2 center = {
        (x1 + x2 + x3) / 3.0f,
        (y1 + y2 + y3) / 3.0f
    };
    return (Triangle){
        (Vector2){x1, y1},
        (Vector2){x2, y2},
        (Vector2){x3, y3},
        center,
        0.0f
    };
}
void RenderTriangle(Triangle t) {
    float rad = t.rotation * DEG2RAD;
    Vector2 a = RotatePoint(t.a, t.position, rad);
    Vector2 b = RotatePoint(t.b, t.position, rad);
    Vector2 c = RotatePoint(t.c, t.position, rad);
    DrawTriangle(a, b, c, default_color);
}
void MoveTriangle(float x, float y, Triangle* t) {
    t->a.x += x;
    t->a.y += y;

    t->b.x += x;
    t->b.y += y;

    t->c.x += x;
    t->c.y += y;
    t->position = (Vector2){
        (t->a.x + t->b.x + t->c.x) / 3.0f,
        (t->a.y + t->b.y + t->c.y) / 3.0f
    };
}
void RotateTriangle(float deg, Triangle* t) {
    t->rotation += deg;
    if (t->rotation >= 360) t->rotation -= 360;
    if (t->rotation < 0) t->rotation += 360;
}
int CheckCollisionTriangleTriangle(Triangle a, Triangle b) {
    
}
