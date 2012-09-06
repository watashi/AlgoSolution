#include <stdio.h>
int main()
{
    int i,n,t,a[6];

    while(1){
        n=0;
        for(i=0;i<6;i++){
            scanf("%d",&a[i]);
            n+=a[i];
        }
        if(n==0) break;
        n=a[5];
        if(a[4]){
            n+=a[4];
            t=11*a[4];
            a[0]-=t;
        }
        if(a[3]){
            n+=a[3];
            t=5*a[3];
            a[1]-=t;
            if(a[1]<0){t=-4*a[1];a[1]=0;a[0]-=t;}
        }
        if(a[2]){
            n+=a[2]/4;
            if(t=a[2]%4){
                n++;
                switch(t){
                case 1:a[1]-=5;t=7;break;
                case 2:a[1]-=3;t=6;break;
                case 3:a[1]-=1;t=5;break;
                }
                if(a[1]<0){t+=-4*a[1];a[1]=0;}
                a[0]-=t;
            }
        }
        if(a[1]){
            n+=a[1]/9;
            if(t=a[1]%9){n++;t=36-4*t;a[0]-=t;}
        }
        if(a[0]>0){
            n+=(a[0]+35)/36;
        }
        printf("%d\n",n);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2552194 2007-08-03 21:29:39 Accepted 1307 C 00:00.02 392K ¤ï¤¿¤· */

// 2012-09-07 02:59:05 | Accepted | 1307 | C | 0 | 160 | watashi | Source
