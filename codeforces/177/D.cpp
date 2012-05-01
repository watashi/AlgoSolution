#include <cstdio>

const int MAXN = 100100;

int a[MAXN], b[MAXN];

int main() {
    int n, m, c, s;

    scanf("%d%d%d", &n, &m, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }

    s = 0;
    for (int i = 0; i < n; ++i) {
        if (i < m) {
            s += b[i];
        }
        printf("%d ", (a[i] + s) % c);
        if (i >= n - m) {
            s -= b[i - (n - m)];
        }
    }

    return 0;
}

/*
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1643463 	Apr 29, 2012 10:38:01 AM 	watashi 	D2 - Encrypting Messages (70 points) 	GNU C++0x 	Accepted 	90 ms 	2100 KB
1643461 	Apr 29, 2012 10:37:33 AM 	watashi 	D1 - Encrypting Messages (30 points) 	GNU C++0x 	Accepted 	30 ms 	2100 KB
*/
