#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int sqr(int x) {
    return x * x;
}

const int MAXN = 1024;

int x[MAXN], y[MAXN], z[MAXN];

int main() {
    int xa, ya, xb, yb, n, m;

    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        z[i] *= z[i];
    }

    if (xa > xb) {
        swap(xa, xb);
    }
    if (ya > yb) {
        swap(ya, yb);
    }
    m = 0;
    for (int i = xa; i <= xb; ++i) {
        for (int j = ya; j <= yb; ++j) {
            if (i == xa || i == xb || j == ya || j == yb) {
                ++m;
                for (int k = 0; k < n; ++k) {
                    if (sqr(i - x[k]) + sqr(j - y[k]) <= z[k]) {
                        --m;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", m);

    return 0;
}
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1133084 	Feb 2, 2012 4:46:14 PM 	watashi 	144B - Meeting 	GNU C++0x 	Accepted 	50 ms 	1400 KB
