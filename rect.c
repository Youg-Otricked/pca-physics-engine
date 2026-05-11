#include "rect.h"
Rect CreateRect(float x, float y, float width, float height) {
    return (Rect){(Vector2){x, y}, width, height, 0.0f};
}
void RenderRect(Rect r){
    Rectangle rec = {
        r.position.x,
        r.position.y,
        r.width,
        r.height
    };
    Vector2 origin = {
        r.width / 2.0f,
        r.height / 2.0f
    };

    DrawRectanglePro(rec, origin, r.rotation, default_color);
}
void MoveRect(float x, float y, Rect* rec) {
    rec->position.x += x;
    rec->position.y += y;
}
void RotateRect(float deg, Rect* rec) {
    rec->rotation += deg;
    if (rec->rotation >= 360) rec->rotation -= 360;
    if (rec->rotation < 0) rec->rotation += 360;
}
int CheckCollisionRectRect(Rectangle a, Rectangle b) {
    return (a.x < b.x + b.width &&
            a.x + a.width > b.x &&
            a.y < b.y + b.height &&
            a.y + a.height > b.y);
}
void PreformCollisionRectRect(Rectangle a, Rectangle b) {
    if (CheckCollisionRectRect(Rectangle a, Rectangle b) == 1 {
    }
}
