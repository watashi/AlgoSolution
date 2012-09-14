#include <stdio.h>
#include <math.h>
int main()
{
    long count;
    long gcd,lcm,x;
    int i,j,k,np,p[500]={2};

    for(k=0,i=3;i<1001;i+=2){
        for(j=3;j<=p[k];j+=2)
            if(i%j==0) break;
        if(j>p[k]) p[++k]=i;
    }
    np=k+1;
    while(scanf("%ld %ld",&gcd,&lcm)!=EOF){
        if(lcm%gcd!=0) printf("0\n");/*天下没有不贱的题目——watashi*/
        else{
            count=1;
            x=lcm/gcd;
            for(i=0;p[i]<=x&&i<np;i++){
                if(x%p[i]==0){
                    do{
                        x/=p[i];
                    }while(x%p[i]==0);
                    count*=2;
                }
            }
            if(x!=1) count*=2;
            printf("%ld\n",count);
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2500267 2007-06-22 18:15:03 Accepted 1577 C 00:00.00 400K わたし */

// 2012-09-07 03:02:39 | Accepted | 1577 | C | 0 | 160 | watashi | Source
