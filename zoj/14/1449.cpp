// 400 * 400 枚举 20 最大和

#include <cstdio>

static int x[22][22][22];

inline int sum(const int i, const int a, const int b, const int c, const int d)
{
    return x[i][a][b] + x[i][c][d] - x[i][a][d] - x[i][c][b];
}

int main(void)
{
    int n, i, j, k, tmp, ans;
    int a, b, c, d;

    while(scanf("%d", &n) != EOF && n > 0) {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) {
                for (k = 1; k <= n; k++) {
                    scanf("%d", &x[i][j][k]);
                    x[i][j][k] += x[i][j][k - 1];
                }
                for (k = 1; k <= n; k++)
                    x[i][j][k] += x[i][j - 1][k];
            }
        ans = -128;
        for (a = 0; a < n; a++)
            for (b = 0; b < n; b++)
                for (c = a + 1; c <= n; c++)
                    for (d = b + 1; d <= n; d++) {
                        tmp = 0;
                        for (i = 1; i <= n; i++) {
                            tmp += sum(i, a, b, c, d);
                            if(tmp > ans)
                                ans = tmp;
                            if(tmp < 0)
                                tmp = 0;
                        }
                    }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2800536 2008-03-24 18:57:35 Accepted 1449 C++ 00:00.01 436K わたし

// 2012-09-07 00:49:45 | Accepted | 1449 | C++ | 0 | 220 | watashi | Source
