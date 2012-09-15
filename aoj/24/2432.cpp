#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 155;
const int INF = 1 << 20;

typedef int Mat[MAXN][MAXN];

int max(int n, const Mat a) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret = max(ret, a[i][j]);
        }
    }
    return ret;
}

void clr(int n, Mat a, int b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = b;
        }
    }
}

void dbg(int n, Mat a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d%c", a[i][j], j == n - 1 ? '\n' : ' ');
        }
    }
}

void cpy(int n, const Mat a, Mat b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[i][j];
        }
    }
}

void mul(int n, const Mat a, const Mat b, Mat ret) {
    static Mat c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = -1;
            for (int k = 0; k < n; ++k) {
                if (a[i][k] != -1 && b[k][j] != -1) {
                    c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
                }
            }
            c[i][j] = min(c[i][j], INF);
        }
    }
    cpy(n, c, ret);
}

void pow(int n, const Mat a, int b, Mat ret) {
    static Mat c;
    clr(n, ret, 0);
    cpy(n, a, c);
    while (b > 0) {
        if (b & 1) {
            mul(n, c, ret, ret);
        }
        mul(n, c, c, c);
        b >>= 1;
    }
}

Mat a, b;

void gao(int n, int q) {
    static int dp[MAXN][MAXN];
    static int pre[MAXN][MAXN];
    fill(dp[0], dp[0] + n, 0);
    for (int m = 1; ; ++m) {
        for (int i = 0; i < n; ++i) {
            dp[m][i] = -1;
            for (int j = 0; j < n; ++j) {
                if (a[j][i] != -1 && dp[m - 1][j] != -1 && dp[m - 1][j] + a[j][i] > dp[m][i]) {
                    dp[m][i] = dp[m - 1][j] + a[j][i];
                    pre[m][i] = j;
                }
            }
        }
        int k = max_element(dp[m], dp[m] + n) - dp[m];
        if (dp[m][k] >= q) {
            vector<int> ans(1, k);
            for (int i = m; i > 0; k = pre[i][k], --i) {
                ans.push_back(pre[i][k]);
            }
            reverse(ans.begin(), ans.end());
            // printf("%d\n", ans.size());
            for (int i = 0; i < (int)ans.size(); ++i) {
                printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
            }
            return;
        }
    }
}

int main() {
    int n, m, q, x, y, z;

    scanf("%d%d%d", &n, &m, &q);
    clr(n, a, -1);
    for (int i = 0; i < n; ++i) {
        a[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = max(a[x][y], z);
    }

    int lo = 0, up = q + 1;

    while (lo < up) {
        int mi = (lo + up) / 2;
        pow(n, a, mi, b);
        if (max(n, b) >= q) {
            up = mi;
        } else {
            lo = mi + 1;
        }
    }

    if (up > q) {
        puts("-1");
    } else if (up > 100) {
        printf("%d\n", up);
    } else {
        printf("%d\n", up);
        gao(n, q);
    }

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#485980 	watashi 	2432 	: Accepted 	C++ 	02:48 sec 	1436 KB 	3177 Bytes 	Sun Sep 16 02:06:44
