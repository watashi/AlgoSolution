#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 512;

char s[MAXN];
int c[MAXN][MAXN], dp[MAXN][MAXN], pre[MAXN][MAXN];

void dump(int m, int n) {
    int p = pre[m][n];
    for (int i = 0; p + i < n - 1 - i; ++i) {
        s[p + i] = s[n - 1 - i];
    }
    if (p > 0) {
        dump(m - 1, p);
        putchar('+');
    }
    for (int i = p; i < n; ++i) {
        putchar(s[i]);
    }
}

int main() {
    int n, m;

    scanf("%s%d", s, &m);
    n = (int)strlen(s);
    fill(c[0], c[n], MAXN);
    for (int i = 0; i < n; ++i) {
        for (int j = i, k = i, l = 0; 0 <= j && k < n; --j, ++k) {
            if (s[j] != s[k]) {
                ++l;
            }
            c[j][k] = l;
        }
        for (int j = i, k = i + 1, l = 0; 0 <= j && k < n; --j, ++k) {
            if (s[j] != s[k]) {
                ++l;
            }
            c[j][k] = l;
        }
    }

    fill(dp[0], dp[m + 1], MAXN);
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                if (dp[i + 1][k + 1] > dp[i][j] + c[j][k]) {
                    dp[i + 1][k + 1] = dp[i][j] + c[j][k];
                    pre[i + 1][k + 1] = j;
                }
            }
        }
    }

    printf("%d\n", dp[m][n]);
    dump(m, n);

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1132773 	Feb 2, 2012 2:45:51 PM 	watashi 	137D - Palindromes 	GNU C++ 	Accepted 	280 ms 	4400 KB
