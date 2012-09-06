#include <cstdio>
#include <algorithm>
using namespace std;

int dp[5005];
int c[100], p[100];

int main(void)
{
    int re;
    int t, n, k, m;
    int *pos;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%*s", &t);
        m = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%*s%d", &k);
            for (int j = 0; j < k; j++)
                scanf("%*d%*s%d%*s", &c[m++]);
        }
        for (int i = 0; i < m; i++)
            scanf("%d", &p[i]);
        fill(dp + 1, dp + t + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < m; i++)
            for (int j = t; j >= c[i]; j--)
                if(dp[j - c[i]] != -1)
                    dp[j] = max(dp[j], dp[j - c[i]] + p[i]);
        pos = max_element(dp, dp + t + 1);
        printf("%d %d\n", pos - dp, *pos);
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2870852   2008-04-26 14:16:24     Accepted    1611    C++     00:00.05    460K    Re:ReJudge

// 2012-09-07 00:55:51 | Accepted | 1611 | C++ | 10 | 200 | watashi | Source
