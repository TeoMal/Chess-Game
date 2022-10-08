typedef struct{
    int x;
    int y;
}coordinates;
typedef struct{
    coordinates before;
    coordinates after;
    int killed;
}move;
#include"raylib.h"
#include<vector>
#define SHADERPOSITION -1
#define PAWNPOSITION 1
#define TOWERPOSITION 2
#define HORSEPOSITION 3
#define BISHOPPOSITION 4
#define QUEENPOSITION 5
#define KINGPOSITION 6
class Player2{
    public:
    Texture2D Pawn, Horse, Bishop, Tower, Queen, King;
    int Map[8][8];
    int dead[5];
    void Color(Texture2D P,Texture2D H,Texture2D T,Texture2D B,Texture2D Q,Texture2D K);
    void Reset(void);
};
class Player1
{
public:
    Texture2D Pawn, Horse, Bishop, Tower, Queen, King;
    int Map[8][8];
    int dead[5];
    void Color(Texture2D P,Texture2D H,Texture2D T,Texture2D B,Texture2D Q,Texture2D K);
    void Reset(void);
};
coordinates Tab(int,int,coordinates,Sound,Sound,bool&,Player1&,Player2&,std :: vector<move>&);
void ClearS(Player1&,Player2&);