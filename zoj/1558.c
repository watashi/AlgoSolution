#include <stdio.h>
#define infinity 1000
int main()
{
    int ri,re,n,i,j,t,coin[6],dp[201],max,sum,count;

    scanf("%d",&re);
    for(ri=0;ri<re;ri++){
        count=100;
        for(i=1;i<201;i++)
            dp[i]=infinity;
        for(i=0;i<6;i++){
            scanf("%d",&coin[i]);
            dp[coin[i]]=1;
            count--;
        }
        for(n=1;count;n++){
            for(i=1;i<201;i++){
                if(dp[i]==n){
                    for(j=0;j<6;j++){
                        t=i+coin[j];
                        if(t<201&&dp[t]==infinity){
                            dp[t]=n+1;
                            if(t<101) count--;
                        }
                        t=abs(i-coin[j]);
                        if(t<201&&dp[t]==infinity){
                            dp[t]=n+1;
                            if(t<101) count--;
                        }
                    }
                }
            }
        }
        sum=0;
        max=1;
        for(i=1;i<=100;i++){
            sum+=dp[i];
            if(dp[i]>max) max=dp[i];
        }
        printf("%.2lf %d\n",(double)sum/100,max);
    }

    return 0;   /* NZEC */
}

/* //2530138 2007-07-22 18:42:15 Accepted 1558 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:02:20 | Accepted | 1558 | C | 0 | 160 | watashi | Source
