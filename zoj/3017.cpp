#include <algorithm> // auto fix CE
#include <cstdio>

const int inf = 1234567890;

int dp[100][10][101];
int t[10][100], p[10][10];

// 或写成记忆化搜索比较好

int main(void)
{
    int re;
    int n, m, z;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d%d", &n, &m, &z);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                scanf("%d", &t[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &p[i][j]);
            }
        }
        /****floyd****/
        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    /* p[i][j] <?= p[i][k] + p[k][j]; */ /* auto fix <?= */
                    p[i][j] = p[i][j] < p[i][k] + p[k][j] ? p[i][j] : p[i][k] + p[k][j];
        /*************/
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k <= z; k++)
                    dp[i][j][k] = inf;
        dp[0][0][z] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = z; j >= 0; j--) {
                for (int k = 0; k < m; k++) {
                    /* dp[i + 1][k][j] <?= dp[i][k][j] + t[k][i]; */ /* auto fix <?= */
                    dp[i + 1][k][j] = dp[i + 1][k][j] < dp[i][k][j] + t[k][i] ? dp[i + 1][k][j] : dp[i][k][j] + t[k][i];
                    for (int l = 0; l < m; l++) {
                        if (j >= p[k][l]) {
                            // p[k][l] always > 0
                            /* dp[i][l][j - p[k][l]] <?= dp[i][k][j]; */ /* auto fix <?= */
                            dp[i][l][j - p[k][l]] = dp[i][l][j - p[k][l]] < dp[i][k][j] ? dp[i][l][j - p[k][l]] : dp[i][k][j];
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int j = z; j >= 0; j--) {
            for (int k = 0; k < m; k++) {
                /* ans <?= dp[n - 1][k][j]; */ /* auto fix <?= */
                ans = ans < dp[n - 1][k][j] ? ans : dp[n - 1][k][j];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//26140     2008-07-06 06:36:40     Accepted    1004    C++     0   660     watashi     Source

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3040696   2008-08-18 16:21:26     Accepted    3017    C++     00:00.03    796K    Re:ReJudge
//

// 2012-09-07 13:54:48 | Accepted | 3017 | C++ | 0 | 580 | watashi | Source
