#include <stdio.h>
#include <stdlib.h>
int comp(const void *a,const void *b)
{
    return (*(int *)a>*(int *)b)?-1:((*(int *)a==*(int *)b)?0:1);
}
int main()
{
    int re,i,n,a[1004],ans;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        qsort((void *)&a[1],n,sizeof(int),comp);
        ans=0;
        for(i=1;i<=n;i++){
            a[i]*=i;
            if(a[i]>ans) ans=a[i];
        }
        printf("%d\n",ans);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2596051 2007-09-04 16:53:43 Accepted 2488 C 00:00.00 396K わたし */
/* //2596050 2007-09-04 16:53:25 Accepted 2488 C 00:00.01 396K わたし */

// 2012-09-07 01:24:43 | Accepted | 2488 | C | 0 | 160 | watashi | Source
