#include <stdio.h>
long long a[501][501];
long long count(int k,int n,int mk,int mn)
{
    int i;
    long long res;

    if(n==0) return 1;
    else if(k==0) return 0;
    else{
        if(k>n) k=n;
        if(n<mn||n==mn&&k<mk) return a[n][k];
        else{
            res=0;
            for(i=1;i<=k;i++)
                res+=count(i-1,n-i,mk,mn);
            return res;
        }
    }
}
int main()
{
    int i,j,n;

    for(i=0;i<501;i++)
        for(j=0;j<=i;j++)
            a[i][j]=count(j,i,j,i);
    while(scanf("%d",&n),n){
        printf("%lld\n",count(n-1,n,500,500));
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2509967 2007-07-05 23:58:48 Accepted 1163 C 00:00.68 2352K ¤ï¤¿¤· */

// 2012-09-07 00:39:36 | Accepted | 1163 | C | 410 | 2120 | watashi | Source
