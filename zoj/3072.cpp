#include <cstdio>

int main()
{
    int n1, n2, n3, r;
    int tmp, ans;

    while (scanf("%d%d%d%d", &n1, &n2, &n3, &r) != EOF && r > 0) {
        ans = 100 * (n1 + n2 + n3);
        for (int i = 0; i * (r + 2) < 100 + r; i++) {
            tmp = 0;
            tmp += n1 * ((100 - i * (r + 2) + r - 1) / r + i);
            tmp += n3 * ((100 + r - 1) / r);
            tmp += n2 * ((100 - i * (r - 1) + r - 1) / r + i);
            // ans <?= tmp;
            if (tmp < ans) {
                ans = tmp;
            }
        }
        printf("%d\n", ans);
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750233   2009-01-28 15:48:10     Accepted    3072    C++     0   176     watashi@Zodiac

// 2012-09-07 02:00:06 | Accepted | 3072 | C++ | 0 | 180 | watashi | Source
