#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>

using namespace std;

const int MAXN = 1024;
int a[MAXN][MAXN];

int main() {
    int w, h, r, g, b, s;

    while (scanf("%dx%d", &w, &h) != EOF) {
        assert(3 <= w && w <= 300);
        assert(3 <= h && h <= 300);
        s = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                assert(scanf(" #%2x%2x%2x", &r, &g, &b) == 3);
                a[i][j] = (11 * r + 16 * g + 5 * b) / 32;
                s += a[i][j];
            }
        }
        s /= (w * h);
        s = (192 + 2 * s) / 3;
        printf("%dx%d\n", w, h);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                printf("%c%c", a[i][j] < s ? '9' : ' ', j == w - 1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//316   2010-06-27 07:47:13     Accepted    1061    C++     160     4276    anotherpeg  Source

// 2012-09-07 15:51:10 | Accepted | 3383 | C++ | 80 | 4276 | watashi | Source
