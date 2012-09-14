#include <stdio.h>
int main()
{
    int a,b,c,t,u,d;
    int su,cu,sd,cd;

    while(scanf("%d",&a)!=EOF && a){
        c=u=d=0;
        su=cu=sd=cd=0;
        t=1;
        while(scanf("%d",&b)!=EOF){
            c++;
            if(b==a){t++;continue;}
            if(b==0){
                if(u){cu++;su+=u+t-1;}
                if(d){cd++;sd+=d+t-1;}
                break;
            }
            if(u==0&&d==0){
                if(b>a) u=t;
                else d=t;
            }
            else if(b>a){
                if(d){cd++;sd+=d+t-1;d=0;u=1;}
                else u+=t;
            }
            else{
                if(u){cu++;su+=u+t-1;u=0;d=1;}
                else d+=t;
            }
            a=b;
            t=1;
        }
        if(!cu) cu=1;
        if(!cd) cd=1;
        printf("Nr values = %d:  %.6f %.6lf\n",c,(double)su/cu,(double)sd/cd);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2630957 2007-10-04 00:14:57 Accepted 1338 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 00:46:24 | Accepted | 1338 | C | 0 | 160 | watashi | Source
