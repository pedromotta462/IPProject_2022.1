#include "raylib.h"
#include <math.h>
#include "car.c"
#include "player.C"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>






#define INITMENU 10
#define GAME 11
#define UPGRADE 12

int main()
{
   
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

   

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Texture2D carTexture = LoadTexture("SportsRacingCar_0.png");
    Texture2D playerTexture = LoadTexture("Assets/CharacterSprites/PlayerIdleLeft.png");
    Rectangle exemplo;

    
    exemplo.x = 0;
    exemplo.y = 0;
    exemplo.height = 10;
    exemplo.y = 10;
    
    Car car = (Car){25, 25, exemplo, 0, 5, 0, 5, AIMING, 0, false};
    Player player = (Player){400, 400, 0, 5, exemplo, exemplo, 5, 5, false};
    
    int gameMode = GAME;

    Rectangle walls[4];
    walls[0].x = 30;
    walls[0].y = 30;
    walls[0].width = 10;
    walls[0].height = 1000;
    walls[1].x = 30;
    walls[1].y = 30;
    walls[1].width = 1500;
    walls[1].height = 10;
    walls[2].x = 1500;
    walls[2].y = 0;
    walls[2].width = 10;
    walls[2].height = 1000;
    walls[3].x = 0;
    walls[3].y = 1000;
    walls[3].width = 1500;
    walls[3].height = 10;
    
    
    
    while (!WindowShouldClose()){    
        
        switch(gameMode){
            case INITMENU:
                // código de implementação e funcionalidade do menu

                break;
            case GAME:
                
                
                car.timeCounter+=GetFrameTime();
                movePlayer(&player);
                
                BeginDrawing();
                ClearBackground(RAYWHITE);
                for(int i=0;i<4;i++){
                    DrawRectangleRec(walls[i], BLACK);
                }
                DrawTexture(playerTexture, player.posX, player.posY, RAYWHITE);
                DrawCar(car, carTexture);

                MasterUpdateCars(&car, 1, walls, player);
                



                
                EndDrawing();
                break;
            case UPGRADE:
                //código da escolha do upgrade no final de cada wave
            break;
        }

        
        
    }
    UnloadTexture(playerTexture);
    UnloadTexture(carTexture);
    CloseWindow();
          
    return 0;
}