#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 32;

struct Hungray {
    int nx, ny, mx[MAXN], my[MAXN];
    bool e[MAXN][MAXN];

    bool mark[MAXN];

    bool augment(int i) {
        if (!mark[i]) {
            mark[i] = true;
            for (int j = 0; j < ny; ++j) {
                if (e[i][j]) {
                    if (my[j] == -1 || augment(my[j])) {
                        mx[i] = j;
                        my[j] = i;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int gao() {
        int ret = 0;
        fill(mx, mx + nx, -1);
        fill(my, my + ny, -1);
        for (int i = 0; i < nx; ++i) {
            fill(mark, mark + nx, false);
            if (augment(i)) {
                ++ret;
            }
        }
        return ret;
    }
};

int main() {
    Hungray bg;
    int ans[MAXN], x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN], x, y, ri = 0;

    while (scanf("%d", &bg.nx) != EOF && bg.nx > 0) {
        bg.ny = bg.nx;
        for (int i = 0; i < bg.nx; ++i) {
            scanf("%d%d%d%d", &x1[i], &x2[i], &y1[i], &y2[i]);
        }
        for (int j = 0; j < bg.ny; ++j) {
            scanf("%d%d", &x, &y);
            for (int i = 0; i < bg.nx; ++i) {
                bg.e[i][j] = x1[i] < x && x < x2[i] && y1[i] < y && y < y2[i];
            }
        }

        x = bg.gao();
        y = 0;
        copy(bg.mx, bg.mx + bg.nx, ans);

        printf("Heap %d\n", ++ri);
        for (int i = 0; i < bg.nx; ++i) {
            if (ans[i] != -1) {
                bg.e[i][ans[i]] = false;
                if (bg.gao() < x) {
                    if (y > 0) {
                        putchar(' ');
                    }
                    printf("(%c,%d)", 'A' + i, 1 + ans[i]);
                    ++y;
                }
                bg.e[i][ans[i]] = true;
            }
        }
        puts(y == 0 ? "none\n" : "\n");
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//293   2010-06-27 06:49:49     Accepted    1018    C++     0   180     anotherpeg  Source

// 2012-09-30 23:38:59 | Accepted | 1197 | C++ | 0 | 180 | watashi | Source
