#include <stdio.h>
#define MAXL 1000000
/* long xways[MAXL+1]={1,2,4}; */
/* collect2: ld terminated with signal 25 [File size limit exceeded] */
long xways[MAXL + 1];
long count;
int main()
{
    int i;
    long re,x;

    xways[0] = 1;
    xways[1] = 2;
    xways[2] = 4;
    for(i=1;i<=MAXL;i++){
        xways[i]=(xways[i-1]+xways[i/2])%1000000;/*why??*/
    }
    scanf("%ld",&re);
    while(re--){
        scanf("%ld",&x);
        printf("%ld\n",xways[x/2]);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2495725 2007-06-18 00:17:09 Accepted 2872 C 00:00.06 4296K ¤ï¤¿¤· */

// 2012-09-07 14:33:27 | Accepted | 2872 | C | 10 | 4064 | watashi | Source
