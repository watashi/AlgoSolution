#include <stdio.h>
int main()
{
    int i,j,k,n,ri,repeat;
    long money[10001];

    scanf("%d",&repeat);
    money[0]=0;
    k=1;
    j=0;
    for(i=1;i<10001;i++){
        if(j<k) j++;
        else{
            k++;
            j=1;
        }
        money[i]=money[i-1]+k;
    }
    for(ri=0;ri<repeat;ri++){
        if(ri) printf("\n");
        while(scanf("%d",&n),n)
            printf("%d %ld\n",n,money[n]);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2478922 2007-06-04 00:15:18 Accepted 2345 C 00:00.00 428K ¤ï¤¿¤· */

// 2012-09-07 01:20:12 | Accepted | 2345 | C | 0 | 160 | watashi | Source
