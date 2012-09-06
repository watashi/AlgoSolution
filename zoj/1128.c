/* //void *bsearch(const void *key, const void *base, size_t *nelem,size_t width, int(*fcmp)(const void *, const *)); */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int xx,yy;
double x[202],y[202];
int mp[202][202];
double a[101][4];
double ans;
int comp(const void *pa,const void *pb)
{
    double a=*(double *)pa,b=*(double *)pb;

    return (a<b)?-1:(a>b);
}
int main()
{
    int i,j,k,n,f,ff,t,tt;
    int ri=0;

    while(scanf("%d",&n)!=EOF && n){
        j=0;
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
            x[j]=a[i][0];y[j]=a[i][1];j++;
            x[j]=a[i][2];y[j]=a[i][3];j++;
        }
        xx=yy=j;
        qsort(x,xx,sizeof(double),comp);
        i=j=0;
        while(1){
            while(++i<xx&&x[i]==x[j]);
            if(i<xx) x[++j]=x[i];
            else break;
        }
        xx=j+1;
        qsort(y,yy,sizeof(double),comp);
        i=j=0;
        while(1){
            while(++i<yy&&y[i]==y[j]);
            if(i<yy) y[++j]=y[i];
            else break;
        }
        yy=j+1;
        memset(mp,0,sizeof(mp));
        ans=0.0;
        for(k=0;k<n;k++){
            f=(double *)bsearch(&a[k][0],x,xx,sizeof(double),comp)-x;
            ff=(double *)bsearch(&a[k][1],y,yy,sizeof(double),comp)-y;
            t=(double *)bsearch(&a[k][2],x,xx,sizeof(double),comp)-x;
            tt=(double *)bsearch(&a[k][3],y,yy,sizeof(double),comp)-y;
            for(i=f;i<t;i++)
                for(j=ff;j<tt;j++)
                    if(!mp[i][j]){
                        mp[i][j]=1;
                        ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
                    }
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++ri,ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2650926 2007-10-19 21:29:13 Accepted 1128 C 00:00.01 564K ¤ï¤¿¤· */

// 2012-09-07 02:56:39 | Accepted | 1128 | C | 0 | 324 | watashi | Source
