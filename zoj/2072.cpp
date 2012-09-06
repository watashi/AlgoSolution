// CONCRETE MATHEMATICS
// 1.3 the Josephus Problem
// Page8-16

#include <cstdio>

long long J(long long n)
{
    if(n == 1)
        return 1;
    else if(n & 1)
        return 2 * J(n / 2) + 1;
    else
        return 2 * J(n / 2) - 1;
}

int main(void)
{
    long long pre, tmp, cnt;

    while(scanf("%lld%lld", &tmp, &cnt) != EOF) {
        for (int i = 0; i < cnt; i++) {
            pre = tmp;
            tmp = J(tmp);
            if(tmp == pre) break;
        }
        printf("%lld\n", tmp);
    }
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2771858 2008-03-05 22:30:07 Accepted 2072 C++ 00:00.02 440K ¤ï¤¿¤·

// 2012-09-07 01:12:05 | Accepted | 2072 | C++ | 10 | 180 | watashi | Source
