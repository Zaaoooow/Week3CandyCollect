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
    Music classicmusic = LoadMusicStream("assets/sounds/classicmusic.mp3");
    Music winmusic = LoadMusicStream("assets/sounds/winmusic.mp3");
    Music losemusic = LoadMusicStream("assets/sounds/losemusic.mp3");
    //sfx
    Sound click = LoadSound("assets/sounds/clicksound.wav");
    Sound back = LoadSound("assets/sounds/back.wav");
    Sound correct = LoadSound("assets/sounds/correctcandy.mp3");
    Sound wrong = LoadSound("assets/sounds/wrongcandy.mp3");
    Sound scare = LoadSound("assets/sounds/jumpscares.mp3");
    
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
    Texture2D candy2 = LoadTexture("assets/textures/candy2.png");
    Texture2D badcandy = LoadTexture("assets/textures/badcandy.png");
    Texture2D badcandy2 = LoadTexture("assets/textures/badcandy2.png");
    Texture2D jumpscare = LoadTexture("assets/textures/jumpscare.png");
    Texture2D gameloss = LoadTexture("assets/textures/gameloss.png");
    Texture2D playagain = LoadTexture("assets/textures/playagain.png");
    Texture2D playagainhover = LoadTexture("assets/textures/playagainhover.png");
    Texture2D gamewin = LoadTexture("assets/textures/gamewin.png");
    Texture2D winpa = LoadTexture("assets/textures/winplayagain.png");
    Texture2D winpahover = LoadTexture("assets/textures/winplayagainhover.png");
    //hardmode screen
    Texture2D hardmodebg = LoadTexture("assets/textures/hardbackground.png");

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
    SetTextureFilter(candy2, TEXTURE_FILTER_POINT);
    SetTextureFilter(badcandy, TEXTURE_FILTER_POINT);
    SetTextureFilter(badcandy2, TEXTURE_FILTER_POINT);
    SetTextureFilter(jumpscare, TEXTURE_FILTER_POINT);
    SetTextureFilter(gameloss, TEXTURE_FILTER_POINT);
    SetTextureFilter(playagain, TEXTURE_FILTER_POINT);
    SetTextureFilter(playagainhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(gamewin, TEXTURE_FILTER_POINT);
    SetTextureFilter(winpa, TEXTURE_FILTER_POINT);
    SetTextureFilter(winpahover, TEXTURE_FILTER_POINT);
    //hardmode screen
    SetTextureFilter(hardmodebg, TEXTURE_FILTER_POINT);

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
    int candytype[candyCount] = {0, 1, 0};
    float candyRadius = 30;
    bool candyShown = true;
    float candySpeed[candyCount] = {-1000, -950, -800};
    float gravity = 900.0f;
    int classicscore = 0;
    int lives = 3;
    bool jumpscareshown = false;
    float scaretime = 0.0f;
    bool losemusicon = false;
    bool winmusicon = false;


    //sounds
    SetMusicVolume(thememusic1, 0.6f);
    SetSoundVolume(click, 0.6f);
    SetSoundVolume(back, 0.6f);
    SetSoundVolume(scare, 1.2f);
    SetMusicVolume(classicmusic, 0.6f);
    SetMusicVolume(losemusic, 0.6f);
    SetMusicVolume(winmusic, 0.6f);

    //slice
    Vector2 previouscursor = GetMousePosition();

    PlayMusicStream(thememusic1);
    while(!WindowShouldClose()){
        HideCursor();
        UpdateMusicStream(losemusic);
        UpdateMusicStream(winmusic);
        UpdateMusicStream(thememusic1);
        UpdateMusicStream(classicmusic);
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
                    StopMusicStream(thememusic1);
                    PlayMusicStream(classicmusic);
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
                    screen = 3;
                    StopMusicStream(thememusic1);

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
            bool playbool = CheckCollisionPointRec(cursor, {160, 432, 120, 40});
            bool againbool = CheckCollisionPointRec(cursor, {192, 480, 168, 72});
            bool winp = CheckCollisionPointRec(cursor, {96, 416, 232, 96});
            bool wina = CheckCollisionPointRec(cursor, {136, 544, 336, 88});
            ClearBackground(WHITE);
            DrawTextureEx(classicbg, {0,0}, 0, 8.0f, WHITE);
            DrawText(TextFormat("Lives: %i", lives), 595, 20, 30, RED);
            DrawText(TextFormat("Score: %i", classicscore), 20, 20, 30, WHITE);

            if(lives > 0 && classicscore < 30){
                for(int i = 0; i < candyCount; i++){
                    Texture2D currentcandy;
                    if(candytype[i] == 0){
                        currentcandy = candy1;
                    }
                    else if(candytype[i] == 1){
                        currentcandy = candy2;
                    }
                    else if(candytype[i] == 2){
                        currentcandy = badcandy;
                    }
                    else{
                        currentcandy = badcandy2;
                    }
                    // move candy
                    candySpeed[i] += gravity * GetFrameTime();
                    candyPositions[i].y += candySpeed[i] * GetFrameTime();

                    //reset candy
                    if(candyPositions[i].y > 800){
                        if(candytype[i] == 0 || candytype[i] == 1){
                            PlaySound(wrong);
                            classicscore--;
                        }
                        candyPositions[i].y = 720;
                        candyPositions[i].x = GetRandomValue(50, 1230);
                        candySpeed[i] = GetRandomValue(-1000, -800);
                        candytype[i] = GetRandomValue(0, 3);
                    }

                    // mouse detection for candies
                    Rectangle candyhitbox = {
                        candyPositions[i].x - (currentcandy.width * 8.0f) / 2,
                        candyPositions[i].y - (currentcandy.height * 8.0f) / 2,
                        currentcandy.width * 8.0f,
                        currentcandy.height * 8.0f
                    };

                    if(CheckCollisionPointRec(cursor, candyhitbox)){
                        if(candytype[i] == 0 || candytype[i] == 1){
                            classicscore++;
                            PlaySound(correct);
                        }
                        else{
                            lives--;
                            classicscore--;
                            PlaySound(wrong);
                            jumpscareshown = true;
                            scaretime = 0.1f;
                            PlaySound(scare);

                        }

                        candyPositions[i].y = 720;
                        candyPositions[i].x = GetRandomValue(50, 1230);
                        candySpeed[i] = GetRandomValue(-1000, -800);
                        candytype[i] = GetRandomValue(0, 3);
                    }
                    DrawTextureEx(currentcandy, {candyPositions[i].x - (currentcandy.width * 8.0f) / 2, candyPositions[i].y - (currentcandy.height * 8.0f) / 2}, 0, 8.0f, WHITE);

                    if(lives <= 0){
                        lives = 0;
                    }
                    if(classicscore >= 30){
                        classicscore = 30;
                    }
                }
            }

            if(lives == 0){
                if(!losemusicon){
                    StopMusicStream(classicmusic);
                    PlayMusicStream(losemusic);
                    losemusicon = true;
                }
                DrawTextureEx(gameloss, {0,0}, 0, 8.0f, WHITE);
                if(playbool || againbool){
                    DrawTextureEx(playagainhover, {0,0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        StopMusicStream(losemusic);
                        PlayMusicStream(thememusic1);
                        losemusicon = false;
                        winmusicon = false;
                        classicscore = 0;
                        lives = 3;
                        candyPositions[0] = {300, 650};
                        candyPositions[1] = {640, 650};
                        candyPositions[2] = {500, 650};
                        candytype[0] = 0;
                        candytype[1] = 1;
                        candytype[2] = 2;
                        candySpeed[0] = -1000;
                        candySpeed[1] = -950;
                        candySpeed[2] = -800;
                        jumpscareshown = false;
                        scaretime = 0.0f;
                        PlaySound(click);
                        screen = 1;
                    }
                }
                else{
                    DrawTextureEx(playagain, {0,0}, 0, 8.0f, WHITE);
                }
                
            }
            if(classicscore == 30){
                if(!winmusicon){
                    StopMusicStream(classicmusic);
                    PlayMusicStream(winmusic);
                    winmusicon = true;
                }
                DrawTextureEx(gamewin, {0,0}, 0, 8.0f, WHITE);
                if(winp || wina){
                    DrawTextureEx(winpahover, {0,0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        StopMusicStream(winmusic);
                        PlayMusicStream(thememusic1);
                        losemusicon = false;
                        winmusicon = false;
                        classicscore = 0;
                        lives = 3;
                        candyPositions[0] = {300, 650};
                        candyPositions[1] = {640, 650};
                        candyPositions[2] = {500, 650};
                        candytype[0] = 0;
                        candytype[1] = 1;
                        candytype[2] = 2;
                        candySpeed[0] = -1000;
                        candySpeed[1] = -950;
                        candySpeed[2] = -800;
                        jumpscareshown = false;
                        scaretime = 0.0f;
                        PlaySound(click);
                        screen = 1;
                    }
                }
                else{
                    DrawTextureEx(winpa, {0,0}, 0, 8.0f, WHITE);
                }
            }

            if(jumpscareshown && lives > 0){
                DrawTextureEx(jumpscare, {0,0}, 0, 8.0f, WHITE);
                scaretime -= GetFrameTime();

                if(scaretime <= 0){
                    jumpscareshown = false;
                }
            }

        }
        else if(screen == 3){
            ClearBackground(WHITE);
            DrawTextureEx(hardmodebg, {0,0}, 0, 8.0f, WHITE);
        }
        DrawCircleV(cursor, 3.0f, WHITE);
        DrawLineEx(previouscursor, cursor, 3.0f, WHITE);
        previouscursor = cursor;
        //end
        EndDrawing();
    }
    UnloadMusicStream(thememusic1);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}