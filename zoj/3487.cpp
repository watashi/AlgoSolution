#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>

const char* s[] = {"th", "st", "nd", "rd"};

int main() {
    int re, n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d", &n) == 1);
        assert(0 <= n && n < 1000000000);
        printf("%d%s\n", n, s[n / 10 % 10 != 1 && n % 10 < 4 ? n % 10 : 0]);
    }
    assert(scanf("%d", &n) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//466   2011-04-15 01:16:10     Accepted    A   C++     10  180     watashi     Source

// 2012-09-07 16:50:59 | Accepted | 3487 | C++ | 0 | 180 | watashi | Source
