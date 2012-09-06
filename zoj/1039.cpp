#include <cstdio>
#include <algorithm>
using namespace std;

int bin[20];
bool dp[1 << 19];

int next(int src, int act)
{
    src |= bin[act - 2];
    for (int i = act; i < 19; i++)
        if(src & bin[i - act])
            src |= bin[i];
    return src;
}

int main(void)
{
    int re, n, t, s;

    for (int i = 0; i < 20; i++)
       bin[i] = 1 << i;
    dp[bin[19] - 1] = false;
    for (int i = bin[19] - 2; i >= 0; i--) {
        dp[i] = false;
        for (int j = 0; j < 19; j++)
            if((i & bin[j]) == 0 && !dp[next(i, j + 2)]) {
                dp[i] = true;
                break;
            }
    }

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        s = bin[19] - 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            s ^= bin[t - 2];
        }
        printf("Scenario #%d:\n", ri);
        if(dp[s]) {
            printf("The winning moves are:");
            for (int i = 0; i < 19; i++)
                if((s & bin[i]) == 0 && !dp[next(s, i + 2)])
                    printf(" %d", i + 2);
            printf(".\n\n");
        }
        else {
            printf("There is no winning move.\n\n");
        }
    }
}
//2871094   2008-04-26 14:57:51     Accepted    1039    C++     00:00.29    900K    Re:ReJudge

// 2012-09-07 00:33:37 | Accepted | 1039 | C++ | 170 | 692 | watashi | Source
