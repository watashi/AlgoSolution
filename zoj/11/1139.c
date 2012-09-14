#include <stdio.h>
#define MAXN 4500
int main()
{
    struct rectangle{
        int xmin,xmax,ymin,ymax;
    }a[MAXN];
    int i,j,n,count;

    while(scanf("%d",&n)!=EOF){
        count=0;
        for(i=0;i<n;i++)
            scanf("%d%d%d%d",&a[i].xmin,&a[i].xmax,&a[i].ymin,&a[i].ymax);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i!=j&&a[i].xmin>=a[j].xmin&&a[i].xmax<=a[j].xmax&&a[i].ymin>=a[j].ymin&&a[i].ymax<=a[j].ymax)
                    {count++;break;}
        printf("%d\n",count);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2497243 2007-06-19 18:06:10 Accepted 1139 C 00:02.49 468K ¤ï¤¿¤· */

// 2012-09-07 02:56:46 | Accepted | 1139 | C | 840 | 160 | watashi | Source
