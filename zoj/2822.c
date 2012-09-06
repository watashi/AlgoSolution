#include <stdio.h>
int main()
{
    int i,j,k,np,p[400],dp[1121][15];

    p[0]=2;p[1]=3;k=2;
    for(i=5;i<=1120;i+=2){
        for(j=1;p[j]*p[j]<=i;j++)
            if(i%p[j]==0) break;
        if(p[j]*p[j]>i) p[k++]=i;
    }
    np=k;
    for(i=0;i<=1120;i++)
        for(j=0;j<=14;j++)
            dp[i][j]=0;
    dp[0][0]=1;
    for(k=0;k<np;k++)
        for(j=14;j;j--)
            for(i=p[k];i<=1120;i++)
                dp[i][j]+=dp[i-p[k]][j-1];
    while(scanf("%d%d",&i,&j),i||j)
        printf("%d\n",dp[i][j]);
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2604241 2007-09-11 14:23:49 Accepted 2822 C 00:00.01 460K わたし */


/*
Rank Submit time Run time Run memory Language User
1 2007-06-10 06:58:12 00:00.00 384K C++ lightsilver
2 2007-06-10 06:58:02 00:00.00 388K C++ ngb
3 2007-05-28 14:57:31 00:00.00 452K C++ 9911
4 2007-06-06 15:20:13 00:00.00 452K C++ 海蓝星
5 2007-06-06 15:20:02 00:00.00 456K C++ gg gl
6 2007-03-12 15:54:38 00:00.00 464K C Dicken
7 2007-03-10 14:11:07 00:00.00 512K C++ ono
8 2007-03-02 21:41:49 00:00.01 460K C++ hazy
9 2007-03-07 08:09:08 00:00.01 460K C++ I love McAfee:D
10 2007-03-07 08:09:32 00:00.01 460K C++ SHiVa
11 2007-03-07 22:06:00 00:00.01 460K C++ katherine
12 2007-03-07 22:07:44 00:00.01 460K C++ KatherineZhang
13 2007-03-26 17:37:56 00:00.01 460K C++ fzbzchenxi
14 2007-03-26 17:38:17 00:00.01 460K C++ chenxizju
15 2007-03-31 22:10:28 00:00.01 460K C++ 卧农居士
16 2007-04-17 00:55:38 00:00.01 460K C++ zhchzh
17 2007-09-11 14:23:49 00:00.01 460K C わたし
18 2007-03-07 21:19:55 00:00.01 464K C++ Liu
19 2007-03-23 14:10:33 00:00.01 464K C 加勒比牛蛙
20 2007-04-09 11:35:10 00:00.01 464K C IS
*/

// 2012-09-07 01:41:28 | Accepted | 2822 | C | 0 | 160 | watashi | Source
