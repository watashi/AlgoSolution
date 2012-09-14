#include <cstdio>
#include <algorithm>
using namespace std;

const int bin[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int mp[10][10];
int dp[1024];

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mp[i][j]);
        fill(dp, dp + bin[n], 0);
        for (int k = 0; k < bin[n]; k++) {
            for (int i = 0; i < n; i++) {
                if(k & bin[i])
                    continue;;
                for (int j = 0; j < n; j++) {
                    if(k & bin[j])
                        continue;
                    if(i == j)
                        continue;
                    dp[k | bin[j]] = max(dp[k | bin[j]], dp[k] + mp[i][j]);
                }
            }
        }
        printf("%d\n", *max_element(dp, dp + bin[n]));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//707   2011-02-08 20:30:59     Accepted    E   C++     60  184     watashi@ArcOfDream  Source

// 2012-09-07 15:59:27 | Accepted | 3471 | C++ | 60 | 184 | watashi | Source
