#include <stdio.h>
#include <math.h>
int main()
{
    long n,num,a[4500]={0};
    int i,na;

    i=1;
    do{
        a[i]=a[i-1]+i;
    }while(a[i++]<10000000);
    na=i;
    while(scanf("%ld",&n)!=EOF){
        num=n;
        i=na;
        while(a[--i]>=n);
        n-=a[i];
        if(i%2) printf("TERM %ld IS %d/%d\n",num,n,i+2-n);
        else printf("TERM %ld IS %d/%d\n",num,i+2-n,n);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2502841 2007-06-25 23:54:08 Accepted 2185 C 00:00.00 408K gl hf */

// 2012-09-07 03:09:08 | Accepted | 2185 | C | 0 | 160 | watashi | Source
