#include <stdio.h>
int main()
{
    long sum;
    int t;
    unsigned int i,j,n,a,eol;
    union{
        int m: 4;
        unsigned int n: 4;
    }b[2];

    while(scanf("%d",&n)!=EOF){
        printf("%d\n",n/2);
        sum=j=eol=0;
        for(i=1;i<n;i++){
            scanf("%x",&a);
            t=a-sum;
            if(t<-8) b[j].m=-8;
            else if(t>7) b[j].m=7;
            else b[j].m=t;
            sum+=b[j].m;
            if(j){
                eol++;
                printf("%02x",16*b[0].n+b[1].n);
                j=0;
                if(eol==8) {printf("\n");eol=0;}
                else printf(" ");
            }
            else j=1;
        }
        scanf("%x",&a);
        t=a-sum;
        if(t<-8) b[j].m=-8;
        else if(t>7) b[j].m=7;
        else b[j].m=t;
        printf("%02x\n",16*b[0].n+b[1].n);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2496238 2007-06-18 17:47:26 Accepted 1493 C 00:00.04 388K ¤ï¤¿¤· */

// 2012-09-07 03:01:44 | Accepted | 1493 | C | 10 | 160 | watashi | Source
