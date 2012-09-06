#include <stdio.h>
int main()
{
    int i,m,n;

    i=0;
    while(scanf("%d%d",&m,&n),m||n){
        printf("Hole #%d\n",++i);
        if(n==1) printf("Hole-in-one.\n\n");
        else if(n==m) printf("Par.\n\n");
        else if(n==m-1) printf("Birdie.\n\n");
        else if(n==m-2) printf("Eagle.\n\n");
        else if(n<=m-3) printf("Double Eagle.\n\n");
        else if(n==m+1) printf("Bogey.\n\n");
        else if(n>=m+2) printf("Double Bogey.\n\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2471064 2007-05-30 00:07:07 Accepted 1294 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 00:44:53 | Accepted | 1294 | C | 0 | 160 | watashi | Source
