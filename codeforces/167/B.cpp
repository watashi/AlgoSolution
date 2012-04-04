#include <cstdio>
#include <algorithm>

const int MAXN = 218;

double dp[2][MAXN][MAXN + MAXN];

using namespace std;

double p[MAXN], q[MAXN];
int a[MAXN];

int main() {
    int n, m, k;
    int pre, cur;
    double ans;

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &p[i]);
        p[i] /= 100;
        q[i] = 1 - p[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    pre = 0;
    cur = 1;
    fill(dp[cur][0], dp[cur + 1][0], 0);
    dp[cur][0][MAXN + k] = 1.0;
    for (int i = 0; i < n; ++i) {
        swap(pre, cur);
        fill(dp[cur][0], dp[cur + 1][0], 0);
        for (int j = 0; j < MAXN; ++j) {
            for (int k = 0; k < MAXN + MAXN; ++k) {
                if (dp[pre][j][k] == 0.0) {
                    continue;
                }
                dp[cur][j + 1][min(k + a[i], MAXN + n)] += dp[pre][j][k] * p[i];
                dp[cur][j][k] += dp[pre][j][k] * q[i];
            }
        }
    }

    ans = 0.0;
    for (int j = m; j < MAXN; ++j) {
        for (int k = MAXN; k < MAXN + MAXN; ++k) {
            ans += dp[cur][j][k];
        }
    }
    printf("%.10lf\n", ans);

    return 0;
}


