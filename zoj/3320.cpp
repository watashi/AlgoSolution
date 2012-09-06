#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const int INF = 2000000000;

template<typename T>
inline void maxit(T& lhs, const T& rhs) {
    lhs = max(lhs, rhs);
}

void gao(int n, const int v[], const int d[], vector<int>& u, vector<int>& uu) {
    int s = 0;
    u.clear();
    uu.clear();
    uu.push_back(-INF); // if 0 then WA fi
    for (int i = 0; i < n; ++i) {
        if (d[i] > 0) {
            u.push_back(s);
            uu.push_back(s + v[i]);
        }
        s += v[i];
    }
    u.push_back(s);
}

void gao(int n, int v[], int d[], vector<int>& u, vector<int>& w, vector<int>& uu, vector<int>& ww) {
    gao(n, v, d, u, uu);
    reverse(v, v + n);
    reverse(d, d + n);
    gao(n, v, d, w, ww);
    for (int i = (int)ww.size() - 1; i >= 0; --i) {
        ww[i] = max(ww[i] + u[0], uu[i] + w[0]);
        for (int j = 1; j < i; ++j) {
            ww[i] = max(ww[i], max(ww[i - j] + u[j], uu[i - j] + w[j]));
        }
    }
    for (int i = (int)w.size() - 2; i >= 0; --i) {
        w[i] = w[i] + u[0];
        for (int j = 1; j <= i; ++j) {
            w[i] = max(w[i], w[i - j] + u[j]);
        }
    }
}

int main() {
    int n, m, l, ans;
    int v[MAXN][MAXN], d[MAXN][MAXN];
    vector<int> u[MAXN], w[MAXN], uu[MAXN], ww[MAXN];   // [0][0], [0][1], [1][0], [1][1]
    int dp[MAXN][MAXN][2][2];   // row, live, last, pass

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        for (int j = n - 1; j >= 0; --j) {
            for (int i = 0; i < m; ++i) {
                scanf("%d%d", &v[i][j], &d[i][j]);
            }
        }
        scanf("%d", &l);
        for (int i = 0; i < m; ++i) {
            gao(n, v[i], d[i], u[i], w[i], uu[i], ww[i]);
        }

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= l; ++j) {
                fill(dp[i][j][0], dp[i][j][2], -INF);
            }
        }
        dp[0][l][0][0] = 0;
        ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < (int)u[i].size(); ++k) {
                for (int j = k; j <= l; ++j) {
                    maxit(dp[i + 1][j - k][0][0], dp[i][j][0][0] + u[i][k]);
                    maxit(dp[i + 1][j - k][1][0], dp[i][j][1][0] + u[i][k]);
                    if (uu[i][k] >= 0) {
                        maxit(dp[i + 1][j - k][1][0], dp[i][j][0][0] + uu[i][k]);
                    }
                }
            }
        }
        maxit(ans, dp[m][0][1][0]);
        for (int j = 1; j <= l; ++j) {
            maxit(ans, dp[m][j][0][0]);
        }

        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < (int)w[i].size(); ++k) {
                for (int j = k; j <= l; ++j) {
                    maxit(dp[i + 1][j - k][0][0], dp[i][j][0][0] + w[i][k]);
                    maxit(dp[i + 1][j - k][0][1], dp[i][j][0][1] + w[i][k]);
                    maxit(dp[i + 1][j - k][1][0], dp[i][j][1][0] + w[i][k]);
                    maxit(dp[i + 1][j - k][1][1], dp[i][j][1][1] + w[i][k]);
                    if (ww[i][k] >= 0) {
                        maxit(dp[i + 1][j - k][1][0], dp[i][j][0][0] + ww[i][k]);
                        maxit(dp[i + 1][j - k][1][1], dp[i][j][0][1] + ww[i][k]);
                    }
                }
                if (k < (int)w[i].size() - 1) {
                    continue;
                }
                for (int j = k; j <= l; ++j) {
                    maxit(dp[i + 1][j - k][0][1], dp[i][j][0][0] + w[i][k]);
                    maxit(dp[i + 1][j - k][1][1], dp[i][j][1][0] + w[i][k]);
                }
            }
        }
        maxit(ans, dp[m][0][1][1]);
        for (int j = 1; j <= l; ++j) {
            maxit(ans, dp[m][j][0][1]);
        }

        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2173011   2010-04-22 15:39:53     Accepted    3320    C++     1690    968     watashi@Zodiac

// 2012-09-07 02:07:39 | Accepted | 3320 | C++ | 1060 | 972 | watashi | Source
