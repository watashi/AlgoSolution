#include <cstdio>

int main() {
    int n;

    while (scanf("%d", &n) != EOF && n > 0) {
        printf("%d\n", n >> 1);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2168613   2010-04-19 00:53:45     Accepted    3328    C++     0   176     watashi@Zodiac

// 2012-09-07 02:08:21 | Accepted | 3328 | C++ | 0 | 180 | watashi | Source
