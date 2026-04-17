#include "circle.h"
Circle CreateCircle(float x, float y, float radius) {
    return (Circle){(Vector2){x, y}, radius, 0.0f};
}
void RenderCircle(Circle cir) {
    DrawCircleV(cir.position, cir.radius, default_color);
    int notches = 12;
    float step = 2 * PI / notches;
    float radOffset = cir.rotation * DEG2RAD;
    for (int i = 0; i < notches; i++) {
        float a = radOffset + i * step;
        Vector2 inner = {
            cir.position.x + cosf(a) * (cir.radius - 4),
            cir.position.y + sinf(a) * (cir.radius - 4)
        };
        Vector2 outer = {
            cir.position.x + cosf(a) * cir.radius,
            cir.position.y + sinf(a) * cir.radius
        };
        DrawLineV(inner, outer, DARKGRAY);
    }
}
void MoveCircle(float x, float y, Circle* cir) {
    cir->position.x += x;
    cir->position.y += y;
}
void RotateCircle(float deg, Circle* cir) { // this changes the rotation field
    cir->rotation += deg;
    if (cir->rotation >= 360) cir->rotation -= 360;
    if (cir->rotation < 0) cir->rotation += 360;
}

int CheckCollisonCircleCircle(Circle a, Circle b) {
    float diffX = a.position.x - b.position.x;
    float diffY = a.position.y - b.position.y;
    float distanceSquared = (diffX * diffX) + (diffY * diffY);
    float radiiSum = a.radius + a.radius;
    return distanceSquared <= (radiiSum * radiiSum);
}

//int CheckCollisionCircleCircle(Circle a, Circle b);
//void PreformCollisionCircleCircle(Circle* a, Circle* b);
