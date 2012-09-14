//可以单向dp
//但双向bfs（更好）
#include <cstdio>

const int Dir[5][2] = {
    {0, 0},
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

bool mp[111][111][111];
int ans[111][3];

int main(void)
{
    int ri = 0, w, h, t;
    int n, ti, Li, Ti, Ri, Bi;
    int x = -1, y = -1, cnt, one, zero;

    while(scanf("%d%d%d", &w, &h, &t) != EOF && (w || h || t)) {
        for (int i = 0; i <= w + 1; i++)
            for (int j = 0; j <= h + 1; j++)
                for (int k = 1; k <= t; k++)
                    mp[i][j][k] = false;
        scanf("%d", &n);
        for (int k = 0; k < n; k++) {
            scanf("%d%d%d%d%d", &ti, &Li, &Ti, &Ri, &Bi);
            for (int i = Li; i <= Ri; i++)
                for (int j = Ti; j <= Bi; j++)
                    mp[i][j][ti] = true;
        }
        for (int i = 1; i <= w; i++)
            for (int j = 1; j <= h; j++)
                mp[i][j][1] = !mp[i][j][1];

        for (int k = 2; k <= t; k++)
            for (int i = 1; i <= w; i++)
                for (int j = 1; j <= h; j++) {
                    if(mp[i][j][k]) {
                        mp[i][j][k] = false;
                        continue;
                    }
                    for (int d = 0; d < 5; d++)
                        if(mp[i + Dir[d][0]][j + Dir[d][1]][k - 1]) {
                            mp[i][j][k] = true;
                            break;
                        }
                }
        for (int k = t - 1; k > 0; k--)
            for (int i = 1; i <= w; i++)
                for (int j = 1; j <= h; j++)
                    if(mp[i][j][k]) {
                        mp[i][j][k] = false;
                        for (int d = 0; d < 5; d++)
                            if(mp[i + Dir[d][0]][j + Dir[d][1]][k + 1]) {
                                mp[i][j][k] = true;
                                break;
                            }
                    }
    /*  for (int k = 1; k <= t; k++) {
            printf("%d:\n", k);
            for (int i = 1; i <= w; i++) {
                for (int j = 1; j <= h; j++)
                    printf("%d ", mp[i][j][k]);
                printf("\n");
            }
        }
    */
        printf("Robbery #%d:\n", ++ri);
        one = zero = 0;
        for (int k = 1; k <= t; k++) {
            cnt = 0;
            for (int i = 1; i <= w; i++) {
                for (int j = 1; j <= h; j++) {
                    if(mp[i][j][k]) {
                        x = i;
                        y = j;
                        ++cnt;
                        if(cnt == 2)
                            break;
                    }
                }
                if(cnt > 1)
                    break;
            }
            switch(cnt)
            {
                case 0:
                    zero++;
                    break;
                case 1:
                    ans[one][0] = x;
                    ans[one][1] = y;
                    ans[one][2] = k;
                    one++;
                    break;
            }
            if(zero > 0)
                break;
        }
        if(zero > 0)
            printf("The robber has escaped.\n");
        else if(one == 0)
            printf("Nothing known.\n");
        else {
            for (int i = 0; i < one; i++)
                printf("Time step %d: The robber has been at %d,%d.\n", ans[i][2], ans[i][0], ans[i][1]);
        }
        printf("\n");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2836978   2008-04-10 22:31:36     Accepted    1144    C++     00:00.12    1736K   わたし

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//18444     2008-04-16 20:31:48     Accepted    1013    C++     30  1844    watashi

// 2012-09-07 00:38:53 | Accepted | 1144 | C++ | 40 | 1516 | watashi | Source
