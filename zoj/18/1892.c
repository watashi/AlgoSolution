/* //1090.c The Circumference of the Circle */
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
int main()
{
    double x0,y0,x1,y1,x2,y2,x3,y3,a1,b1,c1,a2,b2,c2,d,d1,d2,r;
    double da,angle,xmax,ymax,xmin,ymin,x,y;
    int i,n,ri=0;

    while(scanf("%d",&n),n){
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        a1=x1-x2;
        b1=y1-y2;
        c1=(x1+x2)*(x1-x2)/2.0+(y1+y2)*(y1-y2)/2.0;
        a2=x2-x3;
        b2=y2-y3;
        c2=(x2+x3)*(x2-x3)/2.0+(y2+y3)*(y2-y3)/2.0;
        d=a1*b2-a2*b1;
        d1=c1*b2-c2*b1;
        d2=a1*c2-a2*c1;
        x0=d1/d;
        y0=d2/d;
        r=sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
        if(x1>=0) angle=asin((y1-y0)/r);
        else angle=PI-asin((y1-y0)/r);
        xmin=xmax=ymin=ymax=0;
        da=2*PI/n;
        for(i=0;i<=n;i++){
            angle+=da;
            y=sin(angle);
            x=cos(angle);
            if(y>ymax) ymax=y;
            else if(y<ymin) ymin=y;
            if(x>xmax) xmax=x;/*if(y=sin(angle)>ymax) ymax=y;else if(y<ymin) ymin=y;将只做一次y=sin(angle)！！*/
            else if(x<xmin) xmin=x;
        }
        printf("Polygon %d: %.3lf\n",++ri,(xmax-xmin)*(ymax-ymin)*r*r);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2485901 2007-06-09 01:02:54 Accepted 1892 C 00:00.00 400K わたし */

/*
Rank Submit time Run time Run memory Language User
1 2007-05-20 15:04:10 00:00.00 388K C++ casablanca
2 2005-09-14 11:54:07 00:00.00 396K C++ XXXXXX
3 2005-11-24 19:45:46 00:00.00 396K C++ ant
4 2006-02-02 10:41:09 00:00.00 396K C++ wcm
5 2006-04-28 13:13:35 00:00.00 396K C++ wrong answer
6 2006-08-02 20:25:28 00:00.00 396K C++ 小美
7 2007-03-22 15:22:33 00:00.00 396K C++ 9911
8 2005-09-13 23:15:20 00:00.00 400K C Leave me alone
9 2007-06-09 01:02:54 00:00.00 400K C わたし
10 2006-02-05 11:36:41 00:00.00 420K C++ Crane
11 2006-01-30 17:48:16 00:00.00 424K C++ sunny
12 2007-03-17 12:40:31 00:00.00 836K C++ 谢奇
13 2007-04-15 20:18:50 00:00.00 836K C++ 连老天都感动地哭了
*/

// 2012-09-07 01:04:42 | Accepted | 1892 | C | 0 | 160 | watashi | Source
