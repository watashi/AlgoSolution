#include <stdio.h>
int main()
{
    int ri,repeat,i,n,bit[20];
    long num;

    scanf("%d", &repeat);
    for(ri=1; ri<=repeat; ri++){
        scanf("%ld",&num);
        i=0;
        while(num){
            bit[i]=num%2;
            num/=2;
            i++;
        }
        n=i;
        for(i=0;i<n-1;i++)
            if(bit[i]) printf("%d ",i);
        printf("%d",i);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2448621 2007-05-20 02:03:50 Accepted 1383 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:00:37 | Accepted | 1383 | C | 0 | 160 | watashi | Source
