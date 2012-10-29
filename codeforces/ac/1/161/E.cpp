#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

const int t[10] = {1, 10, 100, 1000, 10000, 100000, 1000000};
bool p[MAXN];
int q[MAXN][5];

int digit(int n, int p) {
    return n / t[p] % 10;
}

void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (!p[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                p[j] = true;
            }
            for (int j = 0; j < 5; ++j) {
                ++q[i - digit(i, j) * t[j]][j];
            }
        }
    }
}

int a[10];
int r[10], c[10];

int gao(int m, int n) {
    int ret = 0;
    if (n == 0) {
        ret = 1;
        for (int i = 1; i < m; ++i) {
            ret *= q[a[i]][m - 1 - i];
        }
    } else {
        --n;
        for (int i = 0; i < 10; ++i) {
            ret += gao(m, n);
            a[r[n]] += t[m - 1 - c[n]];
            a[c[n]] += t[m - 1 - r[n]];
        }
        a[r[n]] -= t[m - c[n]];
        a[c[n]] -= t[m - r[n]];
    }
    return ret;
}

int main() {
    int re, n, m, l;

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        m = 0;
        while (t[m] < n) {
            ++m;
        }
        for (int i = 1; i < m; ++i) {
            a[i] = digit(n, m - 1 - i) * t[m - 1];
        }
        l = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                r[l] = i;
                c[l] = j;
                ++l;
            }
        }
        printf("%d\n", gao(m, l));
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1348923 	Mar 11, 2012 11:06:46 PM 	watashi 	161E - Polycarpus the Safecracker 	GNU C++0x 	Accepted 	470 ms 	3400 KB
