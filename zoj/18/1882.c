#include <math.h>
#include <stdio.h>
#include <string.h>
#define eps 1e-6
int mp[101][101];
int ma1[101],ma2[101];
double p[101][2];
double dist(int i,double x,double y)
{
    return sqrt((x-p[i][0])*(x-p[i][0])+(y-p[i][1])*(y-p[i][1]));
}
int hungary(int n,int m)
{
    int s[101],t[101],p,q,i,j,k;
    int ret=0;

    memset(ma1,0xff,n*sizeof(int));
    memset(ma2,0xff,m*sizeof(int));
    for(i=0;i<n;i++){
        memset(t,0xff,m*sizeof(int));
        s[0]=i;
        for(p=q=0;p<=q&&ma1[i]<0;p++){
            k=s[p];
            for(j=0;j<m&&ma1[i]<0;j++)
                if(mp[k][j]&&t[j]<0){
                    s[++q]=ma2[j];
                    t[j]=k;
                    if(s[q]<0)
                        for(p=j;p>=0;j=p){
                            k=ma2[j]=t[j];
                            p=ma1[k];
                            ma1[k]=j;
                        }
                }
        }
        ret+=(ma1[i]>=0);
    }
    return ret;
}
int main()
{
    int i,j,n,m,s,v;
    double d,x,y;

    while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF){
        d=(double)s*(double)v+eps;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&p[i][0],&p[i][1]);
            memset(mp[i],0,m*sizeof(int));
        }
        for(j=0;j<m;j++){
            scanf("%lf%lf",&x,&y);
            for(i=0;i<m;i++)
                if(dist(i,x,y)<=d) mp[i][j]=1;
        }
        printf("%d\n",n-hungary(n,m));
        /* giving the number of vulnerable gophers. !!!!!!!!!!!!!!*/
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2651789 2007-10-20 15:36:42 Accepted 1882 C 00:00.07 448K ¤ï¤¿¤· */

// 2012-09-07 03:06:30 | Accepted | 1882 | C | 20 | 200 | watashi | Source
