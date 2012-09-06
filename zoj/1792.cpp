#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int ini = -65536;

char s1[512], s2[512];
int dp[512][512][3];

int main(void)
{
    int re;
    int l1, l2;

    scanf("%d ", &re);
    while(re--) {
        scanf("%s%s", s1 + 1, s2 + 1);
        l1 = strlen(s1 + 1);
        l2 = strlen(s2 + 1);
        for (int i = 0; i <= l1; i++)
            for (int j = 0; j <= l2; j++)
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = ini;
        dp[0][0][0] = 0;
        for (int i = 1; i <= l1; i++)
            for (int j = 1; j <= l2; j++) {
                dp[i][j][0] = max(dp[i - 1][j - 1][0], max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]));
                if(s1[i] == s2[j])
                    dp[i][j][0] += 2;
                else
                    --dp[i][j][0];
                dp[i][j][1] = max(max(dp[i][j - 1][0], dp[i][j - 1][2]) - 5, dp[i][j - 1][1] - 1);
                dp[i][j][2] = max(max(dp[i - 1][j][0], dp[i - 1][j][1]) - 5, dp[i - 1][j][2] - 1);
            }
        printf("%d\n", max(dp[l1][l2][0], max(dp[l1][l2][1], dp[l1][l2][2])));
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2873161   2008-04-27 08:39:02     Accepted    1792    C++     00:00.02    3464K   Re:ReJudge

// 2012-09-07 01:01:02 | Accepted | 1792 | C++ | 0 | 3252 | watashi | Source
