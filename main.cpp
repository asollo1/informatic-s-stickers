#include "include/raylib/raylib.h"
#include <iostream>
// Variables
Color ver_color = WHITE, hor_color = WHITE;
int health = 3, player_posx = 1, player_posy = 1, player_posx_last = 1, player_posy_last = 1, tick = 0, block1_posx = 1, block1_posy = 1;

// Functions

// Rendering gui
void gui(Color ver_color, Color hor_color, int health, Texture2D texture, Texture2D heart){
    //Variables
    int count = 0;
    int position = 0;

    //background
    DrawTexture(texture, 800 - 800, 800 - 800, WHITE);
     
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
    DrawRectangle(0, 810, 810, 100, BLACK);

    // Health
    position = 560;
    DrawText("Health: ", 440, 830, 30, WHITE);
    while (count != health){
        DrawTexture(heart, position, 820, WHITE);
        position = position + 80;
        count = count + 1;
    }
}

// Rendering player
void player(int player_posx, int player_posy, Texture2D texture){
    player_posx = player_posx * 80 - 70;
    player_posy = player_posy * 80 - 70;
    DrawTexture(texture, player_posx, player_posy, WHITE);
}
// Rendering wall
void wall(int wall_posx, int wall_posy, Texture2D texture){
    wall_posx = wall_posx * 80 - 70;
    wall_posy = wall_posy * 80 - 70;
    DrawTexture(texture, wall_posx, wall_posy, WHITE);
}


//Main code 
int main(){
    //Initialization
    InitWindow(810,900,"GAME");
    SetTargetFPS(60);
    //Texturesimage.png
    Texture2D grass = LoadTexture("textures/grass.png"), player_texture = LoadTexture("textures/player.png"), heart = LoadTexture("textures/heart.png"), wall_texture = LoadTexture("textures/wall.png");
    while(!WindowShouldClose()){
        BeginDrawing();
        //Rending 
        ClearBackground(GREEN);
        gui(ver_color, hor_color, health, grass, heart);
        player(player_posx, player_posy, player_texture);
        if (IsKeyDown(KEY_RIGHT) && player_posx < 10){
            player_posx = player_posx + 1;
        }
        if (IsKeyDown(KEY_LEFT) && player_posx > 1){
            player_posx = player_posx - 1;
        }
        if (IsKeyDown(KEY_UP) && player_posy > 1){
            player_posy = player_posy - 1;
        }
        if (IsKeyDown(KEY_DOWN) && player_posy < 10){
            player_posy = player_posy + 1;
        }
        if (player_posx == 10 && player_posy == 10){
            player_posx = player_posx_last;
            player_posy = player_posy_last;
            if (health != 0){
                health = health - 1;
            }
        }
        wall(2, 1, wall_texture);
        wall(3, 1, wall_texture);
        wall(4, 1, wall_texture);
        wall(5, 1, wall_texture);
        wall(6, 1, wall_texture);
        wall(7, 1, wall_texture);
        wall(8, 1, wall_texture);
        wall(9, 1, wall_texture);
        wall(10, 1, wall_texture);
        wall(10, 10, wall_texture);
        player(block1_posx , 2, player_texture);
        //Tick system
        tick = tick + 1;
        if (tick == 30 or tick == 60){
            block1_posx = block1_posx - 1;
            if (block1_posx == 0){
                block1_posx = 10;
            }
        }
        if (tick == 60) {
            tick = 0;
        }
        //Debuging player position
        player_posx_last = player_posx;
        player_posy_last = player_posy;
        std::cout << tick << std::endl;
        std::cout << player_posy << std::endl;
        std::cout << player_posx << std::endl;
        EndDrawing();
    }
    UnloadTexture(player_texture);
    UnloadTexture(grass);
}