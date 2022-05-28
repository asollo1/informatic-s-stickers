#include "include/raylib/raylib.h"
#include <iostream>
// Variables
Color ver_color = WHITE, hor_color = WHITE;
int health = 3, player_posx = 10, player_posy = 10;
void gui(Color ver_color, Color hor_color, int health){
    //Variables
    int count = 0;
    int position = 0;

    //background
    //DrawTexture(texture, 320 - 320, 320 - 320, WHITE);
     
    //vertical
    while (position != 880){
        DrawRectangle(position, 0, 10,  810, ver_color);
        position = position + 80;
    }

    //horizontal
    position = 0;
    while (position != 880){
        DrawRectangle(0, position, 810,  10, ver_color);
        position = position + 80;
    }

    // Hud
    DrawRectangle(0, 810, 810, 100, BLUE);

    // Health
    position = 50;
    while (count != health){
        DrawCircle(position, 860,30.0f,RED);
        position = position + 80;
        count = count + 1;
    }
}

void player(int player_posx, int player_posy){
    player_posx = player_posx * 80 - 70;
    player_posy = player_posy * 80 - 70;
    DrawRectangle(player_posx, player_posy, 70,  70, BLACK);
}
int main(){
    //Textures
    //Texture2D texture = LoadTexture("textures/grass.png");
    //Initialization
    InitWindow(810,900,"Hello world!");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GREEN);
        gui(ver_color, hor_color, health);
        player(player_posx, player_posy);
        EndDrawing();
    }
}