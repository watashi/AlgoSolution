#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXN = 218;
bool ok[MAXN];
double dp[MAXN][MAXN];
double a, b, c;

double gao(int l, int r) {
        if (l >= r) {
                return 0;
        } else if (dp[l][r] >= 0) {
                return dp[l][r];
        } else {
                double &ret = dp[l][r];
                ret = 0;
                for (int i = l; i < r; ++i) {
                        ret += a * ok[i]  + b * gao(l, i) + c * gao(i + 1, r);
                }
                ret /= (r - l);
                return ret;
        }
}

int main() {
        int n, k;
        int x[MAXN], y[MAXN], z;

        while (scanf("%d", &n) != EOF && (n >= 0)) {
                for (int i = 0; i < n; ++i) {
                        scanf("%d", &x[i]);
                }
                scanf("%d%lf%lf", &k, &a, &b);
                c = 1 - (a + b);
                copy(x, x + n, y);
                sort(y, y + n);
                if (k > unique(y, y + n) - y) {
                        z = -1;
                } else {
                        z = y[k - 1];
                }
                fill(dp[0], dp[n], -1);
                for (int i = 0; i < n; ++i) {
                        ok[i] = (x[i] == z);
                }
                printf("%.3lf\n", fabs(gao(0, n)));
        }
}
// Run ID       Submit Time     Judge Status    Problem ID      Language  Run Time(ms)          Run Memory(KB)          User Name       Admin
// 1296         2009-07-23 17:58:08     Accepted        1077    C++     1560 552        liehuochongsheng        Source

// 2012-09-07 15:46:18 | Accepted | 3307 | C++ | 1150 | 552 | watashi | Source
