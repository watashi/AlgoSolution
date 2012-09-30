#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 512;
const int INF = 0x7f7f7f7f;

int main() {
    int ri = 0, n, m;
    bool mark[MAXN];
    int e[MAXN][MAXN], mind[MAXN];

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            mark[i] = false;
            mind[i] = INF;
            for (int j = 0; j < n; ++j) {
                e[i][j] = INF;
            }
        }
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            --a;
            --b;
            e[a][b] = e[b][a] = c;
        }

        mind[0] = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (!mark[j] && (k == -1 || mind[j] < mind[k])) {
                    k = j;
                }
            }
            mark[k] = true;
            for (int j = 0; j < n; ++j) {
                if (!mark[j] && mind[j] > mind[k] + e[k][j]) {
                    mind[j] = mind[k] + e[k][j];
                }
            }
        }

        double ans = 0;
        int x = 0, y = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (e[i][j] < INF) {
                    double a = min(mind[i], mind[j]);
                    double b = max(mind[i], mind[j]) - a;
                    if (b >= e[i][j]) {
                        if (ans < a + b) {
                            ans = a + b;
                            x = mind[i] > mind[j] ? i : j;
                            y = -1;
                        }
                    } else {
                        if (ans < a + (e[i][j] + b) / 2) {
                            ans = a + (e[i][j] + b) / 2;
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("System #%d\nThe last domino falls after %.1lf seconds, ", ++ri, ans);
        if (y == -1) {
            printf("at key domino %d.\n\n", x + 1);
        } else {
            printf("between key dominoes %d and %d.\n\n", x + 1, y + 1);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//289   2010-06-27 05:33:59     Accepted    1022    C++     10  180     anotherpeg  Source

// 2012-09-30 23:39:29 | Accepted | 1298 | C++ | 0 | 180 | watashi | Source
