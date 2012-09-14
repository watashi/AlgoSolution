#include <stdio.h>
#include <math.h>
#define dist(i,j) sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
typedef struct{
double x,y;
}XY;
XY p[108];
const double INF = 1e10;
int main()
{
    int i,j,k,n,t,mark[108];
    double d,tmp,ans;

    while(scanf("%d",&n)!=EOF){
        ans=0;
        for(i=0;i<n;i++){
            mark[i]=0;
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        mark[0]=1;
        for(k=1;k<n;k++){
            d=INF;
            for(i=0;i<n;i++){
                if(mark[i]==0) continue;
                for(j=0;j<n;j++){
                    if(mark[j]) continue;
                    tmp=dist(i,j);
                    if(tmp<d){
                        d=tmp;
                        t=j;
                    }
                }
            }
            mark[t]=1;
            ans+=d;
        }
        printf("%.2lf\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2593425 2007-09-02 14:22:06 Accepted 1872 C 00:00.00 400K わたし */
/*
Rank Submit time Run time Run memory Language User
1 2006-02-24 23:35:07 00:00.00 384K C++ fly190
2 2007-09-02 14:22:06 00:00.00 400K C わたし
3 2006-06-17 22:10:37 00:00.00 404K C hopeful
4 2005-09-23 18:47:17 00:00.00 408K FPC cqf
5 2006-04-16 14:19:37 00:00.00 408K FPC liuyi
6 2006-07-24 21:02:14 00:00.00 408K C++ ChenXiangRu
7 2006-08-16 11:54:53 00:00.00 408K FPC c
8 2006-04-16 14:19:16 00:00.00 412K FPC 高蕃議土子
9 2007-05-08 17:14:48 00:00.00 412K FPC sky
10 2005-09-13 19:02:33 00:00.00 440K C Xiaolan.Lee
*/

// 2012-09-07 03:06:12 | Accepted | 1872 | C | 0 | 160 | watashi | Source
