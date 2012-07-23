#include <cstdio>

int main() {
    int re, n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        printf("%d\n", n / 2048 + __builtin_popcount(n & 2047));
    }

    return 0;
}

