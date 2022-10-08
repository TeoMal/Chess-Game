#include"funct.h"
void Player2::Reset(void)
{
    dead[0]=0;
    dead[1]=0;
    dead[2]=0;
    dead[3]=0;
    dead[4]=0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == 1)
            {
                Map[i][j] = PAWNPOSITION;
            }
            else if (j == 0)
            {
                if (i == 0 || i == 7)
                    Map[i][j] = TOWERPOSITION;
                else if (i == 1 || i == 6)
                    Map[i][j] = HORSEPOSITION;
                else if (i == 2 || i == 5)
                    Map[i][j] = BISHOPPOSITION;
                else if (i == 3)
                    Map[i][j] = QUEENPOSITION;
                else
                    Map[i][j] = KINGPOSITION;
            }
            else
            {
                Map[i][j] = 0;
            }
        }
    }
}
void Player1::Reset()
    {
        dead[0]=0;
        dead[1]=0;
        dead[2]=0;
        dead[3]=0;
        dead[4]=0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (j == 6)
                {
                    Map[i][j] = PAWNPOSITION;
                }
                else if (j == 7)
                {
                    if (i == 0 || i == 7)
                        Map[i][j] = TOWERPOSITION;
                    else if (i == 1 || i == 6)
                        Map[i][j] = HORSEPOSITION;
                    else if (i == 2 || i == 5)
                        Map[i][j] = BISHOPPOSITION;
                    else if (i == 4)
                        Map[i][j] = QUEENPOSITION;
                    else
                        Map[i][j] = KINGPOSITION;
                }
                else
                {
                    Map[i][j] = 0;
                }
            }
        }
    }
void Player2::Color(Texture2D P,Texture2D H,Texture2D T,Texture2D B,Texture2D Q,Texture2D K){
    Pawn=P;
    Horse=H;
    Tower=T;
    Bishop=B;
    Queen=Q;
    King=K;
    Reset();
}
void Player1::Color(Texture2D P,Texture2D H,Texture2D T,Texture2D B,Texture2D Q,Texture2D K){
    Pawn=P;
    Horse=H;
    Tower=T;
    Bishop=B;
    Queen=Q;
    King=K;
    Reset();
}
void DrawPieces(Image shadow, Player1 player_up, Player2 player_down)
{
    Texture2D Shadt=LoadTextureFromImage(shadow);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            //Player down
            if (player_down.Map[i][j] == PAWNPOSITION)
            {
                DrawTexture(player_down.Pawn, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_down.Map[i][j] == TOWERPOSITION)
            {
                DrawTexture(player_down.Tower, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_down.Map[i][j] == BISHOPPOSITION)
            {
                DrawTexture(player_down.Bishop, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_down.Map[i][j] == HORSEPOSITION)
            {
                DrawTexture(player_down.Horse, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_down.Map[i][j] == QUEENPOSITION)
            {
                DrawTexture(player_down.Queen, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_down.Map[i][j] == KINGPOSITION)
            {
                DrawTexture(player_down.King, 665 + i * 75, 735 - j * 75, WHITE);
            }

            // Player up
            if (player_up.Map[i][j] == PAWNPOSITION)
            {
                DrawTexture(player_up.Pawn, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_up.Map[i][j] == TOWERPOSITION)
            {
                DrawTexture(player_up.Tower, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_up.Map[i][j] == BISHOPPOSITION)
            {
                DrawTexture(player_up.Bishop, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_up.Map[i][j] == HORSEPOSITION)
            {
                DrawTexture(player_up.Horse, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_up.Map[i][j] == QUEENPOSITION)
            {
                DrawTexture(player_up.Queen, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_up.Map[i][j] == KINGPOSITION)
            {
                DrawTexture(player_up.King, 665 + i * 75, 735 - j * 75, WHITE);
            }
            else if (player_up.Map[i][j] == SHADERPOSITION)
            {
                DrawTexture(Shadt, 20+665 + i * 75, 15+735 - j * 75, WHITE);
            }
            if (player_down.Map[i][j] == SHADERPOSITION)
            {
                DrawTexture(Shadt, 20+665 + i * 75, 15+735 - j * 75, WHITE);
            }
        }
    }
}
//Clears Funcion Clears all shadows in the board
void ClearS(Player1& player_up, Player2& player_down)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (player_up.Map[i][j] == SHADERPOSITION)
            {
                player_up.Map[i][j] = 0;
            }
            if (player_down.Map[i][j] == SHADERPOSITION)
            {
                player_down.Map[i][j] = 0;
            }
        }
    }
}
//Function to check whether either king is dead or in case a bug has occured and both kings are dead
int CheckWin(Player1 player_up, Player2 player_down)
{
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (player_up.Map[i][j] == KINGPOSITION)
            {
                flag1 = true;
            }
            if (player_down.Map[i][j] == KINGPOSITION)
            {
                flag2 = true;
            }
        }
    }
    if (flag2 && flag1)
    {
        return 0;
    }
    else if (flag2 && !flag1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
    return 0;
}
