#include <cmath>
#include <cstdio>

const int MAXN = 65536;

const double tau = (sqrt(5.0) - 1) / 2;

int a[MAXN], b[MAXN];

int main() {
    int ri = 0, n, m;

    a[0] = 0;
    b[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        a[i] = (int)(ceil(i * tau) + 0.5);
        b[i] = a[i] + i;
    }
    while (scanf("%d%d", &n, &m) != EOF) {
        printf("Case #%d:\n", ++ri);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                putchar(a[i] <= j && j < b[i] ? 'P' : 'H');
            }
            puts("");
        }
    }

    return 0;
}

// 2012-09-07 16:04:01 | Accepted | 3513 | C++ | 20 | 692 | watashi | Source
