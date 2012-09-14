#include <cmath>
#include <cstdio>
#include <cstdlib>

const int MAXN = 128;

int minCost(int a[], int n) {
    int s, t, p;

    s = t = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }
    for (int i = 0; i < n; ++i) {
        t += a[i];
        if (2 * t >= s) {
            p = i;
            break;
        }
    }
    t = 0;
    for (int i = 0; i < n; ++i) {
        t += abs(p - i) * a[i];
    }

    return t;
}

int main() {
    int re, r, c, a;
    int sr[MAXN], sc[MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; ++i) {
            sr[i] = 0;
        }
        for (int j = 0; j < c; ++j) {
            sc[j] = 0;
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                scanf("%d", &a);
                sr[i] += a;
                sc[j] += a;
            }
        }
        printf("%d blocks\n",
            minCost(sr, r) + minCost(sc, c));
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1746038   2009-01-21 00:42:49     Accepted    3082    C++     20  176     watashi@Zodiac

// 2012-09-07 02:00:48 | Accepted | 3082 | C++ | 20 | 180 | watashi | Source
