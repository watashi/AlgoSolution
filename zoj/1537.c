#include <stdio.h>
#include <string.h>
int mod[1000];
int main()
{
    int f,d,t,k;


    while(scanf("%d",&k)!=EOF){
        memset(mod,0,sizeof(mod));
        for(f=1;f<=9;f++){
            t=d=0;
            do{
                d++;
                t*=10;
                t+=f;
                t%=k;
                if(mod[t]) break;
                else mod[t]=1;
            }while(t);
            if(t==0) break;
        }
        if(f<10) printf("%d %d\n",f,d);
        else printf("-1\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2661254 2007-10-28 17:05:27 Accepted 1537 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:02:08 | Accepted | 1537 | C | 0 | 164 | watashi | Source
