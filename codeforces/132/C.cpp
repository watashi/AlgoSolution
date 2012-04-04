#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int INF = 1000000007;
const int d[] = {-1, 1};

typedef pair<int, int> PII;

char buf[MAXN];
pair<int, int> dp[MAXN][MAXN][2];

PII shift(const PII& p, int h) {
    return {p.first + h, p.second + h};
}

PII merge(const PII& l, const PII& r) {
    return {min(l.first, r.first), max(l.second, r.second)};
}

int main() {
    int n, m, ans;

    scanf("%s%d", buf, &m);
    n = strlen(buf);
    fill(dp[0][0], dp[MAXN][0], make_pair(INF, -INF));
    dp[0][0][0] = dp[0][0][1] = make_pair(0, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (dp[i][j][k].first > dp[i][j][k].second) {
                    continue;
                }
                for (int jj = j + (buf[i] == 'F' ? 0 : 1); jj <= m; jj += 2) {
                    dp[i + 1][jj][k] = merge(dp[i + 1][jj][k], shift(dp[i][j][k], d[k]));
                }
                for (int jj = j + (buf[i] == 'T' ? 0 : 1); jj <= m; jj += 2) {
                    dp[i + 1][jj][k] = merge(dp[i + 1][jj][k], shift(dp[i][j][1 - k], 0));
                }
            }
        }
    }
    ans = 0;
    for (int k = 0; k < 2; ++k) {
        ans = max(ans, abs(dp[n][m][k].first));
        ans = max(ans, abs(dp[n][m][k].second));
    }
    printf("%d\n", ans);

    return 0;
}

