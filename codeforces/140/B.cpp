#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 320;

int p[MAXN][MAXN], q[MAXN][MAXN], a[MAXN], b[MAXN];

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &p[i][j]);
            --p[i][j];
            q[i][p[i][j]] = j;
        }
    }

    a[0] = 0;
    b[0] = -1;
    a[1] = 0;
    b[1] = 1;
    if (q[n][a[1]] > q[n][b[1]]) {
        swap(a[1], b[1]);
    }
    for (int i = 2; i < n; ++i) {
        // printf("> %d %d\n", q[n][i], q[n][b[i - 1]]);
        if (q[n][i] > q[n][b[i - 1]]) {
            a[i] = a[i - 1];
            b[i] = b[i - 1];
        } else if (q[n][i] > q[n][a[i - 1]]) {
            a[i] = a[i - 1];
            b[i] = i;
        } else {
            a[i] = i;
            b[i] = a[i - 1];
        }
        // printf("%d %d\n", a[i], b[i]);
    }

    for (int i = 0; i < n; ++i) {
        int k = -1, u = -1;
        for (int j = 0; j < n; ++j) {
            int v = a[j] != i ? a[j] : b[j];
            if (v == -1) {
                continue;
            }
            // printf("[%d][%d] => %d(%d)\n", i, j, v, q[i][v]);
            if (k == -1 || q[i][u] > q[i][v]) {
                k = j;
                u = v;
            }
        }
        printf("%d ", k + 1);
    }
    puts("");

    return 0;
}

