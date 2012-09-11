#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int r[MAXN], c[MAXN], a[MAXN][MAXN];

int main() {
    int n, m, q, x, y;
    char op;

    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        r[i] = i;
    }
    for (int j = 0; j < m; ++j) {
        c[j] = j;
    }
    for (int k = 0; k < q; ++k) {
        scanf(" %c%d%d", &op, &x, &y);
        --x;
        --y;
        if (op == 'r') {
            swap(r[x], r[y]);
        } else if (op == 'c') {
            swap(c[x], c[y]);
        } else {
            printf("%d\n", a[r[x]][c[y]]);
        }
    }

    return 0;
}

