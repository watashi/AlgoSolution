// CONCRETE MATHEMATICS
// 1.3 the Josephus Problem (Page8-16)

#include <cstdio>

int J(int n)
{
    if(n == 1) return 1;
    else if(n & 1) return (J(n >> 1) << 1) + 1;
    else return (J(n >> 1) << 1) - 1;
}

int main(void)
{
    int a, e;
    while(scanf("%de%d", &a, &e) != EOF) {
        while(e--) a *= 10;
        if(a == 0) break;
        printf("%d\n", J(a));
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2748706 2008-02-11 20:30:43 Accepted 2239 C++ 00:00.00 432K ¤ï¤¿¤·

// 2012-09-07 01:16:44 | Accepted | 2239 | C++ | 0 | 180 | watashi | Source
