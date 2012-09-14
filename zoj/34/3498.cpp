#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>

int main() {
    int re, n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d", &n) == 1 && n > 0);
        printf("%d\n", 32 - __builtin_clz(n));
    }
    assert(scanf("%d", &re) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//479   2011-04-15 01:55:27     Accepted    L   C++     0   180     watashi     Source

// 2012-09-07 16:02:17 | Accepted | 3498 | C++ | 0 | 180 | watashi | Source
