#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 221;
char buf[MAXN][MAXN];
bool a[MAXN][MAXN], b[MAXN][MAXN];

void prepare(int x, int y, int z) {
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            a[i][j] = true;
        }
    }
    for (int k = 0; k <= z; ++k) {
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= y; ++j) {
                if (buf[k * x + i][k * y + j] == 'X') {
                    a[i][j] = false;
                }
            }
        }
    }
}

bool check(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            b[i][j] = a[i][j] &&
                ((i == x1 && j == y1) ||
                (i > x1 && b[i - 1][j]) ||
                (j > y1 && b[i][j - 1]));
        }
    }
    return b[x2][y2];
}

int main() {
    int n, m, ans;

    while (scanf("%d%d", &m, &n) != EOF) {
        memset(buf, 0, sizeof(buf));
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf[i]);
        }
        ans = -1;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (ans != -1 && i + j >= ans) {
                    continue;
                }
                int k = min((n - 1) / i, (m - 1) / j);
                int x = n - 1 - k * i, y = m - 1 - k * j;
                if (x <= i && y <= j) {
                    prepare(i, j, k);
                    if (check(0, 0, x, y) && check(x, y, i, j)) {
                        ans = i + j;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2157687   2010-04-12 23:00:58     Accepted    3315    C++     170     320     watashi@Zodiac

// 2012-09-07 02:07:08 | Accepted | 3315 | C++ | 170 | 324 | watashi | Source
