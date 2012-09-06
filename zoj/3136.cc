#include <cstdio>

const double eps = 1e-8;
int a[32], b[32];

double gao(int n, int y)
{
    int ret = 0;

    for (int i = 0; i < n; i++) {
        ret += (double)(y - b[i]) / a[i];
    }

    return ret;
}

bool gen(int n, int y, int m)
{
    int ret = 0;

    for (int i = 0; i < n; i++) {
        if ((y - b[i]) % a[i] != 0 || (y - b[i]) / a[i] < 0) {
            return false;
        }
        else {
            ret += (y - b[i]) / a[i];
        }
    }

    return ret == m;
}

int main() {
    int re, n, m;
    int l, r, mid;

    scanf("%d", &re);
    while (re--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i], &b[i]);
        }
        scanf("%d", &m);

        l = 0;
        r = 1000000;
        while (l < r) {
            mid = (l + r) / 2;
            if (gao(n, mid) + eps >= m) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        printf("%d\n", gen(n, r, m) ? r : 0);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750161   2009-01-28 14:56:14     Accepted    3136    C++     0   176     watashi@Zodiac

// 2012-09-07 02:02:51 | Accepted | 3136 | C++ | 0 | 180 | watashi | Source
