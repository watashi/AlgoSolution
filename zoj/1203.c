#include <stdio.h>
#include <math.h>
#define infinity 1e123
#define dist(a,b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
int main()
{
    struct point{
        double x,y;
        int mark;
    }a[100];
    int ri,i,j,f,t,count,n;
    double d,min,sum,map[100][100];

    ri=0;
    while(scanf("%d",&n),n){
        if(ri) printf("\n");
        scanf("%lf%lf",&a[0].x,&a[0].y);
        a[0].mark=1;
        for(i=1;i<n;i++){
            scanf("%lf%lf",&a[i].x,&a[i].y);
            a[i].mark=0;
        }
        for(i=0;i<n;i++){
            map[i][i]=0;
            for(j=i+1;j<n;j++)
                map[i][j]=map[j][i]=dist(a[i],a[j]);
        }
        sum=0;
        count=1;
        while(count<n){
            f=t=-1;
            min=infinity;
            for(i=0;i<n;i++){
                if(a[i].mark==0) continue;
                for(j=0;j<n;j++){
                    if(a[j].mark) continue;
                    if(map[i][j]<min){min=map[i][j];f=i;t=j;}
                }
            }
            a[t].mark=1;
            count++;
            sum+=sqrt(min);
        }
        printf("Case #%d:\nThe minimal distance is: %.2lf\n",++ri,sum);
    }

    return 0;   /* NZEC */
}

/*最小生成树*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2546395 2007-07-31 20:08:55 Accepted 1203 C 00:00.00 480K わたし */

// 2012-09-07 02:57:40 | Accepted | 1203 | C | 0 | 160 | watashi | Source
