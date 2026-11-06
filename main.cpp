#include <raylib.h>

int main(){
    InitWindow(1280, 720, "Candy Slice");
    SetTargetFPS(60);
    
    //textures
    //main menu
    Texture2D background0 = LoadTexture("assets/textures/mainmenu.png");
    Texture2D playbutton = LoadTexture("assets/textures/playbutton.png");
    Texture2D playbuttonhover = LoadTexture("assets/textures/playbuttonhover.png");
    Texture2D settingsbutton = LoadTexture("assets/textures/settings.png");
    Texture2D settingsbuttonhover = LoadTexture("assets/textures/settingshover.png");
    Texture2D quitbutton = LoadTexture("assets/textures/quitbutton.png");
    Texture2D quitbuttonhover = LoadTexture("assets/textures/quitbuttonhover.png");
    //gamemode screen
    Texture2D background1 = LoadTexture("assets/textures/background1.png");
    Texture2D classicmode = LoadTexture("assets/textures/classicmode.png");
    Texture2D classicmodehover = LoadTexture("assets/textures/classicmodehover.png");

    //texture filters
    //main menu
    SetTextureFilter(background0, TEXTURE_FILTER_POINT);
    SetTextureFilter(playbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(playbuttonhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(settingsbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(settingsbuttonhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(quitbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(quitbuttonhover, TEXTURE_FILTER_POINT);
    //gamemode screen
    SetTextureFilter(background1, TEXTURE_FILTER_POINT);
    SetTextureFilter(classicmode, TEXTURE_FILTER_POINT);
    SetTextureFilter(classicmodehover, TEXTURE_FILTER_POINT);


    //variables
    //screen
    int screen = 0;

    while(!WindowShouldClose()){
        //mouse position
        Vector2 cursor = GetMousePosition();

        //begin
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextureEx(background0, {0, 0}, 0, 8.0f, WHITE);


        //main menu
        if(screen == 0){
            bool playbuttonbool = CheckCollisionPointRec(cursor, {376, 192, 528, 96});
            bool settingbuttonbool = CheckCollisionPointRec(cursor, {376, 320, 528, 96});
            bool quitbuttonbool = CheckCollisionPointRec(cursor, {376, 448, 528, 96});

            //playbutton
            if(playbuttonbool){
                DrawTextureEx(playbutton, {0, 0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    screen = 1;
                }
            }
            else{
                DrawTextureEx(playbuttonhover, {0,0}, 0, 8.0f, WHITE);
            }

            //settingbutton
            if(settingbuttonbool){
                DrawTextureEx(settingsbuttonhover, {0,0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                }
            }
            else{
                DrawTextureEx(settingsbutton, {0,0}, 0, 8.0f, WHITE);
            }

            //quitbutton
            if(quitbuttonbool){
                DrawTextureEx(quitbuttonhover, {0,0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    break;
                }
            }
            else{
                DrawTextureEx(quitbutton, {0,0}, 0, 8.0f, WHITE);
            }
        }
        
        //gamemode
        if(screen == 1){
            bool classicmodebool = CheckCollisionPointRec(cursor, {376, 192, 528, 96});

            ClearBackground(WHITE);
            DrawTextureEx(background1, {0,0}, 0, 8.0f, WHITE);

            //classicmode button
            if(classicmodebool){
                DrawTextureEx(classicmodehover, {0,0}, 0, 8.0f, WHITE);
            }
            else{
                DrawTextureEx(classicmode, {0,0}, 0, 8.0f, WHITE);
            }



        }
        //end
        EndDrawing();
    }

    CloseWindow();
    return 0;
}