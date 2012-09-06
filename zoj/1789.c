#include <stdio.h>
#include <string.h>
int a[30003];
int root(int i)
{
    if(a[i]==i) return i;
    else return a[i]=root(a[i]);
}
void set_friend(int i,int j)
{
    a[root(j)]=root(i);
}
int main()
{
    int i,j,k,n,m,ans;

    while(scanf("%d%d",&n,&m)!=EOF && (n||m)){
        for(i=0;i<n;i++)
            a[i]=i;
        while(m--){
            scanf("%d",&k);
            if(k==0) continue;
            scanf("%d",&i);
            while(--k){
                scanf("%d",&j);
                set_friend(i,j);
            }
        }
        ans=0;
        k=root(a[0]);
        for(i=0;i<n;i++)
            if(root(a[i])==k) ans++;
        printf("%d\n",ans);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2662089 2007-10-29 19:12:49 Accepted 1789 C 00:00.05 508K ¤ï¤¿¤· */

// 2012-09-07 01:00:56 | Accepted | 1789 | C | 0 | 276 | watashi | Source
