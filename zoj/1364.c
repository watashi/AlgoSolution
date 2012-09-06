/* //覆盖数等于最大匹配数！！！！！！！ */
/* //二分图匹配~~ */
#include <stdio.h>
#include <string.h>
int mp[100][100];
int match1[100],match2[100];
int hungary(int m,int n)
{
    int s[100],t[100],p,q,i,j,k;
    int ret=0;

    memset(match1,0xff,sizeof(match1));
    memset(match2,0xff,sizeof(match2));
    for(i=0;i<m;i++){
        memset(t,0xff,sizeof(t));
        s[0]=i;
        for(p=q=0;p<=q&&match1[i]<0;p++){
            k=s[p];
            for(j=0;j<n&&match1[i]<0;j++)
                if(mp[k][j]&&t[j]<0){
                    s[++q]=match2[j];
                    t[j]=k;
                    if(s[q]<0)
                        for(p=j;p>=0;j=p){
                            k=match2[j]=t[j];
                            p=match1[k];
                            match1[k]=j;
                        }
                }
        }
        ret+=(match1[i]>=0);
    }
    return ret;
}
int main()
{
    int m,n,k,i,j;

    while(scanf("%d%d%d",&m,&n,&k)==3 && m){
        memset(mp,0,sizeof(mp));
        while(k--){
            scanf("%*d%d%d",&i,&j);
            mp[i-1][j-1]=1;
        }
        printf("%d\n",hungary(m,n));
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2651578 2007-10-20 13:00:30 Accepted 1364 C 00:00.01 436K わたし */

// 2012-09-07 03:00:18 | Accepted | 1364 | C | 0 | 200 | watashi | Source
