#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
#include "../styles/cyber/cyber.h"
#include "funct.h"
int main(void)
{
    Player2 pl2;
    Player1 pl1;
    move play;
    std ::vector<move> history;
    bool turns;
    pl2.Reset();
    pl1.Reset();
    turns = false;
    bool end = false;
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Teo Mal Chess Game");
    InitAudioDevice();
    ToggleFullscreen();
    Sound moving = LoadSound("resources/moving.mp3"), capturing = LoadSound("resources/capturing.mp3");
    SetSoundVolume(moving, 0.5f);
    SetSoundVolume(capturing, 0.5f);
    Texture2D Board = LoadTexture("resources/board.png");
    Texture2D Background = LoadTexture("resources/space2.png");
    Image Shad = LoadImage("resources/try3.png");
    Texture2D bub = LoadTexture("resources/bubble.png");
    ImageColorReplace(&Shad, {1, 0, 2, 255}, {4, 217, 255, 130});
    Vector2 Click;
    SetTargetFPS(60);
    int corx, cory, wincon, State = 1;
    coordinates to_be_moved = {-1, -1};
    GuiLoadStyleCyber();
    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
    Music backsound = LoadMusicStream("resources/Starwars.mp3");
    Texture2D icon = LoadTexture("resources/icon.png");
    Texture2D mutedicon = LoadTexture("resources/mutedicon.png");
    Texture2D symbol1 = LoadTexture("resources/symbolw.png");
    Texture2D symbol2 = LoadTexture("resources/symbolb.png");
    Texture2D xbutton = LoadTexture("resources/xbutton.png");
    Texture2D WPawn = LoadTexture("resources/whitepawn.png");
    Texture2D WHorse = LoadTexture("resources/whitehorse.png");
    Texture2D WBishop = LoadTexture("resources/whitebishop.png");
    Texture2D WTower = LoadTexture("resources/whitetower.png");
    Texture2D WQueen = LoadTexture("resources/whitequeen.png");
    Texture2D WKing = LoadTexture("resources/whiteking.png");
    Texture2D BPawn = LoadTexture("resources/blackpawn.png");
    Texture2D BHorse = LoadTexture("resources/blackhorse.png");
    Texture2D BBishop = LoadTexture("resources/blackbishop.png");
    Texture2D BTower = LoadTexture("resources/blacktower.png");
    Texture2D BQueen = LoadTexture("resources/blackqueen.png");
    Texture2D BKing = LoadTexture("resources/blackking.png");
    float audio_bar = 0.5f;
    float sound_fx_bar = 0.5f;
    bool sound_on = true;
    Texture2D temp;
    SetMusicVolume(backsound, audio_bar);
    PlayMusicStream(backsound);
    Font tttf = LoadFontEx("resources/Prototype.ttf", 100, 0, 250);
    while (!WindowShouldClose())
    {
        if (sound_on == true)
        {
            UpdateMusicStream(backsound);
        }

        // Update
        //----------------------------------------------------------------------------------
        corx = 0;
        cory = 0;
        Click = {0, 0};
        Click = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(Click, {1820, 50, 50, 50}))
        {
            if (sound_on)
            {
                PauseMusicStream(backsound);
            }
            else
            {
                ResumeMusicStream(backsound);
            }
            sound_on = !sound_on;
        }
        if (State == 2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !end)
        {
            corx = (int)Click.x;
            cory = (int)Click.y;
            to_be_moved = Tab(corx, cory, to_be_moved, moving, capturing, turns, pl1, pl2, history);
        }
        // Draw
        BeginDrawing();

        ClearBackground({255, 255, 255, 255});
        DrawTexture(Background, 0, 0, WHITE);
        if (sound_on == true)
        {
            DrawTexture(icon, 1820, 50, WHITE);
        }
        else
        {
            DrawTexture(mutedicon, 1820, 50, WHITE);
        }
        //
        if (State == 2)
        {
            if (sound_on == true)
            {
                UpdateMusicStream(backsound);
            }
            DrawTexture(Board, screenWidth / 2 - Board.width / 2, screenHeight / 2 - Board.height / 2 - 40, BLACK);
            DrawPieces(Shad, pl1, pl2);
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                }
            }
            GuiSetStyle(DEFAULT, TEXT_SIZE, 80);
            if (sound_on == true)
            {
                UpdateMusicStream(backsound);
            }
            DrawTextPro(tttf, "GRAVEYARD", {1400, 200}, {0, 0}, 0, 80, 0, BLUE);
            DrawTexture(pl2.Pawn, 1400, 300, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl2.dead[PAWNPOSITION - 1]), {1460, 322}, {0, 0}, 0, 50, 1, BLACK);
            ;
            DrawTexture(pl2.Bishop, 1400, 375, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl2.dead[BISHOPPOSITION - 1]), {1460, 397}, {0, 0}, 0, 50, 1, BLACK);
            DrawTexture(pl2.Tower, 1400, 450, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl2.dead[TOWERPOSITION - 1]), {1460, 477}, {0, 0}, 0, 50, 1, BLACK);
            DrawTexture(pl2.Horse, 1400, 525, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl2.dead[HORSEPOSITION - 1]), {1460, 547}, {0, 0}, 0, 50, 1, BLACK);
            DrawTexture(pl2.Queen, 1400, 600, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl2.dead[QUEENPOSITION - 1]), {1460, 622}, {0, 0}, 0, 50, 1, BLACK);

            // pl1
            DrawTexture(pl1.Pawn, 1600, 300, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl1.dead[PAWNPOSITION - 1]), {1660, 322}, {0, 0}, 0, 50, 1, WHITE);
            DrawTexture(pl1.Bishop, 1600, 375, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl1.dead[BISHOPPOSITION - 1]), {1660, 397}, {0, 0}, 0, 50, 1, WHITE);
            DrawTexture(pl1.Tower, 1600, 450, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl1.dead[TOWERPOSITION - 1]), {1660, 477}, {0, 0}, 0, 50, 1, WHITE);
            DrawTexture(pl1.Horse, 1600, 525, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl1.dead[HORSEPOSITION - 1]), {1660, 547}, {0, 0}, 0, 50, 1, WHITE);
            DrawTexture(pl1.Queen, 1600, 600, WHITE);
            DrawTextPro(tttf, TextFormat(": %i", pl1.dead[QUEENPOSITION - 1]), {1660, 622}, {0, 0}, 0, 50, 1, WHITE);
            GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
            if (GuiButton({1700, 980, 90, 60}, "Menu"))
            {
                State = 1;
                while (!history.empty())
                {
                    history.pop_back();
                }
                GuiEnable();
                continue;
            }
            if (GuiButton({1700, 880, 90, 60}, "Undo"))
            {
                if (history.size() != 0)
                {
                    play = history[history.size() - 1];
                    history.pop_back();
                    if (!turns)
                    {
                        pl2.Map[play.before.x][play.before.y] = pl2.Map[play.after.x][play.after.y];
                        pl2.Map[play.after.x][play.after.y] = 0;
                        pl1.Map[play.after.x][play.after.y] = play.killed;
                        if (play.killed != 0)
                        {
                            pl1.dead[play.killed - 1]--;
                        }
                    }
                    else
                    {
                        pl1.Map[play.before.x][play.before.y] = pl1.Map[play.after.x][play.after.y];
                        pl1.Map[play.after.x][play.after.y] = 0;
                        pl2.Map[play.after.x][play.after.y] = play.killed;
                        if (play.killed != 0)
                        {
                            pl2.dead[play.killed - 1]--;
                        }
                    }
                    turns = !turns;
                }
            }
            if (!end)
            {
                wincon = CheckWin(pl1, pl2);
                if (wincon == 1)
                {
                    // pl2wins
                    end = true;
                }
                else if (wincon == 2)
                {
                    // pl1wins
                    end = true;
                }
            }
            else if (wincon == 1)
            {

                if (GuiButton({835, 490, 250, 100}, "Player1 Wins,Retry!"))
                {
                    end = false;
                    pl1.Reset();
                    pl2.Reset();
                }
            }
            else
            {
                if (GuiButton({835, 490, 250, 100}, "Player2 Wins,Retry!"))
                {
                    end = false;
                    pl1.Reset();
                    pl2.Reset();
                }
            }
        }
        else if (State == 1 || State == 5)
        {
            // MENU
            GuiSetStyle(DEFAULT, TEXT_SIZE, 100);
            DrawTextPro(tttf, "MENU", {857, 100}, {0, 0}, 0, 100, 0, BLUE);
            GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
            if (GuiButton({890, 300, 140, 120}, "PLAY"))
            {
                GuiDisable();
                State = 5;
            }
            else if (GuiButton({890, 480, 140, 120}, "OPTIONS"))
            {
                State = 3;
            }
            else if (GuiButton({890, 660, 140, 120}, "RULES"))
            {
                State = 4;
            }
            if (State == 5)
            {
                DrawTexture(bub, 745, 350, WHITE);
                DrawRectangleRounded({813, 500, 100, 100}, 0.3, 0, RED);
                DrawRectangleRounded({1008, 500, 100, 100}, 0.3, 0, RED);
                DrawTexture(symbol1, 810, 500, WHITE);
                DrawTexture(symbol2, 1010, 500, WHITE);
                DrawTextPro(tttf, "WHITE", {818, 450}, {0, 0}, 0, 40, 0, RED);
                DrawTextPro(tttf, "BLACK", {1018, 450}, {0, 0}, 0, 40, 0, RED);
                DrawTextPro(tttf, "Choose Side:", {840, 400}, {0, 0}, 0, 50, 0, RED);
                DrawTexture(xbutton, 1125, 365, RED);
                if (CheckCollisionPointRec(Click, {813, 500, 100, 100}))
                {
                    DrawRectangleRounded({813, 500, 100, 100}, 0.3, 0, GREEN);
                    DrawTexture(symbol1, 810, 500, WHITE);
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        GuiEnable();
                        pl2.Color(WPawn, WHorse, WTower, WBishop, WQueen, WKing);
                        pl1.Color(BPawn, BHorse, BTower, BBishop, BQueen, BKing);
                        turns = true;
                        State = 2;
                    }
                }
                if (CheckCollisionPointRec(Click, {1008, 500, 100, 100}))
                {
                    DrawRectangleRounded({1008, 500, 100, 100}, 0.3, 0, GREEN);
                    DrawTexture(symbol2, 1010, 500, WHITE);
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        GuiEnable();
                        pl1.Color(WPawn, WHorse, WTower, WBishop, WQueen, WKing);
                        pl2.Color(BPawn, BHorse, BTower, BBishop, BQueen, BKing);
                        turns = false;
                        State = 2;
                    }
                }
                if (CheckCollisionPointRec(Click, {1125, 365, 30, 30}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    GuiEnable();
                    State = 1;
                }
            }
        }
        else if (State == 3)
        {
            // Options
            GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
            if (GuiButton({1700, 980, 90, 60}, "Menu"))
            {
                State = 1;
                GuiEnable();
                continue;
            }
            if (CheckCollisionPointRec(Click, {890, 400, 240, 50}) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                if (!IsSoundPlaying(moving))
                {
                    PlaySound(moving);
                }
                // PlaySound(capturing);
            }
            GuiSetStyle(DEFAULT, TEXT_SIZE, 100);
            DrawTextPro(tttf, "OPTIONS", {850, 100}, {0, 0}, 0, 100, 0, BLUE);
            GuiSetStyle(DEFAULT, TEXT_SIZE, 40);
            SetMusicVolume(backsound, audio_bar = GuiSliderBar((Rectangle){890, 300, 240, 50}, "Music Volume", NULL, audio_bar, 0, 1));
            SetSoundVolume(moving, sound_fx_bar = GuiSliderBar((Rectangle){890, 400, 240, 50}, "SoundFx VOlume", NULL, sound_fx_bar, 0, 1));
            SetSoundVolume(capturing, sound_fx_bar);
        }
        else if (State == 4)
        {
            if (GuiButton({1700, 980, 90, 60}, "Menu"))
            {
                State = 1;
                GuiEnable();
                continue;
            }
            GuiSetStyle(DEFAULT, TEXT_SIZE, 100);
            DrawTextPro(tttf, "RULES", {850, 100}, {0, 0}, 0, 100, 0, BLUE);
            DrawTextPro(tttf, "This has been made by Teo Mal.\nUnfortunately he was too bored to\nmake a Check Mate checker, so\nyou will have to kill the king\nyourself.", {720, 300}, {0, 0}, 0, 50, 0, BLACK);
            GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
