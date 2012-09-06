#include <stdio.h>
char *week[]={"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                {0,31,29,31,30,31,30,31,31,30,31,30,31}};
long year[10001];
int main()
{
    int i,k;
    long d;
    int y,m,w;

    year[1999]=0;
    for(i=2000;i<10001;i++){
        if(i%4!=0) year[i]=year[i-1]+365;
        else if(i%100==0&&i%400!=0) year[i]=year[i-1]+365;
        else year[i]=year[i-1]+366;
    }
    while(scanf("%ld",&d),d!=-1){
        d++;
        w=d%7;
        i=1999;
        while(d>year[++i]);
        d-=year[i-1];
        y=i;
        if(y%4) k=0;
        else if(y%100==0&&y%400!=0) k=0;
        else k=1;
        i=1;
        while(d>month[k][i]) d-=month[k][i++];
        m=i;
        printf("%d-%02d-%02d %s\n",y,m,d,week[w]);
    }

    return 0;   /* NZEC */
}

/*2921570*2921580*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2508721 2007-07-04 00:21:34 Accepted 2420 C 00:00.08 428K ¤ï¤¿¤· */

// 2012-09-07 03:10:16 | Accepted | 2420 | C | 20 | 200 | watashi | Source
