#include <stdio.h>
#include <string.h>
#define dd(x,y,xx,yy) ((x-xx)*(x-xx)+(y-yy)*(y-yy))
int main()
{
    int flag;
    double x,y,xx,yy,xt,yt;
    char str[20];

    while(scanf("%lf%lf%lf%lf ",&x,&y,&xx,&yy)!=EOF){
        flag=0;
        while(gets(str)&&*str){
            if(flag) continue;
            sscanf(str,"%lf%lf",&xt,&yt);
            if(4*dd(x,y,xt,yt)<dd(xx,yy,xt,yt)){
                flag=1;
                *(strchr(str,' '))=',';
                printf("The gopher can escape through the hole at (%s).\n",str);
            }
        }
        if(!flag) printf("The gopher cannot escape.\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2662171 2007-10-29 20:15:57 Accepted 1860 C 00:00.01 396K ¤ï¤¿¤· */

// 2012-09-07 03:05:44 | Accepted | 1860 | C | 0 | 160 | watashi | Source
