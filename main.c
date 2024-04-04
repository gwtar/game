#include <stdio.h>
#include </usr/local/include/raylib.h>

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define WINDOW_TITLE "game"

typedef struct rectangle {
    int posx, posy, widthx, widthy;
    Color color;
} rectangle;

void init(rectangle *qube) {
    qube->widthx = qube->widthy = 200;
    qube->posx = WINDOW_WIDTH / 2 - qube->widthx / 2;
    qube->posy = WINDOW_HEIGHT / 2 - qube->widthy / 2;
    qube->color = WHITE;
}

void draw(rectangle qube) {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawRectangle(qube.posx, qube.posy, qube.widthx, qube.widthy, qube.color);

    EndDrawing();
}

void input_mouse(rectangle *qube) {
    qube->posx = GetMouseX() - qube->widthx / 2;
    qube->posy = GetMouseY() - qube->widthy / 2;
}

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    rectangle hi;

    init(&hi);

    while(!WindowShouldClose()) {
        draw(hi);
        input_mouse(&hi);
    }

    CloseWindow();
    return 0;
}
