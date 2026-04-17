#include "main.h"
Color default_color = BLACK;
Color background_color = RAYWHITE;
float delta = 0.0f;
int main() {
    InitWindow(800, 600, "Raylib Test");
    Camera2D camera = {0};

    camera.offset = (Vector2){
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
    };

    camera.target = (Vector2){ 0.0f, 0.0f };
    camera.zoom = 1.0f;
    camera.rotation = 0.0f;
    SetTargetFPS(60);
    Circle c = CreateCircle(0.0f, 0.0f, 20.0f);
    Rect r = CreateRect(-100.0f, 0.0f, 60.0f, 60.0f);
    Line l = CreateLine(-200.0f, -100.0f, 200.0f, 100.0f);
    Triangle t = CreateTriangle(100, -50, 150,  50, 200, -50);
    while (!WindowShouldClose()) {
        BeginDrawing();
        delta = GetFrameTime();
        ClearBackground(background_color);
        BeginMode2D(camera);
        RenderCircle(c);
        RenderRect(r);
        RenderLine(l); 
        RenderTriangle(t);
        MoveCircle(20.0f * delta, -20.0f * delta, &c);
        RotateCircle(180.0f * delta, &c);
        MoveRect(20.0f * delta, -20.0f * delta, &r);
        RotateRect(20.0f * delta, &r);
        MoveTriangle(20.0f * delta, -20.0f * delta, &t);
        RotateTriangle(20.0f * delta, &t);
        MoveLine(20.0f * delta, -20.0f * delta, &l);
        RotateLine(20.0f * delta, &l);
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}