#include <algorithm> // auto fix CE
#include <cstdio>

const int MAXN = 128;
const int dx[] = {0, 1, 0, -1, 0};  //!! {0, 0} is valid
const int dy[] = {1, 0, -1, 0, 0};

char mind[MAXN][MAXN][MAXN];

int main() {
    bool flag = false;
    int ri = 0, w, h, m, n, t, x1, y1, x2, y2;

    while (scanf("%d%d%d%d", &w, &h, &m, &n) != EOF && w > 0) {
        for (int k = 1; k <= m; ++k) {
            for (int i = 1; i <= w; ++i) {
                mind[k][i][0] = mind[k][i][h + 1] = '#';
            }
            for (int j = 1; j <= h; ++j) {
                mind[k][0][j] = mind[k][w + 1][j] = '#';
            }
            for (int i = 1; i <= w; ++i) {
                for (int j = 1; j <= h; ++j) {
                    mind[k][i][j] = k == 1 ? (m == 1 ? '*' : '.') : ' ';    // WA when m == 1
                }
            }
        }
        for (int k = 1; k <= n; ++k) {
            scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
            for (int i = x1; i <= x2; ++i) {
                for (int j = y1; j <= y2; ++j) {
                    mind[t][i][j] = '#';
                }
            }
        }

        for (int k = 1; k < m; ++k) {
            for (int i = 1; i <= w; ++i) {
                for (int j = 1; j <= h; ++j) {
                    if (mind[k][i][j] != '.') {
                        continue;
                    }
                    // printf("%c %d %d %d\n", '.', k, i, j);
                    for (int d = 0; d < 5; ++d) {
                        if (mind[k + 1][i + dx[d]][j + dy[d]] == ' ') {
                            mind[k + 1][i + dx[d]][j + dy[d]] = (k + 1 == m) ? '*' : '.';
                        }
                    }
                }
            }
        }

        for (int k = m; k > 1; --k) {
            for (int i = 1; i <= w; ++i) {
                for (int j = 1; j <= h; ++j) {
                    if (mind[k][i][j] != '*') {
                        continue;
                    }
                    // printf("%c %d %d %d\n", '*', k, i, j);
                    for (int d = 0; d < 5; ++d) {
                        if (mind[k - 1][i + dx[d]][j + dy[d]] == '.') {
                            mind[k - 1][i + dx[d]][j + dy[d]] = '*';
                        }
                    }
                }
            }
        }

        flag = false;
        printf("Robbery #%d:\n", ++ri);
        for (int k = 1; k <= m; ++k) {
            x1 = y1 = -1;
            for (int i = 1; i <= w; ++i) {
                for (int j = 1; j <= h; ++j) {
                    if (mind[k][i][j] == '*') {
                        if (x1 == -1) {
                            x1 = i;
                            y1 = j;
                        } else {
                            x1 = -2;
                        }
                    }
                }
            }
            if (x1 >= 0) {
                flag = true;
                printf("Time step %d: The robber has been at %d,%d.\n", k, x1, y1);
            } else if (x1 == -1 && k == 1) {
                flag = true;
                puts("The robber has escaped.");
                break;
            }
        }

        if (!flag) {
            puts("Nothing known.");
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//341   2010-06-28 15:49:40     Accepted    1013    C++     40  2228    anotherpeg  Source

// 2012-09-30 23:38:27 | Accepted | 1144 | C++ | 10 | 2228 | watashi | Source
