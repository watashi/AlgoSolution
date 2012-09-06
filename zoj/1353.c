#include <stdio.h>
#include <string.h>
#define MAXN 255
unsigned int dp[MAXN][MAXN];
int main()
{
    int i,j,k,n,ans;

    memset(dp,0,sizeof(dp));
    for(i=1;i<MAXN;i++){
        for(j=1;j<i;j++)
            dp[i][j]=dp[i][j-1]+dp[i-j][j];
        dp[i][i]=dp[i][i-1]+1;
        for(j=i+1;j<MAXN;j++)
            dp[i][j]=dp[i][i];
    }
    while(scanf("%d",&n)!=EOF && n){
        if(n&1){
            ans=0;
            for(i=1;i<n;i+=2)
                ans+=dp[(n-i)>>1][i];
        }
        else{
            ans=dp[n>>1][n>>1];
            for(i=2;i<n;i+=2)
                ans+=dp[(n-i)>>1][i];
        }
        printf("%d %u\n",n,ans+1);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2651078 2007-10-19 22:36:03 Accepted 1353 C 00:00.00 644K ¤ï¤¿¤· */

/*
Rank Submit time Run time Run memory Language User
1 2006-06-09 15:26:36 00:00.00 392K C++ Output Limit Exceeded
2 2007-08-23 22:21:44 00:00.00 568K C gzkenzou
3 2005-12-26 16:34:39 00:00.00 600K C++ AndyZhau
4 2006-10-15 19:44:06 00:00.00 600K C++ Sorry
5 2006-12-07 21:41:13 00:00.00 600K C++ xia192041
6 2007-09-11 11:29:25 00:00.00 600K C++ sy
7 2007-06-06 14:32:41 00:00.00 604K C++ ¶À
8 2007-09-17 22:36:17 00:00.00 604K C++ Dream
9 2007-09-17 22:36:38 00:00.00 604K C++ koy
10 2006-11-23 14:45:54 00:00.00 632K C++ hazy
11 2006-11-23 14:41:43 00:00.00 636K C++ Fall
12 2007-10-19 22:36:03 00:00.00 644K C ¤ï¤¿¤·
13 2007-04-30 20:52:22 00:00.00 740K C++ gogogo
14 2007-04-30 20:52:37 00:00.00 744K C++ luobolj
15 2006-04-12 21:43:09 00:00.00 808K C++ Ò°Âí
16 2007-10-11 08:40:14 00:00.00 808K C++ Snail
17 2007-05-02 10:20:10 00:00.00 836K C |Dragon|ìáºê
*/

// 2012-09-07 03:00:06 | Accepted | 1353 | C | 0 | 412 | watashi | Source
