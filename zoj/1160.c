#include <stdio.h>
int main()
{
    int i,n,re,a,b,c,d,day;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        re=0;
        if(i) printf("\n");
        while(scanf("%d%d%d%d",&a,&b,&c,&d),a>=0){
            a%=23;
            b%=28;
            c%=33;
            day=c-33;
            while(1){
                day+=33;
                if(day%23==a&&day%28==b) break;
            }
            day=day-d;
            if(day<=0) day+=21252;
            printf("Case %d: the next triple peak occurs in %d days.\n",++re,day);
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2501904 2007-06-24 15:41:00 Accepted 1160 C 00:00.06 392K ¤ï¤¿¤· */

// 2012-09-07 02:57:04 | Accepted | 1160 | C | 10 | 160 | watashi | Source
