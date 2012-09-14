#include <stdio.h>
int main()
{
    int re,i,n,j,k,t,a[2][108],aa,bb;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&n,&k);
        aa=0;
        bb=1;
        for(j=0;j<k;j++)
            a[aa][j]=a[bb][j]=-1;
        a[aa][0]=0;
        for(i=0;i<n;i++){
            scanf("%d",&t);
            for(j=0;j<k;j++)
                if(a[aa][j]==i) a[bb][abs(j+t)%k]=a[bb][abs(j-t)%k]=i+1;
            aa=1-aa;
            bb=1-bb;
        }
        if(a[aa][0]==n) printf("Divisible\n");
        else printf("Not divisible\n");
        if(re) printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2549884 2007-08-02 18:15:49 Accepted 2042 C 00:00.36 392K ¤ï¤¿¤· */

// 2012-09-07 01:11:16 | Accepted | 2042 | C | 280 | 160 | watashi | Source
