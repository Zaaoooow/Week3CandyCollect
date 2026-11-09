/* Candy Slice:
game where you slice candy and try to get the highest score
the catch is if you slice the wrong things... youll be surprised.*/
#include <raylib.h>
#include <fstream>

void saveStats(int games, int win, int loss, int wrongstat, int correctstat, int missed, int streak, int highstreak, int winrate){
    std::ofstream file("stats.txt");
    file << games << std::endl;
    file << win << std::endl;
    file << loss << std::endl;
    file << wrongstat << std::endl;
    file << correctstat << std::endl;
    file << missed << std::endl;
    file << streak << std::endl;
    file << highstreak << std::endl;
    file << winrate << std::endl;

    file.close();
}
void loadStats(int &games, int &win, int &loss, int &wrongstat, int &correctstat, int &missed, int &streak, int &highstreak, int &winrate){
    std::ifstream file("stats.txt");

    if(file.is_open()){
        file >> games;
        file >> win;
        file >> loss;
        file >> wrongstat;
        file >> correctstat;
        file >> missed;
        file >> streak;
        file >> highstreak;
        file >> winrate;

        file.close();
    }
}
void resetStats(int &games, int &win, int &loss, int &wrongstat, int &correcstat, int &missed, int &streak, int &highstreak, int &winrate){
    games = 0;
    win = 0;
    loss = 0;
    wrongstat = 0;
    correcstat = 0;
    missed = 0;
    streak = 0;
    highstreak = 0;
    winrate = 0;

    saveStats(games, win, loss, wrongstat, correcstat, missed, streak, highstreak, winrate);
}


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
    Texture2D guidebutton = LoadTexture("assets/textures/guide.png");
    Texture2D guidebuttonhover = LoadTexture("assets/textures/guidehover.png");
    Texture2D guidepage = LoadTexture("assets/textures/guidepage.png");
    Texture2D guideexit = LoadTexture("assets/textures/guideexit.png");
    Texture2D guideexithover = LoadTexture("assets/textures/guideexithover.png");
    Texture2D musicon = LoadTexture("assets/textures/musicon.png");
    Texture2D musicoff = LoadTexture("assets/textures/musicoff.png");
    //gamemode screen
    Texture2D background1 = LoadTexture("assets/textures/background1.png");
    Texture2D classicmode = LoadTexture("assets/textures/classicmode.png");
    Texture2D classicmodehover = LoadTexture("assets/textures/classicmodehover.png");
    Texture2D hardmode = LoadTexture("assets/textures/hardmode.png");
    Texture2D hardmodehover = LoadTexture("assets/textures/hardmodehover.png");
    Texture2D backbutton = LoadTexture("assets/textures/back.png");
    Texture2D backbuttonhover = LoadTexture("assets/textures/backhover.png");
    Texture2D statsbutton = LoadTexture("assets/textures/statsbutton.png");
    Texture2D statsbuttonhover = LoadTexture("assets/textures/statsbuttonhover.png");
    Texture2D statspage = LoadTexture("assets/textures/statspage.png");
    Texture2D statsexit = LoadTexture("assets/textures/statsexit.png");
    Texture2D statsexithover = LoadTexture("assets/textures/statsexithover.png");
    Texture2D savestats = LoadTexture("assets/textures/savebutton.png");
    Texture2D savestatshover = LoadTexture("assets/textures/savehover.png");
    Texture2D resetstats = LoadTexture("assets/textures/resetbutton.png");
    Texture2D resetstatshover = LoadTexture("assets/textures/resethover.png");
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
    SetTextureFilter(guidebutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(guideexit, TEXTURE_FILTER_POINT);
    SetTextureFilter(guideexithover, TEXTURE_FILTER_POINT);
    SetTextureFilter(guidebuttonhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(guidepage, TEXTURE_FILTER_POINT);
    SetTextureFilter(musicon, TEXTURE_FILTER_POINT);
    SetTextureFilter(musicoff, TEXTURE_FILTER_POINT);
    //gamemode screen
    SetTextureFilter(background1, TEXTURE_FILTER_POINT);
    SetTextureFilter(classicmode, TEXTURE_FILTER_POINT);
    SetTextureFilter(classicmodehover, TEXTURE_FILTER_POINT);
    SetTextureFilter(hardmode, TEXTURE_FILTER_POINT);
    SetTextureFilter(hardmodehover, TEXTURE_FILTER_POINT);
    SetTextureFilter(backbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(backbuttonhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(statsbutton, TEXTURE_FILTER_POINT);
    SetTextureFilter(statsbuttonhover, TEXTURE_FILTER_POINT);
    SetTextureFilter(statspage, TEXTURE_FILTER_POINT);
    SetTextureFilter(statsexit, TEXTURE_FILTER_POINT);
    SetTextureFilter(statsexithover, TEXTURE_FILTER_POINT);
    SetTextureFilter(savestats, TEXTURE_FILTER_POINT);
    SetTextureFilter(savestatshover, TEXTURE_FILTER_POINT);
    SetTextureFilter(resetstats, TEXTURE_FILTER_POINT);
    SetTextureFilter(resetstatshover, TEXTURE_FILTER_POINT);
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
    bool guidepagebool = false;
    bool statspagebool = false;
    bool music = true;

    //classic mode
    int candyCount = 3;
    Vector2 candyPositions[candyCount] = {
        {300, 650}, {640, 650}, {500, 650} 
    };
    int candytype[candyCount] = {0, 1, 0};
    bool candyShown = true;
    float candySpeed[candyCount] = {-1000, -950, -800};
    float gravity = 900.0f;
    int classicscore = 0;
    int lives = 3;
    bool jumpscareshown = false;
    float scaretime = 0.0f;
    bool losemusicon = false;
    bool winmusicon = false;
    //hard mode
    int hardcandycount = 5;
    Vector2 hardcandypositions[hardcandycount] = {
        {200, 650}, {400, 650}, {600, 650}, {800, 650}, {1000, 650}
    };
    int hardcandytype[hardcandycount] = {0, 1, 2, 3, 0};
    float hardcandyspeed[hardcandycount] = {
        -1000, -950, -900, -850, -800
    };
    int hardscore = 0;
    int hardlives = 1;
    bool hardlosemusicon = false;
    bool hardwinmusicon = false;

    //statistics
    int games = 0;
    int wrongstat = 0; 
    int correctstat = 0;
    int win = 0;
    int loss = 0;
    int streak = 0;
    int highstreak = 0;
    int missed = 0;
    int winrate = 0;

    //load saved stats
    loadStats(games, win, loss, wrongstat, correctstat, missed, streak, highstreak, winrate);


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
        //music settings
        if(music){
            SetMusicVolume(classicmusic, 0.6f);
            SetMusicVolume(losemusic, 0.6f);
            SetMusicVolume(winmusic, 0.6f);
            SetMusicVolume(thememusic1, 0.6f);
        }
        else if(!music){
            SetMusicVolume(classicmusic, 0.0f);
            SetMusicVolume(losemusic, 0.0f);
            SetMusicVolume(winmusic, 0.0f);
            SetMusicVolume(thememusic1, 0.0f);
        }

        //main menu
        if(screen == 0){
            bool playbuttonbool = CheckCollisionPointRec(cursor, {376, 192, 528, 96});
            bool settingbuttonbool = CheckCollisionPointRec(cursor, {376, 320, 528, 96});
            bool quitbuttonbool = CheckCollisionPointRec(cursor, {376, 448, 528, 96});
            bool settingbool = CheckCollisionPointRec(cursor, {912, 160, 80, 72});
            bool audiobool = CheckCollisionPointRec(cursor, {344, 208, 96, 40});
            bool guidebool = CheckCollisionPointRec(cursor, {376, 576, 528, 96});
            bool guideexitbool = CheckCollisionPointRec(cursor, {896, 152, 40, 40});
            bool musicbool = CheckCollisionPointRec(cursor, {480, 208, 96, 40});

            //playbutton
            if(playbuttonbool && !settingpagebool && !guidepagebool){
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
            if(settingbuttonbool && !settingpagebool && !guidepagebool){
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
            if(quitbuttonbool && !settingpagebool && !guidepagebool){
                DrawTextureEx(quitbuttonhover, {0,0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(click);
                    break;
                }
            }
            else{
                DrawTextureEx(quitbutton, {0,0}, 0, 8.0f, WHITE);
            }

            //guidebutton
            if(guidebool && !settingpagebool && !guidepagebool){
                DrawTextureEx(guidebuttonhover, {0,0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(click);
                    guidepagebool = true;
                }
            }
            else{
                DrawTextureEx(guidebutton, {0,0}, 0, 8.0f, WHITE);
            }
            
            //guide page
            if(guidepagebool){
                DrawTextureEx(guidepage, {0,0}, 0, 8.0f, WHITE);
                DrawText("Classic Mode: ", 350, 150, 20, GREEN);
                DrawText("You have to collect as much good candy as possible with 3 lives.", 350, 175, 15, WHITE);
                DrawText("Lighter candies are good, and darker candies are bad..", 350, 190, 15, WHITE);
                DrawText("If you collect the wrong candy, you'll get surprise..", 350, 205, 15, WHITE);
                DrawText("You'll be thrown 3 random candies constantly.", 350, 220, 15, WHITE);
                DrawText("Your goal is to collect 30 good candies!", 350, 235, 15, WHITE);
                DrawText("Hard Mode: ", 350, 265, 20, RED);
                DrawText("You have to collect as much good candy as possible", 350, 290, 15, WHITE);
                DrawText("Lighter candies are good, and darker candies are bad..", 350, 305, 15, WHITE);
                DrawText("You only have 1 life...", 350, 320, 15, WHITE);
                DrawText("You'll be thrown 5 candies constantly.", 350, 335, 15, WHITE);
                DrawText("Your goal is to collect 45 good candies!", 350, 350, 15, WHITE);

                DrawText("pssst--", 350, 380, 20, SKYBLUE);
                DrawText("Wrong candies make you lose 1 life, and 1 point", 350, 405, 15, WHITE);
                DrawText("Letting a good candy fall down makes you lose 1 point", 350, 420, 15, WHITE);



                if(guideexitbool){
                    DrawTextureEx(guideexithover, {0,0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(back);
                        guidepagebool = false;
                    }
                }
                else{
                    DrawTextureEx(guideexit, {0,0}, 0, 8.0f, WHITE);
                }
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
                if(music){
                    DrawText("Music", 500, 220, 20, WHITE);
                    DrawTextureEx(musicon, {0,0}, 0, 8.0f, WHITE);
                    if(musicbool && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(click);
                        music = false;
                    }
                }
                else if(!music){
                    DrawText("Music", 500, 220, 20, BLACK);
                    DrawTextureEx(musicoff, {0,0}, 0, 8.0f, WHITE);
                    if(musicbool && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(click);
                        music = true;
                    }
                }

            }
        }
        else if(screen == 1){
            bool classicmodebool = CheckCollisionPointRec(cursor, {376, 192, 528, 96});
            bool hardmodebool = CheckCollisionPointRec(cursor, {376, 320, 528, 96});
            bool backbool = CheckCollisionPointRec(cursor, {376, 448, 528, 96});
            bool statsbool = CheckCollisionPointRec(cursor, {376, 576, 528, 96});
            bool statsexitbool = CheckCollisionPointRec(cursor, {936, 160, 56, 56});

            ClearBackground(WHITE);
            DrawTextureEx(background1, {0,0}, 0, 8.0f, WHITE);

            //classicmode button
            if(classicmodebool && !statspagebool){
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
            if(hardmodebool && !statspagebool){
                DrawTextureEx(hardmodehover, {0, 0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(click);
                    screen = 3;
                    StopMusicStream(thememusic1);
                    StopMusicStream(losemusic);
                    StopMusicStream(winmusic);
                    PlayMusicStream(classicmusic);
                    

                    //
                }
            }
            else{
                DrawTextureEx(hardmode, {0, 0}, 0, 8.0f, WHITE);
            }

            //back button
            if(backbool && !statspagebool){
                DrawTextureEx(backbuttonhover, {0, 0}, 0, 8.0f , WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(back);
                    screen = 0;
                }
            }
            else{
                DrawTextureEx(backbutton, {0, 0}, 0, 8.0f, WHITE);
            }
            
            //stats button
            if(statsbool && !statspagebool){
                DrawTextureEx(statsbuttonhover, {0,0}, 0, 8.0f, WHITE);
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    PlaySound(click);
                    statspagebool = true;
                }
            }
            else{
                DrawTextureEx(statsbutton, {0,0}, 0, 8.0f, WHITE);
            }
            
            //stats page
            if(statspagebool){
                bool savestatsbool = CheckCollisionPointRec(cursor, {712, 264, 120, 56});
                bool resetstatsbool = CheckCollisionPointRec(cursor, {712, 400, 120, 56});
                DrawTextureEx(statspage, {0,0}, 0, 8.0f, WHITE);
                DrawText(TextFormat("Games: %i", games), 300, 260, 20, WHITE);
                DrawText(TextFormat("Wins: %i", win), 300, 285, 20, WHITE);
                DrawText(TextFormat("Losses: %i", loss), 300, 310, 20, WHITE);
                DrawText(TextFormat("Wrongs: %i", wrongstat), 300, 335, 20, WHITE);
                DrawText(TextFormat("Correct: %i", correctstat), 300, 360, 20, WHITE);
                DrawText(TextFormat("Missed: %i", missed), 300,385, 20, WHITE);
                DrawText(TextFormat("Streak: %i", streak), 300, 410, 20, WHITE);
                DrawText(TextFormat("High Streak: %i", highstreak), 300, 435, 20, WHITE);
                DrawText(TextFormat("Winrate: %i%%", winrate), 300, 460, 20, WHITE);
                if(statsexitbool){
                    DrawTextureEx(statsexithover, {0,0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        statspagebool = false;
                        PlaySound(back);
                    }
                }
                else{
                    DrawTextureEx(statsexit, {0,0}, 0, 8.0f, WHITE);
                }
                if(savestatsbool){
                    DrawText("Save", 730, 275, 35, WHITE);
                    DrawTextureEx(savestatshover, {0,0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(click);
                        saveStats(games, win, loss, wrongstat, correctstat, missed, streak, highstreak, winrate);
                    }
                }
                else{
                    DrawText("Save", 730, 275, 35, RED);
                    DrawTextureEx(savestats, {0,0}, 0, 8.0f, WHITE);
                }
                if(resetstatsbool){
                    DrawText("Reset", 728, 415, 30, WHITE);
                    DrawTextureEx(resetstatshover, {0,0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(click);
                        resetStats(games, win, loss, wrongstat, correctstat, missed, streak, highstreak, winrate);
                    }
                }
                else{
                    DrawText("Reset", 728, 415, 30, RED);
                    DrawTextureEx(resetstats, {0,0}, 0, 8.0f, WHITE);
                }
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
                            missed++;
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
                            correctstat++;
                            PlaySound(correct);
                        }
                        else{
                            lives--;
                            classicscore--;
                            wrongstat++;
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
                    if(classicscore <= 0){
                        classicscore = 0;
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
                        loss++;
                        games++;
                        streak = 0;
                        if(games > 0){
                        winrate = ((float)win / games) * 100;
                        }
                        saveStats(games, win, loss, wrongstat, correctstat, missed, streak, highstreak, winrate);
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
                        win++;
                        games++;
                        streak++;
                        if(streak >= highstreak){
                            highstreak = streak;
                        }
                        if(games > 0){
                        winrate = ((float)win / games) * 100;
                        }
                        saveStats(games, win, loss, wrongstat, correctstat, missed, streak, highstreak, winrate);
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
            bool losep = CheckCollisionPointRec(cursor, {160, 432, 120, 40});
            bool losea = CheckCollisionPointRec(cursor, {192, 480, 168, 72});
            bool winp = CheckCollisionPointRec(cursor, {96, 416, 232, 96});
            bool wina = CheckCollisionPointRec(cursor, {136, 544, 336, 88});

            ClearBackground(WHITE);
            DrawTextureEx(hardmodebg, {0,0}, 0, 8.0f, WHITE);

            DrawText(TextFormat("Lives: %i", hardlives), 595, 20, 30, PURPLE);
            DrawText(TextFormat("Score: %i", hardscore), 20, 20, 30, WHITE);

            if(hardlives > 0 && hardscore < 45){
                for(int i = 0; i < hardcandycount; i++){
                    Texture2D currentcandy;
                    //candy textures
                    if(hardcandytype[i] == 0){
                        currentcandy = candy1;
                    }
                    else if(hardcandytype[i] == 1){
                        currentcandy = candy2;
                    }
                    else if(hardcandytype[i] == 2){
                        currentcandy = badcandy;
                    }
                    else{
                        currentcandy = badcandy2;
                    }
                    //move candy
                    hardcandyspeed[i] += gravity * GetFrameTime();
                    hardcandypositions[i].y += hardcandyspeed[i] * GetFrameTime();

                    //reset candy
                    if(hardcandypositions[i].y > 800){
                        if(hardcandytype[i] == 0 || hardcandytype[i] == 1){
                            hardscore--;
                            missed++;
                        }
                        hardcandypositions[i].y = 720;
                        hardcandypositions[i].x = GetRandomValue(50, 1230);
                        hardcandyspeed[i] = GetRandomValue(-1000, -800);
                        hardcandytype[i] = GetRandomValue(0, 3);
                    }
                    
                    //checkcollision
                    Rectangle candyhitbox = {
                        hardcandypositions[i].x - (currentcandy.width * 8.0f) /2,
                        hardcandypositions[i].y - (currentcandy.height * 8.0f) / 2,
                        currentcandy.width * 8.0f,
                        currentcandy.height * 8.0f
                    };

                    if(CheckCollisionPointRec(cursor, candyhitbox)){
                        if(hardcandytype[i] == 0 || hardcandytype[i] == 1){
                            hardscore++;
                            correctstat++;
                            PlaySound(correct);
                        }
                        else{
                            hardlives--;
                            wrongstat++;
                            PlaySound(wrong);
                            PlaySound(scare);
                            jumpscareshown = true;
                            scaretime = 0.1f;
                        }
                        hardcandypositions[i].y = 720;
                        hardcandypositions[i].x = GetRandomValue(50, 1230);
                        hardcandyspeed[i] = GetRandomValue(-1000, -800);
                        hardcandytype[i] = GetRandomValue(0, 3);

                        continue;
                    }
                    
                    //draw candy
                    DrawTextureEx(currentcandy, {hardcandypositions[i].x - (currentcandy.width * 8.0f) / 2, hardcandypositions[i].y - (currentcandy.height * 8.0f) / 2}, 0, 8.0f, WHITE);
                }
            }
            if(hardlives <= 0){
                hardlives = 0;
                DrawTextureEx(gameloss, {0,0}, 0, 8.0f, WHITE);
                if(!hardlosemusicon){
                    StopMusicStream(classicmusic);
                    PlayMusicStream(losemusic);
                    StopMusicStream(thememusic1);
                    hardlosemusicon = true;
                }
                if(losep || losea){
                    DrawTextureEx(playagainhover, {0,0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(click);
                        StopMusicStream(losemusic);
                        PlayMusicStream(thememusic1);
                        hardscore = 0;
                        hardlives = 1;
                        scaretime = 0.0f;
                        jumpscareshown = false;
                        hardcandypositions[0] = {200, 650};
                        hardcandypositions[1] = {400, 650};
                        hardcandypositions[2] = {600, 650};
                        hardcandypositions[3] = {800, 650};
                        hardcandypositions[4] = {1000, 650};
                        hardcandytype[0] = 0;
                        hardcandytype[1] = 1;
                        hardcandytype[2] = 2;
                        hardcandytype[3] = 3;
                        hardcandytype[4] = 1;
                        hardcandyspeed[0] = -800;
                        hardcandyspeed[1] = -950;
                        hardcandyspeed[2] = -900;
                        hardcandyspeed[3] = -850;
                        hardcandyspeed[4] = -800;
                        screen = 1;
                        hardlosemusicon = false;
                        hardwinmusicon = false;
                        loss++;
                        games++;
                        streak = 0;
                        if(games > 0){
                        winrate = ((float)win / games) * 100;
                        }
                        saveStats(games, win, loss, wrongstat, correctstat, missed, streak, highstreak, winrate);
                    }
                }
                else{
                    DrawTextureEx(playagain, {0,0}, 0, 8.0f, WHITE);
                }
            }
            if(hardscore >= 45){
                hardscore = 45;
                if(!hardwinmusicon){
                    StopMusicStream(classicmusic);
                    PlayMusicStream(winmusic);
                    hardwinmusicon = true;
                }
                DrawTextureEx(gamewin, {0,0}, 0, 8.0f, WHITE);
                if(winp || wina){
                    DrawTextureEx(winpahover, {0,0}, 0, 8.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        PlaySound(click);
                        StopMusicStream(winmusic);
                        PlayMusicStream(thememusic1);
                        hardlosemusicon = false;
                        hardwinmusicon = false;
                        hardlives = 1;
                        hardscore = 0;
                        scaretime = 0.0f;
                        hardcandypositions[0] = {200, 650};
                        hardcandypositions[1] = {400, 650};
                        hardcandypositions[2] = {600, 650};
                        hardcandypositions[3] = {800, 650};
                        hardcandypositions[4] = {1000, 650};
                        hardcandytype[0] = 0;
                        hardcandytype[1] = 1;
                        hardcandytype[2] = 2;
                        hardcandytype[3] = 3;
                        hardcandytype[4] = 1;
                        hardcandyspeed[0] = -800;
                        hardcandyspeed[1] = -950;
                        hardcandyspeed[2] = -900;
                        hardcandyspeed[3] = -850;
                        hardcandyspeed[4] = -800;
                        screen = 1;
                        win++;
                        games++;
                        streak++;
                        if(streak >= highstreak){
                            highstreak = streak;
                        }
                        if(games > 0){
                        winrate = ((float)win / games) * 100;
                        }
                        saveStats(games, win, loss, wrongstat, correctstat, missed, streak, highstreak, winrate);
                    }
                }
                else{
                    DrawTextureEx(winpa, {0,0}, 0, 8.0f, WHITE);
                }

            }
            if(hardscore <= 0){
                hardscore = 0;
            }
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
