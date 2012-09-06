# include<stdio.h>
int main()
{
    int i,j,k,n,N,c,prime[300]={1,2};

    k=2;
    for(i=3;i<=1111;i+=2){
        for(j=3;j*j<=i;j+=2)
            if(i%j==0) break;
            if(j*j>i){
                prime[k]=i;
                k++;
            }
    }
    while(scanf("%d %d",&N,&c)!=EOF){
        printf("%d %d:",N,c);
        for(i=0;;i++)
            if(prime[i]>N) break;
        n=i;
        /*If the size of the center list exceeds the limits of the list of prime numbers between 1 and N,*/
        if(c>n/2){
            for(i=0;i<=n-1;i++)
                printf(" %d",prime[i]);
        }
        else if(n%2==0){
            for(i=n/2-c;i<=n/2+c-1;i++)
                printf(" %d",prime[i]);
        }
        else{
            for(i=n/2+1-c;i<=n/2+c-1;i++)
                printf(" %d",prime[i]);
        }
        printf("\n\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469474 2007-05-29 12:16:05 Accepted 1312 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 02:59:11 | Accepted | 1312 | C | 0 | 160 | watashi | Source
