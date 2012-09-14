/*n*(1/prime-1)*(1/prime-1)..*/
#include <stdio.h>
int main()
{
    long n,p[3500]={2};
    int i,j,k,np;
    long count;

    k=1;
    for(i=3;i<32000;i+=2){
        for(j=1;j<k;j++)
            if(i%p[j]==0) break;
        if(j>=k) p[k++]=i;
    }
    np=k;
    while(scanf("%ld",&n),n){
        count=n;
        for(i=0;p[i]<n&&i<np;i++){
            if(n%p[i]==0){
                count-=count/p[i];
                do{
                    n/=p[i];
                }while(n%p[i]==0);
            }
        }
        if(n!=1) count-=count/n;
        printf("%ld\n",count);
    }

    return 0;   /* NZEC */
}

/* //2502181 2007-06-24 22:29:04 Accepted 1906 C 00:00.18 420K ¤ï¤¿¤· */

// 2012-09-07 03:06:54 | Accepted | 1906 | C | 70 | 160 | watashi | Source
