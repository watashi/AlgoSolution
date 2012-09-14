//µ›πÈprintit£¨±ÿ–Î¡À

#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

int a[10][2];
int dp[10][10][2];

inline int cost(const int i, const int j, const int k)
{
    return a[i][0] * a[j][1] * a[k][1];
}

void printit(int l, int r)
{
    if(l == r) {
        printf("A%d", l + 1);
    }
    else {
        int m = dp[l][r][1];
        putchar('(');
        printit(l, m);
        printf(" x ");
        printit(m + 1, r);
        putchar(')');
    }
}

int main(void)
{
    int ri = 0, n;
    while(scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i][0], &a[i][1]);
            dp[i][i][0] = 0;
            dp[i][i][1] = -1;
            fill(dp[i][i], dp[i][n + 1], numeric_limits<int>::max());
        }
        for (int l = n - 1; l >= 0; l--)
            for (int r = l + 1; r < n; r++)
                for (int m = l; m < r; m++) {
                    int tmp = dp[l][m][0] + dp[m + 1][r][0] + cost(l, m, r);
                    if(tmp < dp[l][r][0]) {
                        dp[l][r][0] = tmp;
                        dp[l][r][1] = m;
                    }
                }
        printf("Case %d: ", ++ri);
        printit(0, n - 1);
        putchar('\n');
    }
    return 0;
}

//2747360 2008-02-09 23:10:03 Accepted 1276 C++ 00:00.00 432K §Ô§ø§∑

// 2012-09-07 00:43:58 | Accepted | 1276 | C++ | 0 | 180 | watashi | Source
