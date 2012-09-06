#include <stdio.h>
const int bin[3]={1,2,4};
const int map[8][8]={{0,1,0,0,1,0,0,1},
                    {1,0,0,0,0,0,1,0},
                    {0,0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0,0},
                    {1,0,0,1,0,0,0,0},
                    {0,0,1,0,0,0,0,0},
                    {0,1,0,0,0,0,0,0},
                    {1,0,0,0,0,0,0,0}};
static int dp[33][8];
int main()
{
    int i,j,k;

    dp[0][0]=1;
    for(i=1;i<31;i++)
        for(j=0;j<8;j++)
            for(k=0;k<8;k++)
                if(map[k][j]) dp[i][j]+=dp[i-1][k];
    while(scanf("%d",&i),i>=0)
        printf("%d\n",dp[i][0]);

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2592841 2007-09-02 02:50:03 Accepted 2547 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:11:35 | Accepted | 2547 | C | 0 | 160 | watashi | Source
