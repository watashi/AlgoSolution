#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1024;

int dp[512];

void init()
{
    dp[0] = 0;
    for (int i = 1; i < 512; i++) {
        dp[i] = inf;
        for (int j = 0; j < i; j++) {
            int tmp1 = dp[max(0, j - 1)] + dp[max(0, i - 1 - j)];
            int tmp2 = dp[max(0, j)] + dp[max(0, i - 2 - j)];
            dp[i] = min(dp[i], max(tmp1, tmp2));
        }
        ++dp[i];
//      if (i <= 12) printf("%d\n", dp[i]);
    }
}

int n, m;
bool a[512];

int main(void)
{
    int x, y;

    init();
    while (scanf("%d%d", &n, &m) != EOF) {
        fill(a, a + n, false);
        while (m--) {
            scanf("%d%d", &x, &y);
            if (x > y) {
                swap(x, y);
            }
            if (y == x + 1) {
                a[x] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ) {
            if (a[i]) {
                int j;
                for (j = i; a[j]; ++j);
                ans += dp[j - i];
                i = j + 1;
            }
            else {
                ++i;
            }
        }
        printf("%d\n", n - ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801094   2009-03-23 21:04:03     Accepted    3161    C++     70  180     watashi@Zodiac

// 2012-09-07 02:04:47 | Accepted | 3161 | C++ | 40 | 184 | watashi | Source
