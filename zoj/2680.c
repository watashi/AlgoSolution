#include <stdio.h>
#include <math.h>
#define MAXN 5
int main()
{
    struct clock{
        int h,m;
        float angle;
    }a[MAXN],t;
    int i,j,re;

    scanf("%d",&re);
    while(re--){
        for(i=0;i<MAXN;i++){
            scanf("%d:%d",&a[i].h,&a[i].m);
            a[i].angle=a[i].m*6-(a[i].h%12+(float)a[i].m/60)*30;/*a[i].h%12!!*/
            if(a[i].angle<0) a[i].angle=-a[i].angle;
            if(a[i].angle>180) a[i].angle=360-a[i].angle;
        }
        for(i=0;i<MAXN;i++)
            for(j=MAXN-1;i<j;j--)
                if(a[j].angle<a[j-1].angle){
                    t=a[j-1];
                    a[j-1]=a[j];
                    a[j]=t;
                }
        printf("%02d:%02d\n",a[MAXN/2].h,a[MAXN/2].m);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2496721 2007-06-19 00:46:26 Accepted 2680 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 01:34:39 | Accepted | 2680 | C | 0 | 160 | watashi | Source
