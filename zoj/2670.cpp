/*
#include <stdio.h>
int main()
{
    int i,j,n;

    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            printf("0");
            for(j=1;j<n;j++)
                printf(" %d",(j<i)?0:(i+1));
            printf("\n");
        }
        printf("\n");
    }
}
*/
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2627369 2007-10-01 15:50:04 Accepted 2670 C 00:00.02 396K わたし
#include <stdio.h>
int main()
{
    int i,j,n;

    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            putchar('0');
            j=0;
            while(++j<i){putchar(' ');putchar('0');}
            while(j++<n){putchar(' ');putchar(i?'2':'1');}
            putchar('\n');
        }
        putchar('\n');
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2627377 2007-10-01 15:55:36 Accepted 2670 C 00:00.00 392K わたし

// 2012-09-07 01:33:44 | Accepted | 2670 | C++ | 0 | 180 | watashi | Source
