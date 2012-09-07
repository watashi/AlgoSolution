#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cassert>

const int MAXN = 1024;
const int MAXM = 9;

double c[MAXN][MAXN];
// MLE
// double dp[MAXN][MAXN][MAXM];
double x[MAXN][MAXN];   // begin with any, end with false

int main() {
    int n, m;
    double s;

    c[0][0] = x[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
        for (int j = 0; j <= i; ++j) {
            x[i][j] = 0;
            for (int k = 0; k < MAXM && k <= j && k < i; ++k) {
                x[i][j] += x[i - k - 1][j - k];
            }
        }
    }
    while (scanf("%d%d", &n, &m) != EOF) {
        assert(1 <= n && n <= 1000);
        assert(1 <= m && m <= n);
        if (m < MAXM) {
            s = 0;
        } else {
            s = 0;
            for (int i = 0; i < MAXM; ++i) {
                for (int j = 0; i + j < MAXM; ++j) {
                    s += x[n - i - j - 1][m - i - j];
                }
            }
            s = 1 - s / c[n][m];
        }
        // sprintf(buf, "%.2le", s);
        // sscanf(buf, "%d.%de%d\n", &a, &b, &e);
        // printf("%d.%02d*10^%d\n", a, b, e);
        printf("%.6lf%%\n", fabs(s * 100));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//214   2010-08-12 14:59:50     Accepted    cirno   C++     120     16560   watashi@Zodiac  Source

// 2012-09-07 15:50:06 | Accepted | 3374 | C++ | 110 | 16564 | watashi | Source
