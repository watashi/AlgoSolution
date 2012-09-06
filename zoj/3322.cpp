#include <cstdio>
#include <cstring>

int main() {
    int re, c;
    char a[16], b[16];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf(" %10[0-9 ] %10[0-9 ]", a, b);
        c = strcmp(a, b);
        puts(c < 0 ? "javaman" : c > 0 ? "cpcs" : "same");
    }
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2168611   2010-04-19 00:49:53     Accepted    3322    C++     0   176     watashi@Zodiac

// 2012-09-07 02:07:51 | Accepted | 3322 | C++ | 0 | 180 | watashi | Source
