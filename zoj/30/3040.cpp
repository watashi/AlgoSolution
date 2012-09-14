#include <cstdio>

#pragma warning(disable:4996)

// -(Ai1X1 + Ai2X2 + ... + AinXn - Yi - Z) = 0 (i := 1 to n)
// X1 + X2 + ... + Xn + Y' = 1

// min{-Z}

const double eps = 1e-8;

int main()
{
    int re;
    int n, m;
    static double a[128][128];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%d%d", &n, &m);
        // init();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                scanf("%lf", &a[i][j]);
                a[i][j] /= -100.0;
            }
            a[m][j] = 1.0;
        }
        for (int j = 0; j <= m; j++) {
            for (int i = 0; i <= m; i++) {
                a[i][n + j] = (i == j);
            }
        }
        for (int i = 0; i < m; i++) {
            a[i][n + m + 1] = 1.0;
            a[i][n + m + 2] = 0.0;
        }
        a[m][n + m + 1] = 0.0;
        a[m][n + m + 2] = 1.0;
        for (int j = 0; j <= n + m; j++) {
            a[m + 1][j] = 0.0;
        }
        a[m + 1][n + m + 1] = -1.0;
        a[m + 1][n + m + 2] = 0.0;
        // work();
        int mm = m + 1, nn = n + m + 2;
        while (true) {
            int q = -1;
            for (int j = 0; j < nn; j++) {
                if (a[mm][j] < -eps && (q == -1 || a[mm][j] < a[mm][q])) {  // if Bland's rule TLE 2 no answer at all
                    q = j;
                }
            }
            if (q == -1) {
                break;
            }
            int r = -1;
            for (int i = 0; i < mm; i++) {
                if (a[i][q] > eps && (r == -1 || a[i][nn] / a[i][q] < a[r][nn] / a[r][q])) {
                    r = i;
                }
            }
            if (r == -1) {
                throw 1;
            }
            double tmp = a[r][q];
            for (int j = 0; j <= nn; j++) {
                a[r][j] /= tmp;
            }
            for (int i = 0; i <= mm; i++) {
                if (i == r) {
                    continue;
                }
                tmp = a[i][q];
                for (int j = 0; j <= nn; j++) {
                    a[i][j] -= tmp * a[r][j];
                }
            }
        }
        printf("%.20le\n", 100 * a[mm][nn]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1644789   2008-09-15 15:39:04     Accepted    3040    C++     50  388     watashi

// 2012-09-07 01:57:39 | Accepted | 3040 | C++ | 50 | 308 | watashi | Source
