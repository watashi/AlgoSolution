#include <cstdio>
#include <algorithm>

using namespace std;

double dp[128][32 * 128];

int main() {
    int re;
    int n, p, m, q, a, b, c;
    char buf[1024];
    int w[128][128];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &p);
        m = (p + 1) * (n + 1);
        fill(dp[0], dp[0] + 1 + m, 0);
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
                for (int k = 1; k <= p && k <= j; ++k) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] += dp[i][j - 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            for (int j = 0; j < n; ++j) {
                w[i][j] = (buf[j] == 'Y' ? 1 : 1000000000);
            }
            w[i][i] = 0;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
                }
            }
        }

        scanf("%d", &q);
        printf("Case %d\n", ri);
        for (int i = 0; i < q; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            --a;
            --b;
            printf("%.6lf\n", dp[w[a][b]][min(m, c)] / dp[w[a][b]][m]);
        }
        puts("");
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723950  	2011-01-22 17:20:45 	Accepted	1.242	4564	26909	C++	4299 - Randomly-priced Tickets
/*
id => 1174119
pid => 4299
pname => Randomly-priced Tickets
status => Accepted
lang => C++
time => 0.182
date => 2012-12-14 17:25:37
*/
