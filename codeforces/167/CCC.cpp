#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int win[MAXN];

void dump(int i, int n, int b) {
    if (i > 0) {
        dump(i - 1, n / b, b);
        printf("%2d", n % b);
    }
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    fill(win, win + MAXN, false);
    win[0] = true;
    for (int i = 1; i <= m; ++i) {
        dump(8, i, n);
        for (int j = 1; j <= i; j *= n) {
            if (!win[i - j]) {
                win[i] = true;
                break;
            }
        }
        puts(win[i] ? " => YES!": "");
    }
    /*
    for (int i = 0; i <= m; ++i) {
        putchar(win[i] ? 'Y' : 'N');
    }
    */

    return 0;
}

