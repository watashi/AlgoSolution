#include <stdio.h>
int main()
{
    int i,n,a,b,c,d;
    int re;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        d=-1;
        a=0;
        for(i=1;i<n;i++){
            scanf("%d",&b);
            if(i>1&&i<n-1&&(d==-1||b-a<c)){
                    c=b-a;
                    d=i;
            }
            a=b;
        }
        if(d==-1) printf("0\n");
        else{
            printf("%d\n",b+c);
            printf("%d %d %d %d\n",d+1,1,n,d);
        }
        if(re) printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2651403 2007-10-20 10:17:21 Accepted 2433 C 00:00.20 392K ¤ï¤¿¤· */

// 2012-09-07 01:23:22 | Accepted | 2433 | C | 70 | 160 | watashi | Source
