#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int bin[8] = {1, 2, 4, 8, 16, 32, 64, 128};

int x[128], y[128], m[128];
int xx[128][5], yy[128][5], zz[128][5];
int dp[128][1024], t[128];

void update(int p, int v, int c)
{
    for (int i = c; i <= t[p]; i++) {
        dp[p][i] = max(dp[p][i], dp[p + 1][i - c] + v);
    }
}

void gao(int p)
{
    int v, c, k, tc;
    static int pe[8];

    update(p, 0, abs(x[p + 1] - x[p]) + abs(y[p + 1] - y[p]));
    for (int i = 1; i < bin[m[p]]; i++) {
        k = 0;
        v = 0;
        for (int j = 0; j < m[p]; j++) {
            if (bin[j] & i) {
                pe[k++] = j;
                v += zz[p][j];
            }
        }
        c = 987654321;
        do {
            tc = abs(xx[p][pe[0]] - x[p + 1]) + abs(yy[p][pe[0]] - y[p + 1]);
            for (int j = 1; j < k; j++) {
                tc += abs(xx[p][pe[j]] - xx[p][pe[j - 1]]) + abs(yy[p][pe[j]] - yy[p][pe[j - 1]]);
            }
            tc += abs(xx[p][pe[k - 1]] - x[p]) + abs(yy[p][pe[k - 1]] - y[p]);
            c = min(c, tc);
        } while (next_permutation(pe, pe + k));
        update(p, v, c);
    }
}

int main(void)
{
    int re, n, maxt;

    scanf("%d", &re);
    while (re--) {
        scanf("%d", &n);
        for (int i = n; i >= 0; i--) {
            scanf("%d%d", &x[i], &y[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            scanf("%d", &m[i]);
            for (int j = 0; j < m[i]; j++) {
                scanf("%d%d%d", &xx[i][j], &yy[i][j], &zz[i][j]);
            }
        }
        maxt = 0;
        for (int i = n - 1; i >= 0; i--) {
            scanf("%d", &t[i]);
            maxt = max(maxt, t[i]);
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= maxt; j++) {
                dp[i][j] = -987654321;
            }
        }
        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            gao(i);
        }
        int ans = *max_element(dp[0], dp[0] + maxt);
        if (ans < 0) {
            puts("I'm doomed, though I fought bravely");
        }
        else {
            printf("%d\n", ans);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//395   2010-11-11 17:34:58     Accepted    E   C++     170     700     watashi@Zodiac  Source

// 2012-09-07 15:54:25 | Accepted | 3431 | C++ | 150 | 700 | watashi | Source
