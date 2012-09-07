#include <algorithm> // auto fix CE
#include <cstdio>

const int MAXN = 128;
const int INF = 0x33333333;

int abc[MAXN][3];
int d[MAXN][MAXN];
int dp[MAXN][MAXN][3];

inline void minit(int& lhs, const int& rhs) {
    if (lhs > rhs) {
        lhs = rhs;
    }
}

inline void maxit(int& lhs, const int& rhs) {
    if (lhs < rhs) {
        lhs = rhs;
    }
}

int main() {
    int n, m, l, a, b;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = INF;
            }
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &abc[i][0], &abc[i][1], &abc[i][2], &l);
            for (int j = 0; j < l; ++j) {
                scanf("%d%d", &a, &b);
                d[i][a] = b;
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    minit(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][k] = -INF;
                }
            }
        }
        dp[1][0][0] = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][k] += abc[j][k];
                    // no move
                    maxit(dp[i + 1][j][k < 2 ? k + 1 : 2], dp[i][j][k]);
                    // move
                    for (int jj = 0; jj < n; ++jj) {
                        if (dp[i][j][k] >= d[j][jj]) {
                            maxit(dp[i + 1][jj][0], dp[i][j][k] - d[j][jj]);
                        }
                    }
                }
            }
        }

        a = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 3; ++k) {
                maxit(a, dp[m][j][k]);
            }
        }
        printf("%d\n", a);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//912   2010-07-22 02:15:04     Accepted    1111    C++     110     436     anotherpeg  Source

// 2012-09-07 15:48:27 | Accepted | 3358 | C++ | 70 | 436 | watashi | Source
