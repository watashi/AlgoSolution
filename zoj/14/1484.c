/* //the next line contains a permutation of the n integers from 0 to n-1. */
/* //如果没有０－ｎ－１的条件，怎么做？：：预处理《ｘ的数字数～：：考虑出题 */
#include <stdio.h>
#include <string.h>
int a[5005],t[5005],x[5005];
int inv(int n,int a[])
{
    int i,j,l,r,res;

    l=n>>1;
    r=n-l;
    if(r<=1) res=0;
    else res=inv(l,a)+inv(r,a+l);/**/
    for(i=j=0;i<l;i++){
        res+=j;/**/
        while(j<r&&a[i]>=a[l+j]){/*>=*/
            t[i+j]=a[l+j];
            j++;
        }
        t[i+j]=a[i];
    }
    res+=j;/*++*/
    while(j<r){
        t[i+j]=a[l+j];
        j++;
    }
    memcpy(a,t,n*sizeof(int));
    return res;
}
int main()
{
    int i,n,tmp,ans;

    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            x[i]=a[i];
        }
        ans=tmp=inv(n,a);
        for(i=0;i<n;i++){
            tmp+=n-1-x[i];
            tmp-=x[i];
            if(tmp<ans) ans=tmp;
        }
        printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2659493 2007-10-26 19:37:58 Accepted 1484 C 00:00.02 452K わたし */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2659494 2007-10-26 19:38:39 Accepted 1484 C 00:00.01 452K わたし */

// 2012-09-07 03:01:25 | Accepted | 1484 | C | 0 | 216 | watashi | Source
