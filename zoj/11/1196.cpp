// 预处理出在x, y处建相邻的时的dist

#include <cstdio>
#include <algorithm>
using namespace std;

int ri = 0, n, k;
int d[200];
int dp[200];
int cost[200][200];

int main(void)
{
    while(scanf("%d%d", &n, &k) != EOF && n > 0 && k > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &d[i]);
            for (int j = 0; j < i; j++) {
                cost[j][i] = 0;
                for (int k = j + 1; k < i; k++)
                    cost[j][i] += min(d[k] - d[j], d[i] - d[k]);
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++)
                dp[i] += d[i] - d[j];
        }
        while(--k) {
            for (int i = n - 1; i >= 0; i--)
                for (int j = i - 1; j >= 0; j--)
                    dp[i] = min(dp[i], dp[j] + cost[j][i]);
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                dp[i] += d[j] - d[i];
        printf("Chain %d\nTotal distance sum = %d\n\n", ++ri, *min_element(dp, dp + n));
    }
    return 0;
}

// 2012-09-07 00:41:07 | Accepted | 1196 | C++ | 0 | 336 | watashi | Source
