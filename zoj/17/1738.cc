//2^15=32768 181*181=32761

#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <string.h>
int sq[182];
int main()
{
    int i,j,k,dp[32768][4];

    memset(dp,0,sizeof(dp));
    sq[0]=0;
    for(k=1;k<182;k++){
        sq[k]=sq[k-1]+k+k-1;
        dp[sq[k]][0]=1;
        for(i=sq[k];i<32768;i++)
            for(j=1;j<4;j++)
                /*if(dp[i-sq[k]][j-1])*/dp[i][j]+=dp[i-sq[k]][j-1];
    }
    while(scanf("%d",&k),k)
        printf("%d\n",dp[k][0]+dp[k][1]+dp[k][2]+dp[k][3]);
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2612528 2007-09-18 00:01:37 Accepted 1738 C 00:00.12 900K わたし


//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2612531 2007-09-18 00:04:04 Accepted 1738 C++ 00:00.12 904K わたし
/*
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <string.h>
int sq[182];
int main()
{
    int i,j,k,dp[32768][4];

    memset(dp,0,sizeof(dp));
    sq[0]=0;
    for(k=1;k<182;k++){
        sq[k]=k*k;//肖隼k*k酔~
        dp[sq[k]][0]=1;
        for(i=sq[k];i<32768;i++)
            for(j=1;j<4;j++)
                dp[i][j]+=dp[i-sq[k]][j-1];
    }
    while(scanf("%d",&k),k)
        printf("%d\n",dp[k][0]+dp[k][1]+dp[k][2]+dp[k][3]);
}
*/

// WA @ 2.0
/*
#include <cstdio> // auto fix CE
#include <cstring> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    static int i,k,sq,dp[32768][4];

    for(k=1;k<182;k++){
        dp[sq][0]=1;
        for(i=sq;i<32768;i++){
            dp[i][1]+=dp[i-sq][0];
            dp[i][2]+=dp[i-sq][1];
            dp[i][3]+=dp[i-sq][2];
        }
    }
    while(scanf("%d",&k),k)
        printf("%d\n",dp[k][0]+dp[k][1]+dp[k][2]+dp[k][3]);
}
*/
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2612555 2007-09-18 00:19:15 Accepted 1738 C 00:00.09 904K わたし

// 2012-09-07 14:08:59 | Accepted | 1738 | C++ | 20 | 180 | watashi | Source
