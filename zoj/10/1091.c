#include <stdio.h>
int tx,ty;
int movefrom(int x,int y,int move)
{
    if(x==tx&&y==ty) return 1;
    else if(move==0) return 0;
    else{
        if(x>1){
            if(y>2&&movefrom(x-1,y-2,move-1)) return 1;
            if(y<7&&movefrom(x-1,y+2,move-1)) return 1;
            if(x>2){
                if(y>1&&movefrom(x-2,y-1,move-1)) return 1;
                if(y<8&&movefrom(x-2,y+1,move-1)) return 1;
            }
        }
        if(x<8){
            if(y>2&&movefrom(x+1,y-2,move-1)) return 1;
            if(y<7&&movefrom(x+1,y+2,move-1)) return 1;
            if(x<7){
                if(y>1&&movefrom(x+2,y-1,move-1)) return 1;
                if(y<8&&movefrom(x+2,y+1,move-1)) return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int fx,fy,move;
    char f[4],t[4];

    while(scanf("%s %s",f,t)!=EOF){
        move=0;
        fx=f[0]-'a'+1;
        fy=f[1]-'0';
        tx=t[0]-'a'+1;
        ty=t[1]-'0';
        while(!movefrom(fx,fy,move)) move++;
        printf("To get from %s to %s takes %d knight moves.\n",f,t,move);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2515563 2007-07-12 00:16:40 Accepted 1091 C 00:00.03 388K ¤ï¤¿¤· */

// 2012-09-07 02:55:51 | Accepted | 1091 | C | 10 | 160 | watashi | Source
