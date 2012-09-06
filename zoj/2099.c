#include <stdio.h>
int main()
{
    int x,y,x1,x2,y1,y2;

    while(scanf("%d%d",&x1,&y1),x1||y1){
        x2=x1;y2=y1;
        while(scanf("%d%d",&x,&y),x||y){
            if(x<x1) x1=x;
            else if(x>x2) x2=x;
            if(y<y1) y1=y;
            else if(y>y2) y2=y;
        }
        printf("%d %d %d %d\n",x1,y1,x2,y2);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2534728 2007-07-25 09:04:51 Accepted 2099 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:08:14 | Accepted | 2099 | C | 0 | 160 | watashi | Source
