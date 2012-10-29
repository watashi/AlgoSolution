#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 52;

struct Matrix {
    int r, c;
    int a[MAXN][MAXN];

    void read() {
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                scanf("%1d", &a[i][j]);
            }
        }
    }

    int operator()(int i, int j) const {
        return 0 <= i && i < r && 0 <= j && j < c ? a[i][j] : 0;
    }
};

int main() {
    Matrix a, b;
    int dx = 0, dy = 0, dz = 0;

    a.read();
    b.read();
    for (int x = -MAXN; x <= MAXN; ++x) {
        for (int y = -MAXN; y <= MAXN; ++y) {
            int z = 0;
            for (int i = 0; i < a.r; ++i) {
                for (int j = 0; j < a.c; ++j) {
                    z += a(i, j) * b(i + x, j + y);
                }
            }
            if (dz < z) {
                dx = x;
                dy = y;
                dz = z;
            }
        }
    }
    printf("%d %d\n", dx, dy);

    return 0;
}
