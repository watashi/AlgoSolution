#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 310;
const int INF = INT_MAX / MAXN;

void init(int n, int w[MAXN][MAXN]) {
    fill(w[0], w[n], -INF);
    for (int i = 0; i < n; ++i) {
        w[i][i] = 0;
    }
}

void mul(int n, const int a[MAXN][MAXN], const int b[MAXN][MAXN], int ret[MAXN][MAXN]) {
    static int c[MAXN][MAXN];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = -INF;
            for (int k = 0; k < n; ++k) {
                c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    copy(c[0], c[n], ret[0]);
}

void pow(int n, const int w[MAXN][MAXN], int b, int ret[MAXN][MAXN]) {
    static int a[MAXN][MAXN], c[MAXN][MAXN];
    copy(w[0], w[n], a[0]);
    init(n, c);
    while (b > 0) {
        if (b & 1) {
            mul(n, a, c, c);
        }
        b >>= 1;
        mul(n, a, a, a);
    }
    copy(c[0], c[n], ret[0]);
}

int w[MAXN][MAXN], z[MAXN][MAXN];

int main() {
    int n, m, a, b, c, d;

    scanf("%d%d", &n, &m);
    init(n, w);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        --a;
        --b;
        w[a][b] = c;
        w[b][a] = d;
    }

    a = 2;
    b = n + 1;
    while (a < b) {
        c = (a + b) / 2;
        d = -INF;
        pow(n, w, c, z);
        for (int i = 0; i < n; ++i) {
            d = max(d, z[i][i]);
        }
        if (d > 0) {
            b = c;
        } else {
            a = c + 1;
        }
    }
    printf("%d\n", b > n ? 0 : b);

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1120186 	Jan 27, 2012 12:50:00 PM 	watashi 	147B - Smile House 	GNU C++ 	Accepted 	4190 ms 	3200 KB 

