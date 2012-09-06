#include <stdio.h>
int main()
{
    int ri,repeat,i;
    long n;

    scanf("%d",&repeat);
    for(ri=1;ri<=repeat;ri++){
        scanf("%ld",&n);
        i=0;
        while(n%2==0){
            n=n/2;
            i++;
        }
        printf("%ld %d\n",n,i);
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2444973 2007-05-18 23:08:27 Accepted 1382 C++ 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:00:31 | Accepted | 1382 | C | 0 | 160 | watashi | Source
