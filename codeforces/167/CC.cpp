#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int win[MAXN][MAXN];

int gao(long long a, long long b) {
    int &ret = win[a][b];
    if (ret == 0) {
        ret = -1;
        if (a > b) {
            ret = gao(b, a);
        } else if (a == 0) {
            ret = -1;
        } else if (gao(b % a, a) == -1) {
            ret = 1;
        } else {
            long long c = a;
            while (c <= b) {
                if (gao(a, b - c) == -1) {
                    ret = 1;
                    break;
                }
                c *= a;
            }
        }
       // printf("%lld %lld => %d\n", a, b, ret);
    }
    return ret;
}

int main() {
    fill(win[0], win[MAXN], 0);
    for (int i = 0; i < 72; ++i) {
        printf("%3d: ", i);
        for (int j = 0; j <= i; ++j) {
            putchar(gao(i, j) > 0 ? 'W' : 'L');
        }
        puts("");
    }
    /*
    int n = 4;
    for (int i = 1; i <= 100; ++i) {
        printf("%d ", i);
        puts(gao(n, i) > 0 ? " YES" : "");
    }
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf(gao(a, b) > 0 ? "First" : "Second");
    }
    */
    return 0;
}

