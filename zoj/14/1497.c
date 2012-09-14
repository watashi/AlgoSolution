#include <stdio.h>
int n,k,i,f,t,x,a[33];
int c[33],cc,ccc;
int main()
{
    char str[4];

    while(scanf("%d%d",&n,&k)==2 && n){
        for(i=0;i<n;i++){
            scanf("%s",str);
            if(str[0]=='L') a[i]=-1;
            else a[i]=1;
            c[i]=0;
        }
        f=0;
        t=k-1;
        c[t]=1;
        cc=1;
        ccc=1;
        while(cc<n){
            ccc++;
            x=f+a[t];
            if(x==-1) x=n-1;
            else if(x==n) x=0;
            if(x==t){
                x=t+a[t];
                if(x==-1) x=n-1;
                else if(x==n) x=0;
            }
            if(!c[x]){c[x]=1;cc++;}
            a[t]=-a[t];
            f=t;
            t=x;
            /*printf("%d ",x);*/
        }
        printf("Classmate %d got the ball last after %d tosses.\n",t+1,ccc);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2660181 2007-10-27 13:57:26 Accepted 1497 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:01:56 | Accepted | 1497 | C | 0 | 160 | watashi | Source
