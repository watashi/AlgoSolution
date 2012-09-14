#include <cstdio>

int t, m, n, x[12], y[12], z[12];

void gao(int p, int s)
{
    if (p == m) {
        if (s == t) {
            int blank = 0;

            n = 1;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < z[i]; j++) {
                    if (blank) {
                        putchar('+');
                    }
                    else {
                        blank = 1;
                    }
                    printf("%d", x[i]);
                }
            }
            printf("\n");
        }
        return;
    }
    s += x[p] * y[p];
    for (z[p] = y[p]; z[p] >= 0; --z[p]) {
        gao(p + 1, s);
        s -= x[p];
    }
}

int main(void)
{
    while (scanf("%d%d", &t, &n) != EOF && n > 0) {
        m = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[m]);
            if (m == 0 || x[m] != x[m - 1]) {
                y[m++] = 1;
            }
            else {
                ++y[m - 1];
            }
        }
        printf("Sums of %d:\n", t);
        n = 0;
        gao(0, 0);
        if (n == 0) {
            printf("NONE\n");
        }
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948712   2008-06-13 03:22:14     Accepted    1711    C++     00:00.00    432K    Re:ReJudge

// 2012-09-07 00:58:30 | Accepted | 1711 | C++ | 0 | 180 | watashi | Source
