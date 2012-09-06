#include <stdio.h>
#include <stdlib.h>
#define MAXM 1024
struct Sum{
    int id;
    double sum;
}a[MAXM];
int compstruct(const void *a,const void *b)
{
    if(((struct Sum *)a)->sum==((struct Sum *)b)->sum) return (((struct Sum *)a)->id<((struct Sum *)b)->id)?-1:1;
    else return (((struct Sum *)a)->sum>((struct Sum *)b)->sum)?-1:1;
}
int compid(const void *a,const void *b)
{
    return (((struct Sum *)a)->id>((struct Sum *)b)->id)?-1:1;
}
int main()
{
    int n,m,k,i,j;
    double x;

    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(j=0;j<m;j++){
            a[j].id=j+1;
            a[j].sum=0;
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                scanf("%lf",&x);
                a[j].sum+=x;
            }
        qsort(a,m,sizeof(struct Sum),compstruct);
        qsort(a,k,sizeof(struct Sum),compid);
        printf("%d",a[0].id);
        for(i=1;i<k;i++)
            printf(" %d",a[i].id);
        printf("\n");
    }

    return 0;   /* NZEC */
}


/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2646650 2007-10-16 14:37:55 Accepted 2511 C 00:00.75 416K ¤ï¤¿¤· */

// 2012-09-07 03:11:10 | Accepted | 2511 | C | 270 | 176 | watashi | Source
