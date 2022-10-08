#include"tab.h"
coordinates Tab(int x,int y,coordinates last_played,Sound m,Sound n,bool& turns,Player1& player_up,Player2& player_down,std :: vector<move>& history){
    int w=-1,u=-1,k,j;
    for(int i=0;i<8;i++){
        if(x>=662+i*75 && x<=662+(i+1)*75){
            u=i;
        }
        if(y<=805-i*75 && y>=805-(i+1)*75){
            w=i;
        }
    }
    if((!turns && player_up.Map[u][w]!=SHADERPOSITION) || (turns && player_down.Map[u][w]!=SHADERPOSITION)){
        ClearS(player_up,player_down);
    }
    if(u!=-1 && w!=-1){
        if(turns==false){
            if(player_up.Map[u][w]==SHADERPOSITION){
                move in;
                turns= true;
                player_up.Map[u][w]=player_up.Map[last_played.x][last_played.y];
                in.killed=player_down.Map[u][w];
                if(player_down.Map[u][w]!=0){
                    player_down.dead[player_down.Map[u][w]-1]++;
                    player_down.Map[u][w]=0;
                    PlaySound(n);
                }
                else{
                    PlaySound(m);
                }
                in.before.x=last_played.x;
                in.before.y=last_played.y;
                in.after.x=u;
                in.after.y=w;
                history.push_back(in);
                player_up.Map[last_played.x][last_played.y]=0;
                ClearS(player_up,player_down);
                return{-1,-1};
            }
            if(player_up.Map[u][w]==PAWNPOSITION && w!=0){
                if(player_up.Map[u][w-1]==0 && player_down.Map[u][w-1]==0){
                    player_up.Map[u][w-1]=SHADERPOSITION;
                    if(w==6 && player_up.Map[u][w-2]==0){
                        player_up.Map[u][w-2]=SHADERPOSITION;
                    }
                }
                if(u!=0 && player_down.Map[u-1][w-1]!=0){
                    player_up.Map[u-1][w-1]=SHADERPOSITION;
                }
                if(u!=7 && player_down.Map[u+1][w-1]!=0){
                    player_up.Map[u+1][w-1]=SHADERPOSITION;
                }
                return{u,w};
            }
            else if(player_up.Map[u][w]==TOWERPOSITION){
                k=u+1;
                while(k<8  && player_up.Map[k][w]==0){
                    player_up.Map[k][w]=SHADERPOSITION;
                    if(player_down.Map[k][w]!=0){
                        break;
                    }
                    k++;
                }
                k=u-1;
                while(k>=0  && player_up.Map[k][w]==0){
                    player_up.Map[k][w]=SHADERPOSITION;
                    if(player_down.Map[k][w]!=0){
                        break;
                    }
                    k--;
                }
                k=w+1;
                while(k<8 && player_up.Map[u][k]==0){
                    player_up.Map[u][k]=SHADERPOSITION;
                    if(player_down.Map[u][k]!=0){
                        break;
                    }
                    k++;
                }
                k=w-1;
                while(k>=0 && player_up.Map[u][k]==0){
                    player_up.Map[u][k]=SHADERPOSITION;
                    if(player_down.Map[u][k]!=0){
                        break;
                    }
                    k--;
                }
                return{u,w};
            }
            else if(player_up.Map[u][w]==HORSEPOSITION){
                if(u<=5){
                    if(w!=7 && player_up.Map[u+2][w+1]==0){
                        player_up.Map[u+2][w+1]=SHADERPOSITION;
                    }
                    if(w!=0 && player_up.Map[u+2][w-1]==0){
                        player_up.Map[u+2][w-1]=SHADERPOSITION;
                    }
                }
                if(u>=2){
                    if(w!=7 && player_up.Map[u-2][w+1]==0){
                        player_up.Map[u-2][w+1]=SHADERPOSITION;
                    }
                    if(w!=0 && player_up.Map[u-2][w-1]==0){
                        player_up.Map[u-2][w-1]=SHADERPOSITION;
                    }
                }
                if(w<=5){
                    if(u!=7 && player_up.Map[u+1][w+2]==0){
                        player_up.Map[u+1][w+2]=SHADERPOSITION;
                    }
                    if(u!=0 && player_up.Map[u-1][w+2]==0){
                        player_up.Map[u-1][w+2]=SHADERPOSITION;
                    }
                }
                if(w>=2){
                    if(u!=7 && player_up.Map[u+1][w-2]==0){
                        player_up.Map[u+1][w-2]=SHADERPOSITION;
                    }
                    if(u!=0 && player_up.Map[u-1][w-2]==0){
                        player_up.Map[u-1][w-2]=SHADERPOSITION;
                    }
                }
                return{u,w};
            }
            else if(player_up.Map[u][w]==BISHOPPOSITION){
                k=u+1;
                j=w+1;
                while(k<8 && j<8 && player_up.Map[k][j]==0){
                    player_up.Map[k][j]=SHADERPOSITION;
                    if(player_down.Map[k][j]!=0){
                        break;
                    }
                    k++;
                    j++;
                }
                k=u+1;
                j=w-1;
                while(k<8 && j>=0 && player_up.Map[k][j]==0){
                    player_up.Map[k][j]=SHADERPOSITION;
                    if(player_down.Map[k][j]!=0){
                        break;
                    }
                    k++;
                    j--;
                }
                k=u-1;
                j=w+1;
                while(k>=0 && j<8 && player_up.Map[k][j]==0){
                    player_up.Map[k][j]=SHADERPOSITION;
                    if(player_down.Map[k][j]!=0){
                        break;
                    }
                    k--;
                    j++;
                }
                k=u-1;
                j=w-1;
                while(k>=0 && j>=0 && player_up.Map[k][j]==0){
                    player_up.Map[k][j]=SHADERPOSITION;
                    if(player_down.Map[k][j]!=0){
                        break;
                    }
                    k--;
                    j--;
                }
                return{u,w};
            }
            else if(player_up.Map[u][w]==QUEENPOSITION){
               k=u+1;
                j=w+1;
                while(k<8 && j<8 && player_up.Map[k][j]==0){
                    player_up.Map[k][j]=SHADERPOSITION;
                    if(player_down.Map[k][j]!=0){
                        break;
                    }
                    k++;
                    j++;
                }
                k=u+1;
                j=w-1;
                while(k<8 && j>=0 && player_up.Map[k][j]==0){
                    player_up.Map[k][j]=SHADERPOSITION;
                    if(player_down.Map[k][j]!=0){
                        break;
                    }
                    k++;
                    j--;
                }
                k=u-1;
                j=w+1;
                while(k>=0 && j<8 && player_up.Map[k][j]==0){
                    player_up.Map[k][j]=SHADERPOSITION;
                    if(player_down.Map[k][j]!=0){
                        break;
                    }
                    k--;
                    j++;
                }
                k=u-1;
                j=w-1;
                while(k>=0 && j>=0 && player_up.Map[k][j]==0){
                    player_up.Map[k][j]=SHADERPOSITION;
                    if(player_down.Map[k][j]!=0){
                        break;
                    }
                    k--;
                    j--;
                }
                k=u+1;
                while(k<8  && player_up.Map[k][w]==0){
                    player_up.Map[k][w]=SHADERPOSITION;
                    if(player_down.Map[k][w]!=0){
                        break;
                    }
                    k++;
                }
                k=u-1;
                while(k>=0  && player_up.Map[k][w]==0){
                    player_up.Map[k][w]=SHADERPOSITION;
                    if(player_down.Map[k][w]!=0){
                        break;
                    }
                    k--;
                }
                k=w+1;
                while(k<8 && player_up.Map[u][k]==0){
                    player_up.Map[u][k]=SHADERPOSITION;
                    if(player_down.Map[u][k]!=0){
                        break;
                    }
                    k++;
                }
                k=w-1;
                while(k>=0 && player_up.Map[u][k]==0){
                    player_up.Map[u][k]=SHADERPOSITION;
                    if(player_down.Map[u][k]!=0){
                        break;
                    }
                    k--;
                }
                return{u,w};
            }
            else if(player_up.Map[u][w]==KINGPOSITION){
                if(u==3 && w==7 && player_up.Map[u+1][w]==0 && player_up.Map[u+2][w]==0 && player_up.Map[u+3][w]==0 && player_up.Map[u+4][w]==TOWERPOSITION ){
                    player_up.Map[u+2][w]=SHADERPOSITION;
                }
                if(u==3 && w==7 && player_up.Map[u-1][w]==0 && player_up.Map[u-2][w]==0 && player_up.Map[u-3][w]==TOWERPOSITION ){
                    player_up.Map[u-2][w]=SHADERPOSITION;
                }
                if(w!=7){
                    if(u!=0 && player_up.Map[u-1][w+1]==0){
                        player_up.Map[u-1][w+1]=SHADERPOSITION;
                    }
                    if(player_up.Map[u][w+1]==0){
                        player_up.Map[u][w+1]=SHADERPOSITION;
                    }
                    if(u!=7 && player_up.Map[u+1][w+1]==0){
                        player_up.Map[u+1][w+1]=SHADERPOSITION;
                    }
                }
                if(u!=0 && player_up.Map[u-1][w]==0){
                    player_up.Map[u-1][w]=SHADERPOSITION;
                }
                if(u!=7 && player_up.Map[u+1][w]==0){
                    player_up.Map[u+1][w]=SHADERPOSITION;
                }
                if(w!=0){
                    if(u!=0 && player_up.Map[u-1][w-1]==0){
                        player_up.Map[u-1][w-1]=SHADERPOSITION;
                    }
                    if(player_up.Map[u][w-1]==0){
                        player_up.Map[u][w-1]=SHADERPOSITION;
                    }
                    if(u!=7 && player_up.Map[u+1][w-1]==0){
                        player_up.Map[u+1][w-1]=SHADERPOSITION;
                    }
                }
            }
            return{u,w};
        }
        //player_down
        else{
            if(player_down.Map[u][w]==SHADERPOSITION){
                turns= false;
                move in;
                player_down.Map[u][w]=player_down.Map[last_played.x][last_played.y];
                in.killed=player_up.Map[u][w];
                if(player_up.Map[u][w]!=0){
                    player_up.dead[player_up.Map[u][w]-1]++;
                    player_up.Map[u][w]=0;
                    PlaySound(n);
                }
                else{
                    PlaySound(m);
                }
                in.before=last_played;
                in.after={u,w};
                history.push_back(in);
                player_down.Map[last_played.x][last_played.y]=0;
                ClearS(player_up,player_down);
                return{-1,-1};
            }
            if(player_down.Map[u][w]==PAWNPOSITION && w!=7){
                if(player_down.Map[u][w+1]==0 && player_up.Map[u][w+1]==0){
                    player_down.Map[u][w+1]=SHADERPOSITION;
                    if(w==1 && player_down.Map[u][w+2]==0){
                        player_down.Map[u][w+2]=SHADERPOSITION;
                    }
                }
                if(u!=0 && player_up.Map[u-1][w+1]!=0){
                    player_down.Map[u-1][w+1]=SHADERPOSITION;
                }
                if(u!=7 && player_up.Map[u+1][w+1]!=0){
                    player_down.Map[u+1][w+1]=SHADERPOSITION;
                }
                return{u,w};
            }
            else if(player_down.Map[u][w]==TOWERPOSITION){
                k=u+1;
                while(k<8  && player_down.Map[k][w]==0){
                    player_down.Map[k][w]=SHADERPOSITION;
                    if(player_up.Map[k][w]!=0){
                        break;
                    }
                    k++;
                }
                k=u-1;
                while(k>=0  && player_down.Map[k][w]==0){
                    player_down.Map[k][w]=SHADERPOSITION;
                    if(player_up.Map[k][w]!=0){
                        break;
                    }
                    k--;
                }
                k=w+1;
                while(k<8 && player_down.Map[u][k]==0){
                    player_down.Map[u][k]=SHADERPOSITION;
                    if(player_up.Map[u][k]!=0){
                        break;
                    }
                    k++;
                }
                k=w-1;
                while(k>=0 && player_down.Map[u][k]==0){
                    player_down.Map[u][k]=SHADERPOSITION;
                    if(player_up.Map[u][k]!=0){
                        break;
                    }
                    k--;
                }
                return{u,w};
            }
            else if(player_down.Map[u][w]==HORSEPOSITION){
                if(u<=5){
                    if(w!=7 && player_down.Map[u+2][w+1]==0){
                        player_down.Map[u+2][w+1]=SHADERPOSITION;
                    }
                    if(w!=0 && player_down.Map[u+2][w-1]==0){
                        player_down.Map[u+2][w-1]=SHADERPOSITION;
                    }
                }
                if(u>=2){
                    if(w!=7 && player_down.Map[u-2][w+1]==0){
                        player_down.Map[u-2][w+1]=SHADERPOSITION;
                    }
                    if(w!=0 && player_down.Map[u-2][w-1]==0){
                        player_down.Map[u-2][w-1]=SHADERPOSITION;
                    }
                }
                if(w<=5){
                    if(u!=7 && player_down.Map[u+1][w+2]==0){
                        player_down.Map[u+1][w+2]=SHADERPOSITION;
                    }
                    if(u!=0 && player_down.Map[u-1][w+2]==0){
                        player_down.Map[u-1][w+2]=SHADERPOSITION;
                    }
                }
                if(w>=2){
                    if(u!=7 && player_down.Map[u+1][w-2]==0){
                        player_down.Map[u+1][w-2]=SHADERPOSITION;
                    }
                    if(u!=0 && player_down.Map[u-1][w-2]==0){
                        player_down.Map[u-1][w-2]=SHADERPOSITION;
                    }
                }
                return{u,w};
            }
            else if(player_down.Map[u][w]==BISHOPPOSITION){
                k=u+1;
                j=w+1;
                while(k<8 && j<8 && player_down.Map[k][j]==0){
                    player_down.Map[k][j]=SHADERPOSITION;
                    if(player_up.Map[k][j]!=0){
                        break;
                    }
                    k++;
                    j++;
                }
                k=u+1;
                j=w-1;
                while(k<8 && j>0 && player_down.Map[k][j]==0){
                    player_down.Map[k][j]=SHADERPOSITION;
                    if(player_up.Map[k][j]!=0){
                        break;
                    }
                    k++;
                    j--;
                }
                k=u-1;
                j=w+1;
                while(k>0 && j<8 && player_down.Map[k][j]==0){
                    player_down.Map[k][j]=SHADERPOSITION;
                    if(player_up.Map[k][j]!=0){
                        break;
                    }
                    k--;
                    j++;
                }
                k=u-1;
                j=w-1;
                while(k>0 && j>0 && player_down.Map[k][j]==0){
                    player_down.Map[k][j]=SHADERPOSITION;
                    if(player_up.Map[k][j]!=0){
                        break;
                    }
                    k--;
                    j--;
                }
                return{u,w};
            }
            else if(player_down.Map[u][w]==QUEENPOSITION){
               k=u+1;
                j=w+1;
                while(k<8 && j<8 && player_down.Map[k][j]==0){
                    player_down.Map[k][j]=SHADERPOSITION;
                    if(player_up.Map[k][j]!=0){
                        break;
                    }
                    k++;
                    j++;
                }
                k=u+1;
                j=w-1;
                while(k<8 && j>0 && player_down.Map[k][j]==0){
                    player_down.Map[k][j]=SHADERPOSITION;
                    if(player_up.Map[k][j]!=0){
                        break;
                    }
                    k++;
                    j--;
                }
                k=u-1;
                j=w+1;
                while(k>0 && j<8 && player_down.Map[k][j]==0){
                    player_down.Map[k][j]=SHADERPOSITION;
                    if(player_up.Map[k][j]!=0){
                        break;
                    }
                    k--;
                    j++;
                }
                k=u-1;
                j=w-1;
                while(k>0 && j>0 && player_down.Map[k][j]==0){
                    player_down.Map[k][j]=SHADERPOSITION;
                    if(player_up.Map[k][j]!=0){
                        break;
                    }
                    k--;
                    j--;
                }
                k=u+1;
                while(k<8  && player_down.Map[k][w]==0){
                    player_down.Map[k][w]=SHADERPOSITION;
                    if(player_up.Map[k][w]!=0){
                        break;
                    }
                    k++;
                }
                k=u-1;
                while(k>=0  && player_down.Map[k][w]==0){
                    player_down.Map[k][w]=SHADERPOSITION;
                    if(player_up.Map[k][w]!=0){
                        break;
                    }
                    k--;
                }
                k=w+1;
                while(k<8 && player_down.Map[u][k]==0){
                    player_down.Map[u][k]=SHADERPOSITION;
                    if(player_up.Map[u][k]!=0){
                        break;
                    }
                    k++;
                }
                k=w-1;
                while(k>=0 && player_down.Map[u][k]==0){
                    player_down.Map[u][k]=SHADERPOSITION;
                    if(player_up.Map[u][k]!=0){
                        break;
                    }
                    k--;
                } 
                return{u,w};
            }
            else if(player_down.Map[u][w]==KINGPOSITION){
                if(u==4 && w==0 && player_down.Map[u+1][w]==0 && player_down.Map[u+2][w]==0 && player_down.Map[u+3][w]==TOWERPOSITION){
                    player_down.Map[u+2][w]=SHADERPOSITION;
                }
                if(u==4 && w==0 && player_down.Map[u-1][w]==0 && player_down.Map[u-2][w]==0 && player_down.Map[u-3][w]==0 && player_down.Map[u-4][w]==TOWERPOSITION){
                    player_down.Map[u-2][w]=SHADERPOSITION;
                }
                if(w!=7){
                    if(u!=0 && player_down.Map[u-1][w+1]==0){
                        player_down.Map[u-1][w+1]=SHADERPOSITION;
                    }
                    if(player_down.Map[u][w+1]==0){
                        player_down.Map[u][w+1]=SHADERPOSITION;
                    }
                    if(u!=7 && player_down.Map[u+1][w+1]==0){
                        player_down.Map[u+1][w+1]=SHADERPOSITION;
                    }
                }
                if(u!=0 && player_down.Map[u-1][w]==0){
                    player_down.Map[u-1][w]=SHADERPOSITION;
                }
                if(u!=7 && player_down.Map[u+1][w]==0){
                    player_down.Map[u+1][w]=SHADERPOSITION;
                }
                if(w!=0){
                    if(u!=0 && player_down.Map[u-1][w-1]==0){
                        player_down.Map[u-1][w-1]=SHADERPOSITION;
                    }
                    if(player_down.Map[u][w-1]==0){
                        player_down.Map[u][w-1]=SHADERPOSITION;
                    }
                    if(u!=7 && player_down.Map[u+1][w-1]==0){
                        player_down.Map[u+1][w-1]=SHADERPOSITION;
                    }
                }
                return{u,w};
            }

        }
    }
    return {-1,-1};
}
