#include <cstdio>

int main() {
    int re, a, b;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%*d%d%d", &a, &b);
        puts(a > b ? "A" : "B");
    }

    return 0;
}

// 2012-09-07 02:08:46 | Accepted | 3333 | C++ | 0 | 180 | watashi | Source
