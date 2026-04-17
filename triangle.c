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
Vector2 GetWorldPoint(Vector2 local, Vector2 pos, float degrees) {
    float rad = degrees * (M_PI / 180.0f);
    Vector2 world;
    world.x = local.x * cosf(rad) - local.y * sinf(rad) + pos.x;
    world.y = local.x * sinf(rad) + local.y * cosf(rad) + pos.y;
    return world;
}
int IsGap(Vector2 axis, Vector2 tri1[3], Vector2 tri2[3]) {
    float min1 = INFINITY, max1 = -INFINITY;
    float min2 = INFINITY, max2 = -INFINITY;
    for (int i = 0; i < 3; i++) {
        float p1 = (tri1[i].x * axis.x) + (tri1[i].y * axis.y);
        if (p1 < min1) min1 = p1;
        if (p1 > max1) max1 = p1;

        float p2 = (tri2[i].x * axis.x) + (tri2[i].y * axis.y);
        if (p2 < min2) min2 = p2;
        if (p2 > max2) max2 = p2;
    }
    return (max1 < min2 || max2 < min1);
}

int CheckCollisionTriangleTriangle(Triangle a, Triangle b) {
    Vector2 w1[3] = {GetWorldPoint(t1.a, t1.position, t1.rotation),
                     GetWorldPoint(t1.b, t1.position, t1.rotation),
                     GetWorldPoint(t1.c, t1.position, t1.rotation)};
    Vector2 w2[3] = {GetWorldPoint(t2.a, t2.position, t2.rotation),
                     GetWorldPoint(t2.b, t2.position, t2.rotation),
                     GetWorldPoint(t2.c, t2.position, t2.rotation)};
    Vector2* shapes[2] = {w1, w2};
    for (int s = 0; s < 2; s++) {
        for (int i = 0; i < 3; i++) {
            Vector2 p1 = shapes[s][i];
            Vector2 p2 = shapes[s][(i + 1) % 3];
            Vector2 axis = { -(p2.y - p1.y), p2.x - p1.x };
            if (IsGap(axis, w1, w2)) return 0; 
        }
    }
    return 1;
}
