#include "include/raylib/raylib.h"
#include <iostream>

int main(){
    //Initialization
    InitWindow(800,600,"Hello world!");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("1", 370, 270, 30, WHITE);
        EndDrawing();
    }
}