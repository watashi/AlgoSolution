#include <stdio.h>
#define MAXX 1e18
int main()
{
    int i,j,k,n,p[4];
    long long x[4],t[4],a[66666];

    a[0]=1;
    p[0]=p[1]=p[2]=p[3]=0;
    x[0]=2;x[1]=3;x[2]=5;x[3]=7;
    for(i=1;;i++){
        for(j=0;j<4;j++)
            t[j]=a[p[j]]*x[j];
        k=0;
        for(j=1;j<4;j++)
            if(t[j]<t[k]) k=j;
        a[i]=t[k];
        if(a[i]>MAXX) break;
        for(j=0;j<4;j++)
            if(t[j]==t[k]) p[j]++;
    }
    n=i;
    scanf("%d",&k);
    while(k--){
        scanf("%d",&i);
        printf("%lld\n",a[i-1]);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2621791 2007-09-26 19:13:57 Accepted 2873 C 00:00.14 916K わたし
/*
Rank Submit time Run time Run memory Language User
1 2007-08-09 09:18:51 00:00.12 1172K C++ IS
2 2007-06-17 23:03:49 00:00.13 940K C++ 这个GMT+8准了...
3 2007-06-22 12:05:49 00:00.13 1220K C++ pemj
4 2007-09-23 21:04:08 00:00.13 1348K C++ damajia
5 2007-07-30 19:59:10 00:00.13 2984K C++ Jedidiah
6 2007-06-18 16:30:09 00:00.13 8652K C++ Tom Riddle
7 2007-06-17 23:07:14 00:00.14 908K C++ 龙龙
8 2007-09-26 19:13:57 00:00.14 916K C わたし
9 2007-06-27 23:49:33 00:00.14 960K C++ 9911
10 2007-07-31 11:46:23 00:00.14 980K C++ 啊噹
*/

// 2012-09-07 01:44:00 | Accepted | 2873 | C++ | 60 | 180 | watashi | Source
