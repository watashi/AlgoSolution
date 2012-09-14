#include <stdio.h>
int main()
{
    double m,rate[6][6];
    int i,j,n,ri,rep,trip[12]={1};

    scanf("%d",&rep);
    for(ri=0;ri<rep;ri++){
        if(ri) printf("\n");
        for(i=1;i<=5;i++)
            for(j=1;j<=5;j++)
                scanf("%lf",&rate[i][j]);
        while(scanf("%d",&n),n){
            for(i=1;i<=n;i++)
                scanf("%d",&trip[i]);
            trip[n+1]=1;
            scanf("%lf",&m);
            m*=100;
            for(i=0;i<=n;i++){
                m*=rate[trip[i]][trip[i+1]];
                m=(double)(long)(m+0.5);
            }
            printf("%.2lf\n",m/100);
        }
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2505964 2007-06-29 21:35:52 Accepted 1058 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 00:34:56 | Accepted | 1058 | C | 0 | 160 | watashi | Source
