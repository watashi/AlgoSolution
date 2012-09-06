#include <stdio.h>
int main()
{
    float a,b;

    scanf("%f",&a);
    while(scanf("%f",&b),b!=999){
        printf("%.2f\n",b-a);
        a=b;
    }
    printf("End of Output\n");
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2475716 2007-06-01 23:49:25 Accepted 1763 C 00:00.00 388K ¤ï¤¿¤·

// 2012-09-07 01:00:19 | Accepted | 1763 | C++ | 0 | 180 | watashi | Source
