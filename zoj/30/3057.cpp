#include <cstdio>

const int MAXN = 301;

static bool s[MAXN][MAXN][MAXN];

int main(void)
{
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            for (int k = 0; k < MAXN; k++) {
                if (s[i][j][k]) {
                    continue;
                }
                for (int t = i + 1; t < MAXN; t++) {
                    s[t][j][k] = 1;
                }
                for (int t = j + 1; t < MAXN; t++) {
                    s[i][t][k] = 1;
                }
                for (int t = k + 1; t < MAXN; t++) {
                    s[i][j][t] = 1;
                }
                for (int x = i + 1, y = j + 1; x < MAXN && y < MAXN; ++x, ++y) {
                    s[x][y][k] = 1;
                }
                for (int x = i + 1, y = k + 1; x < MAXN && y < MAXN; ++x, ++y) {
                    s[x][j][y] = 1;
                }
                for (int x = j + 1, y = k + 1; x < MAXN && y < MAXN; ++x, ++y) {
                    s[i][x][y] = 1;
                }
            }
        }
    }

    int a, b, c;

    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        printf("%d\n", s[a][b][c]);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1711117   2008-11-26 21:19:20     Accepted    3057    C++     1550    26808   watashi@Zodiac

// 2012-09-07 01:59:05 | Accepted | 3057 | C++ | 1540 | 26812 | watashi | Source
