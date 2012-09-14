/*
#include <stdio.h>
int main()
{
    int i,j,n,a[88];
    char ch[88];
    long count;

    while(scanf("%d",&n),n){
        scanf("%s",ch);
        for(i=0;i<n;i++){
            a[i]=ch[i]-'A';
            for(j=0;j<i;j++)
                if(ch[i]>ch[j]) a[i]--;
        }
        count=0;
        for(i=0;i<n;i++){
            count*=(26-i);
            count+=a[i];
        }
        printf("%ld\n",count);
    }
}
*/
#include <stdio.h>
int main()
{
    int i,j,n,l,a[88];
    char ch[88];
    long count[10];

    while(scanf("%d",&n),n){
        scanf("%s",ch);
        for(i=0;i<n;i++){
            a[i]=ch[i]-'A';
            for(j=0;j<i;j++)
                if(ch[i]>ch[j]) a[i]--;
        }
        count[0]=count[1]=0;
        l=1;
        for(i=0;i<n;i++){
            for(j=0;j<l;j++)
                count[j]*=(26-i);
            count[0]+=a[i];
            for(j=0;j<l;j++)
                if(count[j]>=10000000){count[j+1]+=count[j]/10000000;count[j]%=10000000;}
            if(count[l]) count[++l]=0;
        }
        printf("%ld",count[l-1]);
        for(i=l-2;i>=0;i--)
            printf("%07ld",count[i]);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2507163 2007-07-01 16:00:14 Accepted 2842 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:13:49 | Accepted | 2842 | C | 0 | 160 | watashi | Source
