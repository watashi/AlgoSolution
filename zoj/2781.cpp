#include <stdio.h>
int main()
{
    int re,t,x,len;


    scanf("%d",&re);
    while(re--){
        scanf("%d",&x);
        len=0;
        while(x>=10){
            t=x%10;
            x/=10;
            len++;
            if(t>=5) x++;
        }
        putchar('0'+x);
        while(len--) putchar('0');
        putchar('\n');
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2592844 2007-09-02 03:08:30 Accepted 2781 C 00:00.00 388K ¤ï¤¿¤·

// 2012-09-07 01:39:32 | Accepted | 2781 | C++ | 0 | 180 | watashi | Source
