#include <stdio.h>
#include <string.h>
int a[2002];
int main()
{
    int i,j,k,l,n,m;

    while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,0,n*sizeof(int));
        i=0;
        for(l=n;l;l--){
            k=m%l+1;
            j=0;
            while(1){
                if(!a[i]){
                    j++;
                    if(j==k) break;
                }
                i++;
                if(i==n) i=0;
            }
            a[i]=n-l+1;
            i++;
            if(i==n) i=0;
        }
        printf("%d",a[0]);
        for(i=1;i<n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2659561 2007-10-26 20:12:56 Accepted 1487 C 00:00.42 396K ¤ï¤¿¤· */

// 2012-09-07 03:01:32 | Accepted | 1487 | C | 500 | 168 | watashi | Source
