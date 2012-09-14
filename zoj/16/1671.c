#include <stdio.h>
#include <string.h>
#define INF 1024
typedef struct{
    int x,y,hp;
}status;
int map[8][8];
char mark[8][8][6];
int dist,m,n,tail;
status q[320];
void mark_1(int i,int j,int k)
{
    while(mark[i][j][k]=1,k--);
}
int doit2(int x,int y,int hp)
{
    switch(map[x][y]){
    case 2:break;
    case 3:return 1;
    case 1:
        if(!mark[x][y][hp]){
            mark_1(x,y,hp);
            q[tail].x=x;q[tail].y=y;q[tail].hp=hp;tail++;
        }
        break;
    case 4:
        if(!mark[x][y][5]){
            mark_1(x,y,5);
            q[tail].x=x;q[tail].y=y;q[tail].hp=5;tail++;
        }
    }
    return 0;
}
int doit(int it)
{
    int x=q[it].x,y=q[it].y,hp=q[it].hp;

    if(hp==0) return 0;
    else hp--;
    if(x&&map[x-1][y]){
        if(doit2(x-1,y,hp)) return 1;
    }
    if(x<n-1&&map[x+1][y]){
        if(doit2(x+1,y,hp)) return 1;
    }
    if(y&&map[x][y-1]){
        if(doit2(x,y-1,hp)) return 1;
    }
    if(y<m-1&&map[x][y+1]){
        if(doit2(x,y+1,hp)) return 1;
    }
    return 0;
}
int main()
{
    int i,j,k;

    while(scanf("%d%d",&m,&n),m||n){
        memset(mark,0,sizeof(mark));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==2){mark_1(i,j,5);q[0].x=i;q[0].y=j;q[0].hp=5;}
            }
        dist=0;
        tail=1;
        i=0;
        while(i<tail){
            dist++;
            j=tail;
            for(;i<j;i++)
                if(doit(i)) break;
            if(i<j) break;
        }
        if(i<tail) printf("%d\n",dist);
        else printf("-1\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2614948 2007-09-19 21:03:26 Accepted 1671 C 00:00.00 388K わたし */


/*
Rank Submit time Run time Run memory Language User
1 2005-11-24 18:58:46 00:00.00 384K C++ ant
2 2007-04-17 16:55:07 00:00.00 384K C johnson
3 2005-11-25 10:14:12 00:00.00 388K C++ 我是谁
4 2005-12-07 17:08:37 00:00.00 388K C Dai MIKURUBE
5 2006-03-07 13:10:38 00:00.00 388K C++ rob
6 2006-03-11 20:37:33 00:00.00 388K C++ 枫之羽@HDU
7 2007-04-17 16:54:57 00:00.00 388K C 321313
8 2007-09-19 21:03:26 00:00.00 388K C わたし
9 2005-11-25 10:14:33 00:00.00 392K C++ barryxt
10 2006-03-11 11:35:04 00:00.00 392K C++ 来自杭电
11 2006-04-21 13:44:39 00:00.00 392K C++ WoodcaT
12 2006-07-19 20:33:36 00:00.00 392K C++ bottle
13 2006-08-11 23:08:20 00:00.00 392K C++ Billups
14 2006-08-14 01:25:32 00:00.00 392K C++ zuo_bj2004
15 2006-08-18 10:22:11 00:00.00 392K C WA for ever
16 2006-09-30 11:14:58 00:00.00 392K C++ CIM->A.I
17 2006-10-05 12:23:35 00:00.00 392K C++ Sorry
18 2006-11-25 19:25:58 00:00.00 392K C++ w
19 2006-12-14 22:32:41 00:00.00 392K C++ gzfix
20 2007-03-17 23:12:03 00:00.00 392K C++ 9911
*/

// 2012-09-07 03:03:48 | Accepted | 1671 | C | 0 | 164 | watashi | Source
