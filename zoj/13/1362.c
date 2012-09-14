#include <stdio.h>
int main()
{
    int ri=0,i,j,k,m,n,a[55],b,c;

    while(scanf("%d%d",&m,&n),m){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            k=i;
            for(j=i+1;j<n;j++)
                if(a[j]>a[k]) k=j;
            b=a[k];a[k]=a[i];a[i]=b;
        }
        b=m*n;c=0;
        for(i=0;i<n;i++)
            if(a[i]==b){b--;c++;}
            else{b-=2;}
        printf("Case %d: %d\n",++ri,c);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2584232 2007-08-26 00:40:30 Accepted 1362 C 00:00.00 392K わたし */
/* //2584231 2007-08-26 00:40:15 Accepted 1362 C++ 00:00.00 392K わたし */

// 2012-09-07 03:00:12 | Accepted | 1362 | C | 0 | 160 | watashi | Source
