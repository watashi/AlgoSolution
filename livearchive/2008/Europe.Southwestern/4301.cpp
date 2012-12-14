#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 333;
long long c[MAXN][MAXN];
long long dp[MAXN][MAXN];
long long mod;

int main() {
    int re;
    int n, m, p;
    int b[MAXN], bb[MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%lld", &n, &m, &mod);
        for (int i = 0; i <= n; ++i) {
            b[i] = 0;
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                if (c[i][j] >= mod) {
                    c[i][j] -= mod;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%*d%d", &p);
            ++b[n - p];
        }
        partial_sum(b, b + n, bb);
       /* for (int i = 0; i < n; ++i) {
            printf("%d %d %d\n", i, b[i], bb[i]);
        }*/
        bool flag = true;
        for (int i = 0; flag && i < n; ++i) {
            if (bb[i] > i + 1) {
                flag = false;
            }
        }
        if (!flag) {
            puts("NO");
            continue;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 0;
        }
        dp[0][0] = 1 % mod;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < bb[i]; ++j) {
                dp[i + 1][j] = 0;
            }
            for (int j = bb[i]; j <= n - m + bb[i] && j <= i + 1; ++j) {
                dp[i + 1][j] = 0;
                for (int k = b[i]; k <= j; ++k) {
                    if (dp[i][j - k] > 0) {
                        dp[i + 1][j] += dp[i][j - k] * c[(n - m) - (j - bb[i]) + (k - b[i])][k - b[i]];
                        dp[i + 1][j] %= mod;
                    }
                }
      //          printf("[%d][%d] = %lld\n", i + 1, j, dp[i + 1][j]);
            }
            for (int j = min(i + 1, n - m + bb[i]) + 1; j <= n; ++j) {
                dp[i + 1][j] = 0;
            }
        }
        printf("YES %lld\n", dp[n][n]);
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723953  	2011-01-22 17:23:52 	Accepted	6.344	2136	26909	C++	4301 - The Merchant Guild
/*
id => 1174115
pid => 4301
pname => The Merchant Guild
status => Accepted
lang => C++
time => 2.099
date => 2012-12-14 17:24:38
*/
