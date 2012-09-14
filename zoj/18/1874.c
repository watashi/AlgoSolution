#include <stdio.h>
int main()
{
    long a,b;
    int m,n,sum,count;

    while(scanf("%d%d",&a,&b),a||b){
        count=0;
        sum=0;
        do{
            sum+=a%10;
            sum+=b%10;
            a/=10;
            b/=10;
            if(sum<10) sum=0;
            else{
                sum=1;
                count++;
            }
        }while(a||b);
        switch(count){
        case 0:printf("No carry operation.\n");break;
        case 1:printf("1 carry operation.\n");break;
        default:printf("%d carry operations.\n",count);break;
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2468897 2007-05-28 23:46:22 Accepted 1874 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:06:18 | Accepted | 1874 | C | 0 | 160 | watashi | Source
