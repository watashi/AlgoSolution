#include <stdio.h>
#include <string.h>
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char map[40][42];
int h,w,xx,yy;
int left()
{
    int x=xx,y=yy,tx,ty,dist=1;
    int i,j,t=0;

    while(map[x][y]!='E'){
        dist++;
        for(i=1;i>=-2;i--){
            j=(t+i+4)%4;
            tx=x+d[j][0];
            ty=y+d[j][1];
            if(tx>=0&&ty>=0&&tx<h&&ty<w&&map[tx][ty]!='#'){
                x=tx;
                y=ty;
                t=j;
                break;
            }
        }
    }
    return dist;
}
int right()
{
    int x=xx,y=yy,tx,ty,dist=1;
    int i,j,t=0;

    while(map[x][y]!='E'){
        dist++;
        for(i=-1;i<=2;i++){
            j=(t+i+4)%4;
            tx=x+d[j][0];
            ty=y+d[j][1];
            if(tx>=0&&ty>=0&&tx<h&&ty<w&&map[tx][ty]!='#'){
                x=tx;
                y=ty;
                t=j;
                break;
            }
        }
    }
    return dist;
}
int bfs()
{
    int q[1600][2]={{xx,yy}};
    int i,x,y,mark[40][40];
    int temp,head,tail,dist;

    memset(mark,0,sizeof(mark));
    mark[xx][yy]=1;
    temp=0;head=0;tail=1;dist=1;
    while(head<tail){
        head=tail;
        dist++;
        while(temp<head){
            for(i=0;i<4;i++){
                x=q[temp][0]+d[i][0];
                y=q[temp][1]+d[i][1];
                if(x>=0&&y>=0&&x<h&&y<w&&map[x][y]!='#'&&!mark[x][y]){
                    if(map[x][y]=='E') return dist;
                    mark[x][y]=1;
                    q[tail][0]=x;
                    q[tail][1]=y;
                    tail++;
                }
            }
            temp++;
        }
    }
    return -1;
}
int main()
{
    int re,i;
    char *pt;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&w,&h);
        for(i=0;i<h;i++){
            scanf("%s",map[i]);
            if(pt=strchr(map[i],'S')){
                xx=i;yy=pt-map[i];
            }
        }
        printf("%d %d %d\n",left(),right(),bfs());
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2626195 2007-09-30 17:52:00 Accepted 2787 C 00:00.00 408K わたし */

/*
Rank Submit time Run time Run memory Language User
1 2007-09-30 17:52:00 00:00.00 408K C わたし
2 2007-04-26 21:42:49 00:00.00 416K C++ GreenField
3 2007-02-06 17:21:01 00:00.00 424K C mj
4 2007-04-15 15:11:29 00:00.00 464K C++ mumuxinfei
5 2007-08-11 14:01:14 00:00.00 740K C++ Typhoon
6 2007-02-08 15:54:59 00:00.00 848K C++ 杭之翼
7 2007-09-27 23:44:03 00:00.00 852K C++ Fire
8 2007-02-08 15:54:08 00:00.00 856K C++ Elevent Hour
9 2007-03-22 09:59:07 00:00.00 892K C++ SHOIT
10 2007-06-14 00:52:04 00:00.00 952K C++ angel2008
11 2007-09-24 21:47:55 00:00.00 2984K C++ SHiVa
12 2007-02-07 21:21:36 00:00.00 2988K C++ 11
13 2007-02-09 12:35:44 00:00.00 2988K C++ Athena
14 2007-02-17 13:16:54 00:00.00 2988K C++ *^_^*
15 2007-04-23 20:39:49 00:00.00 2988K C++ AlPacino
16 2007-05-07 18:57:28 00:00.01 448K C++ hazy
17 2007-09-28 01:28:46 00:00.01 844K C++ 看我不见
*/

// 2012-09-07 05:05:33 | Accepted | 2787 | C | 0 | 160 | watashi | Source
