// GRAYÂë

#include <cstdio>

int main(void)
{
    int i, n, a;

    while(scanf("%d%d", &n, &a) != EOF && n > 0) {
        printf("%d", a ^ (a >> 1));
        for (i = a + 1; i < n; i++)
            printf(" %d", i ^ (i >> 1));
        for (i = 0; i < a; i++)
            printf(" %d", i ^ (i >> 1));
        printf("\n");
    }
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795728 2008-03-21 22:39:06 Accepted 2531 C++ 00:00.07 388K ¤ï¤¿¤·

// 2012-09-07 01:27:03 | Accepted | 2531 | C++ | 20 | 180 | watashi | Source
