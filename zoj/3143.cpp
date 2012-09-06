#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

char* next(long long x)
{
    static char buf[1024];
    size_t p = 0;

    for (int i = 9; i >= 2; i--) {
        while (x % i == 0) {
            buf[p++] = '0' + i;
            x /= i;
        }
    }
    if (x == 1) {
        buf[p] = '\0';
        reverse(buf, buf + p);
        return buf;
    }
    else {
        return NULL;
    }
}

int main()
{
    int re;
    long long x;
    char *p;

    scanf("%d", &re);
    while (re--) {
        scanf("%lld", &x);
        p = next(x);
        if (p == NULL) {
            puts("No sequence");
            continue;
        }
        printf("%lld", x);
        for (int i = 2; i <= 10 && p != NULL; i++) {
            printf(" %s", p);
            p = next(atoll(p));
        }
        putchar('\n');
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750177   2009-01-28 15:14:19     Accepted    3143    C++     10  176     watashi@Zodiac

// 2012-09-07 02:03:15 | Accepted | 3143 | C++ | 10 | 180 | watashi | Source
