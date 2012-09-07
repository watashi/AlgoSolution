#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    double a,b,r1,r2;

    while(scanf("%lf%lf%lf%lf",&a,&b,&r1,&r2)!=EOF){//!=EOF important
        if(a-r1-r2>=0&&b-r1-r2>=0&&(r1+r2)*(r1+r2)<=(a-r1-r2)*(a-r1-r2)+(b-r1-r2)*(b-r1-r2))
            printf("Yes\n");
        else
            printf("No\n");
    }
}

/*DONE*/
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2470028 2007-05-29 16:42:17 Accepted 1608 C 00:00.00 388K ¤ï¤¿¤·

// 2012-09-07 14:08:53 | Accepted | 1608 | C++ | 0 | 180 | watashi | Source
