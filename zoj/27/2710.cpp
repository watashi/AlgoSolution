#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXN = 218;
const double INF = 1e100;

double a[2][3];
int pre[MAXN][MAXN];
double dp[MAXN][MAXN];

void readLine(double a[]) {
    static double x1, y1, x2, y2, z;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    a[0] = y1 - y2;
    a[1] = x2 - x1;
    a[2] = x1 * y2 - x2 * y1;
    z = hypot(a[0], a[1]);
    a[0] /= z;
    a[1] /= z;
    a[2] /= z;
}

double distToLine(double a[], double x, double y) {
    return fabs(a[0] * x + a[1] * y + a[2]);
}

void printAns(int n, int k, char c) {
    if (n > 0) {
        // printf("[%d, %d]\n", n, k);
        printAns(n - 1, k - pre[n][k], ' ');
        printf("%d%c", pre[n][k] + 1, c);
    }
}

int main() {
    int n, c, k;
    double x, y, z, u, v;

    while (scanf("%d%d", &n, &c) != EOF) {
        readLine(a[0]);
        readLine(a[1]);
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf", &x, &y, &z);
            u = distToLine(a[0], x, y) * z;
            v = distToLine(a[1], x, y) * z;
            // printf("%d: %lf %lf\n", i, u, v);
            dp[i][0] = dp[i - 1][0] + u;
            pre[i][0] = 0;
            for (int j = 1; j < i; ++j) {
                if (dp[i - 1][j] + u <= dp[i - 1][j - 1] + v) {
                    dp[i][j] = dp[i - 1][j] + u;
                    pre[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + v;
                    pre[i][j] = 1;
                }
            }
            dp[i][i] = dp[i - 1][i - 1] + v;
            pre[i][i] = 1;
        }
        k = -1;
        for (int j = (n - c + 1) / 2; j <= (n + c) / 2; ++j) {
            if (k == -1 || dp[n][j] <= dp[n][k]) {
                k = j;
            }
        }
        printAns(n, k, '\n');
        puts("");
    }

    return 0;
}


/*
2113085 2010-03-16 Accepted     2710    C++      0    732    watashi@Zodiac
        12:54:30
*/

// 2012-09-07 15:45:29 | Accepted | 2710 | C++ | 0 | 736 | watashi | Source
