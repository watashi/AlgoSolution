#include <cstdio>

int main() {
    int re;
    bool flag;
    long long n, x, y, w, h;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lld%lld%lld%lld%lld", &n, &x, &y, &w, &h);
        for (long long i = y; i < y + h; ++i) {
            for (long long j = x; j < x + w; ++j) {
                flag = false;
                for (long long m = n >> 1; m > 0; m >>= 1) {
                    if (i & j & m) {
                        flag = !flag;
                    }
                }
                if (flag) {
                    putchar('-');
                }
                putchar('1');
                putchar(j == x + w - 1 ? '\n' : ' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1746041   2009-01-21 00:44:34     Accepted    3084    C++     50  176     watashi@Zodiac

// 2012-09-07 02:01:07 | Accepted | 3085 | C++ | 0 | 180 | watashi | Source
