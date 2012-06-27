#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int MAXM = 10;

int a[MAXN];
char s[MAXN];
int dp[MAXN][MAXM];

bool gao(int n, int m) {
    fill(dp[0], dp[n], -1);
    if (a[n - 1] == -1) {
        fill(dp[n - 1], dp[n], -2);
    } else {
        dp[n - 1][a[n - 1]] = -2;
    }
    dp[n - 1][a[0]] = -1;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == -1 || a[i] == j) {
                for (int k = 0; k < m; ++k) {
                    if (k != j && dp[i + 1][k] != -1) {
                        dp[i][j] = k;
                        break;
                    }
                }
            }
        }
    }
    if (dp[0][a[0]] == -1) {
        return false;
    } else {
        for (int i = 0, j = a[0]; i < n; j = dp[i][j], ++i) {
            s[i] = '0' + j;
        }
        return true;
    }
}

int main() {
    int re, n, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%s", &m, s);
        n = (int)strlen(s);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                a[i] = -1;
            } else {
                a[i] = s[i] - '0';
            }
        }
        if (n == 1) {
            printf("%d\n", a[0] == -1 ? 0 : a[0]);
            continue;
        }
        for (int i = 0; i <= m; ++i) {
            if (i == m) {
                puts("NO");
            } else if (s[0] == '?' || a[0] == i) {
                a[0] = i;
                if (gao(n, m)) {
                    puts(s);
                    break;
                }
            }
        }
    }

    return 0;
}
