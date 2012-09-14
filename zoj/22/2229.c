#include <stdio.h>
#include <math.h>
int main()
{
    int i,n,v;
    long t0,t,tm;
    const long d=4.5*3600;

    while(scanf("%d",&n),n){
        tm=99999;
        for(i=0;i<n;i++){
            scanf("%d%ld",&v,&t0);
            if(t0>=0){
                t=t0+(d+v-1)/v;
                if(t<tm) tm=t;
            }
        }
        printf("%ld\n",tm);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2508429 2007-07-03 17:13:10 Accepted 2229 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 03:09:39 | Accepted | 2229 | C | 0 | 160 | watashi | Source
