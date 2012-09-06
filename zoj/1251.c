#include <stdio.h>
int main()
{
    int ri,i,n,sum,average,a[50];

    ri=0;
    while(scanf("%d",&n),n){
        ri++;
        sum=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        average=sum/n;
        sum=0;
        for(i=0;i<n;i++)
            if(a[i]>average) sum+=(a[i]-average);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",ri,sum);
    }
}
/*EASY*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469468 2007-05-29 12:13:56 Accepted 1251 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 00:43:15 | Accepted | 1251 | C | 0 | 160 | watashi | Source
