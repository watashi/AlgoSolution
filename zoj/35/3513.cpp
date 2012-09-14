#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 65536;

int n, m;
char _grid[MAXN];

char& grid(int i, int j) {
    return _grid[i * m + j];
}

char gao(int x, int y) {
    char& ret = grid(x, y);
    if (ret == '?') {
        ret = 'P';
        for (int k = x / y; k > 0; --k) {
            if (gao(x - k * y, y) == 'P') {
                ret = 'H';
            }
        }
        for (int k = y / x; k > 0; --k) {
            if (gao(x, y - k * x) == 'P') {
                ret = 'H';
            }
        }
    }
    return ret;
}

int main() {
    int ri = 0;

    while (scanf("%d%d", &n, &m) != EOF) {
        ++n;
        ++m;
        fill(_grid, _grid + n * m, '?');
        for (int i = 0; i < n; ++i) {
            grid(i, 0) = 'H';
        }
        for (int j = 0; j < m; ++j) {
            grid(0, j) = 'H';
        }
        printf("Case #%d:\n", ++ri);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                putchar(gao(i, j));
            }
            puts("");
        }
    }

    return 0;
}

// 2012-09-07 16:03:55 | Accepted | 3513 | C++ | 240 | 244 | watashi | Source
