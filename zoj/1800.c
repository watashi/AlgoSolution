#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[600][12];
int mp[600][600];
int dp[101][600];
char isnext(char *a,char *b)
{
    for(a++;*a==*b;a++,b++);
    return *a;
}
int main()
{
    int i,j,k,l,m,n;
    int ans;

    while(scanf("%d%d%d",&l,&m,&n)!=EOF && (l||m||n) ){
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(isnext(str[i],str[j])=='\0') mp[i][j]=1;
                else mp[i][j]=0;
        l=strlen(str[0]);
        memset(dp,0,sizeof(dp));
        for(j=0;j<n;j++)
            dp[l][j]=1;
        for(i=l;i<m;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    if(mp[j][k]) dp[i+1][k]+=dp[i][j];
        ans=0;
        for(j=0;j<n;j++)
            ans+=dp[m][j];
        printf("%d\n",ans);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2686737 2007-11-27 15:03:55 Accepted 1800 C 00:00.82 2044K 再做几题改成Fire */

// 2012-09-07 01:01:27 | Accepted | 1800 | C | 200 | 1808 | watashi | Source
