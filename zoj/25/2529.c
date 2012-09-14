/* //1.十进制互转;2.加法器; */

#include <stdio.h>
int main()
{
    int prime[27]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,
        43,47,53,59,61,67,71,73,79,83,89,97,101};
    int a[55],b[55],sum[27]={-1},i,m,n,max;
    char ch;

    while(i=1,scanf("%d",&a[25-i])!=EOF){
        while((ch=getchar())==','){
            i++;
            scanf("%d",&a[25-i]);
        }
        m=i;
        i=1;
        scanf("%d",&b[25-i]);
        while((ch=getchar())==','){
            i++;
            scanf("%d",&b[25-i]);
        }
        n=i;
        max=m>n?m:n;
        for(i=0;i<max;i++)
            a[25+i]=b[25+i]=0;
        for(i=1;i<=max+1;i++){
            sum[i]=a[24-m+i]+b[24-n+i];
            if(sum[i-1]>=prime[i-1]){
                sum[i]+=1;
                sum[i-1]-=prime[i-1];
            }
        }
        if(sum[max+1]!=0) printf("%d,",sum[max+1]);
        for(i=max;i>1;i--)
            printf("%d,",sum[i]);
        printf("%d\n",sum[1]);
    }

    return 0;   /* NZEC */
}

/*EOF??*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2470088 2007-05-29 17:00:44 Accepted 2529 C 00:00.00 392K わたし */

// 2012-09-07 03:11:29 | Accepted | 2529 | C | 0 | 160 | watashi | Source
