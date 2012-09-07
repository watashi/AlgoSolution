#include <algorithm> // auto fix CE
#include <cstdio>

const int inf = 1000000000;

int mp[1000][1000];
bool mark[1000];
int mind[1000];
int ord[1000];
int dp[1000];

int main(void)
{
    int n, m, a, b, c;

    while(scanf("%d%d", &n, &m) == 2 && n > 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mp[i][j] = inf;
        while(m--) {
            scanf("%d%d%d", &a, &b, &c);
            --a;
            --b;
            /* mp[a][b] <?= c; */ /* auto fix <?= */
            mp[a][b] = mp[a][b] < c ? mp[a][b] : c;
            /* mp[b][a] <?= c; */ /* auto fix <?= */
            mp[b][a] = mp[b][a] < c ? mp[b][a] : c;
        }

        for (int i = 0; i < n; i++) {
            mark[i] = false;
            mind[i] = inf;
            dp[i] = 0;
        }
        mind[1] = 0;
        for (int i = 0; i < n; i++) {
            ord[i] = -1;
            for (int j = 0; j < n; j++)
                if(!mark[j] && (ord[i] == -1 || mind[j] < mind[ord[i]]))
                    ord[i] = j;
            mark[ord[i]] = true;
            for (int j = 0; j < n; j++)
                if(!mark[j])
                    /* mind[j] <?= mind[ord[i]] + mp[ord[i]][j]; */ /* auto fix <?= */
                    mind[j] = mind[j] < mind[ord[i]] + mp[ord[i]][j] ? mind[j] : mind[ord[i]] + mp[ord[i]][j];
        }
        dp[0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if(mind[ord[i]] == inf)
                continue;
            for (int j = n - 1; j > i; j--) {
                if(mind[ord[i]] == mind[ord[j]])
                    break;
                else if(mp[ord[i]][ord[j]] < inf)
                    dp[ord[i]] += dp[ord[j]]; // if no 'chongbian'
            }
        }
        printf("%d\n", dp[1]);
    }

    return 0;
}
//2874805   2008-04-27 18:28:18     Accepted    2546    C++     00:00.29    4308K   Re:ReJudge

// 2012-09-07 13:54:41 | Accepted | 2546 | C++ | 110 | 4100 | watashi | Source
