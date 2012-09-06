#include <stdio.h>
#include <math.h>
void which(double x,double y,double xl,double xr,double yu,double yd,int lv)
{
    double xm,ym;

    xm=(xl+xr)/2;
    ym=(yu+yd)/2;
    if(lv==0);
    else if(x<xm){
        if(y>ym){printf("q");which(x,y,xl,xm,yu,ym,--lv);}
        else{printf("t");which(x,y,xl,xm,ym,yd,--lv);}
    }
    else{
        if(y>ym){printf("r");which(x,y,xm,xr,yu,ym,--lv);}
        else{printf("s");which(x,y,xm,xr,ym,yd,--lv);}
    }
}
int main()
{
    double longi,lati,x,y;
    const double pi=3.1415926535897932384626433832795,
        xl=-pi,xr=pi,yu=log(tan(pi/4+(85*pi/180)/2)),yd=log(tan(pi/4+(-85*pi/180)/2));
    int lv;

    while(scanf("%lf%lf%d",&longi,&lati,&lv)!=EOF){
        printf("t");
        x=longi*pi/180;
        y=log(tan(pi/4+(lati*pi/180)/2));
        which(x,y,xl,xr,yu,yd,lv);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2494038 2007-06-16 21:42:22 Accepted 2855 C 00:00.06 400K ¤ï¤¿¤· */

// 2012-09-07 03:14:13 | Accepted | 2855 | C | 30 | 160 | watashi | Source
