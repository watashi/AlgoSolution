#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int bin[17] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 1 << 16};
int pr[16], st[1024];
int dp[1 << 16];

int main(void)
{
    int ri = 0;
    int n, m;
    char buf[40];
    map<string, int> mp;

    while(scanf("%d", &n) != EOF && n > 0) {
        mp.clear();
        for (int i = 0; i < n; i++) {
            scanf("%s%d", buf, &pr[i]);
            st[i] = bin[i]; // not 0 !!
            mp[buf] = i;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            st[i] = 0;
            do {
                scanf("%s", buf);
                st[i] |= bin[mp[buf]];
            } while(getchar() != '\n');
        }
        fill(dp, dp + bin[n], 0);
        for (int i = 0; i < bin[n]; i++) {
            for (int j = 0; j < m; j++)
                if((i & st[j]) == st[j]) {
                    dp[i] = 0;
                    goto BREAK;
                }
            for (int j = 0; j < n; j++) {
                if((i & bin[j]) == 0) {
                    /* dp[i | bin[j]] >?= dp[i] + pr[j]; */ /* auto fix >?= */
                    dp[i | bin[j]] = dp[i | bin[j]] > dp[i] + pr[j] ? dp[i | bin[j]] : dp[i] + pr[j];
                }
            }
BREAK:
            ;
        }
        printf("System %d: %d\n", ++ri, *max_element(dp, dp + bin[n]));
    }

    return 0;
}
//2870758   2008-04-26 13:57:57     Accepted    1639    C++     00:00.78    1100K   Re:ReJudge

// 2012-09-07 13:54:23 | Accepted | 1639 | C++ | 240 | 440 | watashi | Source
