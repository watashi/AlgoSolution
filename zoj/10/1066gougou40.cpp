#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int main() {
    int ri = 0;
    char s[128][128];
    int n, r, c, x, y, z;

    while (scanf("%d", &n) != EOF && n > 0) {
        r = 4 * n - 1;
        c = 4 * n + 3;
        for (int i = 1; i <= r; ++i) {
            if (i == 1 || i == r) {
                fill(s[i], s[i] + c, '*');
            } else {
                fill(s[i], s[i] + c, ' ');
                s[i][0] = s[i][c - 1] = '*';
            }
            if ((i & 3) == 0) {
                for (int j = 0; j < n; ++j) {
                    s[i][4 * j + 3] = 'h';
                }
            } else if ((i & 3) == 2) {
                for (int j = 0; j < n; ++j) {
                    s[i][4 * j + 1] = 'h';
                    s[i][4 * j + 3] = 'o';
                }
                s[i][4 * n - 3] = 'h';
            }
            s[i][c] = '\0';
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &z);
                if (z != 0) {
                    x = 4 * i + 2;
                    y = 4 * j + 3;
                    s[x][y] = 'O';
                    if (z > 0) {
                        s[x][y - 1] = '-'; s[x][y - 2] = 'H';
                        s[x][y + 1] = '-'; s[x][y + 2] = 'H';
                    } else {
                        s[x - 1][y] = '|'; s[x - 2][y] = 'H';
                        s[x + 1][y] = '|'; s[x + 2][y] = 'H';
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                x = 4 * i + 2;
                y = 4 * j + 3;
                if (s[x][y] == 'O') {
                    continue;
                }
                s[x][y] = 'O';
                if (s[x][y - 2] == 'h') {
                    s[x][y - 1] = '-'; s[x][y - 2] = 'H';
                } else {
                    s[x][y + 1] = '-'; s[x][y + 2] = 'H';
                }
                if (s[x - 2][y] == 'h') {
                    s[x - 1][y] = '|'; s[x - 2][y] = 'H';
                } else {
                    s[x + 1][y] = '|'; s[x + 2][y] = 'H';
                }
            }
        }

        if (ri > 0) {
            puts("");
        }
        printf("Case %d:\n\n", ++ri);
        for (int i = 1; i <= r; ++i) {
            puts(s[i]);
        }
    }

    return 0;
}

// 2012-09-30 23:37:49 | Accepted | 1066 | C++ | 0 | 180 | watashi | Source
