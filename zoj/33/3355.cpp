#include <algorithm> // auto fix CE
#include <cstdio>

int main() {
    int re;
    int a, b;
    long long c[3];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        for (int i = 0; i < 3; ++i) {
            scanf("%d.%d", &a, &b);
            c[i] = a * 100 + b;
        }
        // printf("%lld %lld\n", c[0] * c[1] * c[2], 100 * (c[0] * c[1] + c[1] * c[2] + c[2] * c[0]));
        if (c[0] * c[1] * c[2] > 100 * (c[0] * c[1] + c[1] * c[2] + c[2] * c[0])) {
            puts("Aha");
        } else {
            puts("No way");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//581   2010-07-16 19:47:01     Accepted    1069    C++     30  180     anotherpeg  Source

// 2012-09-07 15:48:09 | Accepted | 3355 | C++ | 10 | 180 | watashi | Source
