#include <stdio.h>
int main()
{
    long x,y,i,n;

    scanf("%ld",&n);
    for(i=1;i<=n;i++){
        scanf("%ld%ld",&x,&y);
        if((x==y||x==y+2)&&x%2==0) printf("%ld\n",x+y);
        else if((x==y||x==y+2)&&x%2!=0) printf("%ld\n",x+y-1);
        else printf("No Number\n");
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2441658 2007-05-17 21:33:22 Accepted 1414 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 03:01:01 | Accepted | 1414 | C | 0 | 160 | watashi | Source
