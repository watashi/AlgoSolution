/* //”–nlogn£¨”√¡Àn2 */
#include <stdio.h>
#include <stdlib.h>
struct fatmouse{
    short w;
    short s;
    short id;
};
int cmp(const void *pa,const void *pb)
{
    struct fatmouse *a=(struct fatmouse *)pa,*b=(struct fatmoust *)pb;

    if(a->w==b->w){
        if(a->s==b->s) return 0;
        else return (a->s>b->s)?-1:1;
    }
    else return (a->w<b->w)?-1:1;
}
struct fatmouse rec[1000];
short dp[1000],pr[1000];
void printid(int id)
{
    if(pr[id]!=-1) printid(pr[id]);
    printf("%hd\n",rec[id].id);
}
int main()
{
    int i,j,n,ans;

    /*freopen("fatmouseSpeed.txt","r",stdin);*/
    for (i = 0; scanf("%hd%hd", &rec[i].w, &rec[i].s) == 2; rec[i].id = i + 1, ++i);/*rec[i].id = ++i=>++i,rec[i].id=i*/
    n=i;
    qsort(rec,n,sizeof(struct fatmouse),cmp);
    ans=0;
    for(i=0;i<n;i++){
        dp[i]=1;
        pr[i]=-1;
        for(j=0;j<i;j++)
            if(dp[j]>=dp[i]&&rec[j].w<rec[i].w&&rec[j].s>rec[i].s){
                dp[i]=dp[j]+1;
                pr[i]=j;
            }
        if(dp[i]>dp[ans]) ans=i;
    }
    printf("%hd\n",dp[ans]);
    printid(ans);

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2686029 2007-11-26 15:55:02 Accepted 1108 C 00:00.01 412K §Ô§ø§∑ */

// 2012-09-07 02:56:03 | Accepted | 1108 | C | 0 | 168 | watashi | Source
