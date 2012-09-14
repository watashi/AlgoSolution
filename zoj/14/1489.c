#include <stdio.h>
int main()
{
    int i,j,out,a[40000];/*if 1000 wa!!*/
    long n;

    while(scanf("%d",&n)!=EOF){
        if(n%2==0) printf("2^? mod %ld = 1\n",n);
        else{
            i=out=0;
            a[i]=1;
            for(i=1;i<40000&&!out;i++){
                a[i]=(2*a[i-1])%n;
                for(j=0;j<i;j++)
                    if(a[i]==a[j]){
                        out=1;
                        break;
                    }
            }
            if(a[i-1]==1) printf("2^%d mod %ld = 1\n",i-1,n);
            else printf("2^? mod %ld = 1\n",n);
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2487341 2007-06-10 04:34:47 Accepted 1489 C 00:00.91 548K ¤ï¤¿¤· */

// 2012-09-07 03:01:38 | Accepted | 1489 | C | 480 | 160 | watashi | Source
