/*“Ú Ω2°∂=5£ª«Û5&10(zai5zhong)*/
#include <stdio.h>
int main()
{
    long i,n,x,res;

    scanf("%ld",&n);
    for(i=0;i<n;i++){
        scanf("%ld",&x);
        res=0;
        do{
            res+=x/=5;
        }while(x);
        printf("%ld\n",res);
    }

    return 0;   /* NZEC */
}

/* //2489497 2007-06-12 17:13:40 Accepted 2022 C 00:00.16 388K §Ô§ø§∑ */

// 2012-09-07 03:07:55 | Accepted | 2022 | C | 50 | 160 | watashi | Source
