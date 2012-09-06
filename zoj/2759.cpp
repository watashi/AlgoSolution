#include <stdio.h>
int tri[20]={1};
int main()
{
    int i,n,a[22],b[22];

    for(i=1;i<20;i++)
        tri[i]=tri[i-1]*3;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<20;i++){
            a[i]=n/tri[i]%3;
            b[i]=0;
        }
        for(i=0;i<20;i++){
            if(a[i]==1) b[i]=1;
            else if(a[i]==2){b[i]=-1;a[i+1]++;}
            else if(a[i]==3){a[i]=0;a[i+1]++;}
        }
        n=0;
        for(i=0;i<20;i++)
            if(b[i]==-1){
                if(n) printf(" ");
                else n=1;
                printf("%d",tri[i]);
            }
        if(!n) printf("-1");
        printf("\n");
        n=0;
        for(i=0;i<20;i++)
            if(b[i]==1){
                if(n) printf(" ");
                else n=1;
                printf("%d",tri[i]);
            }
        if(!n) printf("-1");
        printf("\n");
        printf("\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2626812 2007-10-01 04:00:44 Accepted 2759 C 00:00.10 392K ¤ï¤¿¤·

// 2012-09-07 01:38:19 | Accepted | 2759 | C++ | 40 | 180 | watashi | Source
