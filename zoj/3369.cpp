#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cstring>

const int MAXN = 52;

int dp[MAXN][MAXN][MAXN];
int pre[MAXN][MAXN][MAXN];

int main() {
    int n, h, ss, pp, mm, t;
    int s[MAXN], p[MAXN], m[MAXN];
    char ans[MAXN];

    while (scanf("%d%d%d%d%d", &n, &h, &ss, &pp, &mm) != EOF) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= mm; ++k) {
                    dp[i][j][k] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &s[i], &p[i], &m[i]);
        }

        dp[0][0][mm] = h;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int k = 0; k <= mm; ++k) {
                    if (dp[i][j][k] == 0) {
                        continue;
                    }

                    t = 2 * s[i] - ss - j;
                    if (t < 0) {
                        t = 0;
                    }
                    if (ss + j >= s[i] && dp[i + 1][j + 1][k] < dp[i][j][k] - t) {
                        dp[i + 1][j + 1][k] = dp[i][j][k] - t;
                        pre[i + 1][j + 1][k] = 0;
                    }

                    t = pp + i - j;
                    if (t >= p[i] && k - m[i] >= 0 && dp[i + 1][j][k - m[i]] < dp[i][j][k]) {
                        dp[i + 1][j][k - m[i]] = dp[i][j][k];
                        pre[i + 1][j][k - m[i]] = 1;
                    }
                }
            }
        }

        ss = -1;
        bool spj = false;
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= mm; ++k) {
                if (dp[n][j][k] > 0) {
                    if (ss != -1) {
                        spj = true;
                    }
                    ss = j;
                    mm = k;
                }
            }
        }

        if (spj) {
            fputs("please spj me!\n", stderr);
        }
        if (ss == -1) {
            strcpy(ans, "UNLUCKY");
        } else {
            ans[n] = '\0';
            for (int i = n - 1; i >= 0; --i) {
                if (pre[i + 1][ss][mm] == 0) {
                    ans[i] = 'D';
                    --ss;
                } else {
                    ans[i] = 'E';
                    mm += m[i];
                }
            }
        }
        puts(ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//528   2010-07-08 14:32:25     Accepted    asc11h  C++     30  1276    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//179   2010-07-08 14:42:08     Accepted    asc11h  C++     0   1276    watashi@Zodiac  Source

// 2012-09-07 15:49:35 | Accepted | 3369 | C++ | 0 | 1280 | watashi | Source
