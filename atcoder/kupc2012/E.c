#include <stdio.h>
#include <stdlib.h>

#define MAXN 50

int pt[MAXN][MAXN];

int main() {
    int i, j, k, m, n, a[MAXN], b[MAXN];
    char buf[MAXN];

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        a[i] = 1;
        scanf("%s", buf);
        for (j = 0; j < n; ++j) {
            switch (buf[j]) {
            case 'o': pt[i][j] = 3; break;
            case '-': pt[i][j] = 1; break;
            case 'x': pt[i][j] = 0; break;
            }
        }
    }

    m = 1000;
    while (m-- > 0) {
        for (i = 0; i < n; ++i) {
            b[i] = 0;
            for (j = 0; j < n; ++j) {
                b[i] += a[j] * pt[i][j];
            }
            b[i] *= b[i];
            if (i > 0) {
                b[i] += b[i - 1];
            }
        }
        k = rand() % b[n - 1];
        for (i = 0; i < n; ++i) {
            if (k < b[i]) {
                printf("%d\n", i + 1);
                break;
            }
        }
        fflush(stdout);

        scanf("%d", &k);
        ++a[k - 1];
    }

    return 0;
}

