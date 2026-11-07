/* Candy Slice:
game where you slice candy and try to get the highest score
the catch is if you slice the wrong things... youll be surprised.*/
#include <raylib.h>

int main(){
    InitAudioDevice();
    InitWindow(1280, 720, "Candy Slice");
    SetTargetFPS(60);
    
    //music
    Music thememusic1 = LoadMusicStream("assets/sounds/thememusic1.mp3");
    //sfx
    Sound click = LoadSound("assets/sounds/clicksound.wav");
    Sound back = LoadSound("assets/sounds/back.wav");
    
    //textures
    //main menu
    Texture2D background0 = LoadTexture("assets/textures/mainmenu.png");
    Texture2D playbutton = LoadTexture("assets/textures/playbutton.png");
    Texture2D playbuttonhover = LoadTexture("assets/textures/playbuttonhover.png");
    Texture2D settingsbutton = LoadTexture("assets/textures/settings.png");
    Texture2D settingsbuttonhover = LoadTexture("assets/textures/settingshover.png");
    Texture2D quitbutton = LoadTexture("assets/textures/quitbutton.png");
    Texture2D quitbuttonhover = LoadTexture("assets/textures/quitbuttonhover.png");
    Texture2D settingspage = LoadTexture("assets/textures/settingspage.png");
    Texture2D settingspageback = LoadTexture("assets/textures/settingspageback.png");
    Texture2D settingspagebackhover = LoadTexture("assets/textures/settingspagebackhover.png");
    Texture2D audiosettingon = LoadTexture("assets/textures/audiosettingon.png");
    Texture2D audiosettingoff = LoadTexture("assets/textures/audiosettingoff.png");
    //gamemode screen
    Texture2D background1 = LoadTexture("assets/textures/background1.png");
    Texture2D classicmode = LoadTexture("assets/textures/classicmode.png");
    Texture2D classicmodehover = LoadTexture("assets/textures/classicmodehover.png");
    Texture2D hardmode = LoadTexture("assets/textures/hardmode.png");
    Texture2D hardmodehover = LoadTexture("assets/textures/hardmodehover.png");
    Texture2D backbutton = LoadTexture("assets/textures/back.png");
    Texture2D backbuttonhover = LoadTexture("assets/textures/backhover.png");
    //classic screen
    Texture2D classicbg = LoadTexture("assets/textures/classicbackground.png");
    Texture2D candy1 = LoadTexture("assets/textures/candy1.png");

    //texture filters
    //main menu
    SetTextureFilter(background0, TEXTURE_FILTER_POINT);
    SetTextureFilter(playbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(playbuttonhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(settingsbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(settingsbuttonhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(quitbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(quitbuttonhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(settingspage, TEXTURE_FILTER_POINT);
    SetTextureFilter(settingspageback, TEXTURE_FILTER_POINT);
    SetTextureFilter(settingspagebackhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(audiosettingon, TEXTURE_FILTER_POINT);
    SetTextureFilter(audiosettingoff, TEXTURE_FILTER_POINT);
    //gamemode screen
    SetTextureFilter(background1, TEXTURE_FILTER_POINT);
    SetTextureFilter(classicmode, TEXTURE_FILTER_POINT);
    SetTextureFilter(classicmodehover, TEXTURE_FILTER_POINT);
    SetTextureFilter(hardmode, TEXTURE_FILTER_POINT);
    SetTextureFilter(hardmodehover, TEXTURE_FILTER_POINT);
    SetTextureFilter(backbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(backbuttonhover, TEXTURE_FILTER_POINT);
    //classic screen
    SetTextureFilter(classicbg, TEXTURE_FILTER_POINT);
    SetTextureFilter(candy1, TEXTURE_FILTER_POINT);

    //variables
    int screen = 0;
    // bool
    bool settingpagebool = false;
    bool audio = true;

    //classic mode
    int candyCount = 3;
    Vector2 candyPositions[candyCount] = {
        {300, 650}, {640, 650}, {500, 650} 
    };
    float candyRadius = 30;
    bool candyShown = true;
    float candySpeed[candyCount] = {300, 350, 280};
    int classicscore = 0;


    //sounds
    SetMusicVolume(thememusic1, 0.6f);
    SetSoundVolume(click, 0.6f);
    SetSoundVolume(back, 0.6f);


    PlayMusicStream(thememusic1);
    while(!WindowShouldClose()){
        UpdateMusicStream(thememusic1);
        //mouse position
        Vector2 cursor = GetMousePosition();

        //begin
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextureEx(background0, {0, 0}, 0, 8.0f, WHITE);

        //audiosettings
        if(audio){
            SetMasterVolume(1.0f);
        }
        else if(!audio){
            SetMasterVolume(0.0f);
        }


        //main menu
        if(screen == 0){
            bool playbuttonbool = CheckCollisionPointRec(cursor, {376, 192, 528, 96});
            bool settingbuttonbool = CheckCollisionPointRec(cursor, {376, 320, 528, 96});
            bool quitbuttonbool = CheckCollisionPointRec(cursor, {376, 448, 528, 96});
            bool settingbool = CheckCollisionPointRec(cursor, {912, 160, 80, 72});
            bool audiobool = CheckCollisionPointRec(cursor, {344, 208, 96, 40});

            //playbutton
            if(playbuttonbool && !settingpagebool){
                DrawTextureEx(playbutton, {0, 0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(click);
                    screen = 1;
                }
            }
            else{
                DrawTextureEx(playbuttonhover, {0,0}, 0, 8.0f, WHITE);
            }

            //settingbutton
            if(settingbuttonbool && !settingpagebool){
                DrawTextureEx(settingsbuttonhover, {0,0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(click);
                    settingpagebool = true;
                }
            }
            else{
                DrawTextureEx(settingsbutton, {0,0}, 0, 8.0f, WHITE);
            }

            //quitbutton
            if(quitbuttonbool && !settingpagebool){
                DrawTextureEx(quitbuttonhover, {0,0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(click);
                    break;
                }
            }
            else{
                DrawTextureEx(quitbutton, {0,0}, 0, 8.0f, WHITE);
            }

            //settingspage
            if(settingpagebool){
                DrawTextureEx(settingspage, {0,0}, 0, 8.0f, WHITE);
                if(settingbool){
                    DrawTextureEx(settingspagebackhover, {0, 0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(back);
                        settingpagebool = false;
                    }
                }
                else{
                    DrawTextureEx(settingspageback, {0, 0}, 0, 8.0f, WHITE);
                }
                if(audio){
                    DrawText("Audio", 366, 220, 20, WHITE);
                    DrawTextureEx(audiosettingon, {0, 0}, 0, 8.0f, WHITE);
                    if(audiobool && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(click);
                        audio = false;
                }
                }
                else if(!audio){
                    DrawText("Audio", 366, 220, 20, BLACK);
                    DrawTextureEx(audiosettingoff, {0, 0}, 0, 8.0f, WHITE);
                    if(audiobool && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(click);
                    audio = true;
                    }
                }
            }
        }
        else if(screen == 1){
            bool classicmodebool = CheckCollisionPointRec(cursor, {376, 192, 528, 96});
            bool hardmodebool = CheckCollisionPointRec(cursor, {376, 320, 528, 96});
            bool backbool = CheckCollisionPointRec(cursor, {376, 448, 528, 96});

            ClearBackground(WHITE);
            DrawTextureEx(background1, {0,0}, 0, 8.0f, WHITE);

            //classicmode button
            if(classicmodebool){
                DrawTextureEx(classicmodehover, {0,0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    screen = 2;
                    PlaySound(click);
                    //
                }
            }
            else{
                DrawTextureEx(classicmode, {0,0}, 0, 8.0f, WHITE);
            }

            //hardmode button
            if(hardmodebool){
                DrawTextureEx(hardmodehover, {0, 0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(click);
                    //
                }
            }
            else{
                DrawTextureEx(hardmode, {0, 0}, 0, 8.0f, WHITE);
            }

            //back button
            if(backbool){
                DrawTextureEx(backbuttonhover, {0, 0}, 0, 8.0f , WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(back);
                    screen = 0;
                }
            }
            else{
                DrawTextureEx(backbutton, {0, 0}, 0, 8.0f, WHITE);
            }
        }
        else if(screen == 2){
            ClearBackground(WHITE);
            DrawTextureEx(classicbg, {0,0}, 0, 8.0f, WHITE);
            DrawText(TextFormat("Score: %i", classicscore), 20, 25, 30, WHITE);
            for(int i = 0; i < candyCount; i++){
                // move candy
                candyPositions[i].y -= candySpeed[i] * GetFrameTime();

                //reset candy
                if(candyPositions[i].y < -candyRadius){
                    candyPositions[i].y = 650;
                    candyPositions[i].x = GetRandomValue(50, 1230);
                }

                // mouse detection for candies
                Rectangle candyhitbox = {
                    candyPositions[i].x - (candy1.width * 8.0f) / 2,
                    candyPositions[i].y - (candy1.height * 8.0f) / 2,
                    candy1.width * 8.0f,
                    candy1.height * 8.0f
                };

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    if(CheckCollisionPointRec(cursor, candyhitbox)){
                        classicscore++;

                        candyPositions[i].y = 650;
                        candyPositions[i].x = GetRandomValue(50, 1230);
                    }
                }
                DrawTextureEx(candy1, {candyPositions[i].x - (candy1.width * 8.0f) / 2, candyPositions[i].y - (candy1.height * 8.0f) / 2}, 0, 8.0f, WHITE);

            }

        }
        //end
        EndDrawing();
    }
    UnloadMusicStream(thememusic1);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}