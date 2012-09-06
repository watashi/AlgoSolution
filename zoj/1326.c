#include <stdio.h>
int n,x,d[22],a[55];
int main()
{
    int i,j,k,t;
    int ri=0;

    while(scanf("%d%d",&n,&x)!=EOF){
        for(i=0;i<20;i++)
            scanf("%d",&d[i]);
        t=n;
        for(i=0;i<n;i++)
            a[i]=1;
        for(i=0;i<20&&x<t;i++){
            k=0;
            for(j=0;j<n&&x<t;j++){
                if(a[j]) k++;
                if(k==d[i]){a[j]=0;k=0;t--;}
            }
        }
        printf("Selection #%d\n",++ri);
        k=0;
        for(i=0;i<n;i++)
            if(a[i]){
                if(k) printf(" ");
                else k=1;
                printf("%d",i+1);
            }
        printf("\n\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2656748 2007-10-24 15:44:57 Accepted 1326 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 02:59:36 | Accepted | 1326 | C | 0 | 160 | watashi | Source
