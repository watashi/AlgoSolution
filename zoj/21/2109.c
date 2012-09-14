#include <stdio.h>
int main()
{
    struct{
        double j,f,r;
    }a[1000],t;
    int m,n,i,j,k,index;
    double sum;

    while(scanf("%d%d",&m,&n),n+1){
        for(i=0;i<n;i++){
            scanf("%lf%lf",&a[i].j,&a[i].f);
            a[i].r=a[i].j/a[i].f;
        }
        for(i=0;i<n;i++){
            k=i;
            for(j=i+1;j<n;j++)
                if(a[j].r>a[k].r) k=j;
            t=a[i];a[i]=a[k];a[k]=t;
        }
        sum=0;
        for(i=0;i<n;i++){
            if(m>=a[i].f){m-=a[i].f;sum+=a[i].j;}
            else{
                sum+=a[i].r*(double)m;
                break;
            }
        }
        printf("%.3lf\n",sum);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2500495 2007-06-22 23:05:00 Accepted 2109 C 00:00.20 420K ¤ï¤¿¤· */

// 2012-09-07 03:08:26 | Accepted | 2109 | C | 70 | 160 | watashi | Source
