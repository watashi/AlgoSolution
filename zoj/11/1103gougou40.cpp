#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 64;
const int MAXQ = 50 * 50 * 50;

int x[MAXQ], y[MAXQ], z[MAXQ];
int d[MAXN][MAXN][MAXN];
char e[MAXN][MAXN];

int main() {
    int n, p1, p2, p3, ans;

    while (scanf("%d%d%d%d", &n, &p1, &p2, &p3) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf(" %c", &e[i][j]);
                for (int k = 0; k < n; ++k) {
                    d[i][j][k] = -1;
                }
            }
        }

        ans = -1;
        d[p1 - 1][p2 - 1][p3 - 1] = 0;
        x[0] = p1 - 1;
        y[0] = p2 - 1;
        z[0] = p3 - 1;
        for (int begin = 0, end = 1; begin < end; ++begin) {
            p1 = x[begin];
            p2 = y[begin];
            p3 = z[begin];
        //  printf("%d %d %d\n", p1, p2, p3);
            if (p1 == p2 && p2 == p3) {
                ans = d[p1][p2][p3];
                break;
            }
            for (int i = 0; i < n; ++i) {
                if (e[p1][i] == e[p2][p3] && d[i][p2][p3] == -1) {
                    d[i][p2][p3] = d[p1][p2][p3] + 1;
                    x[end] = i;
                    y[end] = p2;
                    z[end] = p3;
                    ++end;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (e[p2][i] == e[p3][p1] && d[p1][i][p3] == -1) {
                    d[p1][i][p3] = d[p1][p2][p3] + 1;
                    x[end] = p1;
                    y[end] = i;
                    z[end] = p3;
                    ++end;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (e[p3][i] == e[p1][p2] && d[p1][p2][i] == -1) {
                    d[p1][p2][i] = d[p1][p2][p3] + 1;
                    x[end] = p1;
                    y[end] = p2;
                    z[end] = i;
                    ++end;
                }
            }
        }

        if (ans == -1) {
            puts("impossible");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//252   2010-06-24 17:13:47     Accepted    1009    C++     30  2672    anotherpeg  Source

// 2012-09-30 23:38:01 | Accepted | 1103 | C++ | 10 | 2672 | watashi | Source
