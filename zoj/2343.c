#include <stdio.h>
int main()
{
    int re,i,j,k,n,m,y,sum;
    short int p[1000];
    struct robber{
        int i,k,x;
        double r,dif;
    }a[1000],t;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d%d",&n,&m,&y);
        sum=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i].x);
            a[i].i=i;
            a[i].r=(double)a[i].x/y;
            a[i].k=(int)(m*a[i].r);
            a[i].dif=(double)(2*a[i].k+1)/m-2*a[i].r;
            sum+=a[i].k;
        }
        sum=m-sum;
        for(i=0;i<n;i++){
            k=i;
            for(j=i+1;j<n;j++)
                if(a[j].dif<a[k].dif) k=j;
            t=a[i];a[i]=a[k];a[k]=t;
            if(i<sum) a[i].k++;
        }
        for(i=0;i<n;i++){
            for(j=i;j<n;j++)
                if(a[j].i==i) break;
            t=a[i];a[i]=a[j];a[j]=t;
        }
        printf("%d",a[0].k);
        for(i=1;i<n;i++)
            printf(" %d",a[i].k);
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2532047 2007-07-23 21:00:29 Accepted 2343 C 00:00.03 420K ¤ï¤¿¤· */

// 2012-09-07 01:20:00 | Accepted | 2343 | C | 10 | 160 | watashi | Source
