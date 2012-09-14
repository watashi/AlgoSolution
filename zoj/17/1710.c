#include <stdio.h>
int main()
{
    int t;
    float h,u,d,f,x;

    while(scanf("%f%f%f%f",&h,&u,&d,&f),h){
        x=0;
        t=0;
        while(1){
            if(t*f<100) x+=u*(1-t*f/100);
            t++;
            if(x>h) break;
            x-=d;
            if(x<0) break;
        }
        if(x>h) printf("success on day %d\n",t);
        else printf("failure on day %d\n",t);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2497231 2007-06-19 17:51:27 Accepted 1710 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:03:54 | Accepted | 1710 | C | 0 | 160 | watashi | Source
