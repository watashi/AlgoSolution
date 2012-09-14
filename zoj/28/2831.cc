#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <string.h>
typedef char bitmap[8][10];
const bitmap digit[11]=
{
    {
    "  XXXX  ",
    " XX  XX ",
    " XX  XX ",
    " XX  XX ",
    " XX  XX ",
    " XX  XX ",
    " XX  XX ",
    "  XXXX  ",
    },
    {
    "   XX   ",
    " XXXX   ",
    "   XX   ",
    "   XX   ",
    "   XX   ",
    "   XX   ",
    "   XX   ",
    " XXXXXX ",
    },
    {
    "  XXXX  ",
    " XX  XX ",
    " XX  XX ",
    "     XX ",
    "    XX  ",
    "   XX   ",
    "  XX    ",
    " XXXXXX ",
    },
    {
    "  XXXX  ",
    " X   XX ",
    "     XX ",
    "   XXX  ",
    "     XX ",
    "     XX ",
    " X   XX ",
    "  XXXX  ",
    },
    {
    "    XX  ",
    "   XXX  ",
    "   XXX  ",
    "  X XX  ",
    " X  XX  ",
    " XXXXXX ",
    "    XX  ",
    "  XXXXX ",
    },
    {
    "  XXXXX ",
    "  XX    ",
    "  XXXX  ",
    "  X  XX ",
    "     XX ",
    "     XX ",
    " X   XX ",
    "  XXXX  ",
    },
    {
    "   XXXX ",
    "  XX    ",
    " XX     ",
    " XXXXX  ",
    " XX  XX ",
    " XX  XX ",
    " XX  XX ",
    "  XXXX  ",
    },
    {
    " XXXXXX ",
    " X   XX ",
    "     XX ",
    "    XX  ",
    "    XX  ",
    "    XX  ",
    "   XX   ",
    "   XX   ",
    },
    {
    "  XXXX  ",
    " XX  XX ",
    " XX  XX ",
    "  XXXX  ",
    " XX  XX ",
    " XX  XX ",
    " XX  XX ",
    "  XXXX  ",
    },
    {
    "  XXXX  ",
    " XX  XX ",
    " XX  XX ",
    " XX  XX ",
    "  XXXXX ",
    "     XX ",
    "    XX  ",
    " XXXX   ",
    },
    {
    "        ",
    "   X    ",
    "   X    ",
    "   X    ",
    "XXXXXXX ",
    "   X    ",
    "   X    ",
    "   X    ",
    }
};
char line[8][1024];
int beblank(int p)
{
    int i;

    for(i=0;i<8;i++)
        if(line[i][p]=='X') return 0;
        else if(line[i][p]=='*') return EOF;
    return 1;
}
int getdigit(int p)
{
    int i,j,k;

    for(i=0;i<10;i++){
        for(j=0;j<8;j++){
            for(k=1;k<7;k++)
                if(line[j][p+k-1]!=digit[i][j][k]) break;
            if(k<7) break;
        }
        if(j>=8) return i;
    }
    return 10;
}
void putdigit(int x,int p)
{
    int i,j;

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            line[i][p+j]=digit[x][i][j];
}
void putline(int x)
{
    int t,i,a[10];

    i=0;
    t=x;
    do{
        a[i++]=x%10;
        x/=10;
    }while(x);
    i--;
    t=0;
    do{
        putdigit(a[i],t);
        t+=8;
    }while(i--);
    for(i=0;i<8;i++){
        line[i][t]='\0';
        puts(line[i]);
    }
}
int main()
{
    int re,i,t,a,b;

    scanf("%d",&re);
    getchar();
    while(re--){
        for(i=0;i<8;i++){
            gets(line[i]);
            strcat(line[i],"        ********");//and the trailing spaces at the end of the line may be removed by his (may be "her") editor.
        }
        i=0;
        a=0;t=0;
        while(t!=10){
            a*=10;
            a+=t;
            while(beblank(i)==1) i++;
            t=getdigit(i);
            i+=7;
        }
        b=0;t=0;
        while(beblank(i)==1) i++;
        while(beblank(i)!=EOF){
            t=getdigit(i);
            i+=7;
            b*=10;
            b+=t;
            while(beblank(i)==1) i++;
        }
        putline(a+b);
        if(re){
            puts("");
            gets(line[0]);//There will be a blank line between consecutive test cases.
        }
    }
}
/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2591479 2007-09-01 02:32:48 Accepted 2831 C++ 00:00.00 404K ¤ï¤¿¤·
*/

// 2012-09-07 14:11:04 | Accepted | 2831 | C++ | 0 | 188 | watashi | Source
